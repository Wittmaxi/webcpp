#pragma once
#include <string>
#include "../src/header/webcpp.hpp"

using namespace WCP;


NavBar projectNavBar {
    ClassAttribute {"navbar navbar-expand-lg navbar-dark my_navbar"},
    HyperLink {HyperReference{"main.cgi"}, Container {ClassAttribute {"navbar-brand"}, Text{"WEBCPP"}}},
    HyperLink {HyperReference{"https://www.github.com/wittmaxi/webcpp"}, Container {ClassAttribute {"nav-link"}, Text{"Our Repository"}}},
    Container {ClassAttribute{"container"}},
    Function {
        [] () {
            std::cout << ENV::COOKIE("username") << "<br>";
            if (ENV::COOKIE ("username") == "") {
                std::cout << Form {
                    HyperLink {HyperReference{"login.cgi"}, ClassAttribute {"nav-link btn btn-primary"}, 
                        Text{"Login or Register"}
                    }
                };
            } 
        }
    }
};