#ifndef DEFINED_HEADER_TAGS
#define DEFINED_HEADER_TAGS
#include "base_traits.hpp"
#include "util.hpp"

namespace WCP {
class Head : public Block {
public:
  template <class... T>
  explicit Head(const T... arg) {
    restricted_unpacker<HeaderObject>(arg...);
  }
  void outputOpening() const;
  void outputClosing() const;
};

class Title : public Block, public HeaderObject {
public:
  Title();
  explicit Title(Text arg);
  void outputOpening() const;
  void outputClosing() const;
};

class Include : public Block, public HeaderObject {
public:
  Include(const std::string &_href, const std::string &_type, const std::string &_rel);
  Include();
  void outputOpening() const;
  void outputClosing() const;

private:
  std::string rel, href, type;
};

class IncludeScript : public Block, public HeaderObject {
public:
  explicit IncludeScript(const std::string &_href);
  IncludeScript();
  void outputOpening() const;
  void outputClosing() const;

private:
  std::string href;
};

class HttpEquiv : public Block, public HeaderObject {
public:
  HttpEquiv();
  explicit HttpEquiv(const std::string &equiv, const std::string &content);
  void outputOpening() const;
  void outputClosing() const;
private:
    std::string equiv, content;
};

class Charset : public Block, public HeaderObject {
public:
  Charset();
  explicit Charset(const std::string &charset);
  void outputOpening() const;  
  void outputClosing() const;
private:
    std::string charset;
};

class Meta : public Block, public HeaderObject {
public:
  Meta();
  explicit Meta(const std::string &name, const std::string &content);
  void outputOpening() const;
  void outputClosing() const;
private:
    std::string name, content;
};


} // namespace WCP

#endif