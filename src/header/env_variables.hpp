#ifndef DEFINE_ENV_VARIABLES
#define DEFINE_ENV_VARIABLES
#include <string>
#include <array>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <map>

namespace WCP
{
namespace ENV
{

//    "COMSPEC", "DOCUMENT_ROOT", "GATEWAY_INTERFACE",   
//    "HTTP_ACCEPT", "HTTP_ACCEPT_ENCODING",             
//    "HTTP_ACCEPT_LANGUAGE", "HTTP_CONNECTION",         
//    "HTTP_HOST", "HTTP_USER_AGENT", "PATH",            
//    "QUERY_STRING", "REMOTE_ADDR", "REMOTE_PORT",      
//    "REQUEST_METHOD", "REQUEST_URI", "SCRIPT_FILENAME",
//    "SCRIPT_NAME", "SERVER_ADDR", "SERVER_ADMIN",      
//    "SERVER_NAME","SERVER_PORT","SERVER_PROTOCOL",     
//    "SERVER_SIGNATURE","SERVER_SOFTWARE"  
// source : https://www.tutorialspoint.com/cplusplus/cpp_web_programming.htm

namespace UTIL {
extern std::string to_print;
extern std::map <std::string, std::string> GET_MAP;
extern std::map <std::string, std::string> POST_MAP;
extern std::map <std::string, std::string> COOKIE_MAP;

std::string removeBrowserEscapes (std::string text);
std::string removeUntil (std::string toProcess, char until);
std::string getUntil (std::string toProcess, char until);
std::string getPostData ();
std::string extractAndRemoveGetKeyValueFromString (std::string temporary);
void initializeGet();
void initializePost();
void initializeCookies ();
}

void initializeENV ();

std::string GET (std::string name);
std::string POST (std::string name);

}
} // namespace WCP

#endif