#pragma once
#include <string>
#include "../src/header/webcpp.hpp"

using namespace WCP;

bool isLoggedIn () {
    return false; //temporary
}

std::string getUserName () {
    return "MAXI"; //temporary
}

void printNavbarLoginState () {
    if (! isLoggedIn ()) {
        Form toPrint { ClassAttribute {"form-inline"},
            Input {
                InputType{"button"}, ClassAttribute{"form-control mr-sm-2 btn btn-success "}, InputValue {"Login"}
            },
            Input {
                InputType{"button"}, ClassAttribute{"form-control mr-sm-2 btn btn-info"}, InputValue {"Register"}
            }
        };
        std::cout << toPrint;
    } else {
        Form toPrint { ClassAttribute {"form-inline"},
            Input {
                InputType{"button"}, ClassAttribute{"form-control mr-sm-2 "}, InputValue {"Welcome, " + getUserName ()}
            } 
        };
        std::cout << toPrint;
    }
}


NavBar projectNavBar {
    ClassAttribute {"navbar navbar-expand-lg navbar-dark my_navbar"},
    HyperLink {HyperReference{"main.cgi"}, Container {ClassAttribute {"navbar-brand"}, Text{"WEBCPP"}}},
    HyperLink {HyperReference{"https://www.github.com/wittmaxi/webcpp"}, Container {ClassAttribute {"nav-link"}, Text{"Our Repository"}}},
    Container {ClassAttribute{"container"}},
    Function {printNavbarLoginState}
};