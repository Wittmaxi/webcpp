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
    Body {
        Text {"Hello World überstunden"},
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
        H6 {
            Text {"H6 - Hello World"}
        },
        Function {
            []() {
                std::fstream a {"../README.md", std::ios::in};
                while (! a.eof()) {
                    std::string b;
                    a >> b;
                    std::cout << b;
                }
            }
        }        
    }
};
}