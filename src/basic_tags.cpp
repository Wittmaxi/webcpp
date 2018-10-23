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

namespace WCP
{
void Document::outputOpening()
{
    std::cout << "Content-type:text/html\r\n\r\n";
    std::cout << "<!DOCTYPE html>";
    std::cout << "<html>";
}
void Document::outputClosing()
{
    std::cout << "</html>";
}



} // namespace WCP