#include "header/base_traits.hpp"
#include "header/basic_tags.hpp"

#include <iostream>

std::ostream &operator<<(std::ostream &os, const WCP::Block &other) //other NEEDS to be const because else you cannot pass it as rvalue to cout. 
{
    WCP::Block* obj_ptr = const_cast <WCP::Block*> (&other); 
    obj_ptr->outputOpening();
    for (auto i : obj_ptr->containedBlocks)
        os << (*i);
    obj_ptr->outputClosing();
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