#ifndef __DEFINED__BASIC__TAGS
#define __DEFINED__BASIC__TAGS
#include "base_traits.hpp"
#include "header_tags.hpp"
#include "body_tags.hpp"
#include "specialized_tags.hpp"
#include "attributes.hpp"
#include "util.hpp"

namespace WCP
{
class Document : public Block
{
public:
  template <class... T>
  Document(T... arg) { unpacker(arg...); std::cout << *this; }
  void outputOpening();
  void outputPayload();
  void outputClosing();
};
} // namespace WCP

#endif