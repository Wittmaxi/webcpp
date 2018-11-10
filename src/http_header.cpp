#include "header/http_header.hpp"

namespace WCP
{
void HTTPHeader::setContentType(std::string ct)
{
    contentType = ct;
}
void HTTPHeader::addCookie(std::string name, std::string value, bool HTTPonly, std::string expiry)
{
    std::string flag = "Set-Cookie: " + name + "=" + value + ";" + (HTTPonly ? "Secure; HttpOnly;" : "") + (expiry.size() != 0 ? expiry : "");
    addFlag(flag);
}
void HTTPHeader::addFlag(std::string flag)
{
    flags.push_back(flag);
}
std::ostream &HTTPHeader::operator<<(std::ostream &os)
{
    os << contentType << "\n";
    for (const auto &i : flags)
        os << i << "\n";
    os << "\r\n\r\n";
    return os;
}
} // namespace WCP