#ifndef __DEFINED__UTIL
#define __DEFINED__UTIL
#include "base_traits.hpp"
#include <ostream>

namespace WCP
{
class Text : public Block, public HeaderObject, public BodyObject
{
public:
  Text(const char *arg);
  Text(std::string);
  Text();
  void outputOpening() const;
  void outputClosing() const;

private:
  std::string containedText;
};

class UnformattedText : public Block, public HeaderObject, public BodyObject
{
public:
  UnformattedText(const char *arg);
  UnformattedText(std::string);
  UnformattedText();
  void outputOpening() const;
  void outputClosing() const;

private:
  std::string containedText;
};

class ConvenientText : public Block, public HeaderObject, public BodyObject
{
public:
  ConvenientText(const char *arg);
  ConvenientText(std::string);
  ConvenientText();
  void outputOpening() const;
  void outputClosing() const;

private:
  std::string containedText;
};
} // namespace WCP

#endif