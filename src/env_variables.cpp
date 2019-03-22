#include "header/env_variables.hpp"
#include <regex>

namespace WCP
{
namespace ENV
{
namespace UTIL {
std::string to_print;
std::map <std::string, std::string> GET_MAP;
std::map <std::string, std::string> POST_MAP;
std::map <std::string, FILE> POST_FILES_MAP;
std::map <std::string, std::string> COOKIE_MAP;
bool enctype_form_data = false;

std::string removeUntil (const std::string& toProcess, const std::string& until) {
    auto it = toProcess.find(until);
    if (it == std::string::npos) 
        return "";
    return std::string (toProcess.begin() + ++it + until.size(), toProcess.end());
}

std::string getUntil (const std::string& toProcess, const std::string& until) {
    auto it = toProcess.find(until);
    if (it == std::string::npos) 
        return toProcess;
    return std::string (toProcess.begin(), toProcess.begin() + --it);
}

std::string getUntilBefore (const std::string& toProcess, const std::string& until) {
    auto it = toProcess.find(until);
    if (it == std::string::npos) 
        return toProcess;
    return std::string (toProcess.begin(), toProcess.begin() + --(--it));
}


std::string removeUntil (std::string toProcess, char until) {
    auto it = std::find(toProcess.begin(), toProcess.end(), until);
    if (it == toProcess.end()) 
        return "";
    return std::string (++it, toProcess.end());
}

std::string getUntil (std::string toProcess, char until) {
    auto it = std::find(toProcess.begin(), toProcess.end(), until);
    return std::string (toProcess.begin(), it);
}

std::string getUntilBefore (std::string toProcess, char until) {
    std::string temp;
    temp = getUntil (toProcess, until);
    temp = temp.substr(0, temp.size() - 1);
    return temp;
}


std::string removeBrowserEscapes (std::string text) {
    std::string temp_string;
    char *textPtr = const_cast <char*> (text.c_str());
    for (size_t i = 0; i < text.size(); i++) {
        if (text [i] == '+') {
            temp_string += " ";
        } else if (text [i] == '%') {
            char a = strtol (&(textPtr[i+1]), nullptr, 16);
            temp_string += a;
            i += 2;
        } else {
            temp_string += text [i];
        }
    }
    return temp_string;
}

std::string extractAndRemoveGetKeyValueFromString (std::string temporary, std::map<std::string, std::string> &mapToUse, char termination = '&') {
    std::string key = UTIL::getUntil(temporary, '=');
    key = std::regex_replace(key, std::regex(" "), "");
    temporary = UTIL::removeUntil (temporary, '=');
    std::string value = UTIL::getUntil (temporary, termination);
    mapToUse [key] = value;
    return UTIL::removeUntil(temporary, termination);
}

std::string getPostData () {
    std::string postData;
    std::string temp;
    while (std::getline(std::cin, temp).good())
        postData += temp + "\n"; 
    return postData;
}

std::string getPostHeader () {
    char *len_ = getenv("CONTENT_LENGTH");
    if (len_ == nullptr) 
        return "";
    long len = strtol(len_, nullptr, 10);
    if (len == 0)
        return "";
    char *postdata = static_cast <char*> (malloc(len + 1));
    if (!postdata) {
        std::cerr << "WEBCPP and it's HTTP accessor must be run in a webserver-context!";
        return "";
    }
    fgets(postdata, len + 1, stdin);
    std::string temp (postdata);
    free(postdata);
    return temp;
}


void initializeGet () {
    if (getenv ("QUERY_STRING") == nullptr) {
        std::cerr << "WEBCPP and it's HTTP accessor must be run in a webserver-context!";
        return;
    }
    std::string temporary = std::string(getenv ("QUERY_STRING"));
    while (temporary != "")
        temporary = extractAndRemoveGetKeyValueFromString (temporary, GET_MAP);
}

void parseMIMEPage(std::string input) {
    if (input == "") 
        return;
    std::string header = UTIL::removeUntil(input, '\n');
    header = UTIL::getUntilBefore(header, '\n');
    header = std::regex_replace(header, std::regex(" "), "");
    std::map<std::string, std::string> tempMap;
    header = UTIL::removeUntil(header, ';');
    while (header != "") {
        header = extractAndRemoveGetKeyValueFromString (header, tempMap, ';');
    }
    input = UTIL::removeUntil(input, '\n');
    input = UTIL::removeUntil(input, '\n');
    std::string contentType = UTIL::getUntil(input, '\n');
    input = UTIL::removeUntil(input, '\n');
    if (std::regex_search(contentType, std::regex("Content-Type:"))) {
        FILE tempFile; 
        tempFile.datatype = std::regex_replace(contentType, std::regex("Content-Type:"), "");
        tempFile.content = input;
        tempFile.filename = std::regex_replace(tempMap["filename"], std::regex("\""), "");
        POST_FILES_MAP[std::regex_replace(tempMap["name"], std::regex("\""), "")] = tempFile;
    } else {
        POST_MAP[std::regex_replace(tempMap["name"], std::regex("\""), "")] = UTIL::getUntil(input, '\n');
    }
}

void parsePOSTPage(std::string input) {
    if (input == "") 
        return;
    while (input != "")
        input = extractAndRemoveGetKeyValueFromString (input, POST_MAP);
}

void initializePost () {
    if (getenv ("CONTENT_TYPE") == nullptr) {
        std::cerr << "WEBCPP and it's HTTP accessor must be run in a webserver-context!";
        return;
    }
    std::string contentType = getenv("CONTENT_TYPE");
    if (std::regex_search(contentType, std::regex("multipart\\/form-data"))) {
        std::string content = getPostData();
        std::cout << "in";
        std::string boundary = std::regex_replace(contentType, std::regex("(.)+(boundary=)"), "");
        content = removeUntil(content, boundary);
        while (content != "") {
            parseMIMEPage(getUntilBefore(content, boundary));
            content = removeUntil(content, boundary);
        }
    } 
    else {
        std::string content = getPostHeader();
        parsePOSTPage(content);
    }
}

void initializeCookies () {
    if (getenv ("HTTP_COOKIE") == nullptr) {
        std::cerr << "WEBCPP and it's HTTP accessor must be run in a webserver-context!";
        return;
    }
    std::string temporary = std::string(getenv ("HTTP_COOKIE"));
    while (temporary != "")
        temporary = extractAndRemoveGetKeyValueFromString (temporary, COOKIE_MAP, ';');
}
}

void initializeENV () {
    UTIL::initializeGet();
    UTIL::initializePost();
    UTIL::initializeCookies();
}

std::string GET (const std::string &name) {
    return UTIL::removeBrowserEscapes(UTIL::GET_MAP [name]);
}
std::string POST (const std::string& name) {
    return UTIL::removeBrowserEscapes(UTIL::POST_MAP [name]);
}
FILE POSTFILE (const std::string& name) {
    return UTIL::POST_FILES_MAP[name];
}
std::string COOKIE (const std::string& name) {
    return UTIL::COOKIE_MAP[name];
}
}
} // namespace WCP