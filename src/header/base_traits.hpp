#ifndef DEFINED_BASE_CLASSES
#define DEFINED_BASE_CLASSES
#include <iostream>
#include <string>
#include <vector>
#include <memory>

namespace WCP
{
class HeaderObject
{
};
class BodyObject
{
};
class TableObject 
{
};
class DocumentObject : public HeaderObject, public BodyObject
{
};
class StyleObject : public DocumentObject, public TableObject
{
};

class NamedAttribute : public StyleObject
{
public:
  virtual void printAttribute() = 0;
};

class Block
{
public:

  template <class A>
  void addElementInCorrectContainer (A elem, typename std::enable_if <std::is_base_of <Block, A>::value, int>::type a = 0) {
    A *ptr = new A();
    *ptr = elem;
    containedBlocks.push_back(std::shared_ptr<A>(ptr));
  }
  template <class A>
  void addElementInCorrectContainer (A elem, typename std::enable_if <std::is_base_of <NamedAttribute, A>::value, int>::type a = 0) {
    A *ptr = new A();
    *ptr = elem;
    attributes.push_back(std::shared_ptr<A>(ptr));
  }

  template <class A, class... T>
  void unpacker(A first, T &&... arg)
  {
    addElementInCorrectContainer<A>(first);
    unpacker(arg...);
  }

  template <class B, class A, class... T>
  void restricted_unpacker(A first, T &&... arg)
  {
    static_assert(std::is_base_of<B, A>::value, "Misplaced Object (example: header-object put into the body)");
    addElementInCorrectContainer<A>(first);
    restricted_unpacker<B>(arg...);
  }

  template <class B>
  void restricted_unpacker()
  {
  }

  void unpacker()
  {
  }

  virtual void outputOpening() const = 0;
  virtual void outputClosing() const = 0;
  void appendBlock(Block &other);

  std::vector<std::shared_ptr<Block>> containedBlocks;
  std::vector<std::shared_ptr<NamedAttribute>> attributes;
};
} // namespace WCP


std::ostream &operator<<(std::ostream &os, const WCP::Block &);
std::ostream &operator<<(std::ostream &os, const std::vector<std::shared_ptr<WCP::NamedAttribute>> &);

#endif