#include "header/output.hpp"
#include "header/webcpp.hpp"

namespace WCP
{
wcpout_t wcpout;

void wcpout_t::outputToFile(const std::string &fileName)
{
    type = outputType::FILE;
    outputFile = std::fstream (fileName);
    if (!outputFile.good()) {
        std::cerr << "Cannot open file " << fileName << "\n";
    }
}
void wcpout_t::outputToSTDOUT()
{
    type = outputType::STDOUT;
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
    for (const auto i : other) {
        wcpout << " ";
        (*i).printAttribute();
    }
    return os;
}

wcpout_t &operator<<(wcpout_t &os, const std::string &in)
{
    switch (os.type)
    {
    case outputType::STDOUT:
        std::cout << in;
        break;
    case outputType::FILE:
        os.outputFile << in;
        break;
    }
    return os;
}

} // namespace WCP