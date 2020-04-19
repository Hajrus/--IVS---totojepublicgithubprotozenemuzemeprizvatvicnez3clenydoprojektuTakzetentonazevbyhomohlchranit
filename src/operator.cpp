#include <math.h>
#include "operator.h"

using namespace IVS;

void Plus::execute(){
    this->_result = new Operand(this->_o1->ToDouble() + this->_o2->ToDouble());
}
void Minus::execute(){
    this->_result = new Operand(this->_o1->ToDouble() - this->_o2->ToDouble());
}
void Multiply::execute(){
    this->_result = new Operand(this->_o1->ToDouble() * this->_o2->ToDouble());
}
void Divide::execute(){
    this->_result = new Operand(this->_o1->ToDouble() / this->_o2->ToDouble());
}
void Power::execute(){
    this->_result = new Operand(pow(this->_o1->ToDouble(), this->_o2->ToDouble()));
}
void Sqrt::execute(){
    this->_result = new Operand(sqrt(this->_o1->ToDouble()));
}
void Mod::execute(){
    this->_result = new Operand((int)this->_o1->ToDouble() % (int)this->_o2->ToDouble());
}
void Factorial::execute(){
    double retval = this->_o1->ToDouble();
    for(int i = this->_o1->ToDouble(); i >= 1; i--){
        retval*=i;
    }
    this->_result = new Operand(retval);
}