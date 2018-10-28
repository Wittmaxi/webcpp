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