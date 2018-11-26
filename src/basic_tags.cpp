#include "header/output.hpp"
#include "header/base_traits.hpp"
#include "header/basic_tags.hpp"
#include <iostream>

namespace WCP
{
void Document::outputOpening() const
{   
    wcpout << "Content-type:text/html";
    wcpout << "<!DOCTYPE HTML>\n";
    wcpout << "<html" << attributes << ">";
}
void Document::outputClosing() const
{
    wcpout << "</html>";
}
} // namespace WCP