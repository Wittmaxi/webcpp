#include "header/body_tags.hpp"

namespace WCP
{
Body::Body() {}
Body::Body(const char* text) {
    unpacker (Text(std::string (text)));
}
void Body::outputOpening()
{
    std::cout << "<body" << attributes << ">";
}
void Body::outputClosing()
{
    std::cout << "</body>";
}

H1::H1() {}
H1::H1(const char* text) {
    unpacker (Text(std::string (text)));
}
void H1::outputOpening()
{
    std::cout << "<h1" << attributes << ">";
}
void H1::outputClosing()
{
    std::cout << "</h1>";
}

H2::H2() {}
H2::H2(const char* text) {
    unpacker (Text(std::string (text)));
}
void H2::outputOpening()
{
    std::cout << "<h2" << attributes << ">";
}
void H2::outputClosing()
{
    std::cout << "</h2>";
}

H3::H3() {}
H3::H3(const char* text) {
    unpacker (Text(std::string (text)));
}
void H3::outputOpening()
{
    std::cout << "<h3" << attributes << ">";
}
void H3::outputClosing()
{
    std::cout << "</h3>";
}

H4::H4() {}
H4::H4(const char* text) {
    unpacker (Text(std::string (text)));
}
void H4::outputOpening()
{
    std::cout << "<h4" << attributes << ">";
}
void H4::outputClosing()
{
    std::cout << "</h4>";
}

H5::H5() {}
H5::H5(const char* text) {
    unpacker (Text(std::string (text)));
}
void H5::outputOpening()
{
    std::cout << "<h5" << attributes << ">";
}
void H5::outputClosing()
{
    std::cout << "</h5>";
}

H6::H6() {}
H6::H6(const char* text) {
    unpacker (Text(std::string (text)));
}
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
Centered::Centered(const char* text) {
    unpacker (Text(std::string (text)));
}
void Centered::outputOpening() {
    std::cout << "<center" << attributes << ">";
}
void Centered::outputClosing() {
    std::cout << "</center>";
}

Table::Table() {}
Table::Table(const char* text) {
    unpacker (Text(std::string (text)));
}
void Table::outputOpening() {
    std::cout << "<table" << attributes << ">";
}
void Table::outputClosing() {
    std::cout << "</table>";
}

Row::Row() {}
Row::Row(const char* text) {
    unpacker (Text(std::string (text)));
}
void Row::outputOpening() {
    std::cout << "<tr" << attributes << ">";
}
void Row::outputClosing() {
    std::cout << "</tr>";
}

Cell::Cell() {}
Cell::Cell(const char* text) {
    unpacker (Text(std::string (text)));
}
void Cell::outputOpening() {
    std::cout << "<td" << attributes << ">";
}
void Cell::outputClosing() {
    std::cout << "</td>";
}

HighlightedCell::HighlightedCell() {}
HighlightedCell::HighlightedCell(const char* text) {
    unpacker (Text(std::string (text)));
}
void HighlightedCell::outputOpening() {
    std::cout << "<th" << attributes << ">";
}
void HighlightedCell::outputClosing() {
    std::cout << "</th>";
}

Container::Container() {}
Container::Container(const char* text) {
    unpacker (Text(std::string (text)));
}
void Container::outputOpening() {
    std::cout << "<div" << attributes << ">";
}
void Container::outputClosing() {
    std::cout << "</div>";
}

NavBar::NavBar() {}
NavBar::NavBar(const char* text) {
    unpacker (Text(std::string (text)));
}
void NavBar::outputOpening() {
    std::cout << "<nav" << attributes << ">";
}
void NavBar::outputClosing() {
    std::cout << "</nav>";
}

HyperLink::HyperLink() {}
void HyperLink::outputOpening() {
    std::cout << "<a" << attributes << ">";
}
void HyperLink::outputClosing() {
    std::cout << "</a>";
}

Marked::Marked() {}
void Marked::outputOpening() {
    std::cout << "<mark" << attributes << ">";
}
void Marked::outputClosing() {
    std::cout << "</mark>";
}

Form::Form() {}
void Form::outputOpening() {
    std::cout << "<form" << attributes << ">";
}
void Form::outputClosing() {
    std::cout << "</form>";
}

Input::Input() {}
void Input::outputOpening() {
    std::cout << "<input" << attributes << ">";
}
void Input::outputClosing() {
    std::cout << "</input>";
}


} // namespace WCP