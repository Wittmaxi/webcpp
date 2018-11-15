#ifndef __DEFINED__UTIL
#define __DEFINED__UTIL
#include "base_traits.hpp"
#include <ostream>

namespace WCP
{
class Text : public Block, public HeaderObject, public BodyObject
{
public:
  explicit Text(const char *arg);
  explicit Text(const std::string&);
  Text();
  void outputOpening() const;
  void outputClosing() const;

private:
  std::string containedText;
};

class UnformattedText : public Block, public HeaderObject, public BodyObject
{
public:
  explicit UnformattedText(const char *arg);
  explicit UnformattedText(const std::string&);
  UnformattedText();
  void outputOpening() const;
  void outputClosing() const;

private:
  std::string containedText;
};

class ConvenientText : public Block, public HeaderObject, public BodyObject
{
public:
  explicit ConvenientText(const char *arg);
  explicit ConvenientText(const std::string&);
  ConvenientText();
  void outputOpening() const;
  void outputClosing() const;

private:
  std::string containedText;
};
} // namespace WCP

#endif