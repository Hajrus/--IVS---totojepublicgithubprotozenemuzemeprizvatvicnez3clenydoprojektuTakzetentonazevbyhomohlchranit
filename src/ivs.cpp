#include <string>
#include <iostream>
#include <sstream>
#include "ivs.h"
#include "operator.h"

using namespace IVS;

CalculatorException::CalculatorException(std::string message){
    this->message = message;
}
void CalculatorException::Print(){
    std::cerr << this->message << std::endl;
}

Operand::Operand(){}
Operand::Operand(std::string sOp){
    try{
        this->validStr(sOp);
        this->_stringValue = sOp;
        this->_doubleValue = std::stod(sOp);
    }
    catch(CalculatorException* e){
        e->Print();
    }
}
Operand::Operand(double op){
    this->_doubleValue = op; 
    this->_stringValue = DoubleToStr(op);
}

std::string Operand::ToString(){
    return this->_stringValue;
}

double Operand::ToDouble(){
    return this->_doubleValue;
}

void Operand::Append(CalculatorButton c){
    try{
        validChar(c);
        this->_stringValue += (char) c;
        this->_doubleValue = std::stod(this->_stringValue);
    }
    catch(CalculatorException* e){
        e->Print();
    }
}
void Operand::Erase(){
    if(!this->_stringValue.empty())
        this->_stringValue.pop_back();

     this->_doubleValue = std::stod(this->_stringValue);
}   
std::string Operand::DoubleToStr(double val){
    std::ostringstream strs;
    strs << val;
    return strs.str();
}
bool Operand::validStr(std::string input){
    for(unsigned int i = 0; i < input.size(); i++){
        if(!this->validChar(static_cast<CalculatorButton>((int)input[i]))){
            return false;
        }
    }
    return true;
}
bool Operand::validChar(CalculatorButton c){
    if((c < 48 || c > 57) && c != 46){
        throw new CalculatorException("Neplatný znak v operandu.");
    }
    return true;
}
Operator::Operator(){}
Operator::Operator(Operand* o1, Operand* o2){
    this->_o1 = o1;
    this->_o2 = o2;
    this->_result = new Operand();
}
Operator::Operator(Operand* o1){
    this->_o1 = o1;
}
Operator::~Operator(){
    delete this->_result;
}
Operand* Operator::GetResult(){
    return this->_result;
}

Calculator::Calculator(){
    this->_state = InsertFirstOperand;
    this->_o1 = new Operand();
    this->_o2 = new Operand();
}
void Calculator::Press(CalculatorButton button){
    if(this->_state == InsertFirstOperand){
        if(isConstant(button)){
            this->_o1->Append(button);
        }
        else if(isOperator(button)){
            this->_actualOperator = button;
            this->_state = OperatorAdded;
        }
        else if(isFunction(button)){
            if(button == del){
                 this->_o1->Erase();
            }
            else if(button == CalculatorButton::clear){
                this->clear();
            }
        }
    }
    else if(this->_state == OperatorAdded){
        if(isConstant(button)){
            this->_o2->Append(button);
            this->_state = InsertSecondOperand;
        }
        else if(isOperator(button)){
            this->_actualOperator = button;
        }
        else if(isFunction(button)){
            if(button == del){
                 this->_state = InsertFirstOperand;
            }
            else if(button == CalculatorButton::clear){
                this->clear();
            }
        }
    }
    else if(this->_state == InsertSecondOperand){
        if(isConstant(button)){
            this->_o2->Append(button);
        }
        else if(isOperator(button)){
            this->_actualOperator = button;
        }
        else if(isFunction(button)){
            if(button == equals){
                execute();
                this->_state = InsertFirstOperand;
                this->_o2 = new Operand();
            }
            else if(button == CalculatorButton::clear){
                this->_state = InsertFirstOperand;
                this->clear();
            }
            else if(button == CalculatorButton::del){
                this->_o2->Erase();
            }
        }
    }
    this->redrawBuffers();
}
std::string Calculator::GetScreenBuffer(){
    return this->_screenBuffer;
}
std::string Calculator::GetHistoryBuffer(){
    return this->_historyBuffer;
}
bool Calculator::isConstant(CalculatorButton button){
    if(((int)button >= 48 && (int)button <= 57) || button == dot){
        return true;
    }
    return false;
}
bool Calculator::isOperator(CalculatorButton button){
    if (button == multiply ||
        button == plus ||
        button == minus ||
        button == divide ||
        button == power ||
        button == mod ||
        button == factorial ||
        button == sqr 
        ){
        return true;
    }
    return false;
}
bool Calculator::isFunction(CalculatorButton button){
    if (button == equals ||
        button == CalculatorButton::clear ||
        button == del 
        ){
        return true;
    }
    return false;
}
void Calculator::clear(){
    delete this->_o1;
    this->_o1 = new Operand();
    delete this->_o2;
    this->_o2 = new Operand();
    
    this->_screenBuffer = "";
    this->_historyBuffer = "";
}
void Calculator::execute(){
    Operand* oldOperand = this->_o1;
    if(this->_actualOperator == multiply)
        this->_o1 = (new Multiply(this->_o1, this->_o2))->execute();
    else if(this->_actualOperator == plus)
        this->_o1 = (new Plus(this->_o1, this->_o2))->execute();
    else if(this->_actualOperator == minus)
        this->_o1 = (new Minus(this->_o1, this->_o2))->execute();
    else if(this->_actualOperator == divide)
        this->_o1 = (new Divide(this->_o1, this->_o2))->execute();
    else if(this->_actualOperator == divide)
        this->_o1 = (new Power(this->_o1, this->_o2))->execute();
    else if(this->_actualOperator == mod)
        this->_o1 = (new Mod(this->_o1, this->_o2))->execute();
    else if(this->_actualOperator == factorial)
        this->_o1 = (new Factorial(this->_o1, this->_o2))->execute();
    else if(this->_actualOperator == sqr)
        this->_o1 = (new Sqrt(this->_o1, this->_o2))->execute();
    
    delete oldOperand;
    delete this->_o2;
}
void Calculator::redrawBuffers(){
    if(this->_state == InsertFirstOperand){
        this->_historyBuffer = "";
        this->_screenBuffer = this->_o1->ToString();
    }
    else{
        std::string operatorStr(1, (char)this->_actualOperator);
        this->_historyBuffer = this->_o1->ToString() + " " + operatorStr;
        this->_screenBuffer = this->_o2->ToString();
    }
}