#ifndef __DEFINED__ATTRIBUTES
#define __DEFINED__ATTRIBUTES
#include "base_traits.hpp"

namespace WCP {
class ClassAttribute : public NamedAttribute {
public:
    ClassAttribute();
    ClassAttribute(std::string);
    void printAttribute();
private: 
    std::string name;
};
class StyleAttribute : public NamedAttribute {
public:
    StyleAttribute();
    StyleAttribute(std::string);
    void printAttribute();
private: 
    std::string name;
};
}

#endif