#include "header/basic_tags.hpp"

namespace WCP
{
void Head::outputOpening() const
{
    std::cout << "<head> ";
}
void Head::outputClosing() const
{
    std::cout << "</head>";
}

Title::Title() {}
Title::Title(WCP::Text arg)
{
    unpacker(arg);
}
void Title::outputOpening() const
{
    std::cout << "<title>";
}
void Title::outputClosing() const
{
    std::cout << "</title>";
}

Include::Include(const std::string &href_, const std::string &type_, const std::string &rel_) :  type (type_), href(href_), rel (rel_) 
{
}
Include::Include() {}
void Include::outputOpening() const
{
    std::cout << "<link rel='" + rel + "' type='" + type + "' href='" + href + "'>";
}
void Include::outputClosing() const {}

IncludeScript::IncludeScript(const std::string &href_) : href(href_)
{
}
IncludeScript::IncludeScript() {}
void IncludeScript::outputOpening() const
{
    std::cout << "<script src='" + href + "'>";
}
void IncludeScript::outputClosing() const {
    std::cout << "</script>";
}


HttpEquiv::HttpEquiv() {}
HttpEquiv::HttpEquiv(const std::string &equiv_, const std::string &content_) : equiv (equiv_), content(content_)
{
}
void HttpEquiv::outputOpening() const
{
    std::cout << "<meta http-equiv='" + equiv + "' content='" + content + "'>";
}
void HttpEquiv::outputClosing() const {}

Charset::Charset() {}
Charset::Charset(const std::string &charset_) : charset (charset_)
{
}
void Charset::outputOpening() const
{
    std::cout << "<meta charset='" + charset + "'> ";
}
void Charset::outputClosing() const {}

Meta::Meta() {}
Meta::Meta(const std::string &name_, const std::string &content_) : name (name_), content(content_)
{
}
void Meta::outputOpening() const
{
    std::cout << "<meta name='" + name + "' content='" + content + "'>";
}
void Meta::outputClosing() const {}

} // namespace WCP