#ifndef __DEFINED__ATTRIBUTES
#define __DEFINED__ATTRIBUTES
#include "base_traits.hpp"

namespace WCP
{
class Attribute : public NamedAttribute
{
  public:
    Attribute();
    Attribute(std::string);
    void printAttribute();

  private:
    std::string name;
};
class ClassAttribute : public NamedAttribute
{
  public:
    ClassAttribute();
    ClassAttribute(std::string);
    void printAttribute();

  private:
    std::string name;
};
class IdAttribute : public NamedAttribute
{
  public:
    IdAttribute();
    IdAttribute(std::string);
    void printAttribute();

  private:
    std::string name;
};
class StyleAttribute : public NamedAttribute
{
  public:
    StyleAttribute();
    StyleAttribute(std::string);
    void printAttribute();

  private:
    std::string name;
};
class SourceAttribute : public NamedAttribute
{
  public:
    SourceAttribute();
    SourceAttribute(std::string);
    void printAttribute();

  private:
    std::string name;
};
class HyperReference : public NamedAttribute
{
  public:
    HyperReference();
    HyperReference(std::string);
    void printAttribute();

  private:
    std::string name;
};
class FormMethod : public NamedAttribute
{
  public:
    FormMethod();
    FormMethod(std::string);
    void printAttribute();

  private:
    std::string method;
};
class InputType : public NamedAttribute
{
  public:
    InputType();
    InputType(std::string);
    void printAttribute();

  private:
    std::string type;
};
class InputName : public NamedAttribute
{
  public:
    InputName();
    InputName(std::string);
    void printAttribute();

  private:
    std::string name;
};
class InputValue : public NamedAttribute
{
  public:
    InputValue();
    InputValue(std::string);
    void printAttribute();

  private:
    std::string name;
};
} // namespace WCP

#endif