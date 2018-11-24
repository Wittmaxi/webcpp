#ifndef  DEFINED_COOKIES_HPP
#define   DEFINED_COOKIES_HPP
#include <string>
#include <vector>
#include <ostream>

namespace WCP {
class HTTPHeader {
public:
    void setContentType (const std::string &ct);
    void addCookie (const std::string &name, const std::string &value, const bool HTTPonly, const std::string &expiry);
    void addFlag (const std::string &flag);
    void print();
    std::ostream& operator<< (std::ostream& os);
private:
    std::string contentType = "";
    std::vector<std::string> flags;
};
}

#endif