#ifndef __DEFINED__BASE__CLASSES
#define __DEFINED__BASE__CLASSES
#include <iostream>
#include <string>
#include <vector>
#include <memory>

namespace WCP
{
class HeaderObject {};
class BodyObject {};
class DocumentObject : public HeaderObject, public BodyObject {};

class StyleBlock {

};

class Block
{
public:
  template <class A, class... T>
  void unpacker(A first, T&&... arg)
  {
    A* ptr = new A();
    *ptr = first;
    containedBlocks.push_back(std::shared_ptr<A>(ptr));
    unpacker(arg...);
  }

  template <class B, class A, class... T>
  void restricted_unpacker(A first, T&&... arg)
  {
    static_assert (std::is_base_of <B, A>::value, "Misplaced Object (example: header-object put into the body)");
    A* ptr = new A();
    *ptr = first;
    containedBlocks.push_back(std::shared_ptr<A>(ptr));
    restricted_unpacker<B>(arg...);
  }

  template<class B>
  void restricted_unpacker() {
  }

  void unpacker()
  {
  }

  virtual void outputOpening() = 0;
  virtual void outputClosing() = 0;
  void appendBlock(Block &other);

  std::vector<std::shared_ptr<Block>> containedBlocks;
  std::shared_ptr<StyleBlock> styleBlock;
};
} // namespace WCP

std::ostream &operator<<(std::ostream &os, WCP::Block &);

#endif