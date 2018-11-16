#ifndef SPECIALIZED_TAGS
#define SPECIALIZED_TAGS

#include "base_traits.hpp"
#include <functional>

namespace WCP {
class Function : public Block, public DocumentObject
{
public: 
    Function ();
    explicit Function (const std::function<void (void)> &func);
    void outputOpening() const;
    void outputClosing() const;
private:
    std::function<void (void)> function;
};
}

#endif