#ifndef OUTPUT_HPP
#define OUTPUT_HPP

#include <ostream>
#include <iostream>
#include <string>
#include <vector>
#include <memory>

namespace WCP {
enum class outputType {
    STDOUT,
    SOCKET,
    FILE
};

struct wcpout_t {
    outputType type = outputType::STDOUT;
};

extern wcpout_t wcpout;

class Block;
class NamedAttribute;

wcpout_t &operator<<(wcpout_t& os, const Block &);
wcpout_t &operator<< (wcpout_t& os, const std::string& in);
wcpout_t &operator<<(wcpout_t& os, const std::vector<std::shared_ptr<NamedAttribute>> &);

}

#endif 