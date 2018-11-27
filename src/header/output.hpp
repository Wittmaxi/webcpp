#ifndef OUTPUT_HPP
#define OUTPUT_HPP

#include <ostream>
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <fstream>

namespace WCP {
enum class outputType {
    STDOUT,
    SOCKET,
    FILE
};

struct wcpout_t {
    outputType type = outputType::STDOUT;
    std::fstream outputFile;

    void outputToFile(const std::string &fileName);
    void outputToSTDOUT();
};

extern wcpout_t wcpout;

class Block;
class NamedAttribute;

wcpout_t &operator<<(wcpout_t& os, const Block &);
std::ostream &operator<<(std::ostream& os, const Block &);
wcpout_t &operator<< (wcpout_t& os, const std::string& in);
wcpout_t &operator<<(wcpout_t& os, const std::vector<std::shared_ptr<NamedAttribute>> &);

}

#endif 