#ifndef __DEFINED__UTIL
#define __DEFINED__UTIL
#include "base_traits.hpp"
#include <ostream>

namespace WCP
{
class Text : public Block, public HeaderObject, public BodyObject
{
  public:
    Text(std::string arg);
    Text(const char* arg);
    Text();
    void outputOpening();
    void outputClosing();

  private:
    std::string containedText;
};
} // namespace WCP

#endif