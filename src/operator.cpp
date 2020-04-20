#include <math.h>
#include "operator.h"
#include "Math.h"

using namespace IVS;

Operand* Plus::execute(){
    return this->_result = new Operand(Math::Add(this->_o1->ToDouble(), this->_o2->ToDouble()));
}
Operand* Minus::execute(){
    return this->_result = new Operand(Math::Sub(this->_o1->ToDouble(),this->_o2->ToDouble()));
}
Operand* Multiply::execute(){
    return this->_result = new Operand(Math::Mult(this->_o1->ToDouble(), this->_o2->ToDouble()));
}
Operand* Divide::execute(){
    return this->_result = new Operand(Math::Div(this->_o1->ToDouble(), this->_o2->ToDouble()));
}
Operand* Power::execute(){
    return this->_result = new Operand(Math::Power(this->_o1->ToDouble(), this->_o2->ToDouble()));
}
Operand* Sqrt::execute(){
    return this->_result = new Operand(Math::GeneralRoot(this->_o1->ToDouble(), this->_o2->ToDouble()));
}
Operand* Mod::execute(){
    return this->_result = new Operand(Math::Mod((int)this->_o1->ToDouble(), (int)this->_o2->ToDouble()));
}
Operand* Factorial::execute(){
    return this->_result = new Operand(Math::Factorial((unsigned long)(unsigned int)(int)this->_o1->ToDouble()));
}