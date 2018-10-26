#include "../src/header/webcpp.hpp"
#include <fstream>

using namespace WCP;


bool isLoggedIn () {
    return true; //temporary
}

std::string getUserName () {
    return "MAXI"; //temporary
}

void printNavbarLoginState () {
    if (isLoggedIn ()) {
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
    Container {ClassAttribute {"navbar-brand"}, Text{"WEBCPP"}},
    HyperLink {HyperReference{"https://www.github.com/wittmaxi/webcpp"}, Container {ClassAttribute {"nav-link"}, Text{"Our Repository"}}},
    Container {ClassAttribute{"container"}},
    Function {printNavbarLoginState}
};

Head projectHeader {
    Title {"My Page"},
    Charset{"utf-8"},
    Include {"../style.css", "text/css", "stylesheet"},
    Include {"https://stackpath.bootstrapcdn.com/bootstrap/4.1.3/css/bootstrap.min.css", "text/css", "stylesheet"},
    IncludeScript {"https://code.jquery.com/jquery-3.3.1.slim.min.js"},
    IncludeScript {"https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.3/umd/popper.min.js"},
    IncludeScript {"https://stackpath.bootstrapcdn.com/bootstrap/4.1.3/js/bootstrap.min.js"}
};

int main()
{
Document{
projectHeader,
Body {
    projectNavBar
}
};
}