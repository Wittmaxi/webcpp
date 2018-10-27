#include "header/util.hpp"
#include <algorithm>
#include <regex>

namespace WCP {
Text::Text (std::string arg) {
    containedText = arg;
    containedText = std::regex_replace(containedText, std::regex("&"), "&amp;");
    containedText = std::regex_replace(containedText, std::regex(">"), "&gt;");
    containedText = std::regex_replace(containedText, std::regex("<"), "&lt;");
}
Text::Text (const char *arg) : Text(std::string(arg)) {}
Text::Text(){}
void Text::outputOpening() {
    std::cout << containedText;
}
void Text::outputClosing() {}
}