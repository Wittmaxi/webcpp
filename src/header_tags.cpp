#include "header/basic_tags.hpp"

namespace WCP
{
void Head::outputOpening()
{
    std::cout << "<head> ";
}
void Head::outputClosing()
{
    std::cout << "</head>";
}

Title::Title() {}
Title::Title(WCP::Text arg)
{
    unpacker(arg);
}
void Title::outputOpening()
{
    std::cout << "<title>";
}
void Title::outputClosing()
{
    std::cout << "</title>";
}

Include::Include(std::string _href, std::string _type, std::string _rel)
{
    rel = _rel;
    type = _type;
    href = _href;
}
Include::Include() {}
void Include::outputOpening()
{
    std::cout << "<link rel='" + rel + "' type='" + type + "' href='" + href + "'>";
}
void Include::outputClosing() {}

IncludeScript::IncludeScript(std::string _href)
{
    href = _href;
}
IncludeScript::IncludeScript() {}
void IncludeScript::outputOpening()
{
    std::cout << "<script src='" + href + "'>";
}
void IncludeScript::outputClosing() {
    std::cout << "</script>";
}


HttpEquiv::HttpEquiv() {}
HttpEquiv::HttpEquiv(std::string _equiv, std::string _content)
{
    equiv = _equiv;
    content = _content;
}
void HttpEquiv::outputOpening()
{
    std::cout << "<meta http-equiv='" + equiv + "' content='" + content + "'>";
}
void HttpEquiv::outputClosing() {}

Charset::Charset() {}
Charset::Charset(std::string _charset)
{
    charset = _charset;
}
void Charset::outputOpening()
{
    std::cout << "<meta charset='" + charset + "'> ";
}
void Charset::outputClosing() {}

Meta::Meta() {}
Meta::Meta(std::string _name, std::string _content)
{
    name = _name;
    content = _content;
}
void Meta::outputOpening()
{
    std::cout << "<meta name='" + name + "' content='" + content + "'>";
}
void Meta::outputClosing() {}

} // namespace WCP