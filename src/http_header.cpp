#include "header/http_header.hpp"
#include <iostream>

namespace WCP
{
void HTTPHeader::setContentType(const std::string &ct)
{
    contentType = ct;
}
void HTTPHeader::addCookie(const std::string &name, const std::string &value, const bool HTTPonly, const std::string &expiry)
{
    std::string flag = "Set-Cookie: " + name + "=" + value + ";" + (HTTPonly ? "Secure; HttpOnly;" : "") + (expiry.size() != 0 ? expiry : "");
    addFlag(flag);
}
void HTTPHeader::addFlag(const std::string &flag)
{
    flags.push_back(flag);
}
void HTTPHeader::print() {
    std::cout << contentType << "\n";
    for (const auto &i : flags)
        std::cout << i << "\n";
    std::cout << "\r\n\r\n";
}
std::ostream &HTTPHeader::operator<<(std::ostream &os)
{
    print();
    return os;
}
} // namespace WCP