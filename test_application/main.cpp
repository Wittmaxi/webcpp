#include "../src/header/webcpp.hpp"
#include <fstream>

using namespace WCP;

int main()
{
Document{
    Head{
        Title{"My First Homepage :D"},
        Include {"https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css", "text/css", "stylesheet"},
        HttpEquiv{"refresh", "1000"},
        Charset{"utf-8"}, 
        Meta {"Author", "Maximilian"}
    },
    Body {StyleAttribute {"background-color: #111122; color: white;"},
        Text {"Hello World überstunden"},
        Centered {StyleAttribute{"font-family: \"Comic Sans MS\", \"Comic Sans\", cursive;"},
            H1 {
                Text {"H1 - Hello World"}
            },
            H2 {
                Text {"H2 - Hello World"}
            },
            H3 {
                Text {"H3 - Hello World"}
            },
            H4 {
                Text {"H4 - Hello World"}
            },
            H5 {
                Text {"H5 - Hello World"}
            },
            Break,
            H6 {ClassAttribute {"btn btn-primary"}, StyleAttribute {"min-width: 400px;"},
                Text {"H6 - Hello World"}, 
            },
            Break,
            Function {
                []() {
                    std::fstream a {"../README.md", std::ios::in};
                    while (! a.eof()) {
                        std::string b;
                        a >> b;
                        std::cout << b << " ";
                    }
                }
            }
        }        
    }
};
}