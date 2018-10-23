#include "header/util.hpp"

namespace WCP {
Text::Text (std::string arg) {
    containedText = arg;
}
Text::Text (const char *arg) {
    containedText = std::string(arg);
}
Text::Text(){}
void Text::outputOpening() {
    std::cout << containedText;
}
void Text::outputClosing() {}
}