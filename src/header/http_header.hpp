#ifndef  DEFINED_COOKIES_HPP
#define   DEFINED_COOKIES_HPP
#include <string>
#include <vector>
#include <ostream>

namespace WCP {
class HTTPHeader {
public:
    ~HTTPHeader();
    void setContentType (const std::string &ct);
    void addCookie (const std::string &name, const std::string &value, const bool HTTPonly, const std::string &expiry);
    void addFlag (const std::string &flag);
    void print() const;
private:
    std::string contentType = "Content-type:text/html";
    bool printed;
    std::vector<std::string> flags;
};
}

#endif