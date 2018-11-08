#ifndef __SPECIALIZED__TAGS
#define __SPECIALIZED__TAGS

#include "base_traits.hpp"
#include <functional>

namespace WCP {
class Function : public Block, public DocumentObject
{
public: 
    Function ();
    Function (std::function<void (void)> func);
    void outputOpening() const;
    void outputClosing() const;
private:
    std::function<void (void)> function;
};
}

#endif