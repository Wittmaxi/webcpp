#include "header/attributes.hpp"

namespace WCP {
ClassAttribute::ClassAttribute() {}
ClassAttribute::ClassAttribute(std::string cn) {
    name = cn;
}
void ClassAttribute::printAttribute() {
    std::cout << "class='" << name << "'";
}
StyleAttribute::StyleAttribute() {}
StyleAttribute::StyleAttribute(std::string cn) {
    name = cn;
}
void StyleAttribute::printAttribute() {
    std::cout << "style='" << name << "'";
}
}