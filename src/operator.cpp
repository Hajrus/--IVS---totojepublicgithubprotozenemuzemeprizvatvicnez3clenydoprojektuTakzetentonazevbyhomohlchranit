#include <math.h>
#include "operator.h"

using namespace IVS;

Operand* Plus::execute(){
    return this->_result = new Operand(this->_o1->ToDouble() + this->_o2->ToDouble());
}
Operand* Minus::execute(){
    return this->_result = new Operand(this->_o1->ToDouble() - this->_o2->ToDouble());
}
Operand* Multiply::execute(){
    return this->_result = new Operand(this->_o1->ToDouble() * this->_o2->ToDouble());
}
Operand* Divide::execute(){
    return this->_result = new Operand(this->_o1->ToDouble() / this->_o2->ToDouble());
}
Operand* Power::execute(){
    return this->_result = new Operand(pow(this->_o1->ToDouble(), this->_o2->ToDouble()));
}
Operand* Sqrt::execute(){
    return this->_result = new Operand(sqrt(this->_o1->ToDouble()));
}
Operand* Mod::execute(){
    return this->_result = new Operand((int)this->_o1->ToDouble() % (int)this->_o2->ToDouble());
}
Operand* Factorial::execute(){
    double retval = this->_o1->ToDouble();
    for(int i = this->_o1->ToDouble(); i >= 1; i--){
        retval*=i;
    }
    return this->_result = new Operand(retval);
}