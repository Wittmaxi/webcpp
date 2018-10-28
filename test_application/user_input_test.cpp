#include "../src/header/webcpp.hpp"
#include "navbar.hpp"
#include "header.hpp"
#include <fstream>

using namespace WCP;


Container projectContent {ClassAttribute {"content-box col-sm-9 bg-dark text-light"},
    Container  {ClassAttribute{"form-group"},
        Form { FormMethod {"GET"},
            Container {ConvenientText {"Please Leave a comment about our Website!"}},
            Input {InputType {"input"}, InputName {"Comment"}, ClassAttribute{"form-control"}},
            Container {ConvenientText {"Please enter your Username!"}},
            Input {InputType{"input"}, InputName {"Username"}, ClassAttribute{"form-control"}},
            Input {InputType{"submit"}, ClassAttribute{"form-control"}}
        }
    },
    H1 {
        "Users said so far:"
    },
    H5 {
        Function {
            [] () {
                std::ifstream file ("user_comments.txt");
                std::vector<std::string> vec;
                std::string temp;
                while (file.good()) {
                    std::getline (file, temp);
                    vec.push_back(temp);
                }
                for (auto i = vec.rbegin(); i != vec.rend(); i++)
                    std::cout << ConvenientText {*i} << HorizontalLine {};
            }
        }
    }
};

int main()
{
ENV::initializeENV();

Document myDocument{
projectHeader,
Body {
    projectNavBar, 
    projectContent
}
};


std::ofstream file2 ("user_comments.txt", std::ios::app);
std::string un = ENV::GET ("Username");
std::string c = ENV::GET ("Comment");

if (c != "") {
    un = un.substr(0, 100);
    c = c.substr(0, 300);
    file2 << un << " : " << c << "\n" << std::flush;
} 

std::cout << myDocument;
}