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

std::string removeBrowserEscapes (std::string text) {
    text = std::regex_replace(text, std::regex("%20|\\+"), " ");
    text = std::regex_replace(text, std::regex("%24"), "$");
    text = std::regex_replace(text, std::regex("%26"), "&");
    text = std::regex_replace(text, std::regex("%60"), "`");
    text = std::regex_replace(text, std::regex("%3A"), ":");
    text = std::regex_replace(text, std::regex("%3C"), "<");
    text = std::regex_replace(text, std::regex("%3E"), ">");
    text = std::regex_replace(text, std::regex("%28"), "(");
    text = std::regex_replace(text, std::regex("%29"), ")");
    text = std::regex_replace(text, std::regex("%5B"), "[");
    text = std::regex_replace(text, std::regex("%5D"), "]");
    text = std::regex_replace(text, std::regex("%7B"), "{");
    text = std::regex_replace(text, std::regex("%7D"), "}");
    text = std::regex_replace(text, std::regex("%22"), "\"");
    text = std::regex_replace(text, std::regex("%2B"), "+");
    text = std::regex_replace(text, std::regex("%23"), "#");
    text = std::regex_replace(text, std::regex("%25"), "%");
    text = std::regex_replace(text, std::regex("%40"), "@");
    text = std::regex_replace(text, std::regex("%2F"), "/");
    text = std::regex_replace(text, std::regex("%3B"), ";");
    text = std::regex_replace(text, std::regex("%3D"), "=");
    text = std::regex_replace(text, std::regex("%3F"), "?");
    text = std::regex_replace(text, std::regex("%5C"), "\\");
    text = std::regex_replace(text, std::regex("%5E"), "^");
    text = std::regex_replace(text, std::regex("%7C"), "|");
    text = std::regex_replace(text, std::regex("%7E"), "~");
    text = std::regex_replace(text, std::regex("%27"), "´");
    text = std::regex_replace(text, std::regex("%2C"), ",");
    return text;
}

std::string extractAndRemoveGetKeyValueFromString (std::string temporary, std::map<std::string, std::string> &mapToUse) {
    std::string key = UTIL::getUntil(temporary, '=');
    temporary = UTIL::removeUntil (temporary, '=');
    std::string value = UTIL::getUntil (temporary, '&');
    mapToUse [key] = value;
    return temporary;
} 

std::string getPostData () {
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
    while (UTIL::getUntil(temporary, '=') != "") {
        temporary = extractAndRemoveGetKeyValueFromString (temporary, GET_MAP);
        temporary = UTIL::removeUntil(temporary, '&');
    }
}


void initializePost () {
    std::string temporary = std::string (getPostData());
    if (temporary == "") 
        return;
    while (UTIL::getUntil(temporary, '=') != "") {
        temporary = extractAndRemoveGetKeyValueFromString (temporary, POST_MAP);
        temporary = UTIL::removeUntil(temporary, '&');
    }
}
}


void initializeENV () {
    UTIL::initializeGet();
    UTIL::initializePost();
}

std::string GET (std::string name) {
    return UTIL::removeBrowserEscapes(UTIL::GET_MAP [name]);
}
std::string POST (std::string name) {
    return UTIL::removeBrowserEscapes(UTIL::POST_MAP [name]);
}

}
} // namespace WCP