#include "header/body_tags.hpp"

namespace WCP
{
Body::Body() {}
void Body::outputOpening()
{
    std::cout << "<body>";
}
void Body::outputClosing()
{
    std::cout << "</body>";
}

H1::H1() {}
void H1::outputOpening()
{
    std::cout << "<h1>";
}
void H1::outputClosing()
{
    std::cout << "</h1>";
}

H2::H2() {}
void H2::outputOpening()
{
    std::cout << "<h2>";
}
void H2::outputClosing()
{
    std::cout << "</h2>";
}

H3::H3() {}
void H3::outputOpening()
{
    std::cout << "<h3>";
}
void H3::outputClosing()
{
    std::cout << "</h3>";
}

H4::H4() {}
void H4::outputOpening()
{
    std::cout << "<h4>";
}
void H4::outputClosing()
{
    std::cout << "</h4>";
}

H5::H5() {}
void H5::outputOpening()
{
    std::cout << "<h5>";
}
void H5::outputClosing()
{
    std::cout << "</h5>";
}

H6::H6() {}
void H6::outputOpening()
{
    std::cout << "<h6>";
}
void H6::outputClosing()
{
    std::cout << "</h6>";
}

Break::Break() {}
void Break::outputOpening() {
    std::cout << "<br>";
}
void Break::outputClosing() {}

} // namespace WCP