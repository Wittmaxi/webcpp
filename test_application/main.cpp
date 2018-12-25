#include "../src/header/webcpp.hpp"
#include "navbar.hpp"
#include "header.hpp"
#include <fstream>

using namespace WCP;

Container projectContent {ClassAttribute {"content-box col-sm-9 bg-dark"},
Container {ClassAttribute {"border border-success rounded"},
    H1 {ClassAttribute {"text-light"},
        Centered {
            "WEBCPP - Webdev in C++. Yep, it's possible!"
        }
    }
},
HorizontalLine(),
Container {ClassAttribute {"row"},
    Container {ClassAttribute {"card col-xl-3 col-sm-6"},
        Image {ClassAttribute {"card-img-top"}, SourceAttribute {"../media/libcode.png"}},
        Container {ClassAttribute {"card-body"},
            H3 {"WEBCPP!"},
            Paragraph {"The WEBCPP Library! The entire code, the real deal!"},
            HyperLink {HyperReference {"https://github.com/Wittmaxi/webcpp"}, ClassAttribute {"btn btn-primary"},
                Text {
                    "Go Go Go!"
                }            
            }
        }
    },
    Container {ClassAttribute {"card col-xl-3 col-sm-6"},
        Image {ClassAttribute {"card-img-top"}, SourceAttribute {"../media/websitecode.png"}},
        Container {ClassAttribute {"card-body"},
            H3 {"This Website's Source Code!"},
            Paragraph {"Look at the Source Code of this webpage. Completely written in C++ obviously!"},
            HyperLink {HyperReference {"https://github.com/Wittmaxi/webcpp/tree/master/test_application"}, ClassAttribute {"btn btn-primary"},
                Text {
                    "Go Go Go!"
                }            
            }
        }
    },
    Container {ClassAttribute {"card col-xl-3 col-sm-6"},
        Image {ClassAttribute {"card-img-top"}, SourceAttribute {"../media/doc.png"}},
        Container {ClassAttribute {"card-body"},
            H3 {"WEBCPP Documentation!"},
            Paragraph {"Look at the Source Code of this webpage. Completely written in C++ obviously!"},
            HyperLink {HyperReference {"https://github.com/Wittmaxi/webcpp/blob/master/README.md"}, ClassAttribute {"btn btn-warning"},
                Text {
                    "Go Go Go!"
                }            
            }
        }
    },
    Container {ClassAttribute {"card col-xl-3 col-sm-6"},
        Image {ClassAttribute {"card-img-top"}, SourceAttribute {"../media/testpage.png"}},
        Container {ClassAttribute {"card-body"},
            H3 {"Testing AREA!"},
            Paragraph {"This is where I test out things without compromising the main page!"},
            HyperLink {HyperReference {"user_input_test.cgi"}, ClassAttribute {"btn btn-danger"},
                Text {
                    "Go Go Go!"
                }            
            }
        }
    }
}
};

int main()
{
ENV::initializeENV();
HTTPHeader myHeader;
myHeader.addCookie("username", "Klimi", false, "");

Document myDocument{
projectHeader,
Body {
    projectNavBar, 
    projectContent
}
};

myHeader.print();
std::cout << myDocument;
}