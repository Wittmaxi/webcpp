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
  explicit Document(T... arg) { unpacker(arg...);}
  void outputOpening() const;
  void outputClosing() const;
};
} // namespace WCP

#endif