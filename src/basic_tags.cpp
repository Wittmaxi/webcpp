#include "header/base_traits.hpp"
#include "header/basic_tags.hpp"

#include <iostream>

std::ostream &operator<<(std::ostream &os, WCP::Block &other)
{
    other.outputOpening();
    for (auto i : other.containedBlocks)
        os << (*i);
    other.outputClosing();
}

std::ostream &operator<<(std::ostream& os, WCP::NamedAttribute& a) {
    std::cout << " ";
    a.printAttribute(); 
    return os;
}

std::ostream &operator<<(std::ostream &os, std::vector<std::shared_ptr <WCP::NamedAttribute>> &other)
{
    for (const auto &i : other) {
        std::cout << (*i);
    }
    return os;
}

namespace WCP
{
void Document::outputOpening()
{
    std::cout << "Content-type:text/html\r\n\r\n";
    std::cout << "<!DOCTYPE html>";
    std::cout << "<html" << attributes << ">";
}
void Document::outputClosing()
{
    std::cout << "</html>";
}
} // namespace WCP