#include "header/body_tags.hpp"

namespace WCP
{
Body::Body() {}
void Body::outputOpening()
{
    std::cout << "<body" << attributes << ">";
}
void Body::outputClosing()
{
    std::cout << "</body>";
}

H1::H1() {}
void H1::outputOpening()
{
    std::cout << "<h1" << attributes << ">";
}
void H1::outputClosing()
{
    std::cout << "</h1>";
}

H2::H2() {}
void H2::outputOpening()
{
    std::cout << "<h2" << attributes << ">";
}
void H2::outputClosing()
{
    std::cout << "</h2>";
}

H3::H3() {}
void H3::outputOpening()
{
    std::cout << "<h3" << attributes << ">";
}
void H3::outputClosing()
{
    std::cout << "</h3>";
}

H4::H4() {}
void H4::outputOpening()
{
    std::cout << "<h4" << attributes << ">";
}
void H4::outputClosing()
{
    std::cout << "</h4>";
}

H5::H5() {}
void H5::outputOpening()
{
    std::cout << "<h5" << attributes << ">";
}
void H5::outputClosing()
{
    std::cout << "</h5>";
}

H6::H6() {}
void H6::outputOpening()
{
    std::cout << "<h6" << attributes << ">";
}
void H6::outputClosing()
{
    std::cout << "</h6>";
}

LineBreak::LineBreak() {}
void LineBreak::outputOpening()
{
    std::cout << "<br>";
}
void LineBreak::outputClosing() {}
LineBreak Break{};

Centered::Centered() {}
void Centered::outputOpening() {
    std::cout << "<center" << attributes << ">";
}
void Centered::outputClosing() {
    std::cout << "</center>";
}

} // namespace WCP