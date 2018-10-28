#include "header/attributes.hpp"
#include <regex>

namespace WCP
{
Attribute::Attribute() {}
Attribute::Attribute(std::string cn)
{
    name = cn;
}
void Attribute::printAttribute()
{
    std::cout << name;
}

ClassAttribute::ClassAttribute() {}
ClassAttribute::ClassAttribute(std::string cn)
{
    name = cn;
    name = std::regex_replace(name, std::regex("\""), "&quot;");
    name = std::regex_replace(name, std::regex("\'"), "&#39");
}
void ClassAttribute::printAttribute()
{
    std::cout << "class=\"" << name << "\"";
}


IdAttribute::IdAttribute() {}
IdAttribute::IdAttribute(std::string cn)
{
    name = cn;
    name = std::regex_replace(name, std::regex("\""), "&quot;");
    name = std::regex_replace(name, std::regex("\'"), "&#39");
}
void IdAttribute::printAttribute()
{
    std::cout << "id=\"" << name << "\"";
}

StyleAttribute::StyleAttribute() {}
StyleAttribute::StyleAttribute(std::string cn)
{
    name = cn;
    name = std::regex_replace(name, std::regex("\""), "&quot;");
    name = std::regex_replace(name, std::regex("\'"), "&#39");
}
void StyleAttribute::printAttribute()
{
    std::cout << "style=\"" << name << "\"";
}

HyperReference::HyperReference() {}
HyperReference::HyperReference(std::string cn)
{
    name = cn;
    name = std::regex_replace(name, std::regex("\""), "&quot;");
    name = std::regex_replace(name, std::regex("\'"), "&#39");
}
void HyperReference::printAttribute()
{
    std::cout << "href=\"" << name << "\"";
}

FormMethod::FormMethod() {}
FormMethod::FormMethod(std::string cn)
{
    method = cn;
    method = std::regex_replace(method, std::regex("\""), "&quot;");
    method = std::regex_replace(method, std::regex("\'"), "&#39");
}
void FormMethod::printAttribute()
{
    std::cout << "method=\"" << method << "\"";
}

InputType::InputType() {}
InputType::InputType(std::string cn)
{
    type = cn;
    type = std::regex_replace(type, std::regex("\""), "&quot;");
    type = std::regex_replace(type, std::regex("\'"), "&#39");
}
void InputType::printAttribute()
{
    std::cout << "type=\"" << type << "\"";
}

InputName::InputName() {}
InputName::InputName(std::string cn)
{
    name = cn;
    name = std::regex_replace(name, std::regex("\""), "&quot;");
    name = std::regex_replace(name, std::regex("\'"), "&#39");
}
void InputName::printAttribute()
{
    std::cout << "name=\"" << name << "\"";
}

InputValue::InputValue() {}
InputValue::InputValue(std::string cn)
{
    name = cn;
    name = std::regex_replace(name, std::regex("\""), "&quot;");
    name = std::regex_replace(name, std::regex("\'"), "&#39");
}
void InputValue::printAttribute()
{
    std::cout << "value=\"" << name << "\"";
}

SourceAttribute::SourceAttribute() {}
SourceAttribute::SourceAttribute(std::string cn)
{
    name = cn;
    name = std::regex_replace(name, std::regex("\""), "&quot;");
    name = std::regex_replace(name, std::regex("\'"), "&#39");
}
void SourceAttribute::printAttribute()
{
    std::cout << "src=\"" << name << "\"";
}
} // namespace WCP