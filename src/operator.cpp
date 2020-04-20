#include <math.h>
#include "operator.h"
#include "lib/Math.h"

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
    if(this->_o2->ToDouble() == 0){
        throw CalculatorException("Dělení nulou.");
    }
    return this->_result = new Operand(Math::Div(this->_o1->ToDouble(), this->_o2->ToDouble()));
}
Operand* Power::execute(){
    return this->_result = new Operand(Math::Power(this->_o1->ToDouble(), (int)this->_o2->ToDouble()));
}
Operand* Sqrt::execute(){
    if(this->_o2->ToDouble() < 0){
        throw CalculatorException("Odmocnina ze záporného čísla neexistuje.");
    }
    return this->_result = new Operand(Math::GeneralRoot(this->_o2->ToDouble(), this->_o1->ToDouble()));
}
Operand* Mod::execute(){
    if(this->_o2->ToDouble() == 0){
        throw CalculatorException("Modulo nulou.");
    }
    return this->_result = new Operand(Math::Mod((int)this->_o1->ToDouble(), (int)this->_o2->ToDouble()));
}
Operand* Factorial::execute(){
    if(this->_o1->ToDouble() < 0){
        throw CalculatorException("Operand faktorialu musí být větší než -1.");
    }
    return this->_result = new Operand(Math::Factorial((unsigned long)(unsigned int)(int)this->_o1->ToDouble()));
}