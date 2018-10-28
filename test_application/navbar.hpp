#pragma once
#include <string>
#include "../src/header/webcpp.hpp"

using namespace WCP;


NavBar projectNavBar {
    ClassAttribute {"navbar navbar-expand-lg navbar-dark my_navbar"},
    HyperLink {HyperReference{"main.cgi"}, Container {ClassAttribute {"navbar-brand"}, Text{"WEBCPP"}}},
    HyperLink {HyperReference{"https://www.github.com/wittmaxi/webcpp"}, Container {ClassAttribute {"nav-link"}, Text{"Our Repository"}}},
    Container {ClassAttribute{"container"}}
};