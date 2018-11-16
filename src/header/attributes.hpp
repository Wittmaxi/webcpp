#ifndef DEFINED_ATTRIBUTES
#define DEFINED_ATTRIBUTES
#include "base_traits.hpp"

namespace WCP
{
class Attribute : public NamedAttribute
{
  public:
    Attribute();
    explicit Attribute(const std::string&);
    explicit Attribute(const char*);
    void printAttribute();

  private:
    std::string name;
};
class ClassAttribute : public NamedAttribute
{
  public:
    ClassAttribute();
    explicit ClassAttribute(const std::string&);
    explicit ClassAttribute(const char*);
    void printAttribute();

  private:
    std::string name;
};
class IdAttribute : public NamedAttribute
{
  public:
    IdAttribute();
    explicit IdAttribute(const std::string&);
    explicit IdAttribute(const char*);
    void printAttribute();

  private:
    std::string name;
};
class StyleAttribute : public NamedAttribute
{
  public:
    StyleAttribute();
    explicit StyleAttribute(const std::string&);
    explicit StyleAttribute(const char*);
    void printAttribute();

  private:
    std::string name;
};
class SourceAttribute : public NamedAttribute
{
  public:
    SourceAttribute();
    explicit SourceAttribute(const std::string&);
    explicit SourceAttribute(const char*);
    void printAttribute();

  private:
    std::string name;
};
class HyperReference : public NamedAttribute
{
  public:
    HyperReference();
    explicit HyperReference(const std::string&);
    explicit HyperReference(const char*);
    void printAttribute();

  private:
    std::string name;
};
class FormMethod : public NamedAttribute
{
  public:
    FormMethod();
    explicit FormMethod(const std::string&);
    explicit FormMethod(const char*);
    void printAttribute();

  private:
    std::string method;
};
class InputType : public NamedAttribute
{
  public:
    InputType();
    explicit InputType(const std::string&);
    explicit InputType(const char*);
    void printAttribute();

  private:
    std::string type;
};
class InputName : public NamedAttribute
{
  public:
    InputName();
    explicit InputName(const std::string&);
    explicit InputName(const char*);
    void printAttribute();

  private:
    std::string name;
};
class InputValue : public NamedAttribute
{
  public:
    InputValue();
    explicit InputValue(const std::string&);
    explicit InputValue(const char*);
    void printAttribute();

  private:
    std::string name;
};
} // namespace WCP

#endif