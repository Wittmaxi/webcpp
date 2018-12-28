#include "header/http_header.hpp"
#include "header/output.hpp"
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
void HTTPHeader::print() const {
    bool printed = true;
    for (const auto &i : flags)
        wcpout << i << "\n";
    wcpout << contentType;
    wcpout << "\r\n\r\n";
}

} // namespace WCP