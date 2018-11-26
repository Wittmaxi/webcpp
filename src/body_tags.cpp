#include "header/body_tags.hpp"
#include "header/output.hpp"


namespace WCP
{
Body::Body() {}
Body::Body(const char* text) {
    unpacker (Text(std::string (text)));
}
void Body::outputOpening() const
{
    wcpout << "<body" << attributes << ">";
}
void Body::outputClosing() const
{
    wcpout << "</body>";
}

H1::H1() {}
H1::H1(const char* text) {
    unpacker (Text(std::string (text)));
}
void H1::outputOpening() const
{
    wcpout << "<h1" << attributes << ">";
}
void H1::outputClosing() const
{
    wcpout << "</h1>";
}

H2::H2() {}
H2::H2(const char* text) {
    unpacker (Text(std::string (text)));
}
void H2::outputOpening() const
{
    wcpout << "<h2" << attributes << ">";
}
void H2::outputClosing() const
{
    wcpout << "</h2>";
}

H3::H3() {}
H3::H3(const char* text) {
    unpacker (Text(std::string (text)));
}
void H3::outputOpening() const
{
    wcpout << "<h3" << attributes << ">";
}
void H3::outputClosing() const
{
    wcpout << "</h3>";
}

H4::H4() {}
H4::H4(const char* text) {
    unpacker (Text(std::string (text)));
}
void H4::outputOpening() const
{
    wcpout << "<h4" << attributes << ">";
}
void H4::outputClosing() const
{
    wcpout << "</h4>";
}

H5::H5() {}
H5::H5(const char* text) {
    unpacker (Text(std::string (text)));
}
void H5::outputOpening() const
{
    wcpout << "<h5" << attributes << ">";
}
void H5::outputClosing() const
{
    wcpout << "</h5>";
}

H6::H6() {}
H6::H6(const char* text) {
    unpacker (Text(std::string (text)));
}
void H6::outputOpening() const
{
    wcpout << "<h6" << attributes << ">";
}
void H6::outputClosing() const
{
    wcpout << "</h6>";
}

LineBreak::LineBreak() {}
void LineBreak::outputOpening() const
{
    wcpout << "<br>";
}
void LineBreak::outputClosing() const {}
LineBreak Break{};

Centered::Centered() {}
Centered::Centered(const char* text) {
    unpacker (Text(std::string (text)));
}
void Centered::outputOpening() const {
    wcpout << "<center" << attributes << ">";
}
void Centered::outputClosing() const {
    wcpout << "</center>";
}

Table::Table() {}
Table::Table(const char* text) {
    unpacker (Text(std::string (text)));
}
void Table::outputOpening() const {
    wcpout << "<table" << attributes << ">";
}
void Table::outputClosing() const {
    wcpout << "</table>";
}

Row::Row() {}
Row::Row(const char* text) {
    unpacker (Text(std::string (text)));
}
void Row::outputOpening() const {
    wcpout << "<tr" << attributes << ">";
}
void Row::outputClosing() const {
    wcpout << "</tr>";
}

Cell::Cell() {}
Cell::Cell(const char* text) {
    unpacker (Text(std::string (text)));
}
void Cell::outputOpening() const {
    wcpout << "<td" << attributes << ">";
}
void Cell::outputClosing() const {
    wcpout << "</td>";
}

HighlightedCell::HighlightedCell() {}
HighlightedCell::HighlightedCell(const char* text) {
    unpacker (Text(std::string (text)));
}
void HighlightedCell::outputOpening() const {
    wcpout << "<th" << attributes << ">";
}
void HighlightedCell::outputClosing() const {
    wcpout << "</th>";
}

Container::Container() {}
Container::Container(const char* text) {
    unpacker (Text(std::string (text)));
}
void Container::outputOpening() const {
    wcpout << "<div" << attributes << ">";
}
void Container::outputClosing() const {
    wcpout << "</div>";
}

NavBar::NavBar() {}
NavBar::NavBar(const char* text) {
    unpacker (Text(std::string (text)));
}
void NavBar::outputOpening() const {
    wcpout << "<nav" << attributes << ">";
}
void NavBar::outputClosing() const {
    wcpout << "</nav>";
}

HyperLink::HyperLink() {}
HyperLink::HyperLink(const char* text) : HyperLink (Text (text)) {}
void HyperLink::outputOpening() const {
    wcpout << "<a" << attributes << ">";
}
void HyperLink::outputClosing() const {
    wcpout << "</a>";
}

Marked::Marked() {}
Marked::Marked(const char* text) : Marked (Text (text)) {}
void Marked::outputOpening() const {
    wcpout << "<mark" << attributes << ">";
}
void Marked::outputClosing() const {
    wcpout << "</mark>";
}

Form::Form() {}
Form::Form(const char* text) : Form (Text (text)) {}
void Form::outputOpening() const {
    wcpout << "<form" << attributes << ">";
}
void Form::outputClosing() const {
    wcpout << "</form>";
}

Input::Input() {}
void Input::outputOpening() const {
    wcpout << "<input" << attributes << ">";
}
void Input::outputClosing() const {
}

Paragraph::Paragraph() {}
Paragraph::Paragraph(const char* text) : Paragraph (Text (text)) {}
void Paragraph::outputOpening() const {
    wcpout << "<p" << attributes << ">";
}
void Paragraph::outputClosing() const {
    wcpout << "</p>";
}

Image::Image() {}
void Image::outputOpening() const {
    wcpout << "<img" << attributes << ">";
}
void Image::outputClosing() const {
}

Picture::Picture() {}
void Picture::outputOpening() const {
    wcpout << "<picture" << attributes << ">";
}
void Picture::outputClosing() const {
    wcpout << "</picture>";
}

Source::Source() {}
void Source::outputOpening() const {
    wcpout << "<source" << attributes << ">";
}
void Source::outputClosing() const {
}

HorizontalLine::HorizontalLine() {}
void HorizontalLine::outputOpening() const {
    wcpout << "<hr>";
}
void HorizontalLine::outputClosing() const {
}

Quote::Quote() {}
Quote::Quote(const char* text) : Quote (Text (text)) {}
void Quote::outputOpening() const {
    wcpout << "<blockquote" << attributes << ">";
}
void Quote::outputClosing() const {
    wcpout << "</blockquote>";
}

Label::Label() {}
Label::Label(const char* text) : Label (Text (text)) {}
void Label::outputOpening() const {
    wcpout << "<label" << attributes << ">";
}
void Label::outputClosing() const {
    wcpout << "</label>";
}

} // namespace WCP