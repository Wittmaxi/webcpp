#include "header/body_tags.hpp"

namespace WCP
{
Body::Body() {}
Body::Body(const char* text) {
    unpacker (Text(std::string (text)));
}
void Body::outputOpening() const
{
    std::cout << "<body" << attributes << ">";
}
void Body::outputClosing() const
{
    std::cout << "</body>";
}

H1::H1() {}
H1::H1(const char* text) {
    unpacker (Text(std::string (text)));
}
void H1::outputOpening() const
{
    std::cout << "<h1" << attributes << ">";
}
void H1::outputClosing() const
{
    std::cout << "</h1>";
}

H2::H2() {}
H2::H2(const char* text) {
    unpacker (Text(std::string (text)));
}
void H2::outputOpening() const
{
    std::cout << "<h2" << attributes << ">";
}
void H2::outputClosing() const
{
    std::cout << "</h2>";
}

H3::H3() {}
H3::H3(const char* text) {
    unpacker (Text(std::string (text)));
}
void H3::outputOpening() const
{
    std::cout << "<h3" << attributes << ">";
}
void H3::outputClosing() const
{
    std::cout << "</h3>";
}

H4::H4() {}
H4::H4(const char* text) {
    unpacker (Text(std::string (text)));
}
void H4::outputOpening() const
{
    std::cout << "<h4" << attributes << ">";
}
void H4::outputClosing() const
{
    std::cout << "</h4>";
}

H5::H5() {}
H5::H5(const char* text) {
    unpacker (Text(std::string (text)));
}
void H5::outputOpening() const
{
    std::cout << "<h5" << attributes << ">";
}
void H5::outputClosing() const
{
    std::cout << "</h5>";
}

H6::H6() {}
H6::H6(const char* text) {
    unpacker (Text(std::string (text)));
}
void H6::outputOpening() const
{
    std::cout << "<h6" << attributes << ">";
}
void H6::outputClosing() const
{
    std::cout << "</h6>";
}

LineBreak::LineBreak() {}
void LineBreak::outputOpening() const
{
    std::cout << "<br>";
}
void LineBreak::outputClosing() const {}
LineBreak Break{};

Centered::Centered() {}
Centered::Centered(const char* text) {
    unpacker (Text(std::string (text)));
}
void Centered::outputOpening() const {
    std::cout << "<center" << attributes << ">";
}
void Centered::outputClosing() const {
    std::cout << "</center>";
}

Table::Table() {}
Table::Table(const char* text) {
    unpacker (Text(std::string (text)));
}
void Table::outputOpening() const {
    std::cout << "<table" << attributes << ">";
}
void Table::outputClosing() const {
    std::cout << "</table>";
}

Row::Row() {}
Row::Row(const char* text) {
    unpacker (Text(std::string (text)));
}
void Row::outputOpening() const {
    std::cout << "<tr" << attributes << ">";
}
void Row::outputClosing() const {
    std::cout << "</tr>";
}

Cell::Cell() {}
Cell::Cell(const char* text) {
    unpacker (Text(std::string (text)));
}
void Cell::outputOpening() const {
    std::cout << "<td" << attributes << ">";
}
void Cell::outputClosing() const {
    std::cout << "</td>";
}

HighlightedCell::HighlightedCell() {}
HighlightedCell::HighlightedCell(const char* text) {
    unpacker (Text(std::string (text)));
}
void HighlightedCell::outputOpening() const {
    std::cout << "<th" << attributes << ">";
}
void HighlightedCell::outputClosing() const {
    std::cout << "</th>";
}

Container::Container() {}
Container::Container(const char* text) {
    unpacker (Text(std::string (text)));
}
void Container::outputOpening() const {
    std::cout << "<div" << attributes << ">";
}
void Container::outputClosing() const {
    std::cout << "</div>";
}

NavBar::NavBar() {}
NavBar::NavBar(const char* text) {
    unpacker (Text(std::string (text)));
}
void NavBar::outputOpening() const {
    std::cout << "<nav" << attributes << ">";
}
void NavBar::outputClosing() const {
    std::cout << "</nav>";
}

HyperLink::HyperLink() {}
HyperLink::HyperLink(const char* text) : HyperLink (Text (text)) {}
void HyperLink::outputOpening() const {
    std::cout << "<a" << attributes << ">";
}
void HyperLink::outputClosing() const {
    std::cout << "</a>";
}

Marked::Marked() {}
Marked::Marked(const char* text) : Marked (Text (text)) {}
void Marked::outputOpening() const {
    std::cout << "<mark" << attributes << ">";
}
void Marked::outputClosing() const {
    std::cout << "</mark>";
}

Form::Form() {}
Form::Form(const char* text) : Form (Text (text)) {}
void Form::outputOpening() const {
    std::cout << "<form" << attributes << ">";
}
void Form::outputClosing() const {
    std::cout << "</form>";
}

Input::Input() {}
void Input::outputOpening() const {
    std::cout << "<input" << attributes << ">";
}
void Input::outputClosing() const {
}

Paragraph::Paragraph() {}
Paragraph::Paragraph(const char* text) : Paragraph (Text (text)) {}
void Paragraph::outputOpening() const {
    std::cout << "<p" << attributes << ">";
}
void Paragraph::outputClosing() const {
    std::cout << "</p>";
}

Image::Image() {}
void Image::outputOpening() const {
    std::cout << "<img" << attributes << ">";
}
void Image::outputClosing() const {
}

Picture::Picture() {}
void Picture::outputOpening() const {
    std::cout << "<picture" << attributes << ">";
}
void Picture::outputClosing() const {
    std::cout << "</picture>";
}

Source::Source() {}
void Source::outputOpening() const {
    std::cout << "<source" << attributes << ">";
}
void Source::outputClosing() const {
}

HorizontalLine::HorizontalLine() {}
void HorizontalLine::outputOpening() const {
    std::cout << "<hr>";
}
void HorizontalLine::outputClosing() const {
}

Quote::Quote() {}
Quote::Quote(const char* text) : Quote (Text (text)) {}
void Quote::outputOpening() const {
    std::cout << "<blockquote" << attributes << ">";
}
void Quote::outputClosing() const {
    std::cout << "</blockquote>";
}

Label::Label() {}
Label::Label(const char* text) : Label (Text (text)) {}
void Label::outputOpening() const {
    std::cout << "<label" << attributes << ">";
}
void Label::outputClosing() const {
    std::cout << "</label>";
}

} // namespace WCP