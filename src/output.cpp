#include "header/output.hpp"
#include "webcpp.hpp"

namespace WCP {
wcpout_t wcpout;


wcpout_t &operator<<(wcpout_t &os, const Block &other) //other NEEDS to be const because else you cannot pass it as rvalue to cout. 
{
    other.outputOpening();
    for (const auto i : other.containedBlocks)
        os << (*i);
    other.outputClosing();
    return os;
}


wcpout_t &operator<<(wcpout_t& os, NamedAttribute& a) {
    wcpout << " ";
    a.printAttribute(); 
    return os;
}

wcpout_t &operator<<(wcpout_t &os, const std::vector<std::shared_ptr <NamedAttribute>> &other)
{
    for (const auto i : other)
        wcpout << (*i);
    return os;
}


wcpout_t& operator<< (wcpout_t& os, const std::string& in) {
    switch (os.type) {
        case outputType::STDOUT:
            wcpout << in;
            break;
    }
}

}