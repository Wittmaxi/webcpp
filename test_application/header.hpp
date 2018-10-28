#pragma once
#include <string>
#include "../src/header/webcpp.hpp"

using namespace WCP;

Head projectHeader {
    Title {"My Page"},
    Charset{"utf-8"},
    Include {"https://stackpath.bootstrapcdn.com/bootstrap/4.1.3/css/bootstrap.min.css", "text/css", "stylesheet"},
    IncludeScript {"https://code.jquery.com/jquery-3.3.1.slim.min.js"},
    IncludeScript {"https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.3/umd/popper.min.js"},
    IncludeScript {"https://stackpath.bootstrapcdn.com/bootstrap/4.1.3/js/bootstrap.min.js"},
    Include {"../style.css", "text/css", "stylesheet"},
    Meta {"viewport", "width=device-width, initial-scale=1.0"},
    Function {
        [] () {
            if (ENV::GET ("Username") != "" || ENV::GET("Content") != "")
                std::cout << HttpEquiv {"refresh", "0; user_input_test.cgi"};
        }
    }
};