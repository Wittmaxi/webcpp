#include "header/util.hpp"
#include <algorithm>
#include <regex>

namespace WCP {
Text::Text (std::string arg) {
    containedText = arg;
}
Text::Text (const char *arg) {
    containedText = std::string(arg);
    containedText = std::regex_replace(containedText, std::regex(">"), "&gt;");
    containedText = std::regex_replace(containedText, std::regex("<"), "&lt;");
    containedText = std::regex_replace(containedText, std::regex("&"), "&amp;");
}
Text::Text(){}
void Text::outputOpening() {
    std::cout << containedText;
}
void Text::outputClosing() {}
}