#ifndef __DEFINED__ATTRIBUTES
#define __DEFINED__ATTRIBUTES
#include "base_traits.hpp"

namespace WCP
{
class Attribute : public NamedAttribute
{
  public:
    Attribute();
    explicit Attribute(std::string&);
    void printAttribute();

  private:
    std::string name;
};
class ClassAttribute : public NamedAttribute
{
  public:
    ClassAttribute();
    explicit ClassAttribute(std::string&);
    void printAttribute();

  private:
    std::string name;
};
class IdAttribute : public NamedAttribute
{
  public:
    IdAttribute();
    explicit IdAttribute(std::string&);
    void printAttribute();

  private:
    std::string name;
};
class StyleAttribute : public NamedAttribute
{
  public:
    StyleAttribute();
    explicit StyleAttribute(std::string&);
    void printAttribute();

  private:
    std::string name;
};
class SourceAttribute : public NamedAttribute
{
  public:
    SourceAttribute();
    explicit SourceAttribute(std::string&);
    void printAttribute();

  private:
    std::string name;
};
class HyperReference : public NamedAttribute
{
  public:
    HyperReference();
    explicit HyperReference(std::string&);
    void printAttribute();

  private:
    std::string name;
};
class FormMethod : public NamedAttribute
{
  public:
    FormMethod();
    explicit FormMethod(std::string&);
    void printAttribute();

  private:
    std::string method;
};
class InputType : public NamedAttribute
{
  public:
    InputType();
    explicit InputType(std::string&);
    void printAttribute();

  private:
    std::string type;
};
class InputName : public NamedAttribute
{
  public:
    InputName();
    explicit InputName(std::string&);
    void printAttribute();

  private:
    std::string name;
};
class InputValue : public NamedAttribute
{
  public:
    InputValue();
    explicit InputValue(std::string&);
    void printAttribute();

  private:
    std::string name;
};
} // namespace WCP

#endif