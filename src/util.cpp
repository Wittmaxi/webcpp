#include "header/util.hpp"
#include <algorithm>
#include <regex>

namespace WCP {
Text::Text (const std::string &arg) : containedText(arg)
{
    containedText = std::regex_replace(containedText, std::regex("&"), "&amp;");
    containedText = std::regex_replace(containedText, std::regex(">"), "&gt;");
    containedText = std::regex_replace(containedText, std::regex("<"), "&lt;");
}
Text::Text (const char *arg) : Text(std::string(arg)) {}
Text::Text(){}
void Text::outputOpening() const {
    std::cout << containedText;
}
void Text::outputClosing() const {}

UnformattedText::UnformattedText (const std::string &arg) : containedText(arg)
{
}
UnformattedText::UnformattedText (const char *arg) : UnformattedText(std::string(arg)) {}
UnformattedText::UnformattedText(){}
void UnformattedText::outputOpening() const {
    std::cout << containedText;
}
void UnformattedText::outputClosing() const {}

ConvenientText::ConvenientText (const std::string &arg) : containedText(arg)
{
    containedText = std::regex_replace(containedText, std::regex("&"), "&amp;");
    containedText = std::regex_replace(containedText, std::regex(">"), "&gt;");
    containedText = std::regex_replace(containedText, std::regex("<"), "&lt;");
    containedText = std::regex_replace(containedText, std::regex("\n"), "<br>");
    containedText = std::regex_replace(containedText, std::regex("\t"), "<span style = 'padding-right: 30px !important;'></span>");
}
ConvenientText::ConvenientText (const char *arg) : ConvenientText(std::string(arg)) {}
ConvenientText::ConvenientText(){}
void ConvenientText::outputOpening() const {
    std::cout << containedText;
}
void ConvenientText::outputClosing() const {}
}