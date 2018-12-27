#include "header/output.hpp"
#include "header/webcpp.hpp"

namespace WCP
{
wcpout_t wcpout;

void wcpout_t::outputToFile(const std::string &fileName)
{
    std::fstream outputFile(fileName);
    outputFile << stored;
    outputted = true;
}
void wcpout_t::outputToSTDOUT()
{
    std::cout << stored;
    outputted = true;
}
std::string wcpout_t::getString()
{
    outputted = true;
    return stored;
}
wcpout_t::~wcpout_t () {
    if (!outputted)
        std::cout << stored;
}

wcpout_t &operator<<(wcpout_t &os, const Block &other)
{
    other.outputOpening();
    for (const auto i : other.containedBlocks)
        os << (*i);
    other.outputClosing();
    return os;
}

std::ostream &operator<<(std::ostream &os, const Block &other)
{
    other.outputOpening();
    for (const auto i : other.containedBlocks)
        wcpout << (*i);
    other.outputClosing();
    return os;
}

wcpout_t &operator<<(wcpout_t &os, NamedAttribute &a)
{
    wcpout << " ";
    a.printAttribute();
    return os;
}

wcpout_t &operator<<(wcpout_t &os, const std::vector<std::shared_ptr<NamedAttribute>> &other)
{
    for (const auto i : other)
    {
        wcpout << " ";
        (*i).printAttribute();
    }
    return os;
}

wcpout_t &operator<<(wcpout_t &os, const std::string &in)
{
    os.stored += in;
    return os;
}

} // namespace WCP
