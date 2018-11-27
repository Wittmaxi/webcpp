#include "header/basic_tags.hpp"
#include "header/output.hpp"


namespace WCP
{
void Head::outputOpening() const
{
    wcpout << "<head> ";
}
void Head::outputClosing() const
{
    wcpout << "</head>";
}

Title::Title() {}
Title::Title(WCP::Text arg)
{
    unpacker(arg);
}
void Title::outputOpening() const
{
    wcpout << "<title>";
}
void Title::outputClosing() const
{
    wcpout << "</title>";
}

Include::Include(const std::string &href_, const std::string &type_, const std::string &rel_) :  type (type_), href(href_), rel (rel_) 
{
}
Include::Include() {}
void Include::outputOpening() const
{
    wcpout << "<link rel='" + rel + "' type='" + type + "' href='" + href + "'>";
}
void Include::outputClosing() const {}

IncludeScript::IncludeScript(const std::string &href_) : href(href_)
{
}
IncludeScript::IncludeScript() {}
void IncludeScript::outputOpening() const
{
    wcpout << "<script src='" + href + "'>";
}
void IncludeScript::outputClosing() const {
    wcpout << "</script>";
}


HttpEquiv::HttpEquiv() {}
HttpEquiv::HttpEquiv(const std::string &equiv_, const std::string &content_) : equiv (equiv_), content(content_)
{
}
void HttpEquiv::outputOpening() const
{
    wcpout << "<meta http-equiv='" + equiv + "' content='" + content + "'>";
}
void HttpEquiv::outputClosing() const {}

Charset::Charset() {}
Charset::Charset(const std::string &charset_) : charset (charset_)
{
}
void Charset::outputOpening() const
{
    wcpout << "<meta charset='" + charset + "'> ";
}
void Charset::outputClosing() const {}

Meta::Meta() {}
Meta::Meta(const std::string &name_, const std::string &content_) : name (name_), content(content_)
{
}
void Meta::outputOpening() const
{
    wcpout << "<meta name='" + name + "' content='" + content + "'>";
}
void Meta::outputClosing() const {}

} // namespace WCP