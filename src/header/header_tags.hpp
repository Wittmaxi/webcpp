#ifndef __DEFINED__HEADER__TAGS
#define __DEFINED__HEADER__TAGS
#include "base_traits.hpp"
#include "util.hpp"

namespace WCP {
class Head : public Block {
public:
  template <class... T> Head(T... arg) {
    restricted_unpacker<HeaderObject>(arg...);
  }
  void outputOpening() const;
  void outputClosing() const;
};

class Title : public Block, public HeaderObject {
public:
  Title();
  Title(Text arg);
  void outputOpening() const;
  void outputClosing() const;
};

class Include : public Block, public HeaderObject {
public:
  Include(std::string _href, std::string _type, std::string _rel);
  Include();
  void outputOpening() const;
  void outputClosing() const;

private:
  std::string rel, href, type;
};

class IncludeScript : public Block, public HeaderObject {
public:
  IncludeScript(std::string _href);
  IncludeScript();
  void outputOpening() const;
  void outputClosing() const;

private:
  std::string href;
};

class HttpEquiv : public Block, public HeaderObject {
public:
  HttpEquiv();
  HttpEquiv(std::string equiv, std::string content);
  void outputOpening() const;
  void outputClosing() const;
private:
    std::string equiv, content;
};

class Charset : public Block, public HeaderObject {
public:
  Charset();
  Charset(std::string charset);
  void outputOpening() const;  
  void outputClosing() const;
private:
    std::string charset;
};

class Meta : public Block, public HeaderObject {
public:
  Meta();
  Meta(std::string name, std::string content);
  void outputOpening() const;
  void outputClosing() const;
private:
    std::string name, content;
};


} // namespace WCP

#endif