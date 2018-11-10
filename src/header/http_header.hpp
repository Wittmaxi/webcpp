#ifndef DEFINED__COOKIES__HPP
#define  DEFINED__COOKIES__HPP
#include <string>
#include <vector>
#include <ostream>

namespace WCP {
class HTTPHeader {
public:
    void setContentType (std::string ct);
    void addCookie (std::string name, std::string value, bool HTTPonly, std::string expiry);
    void addFlag (std::string flag);
    void print();
    std::ostream& operator<< (std::ostream& os);
private:
    std::string contentType = "Content-type:text/html";
    std::vector<std::string> flags;
};
}

#endif