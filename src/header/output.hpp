#ifndef OUTPUT_HPP
#define OUTPUT_HPP

#include <ostream>
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <fstream>

namespace WCP {

struct wcpout_t {
    bool outputted;
    std::string stored; 

    void outputToFile(const std::string &fileName);
    void outputToSTDOUT();
    std::string getString();
    ~wcpout_t();
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