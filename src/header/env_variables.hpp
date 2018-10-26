#ifndef __DEFINE__ENV__VARIABLES
#define __DEFINE__ENV__VARIABLES
#include <string>
#include <array>
#include <stdlib.h>
#include <iostream>
#include <algorithm>


namespace WCP
{
namespace ENV
{
const std::array<std::string, 24> ENV_VARIABLE_NAMES = {
   "COMSPEC", "DOCUMENT_ROOT", "GATEWAY_INTERFACE",   
   "HTTP_ACCEPT", "HTTP_ACCEPT_ENCODING",             
   "HTTP_ACCEPT_LANGUAGE", "HTTP_CONNECTION",         
   "HTTP_HOST", "HTTP_USER_AGENT", "PATH",            
   "QUERY_STRING", "REMOTE_ADDR", "REMOTE_PORT",      
   "REQUEST_METHOD", "REQUEST_URI", "SCRIPT_FILENAME",
   "SCRIPT_NAME", "SERVER_ADDR", "SERVER_ADMIN",      
   "SERVER_NAME","SERVER_PORT","SERVER_PROTOCOL",     
   "SERVER_SIGNATURE","SERVER_SOFTWARE" };  

namespace __UTIL {
std::string removeUntil (std::string toProcess, char until) {
    return std::string (std::find(toProcess.begin(), toProcess.end(), until), toProcess.end());
}
std::string getUntil (std::string toProcess, char until) {
    return std::string (toProcess.begin(), std::find(toProcess.begin(), toProcess.end(), until));
}
}


std::string GET (std::string name) {
    std::string temporary(getenv ("QUERY_STRING"));
    temporary = __UTIL::removeUntil(temporary, '?');
    while (true) {
        if (__UTIL::getUntil (temporary, '=') == name) {
            return __UTIL::getUntil (__UTIL::removeUntil(temporary, '='), '&');
        }
    }
}

}
} // namespace WCP

#endif