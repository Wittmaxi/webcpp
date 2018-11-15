#include "header/specialized_tags.hpp"

namespace WCP
{
Function::Function() {}
Function::Function(std::function<void(void)> &func) : function (func) 
{
}
void Function::outputOpening() const {
    function ();
}
void Function::outputClosing() const {

}
} // namespace WCP