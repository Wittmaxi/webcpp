#include "header/attributes.hpp"
#include <regex>

namespace WCP
{
Attribute::Attribute() {}
Attribute::Attribute(const char *cn) : Attribute(std::string(cn)) {}
Attribute::Attribute(const std::string &cn) : name(cn)
{
}
void Attribute::printAttribute()
{
    std::cout << name;
}

ClassAttribute::ClassAttribute() {}
ClassAttribute::ClassAttribute(const char *cn) : ClassAttribute(std::string(cn)) {}
ClassAttribute::ClassAttribute(const std::string &cn) : name(cn)
{
    name = std::regex_replace(name, std::regex("\""), "&quot;");
    name = std::regex_replace(name, std::regex("\'"), "&#39");
}
void ClassAttribute::printAttribute()
{
    std::cout << "class=\"" << name << "\"";
}

IdAttribute::IdAttribute() {}
IdAttribute::IdAttribute(const char *cn) : IdAttribute(std::string(cn)) {}
IdAttribute::IdAttribute(const std::string &cn) : name(cn)
{
    name = std::regex_replace(name, std::regex("\""), "&quot;");
    name = std::regex_replace(name, std::regex("\'"), "&#39");
}
void IdAttribute::printAttribute()
{
    std::cout << "id=\"" << name << "\"";
}

StyleAttribute::StyleAttribute() {}
StyleAttribute::StyleAttribute(const char *cn) : StyleAttribute(std::string(cn)) {}
StyleAttribute::StyleAttribute(const std::string &cn) : name(cn)
{
    name = std::regex_replace(name, std::regex("\""), "&quot;");
    name = std::regex_replace(name, std::regex("\'"), "&#39");
}
void StyleAttribute::printAttribute()
{
    std::cout << "style=\"" << name << "\"";
}

HyperReference::HyperReference() {}
HyperReference::HyperReference(const char *cn) : HyperReference(std::string(cn)) {}
HyperReference::HyperReference(const std::string &cn) : name(cn)
{
    name = std::regex_replace(name, std::regex("\""), "&quot;");
    name = std::regex_replace(name, std::regex("\'"), "&#39");
}
void HyperReference::printAttribute()
{
    std::cout << "href=\"" << name << "\"";
}

FormMethod::FormMethod() {}
FormMethod::FormMethod(const char *cn) : FormMethod(std::string(cn)) {}
FormMethod::FormMethod(const std::string &cn) : method(cn)
{
    method = std::regex_replace(method, std::regex("\""), "&quot;");
    method = std::regex_replace(method, std::regex("\'"), "&#39");
}
void FormMethod::printAttribute()
{
    std::cout << "method=\"" << method << "\"";
}

InputType::InputType() {}
InputType::InputType(const char *cn) : InputType(std::string(cn)) {}
InputType::InputType(const std::string &cn) : type(cn)
{
    type = std::regex_replace(type, std::regex("\""), "&quot;");
    type = std::regex_replace(type, std::regex("\'"), "&#39");
}
void InputType::printAttribute()
{
    std::cout << "type=\"" << type << "\"";
}

InputName::InputName() {}
InputName::InputName(const char *cn) : InputName(std::string(cn)) {}
InputName::InputName(const std::string &cn) : name(cn)
{
    name = std::regex_replace(name, std::regex("\""), "&quot;");
    name = std::regex_replace(name, std::regex("\'"), "&#39");
}
void InputName::printAttribute()
{
    std::cout << "name=\"" << name << "\"";
}

InputValue::InputValue() {}
InputValue::InputValue(const char *cn) : InputValue(std::string(cn)) {}
InputValue::InputValue(const std::string &cn) : name(cn)
{
    name = std::regex_replace(name, std::regex("\""), "&quot;");
    name = std::regex_replace(name, std::regex("\'"), "&#39");
}
void InputValue::printAttribute()
{
    std::cout << "value=\"" << name << "\"";
}

SourceAttribute::SourceAttribute() {}
SourceAttribute::SourceAttribute(const char *cn) : SourceAttribute(std::string(cn)) {}
SourceAttribute::SourceAttribute(const std::string &cn) : name(cn)
{
    name = std::regex_replace(name, std::regex("\""), "&quot;");
    name = std::regex_replace(name, std::regex("\'"), "&#39");
}
void SourceAttribute::printAttribute()
{
    std::cout << "src=\"" << name << "\"";
}
} // namespace WCP