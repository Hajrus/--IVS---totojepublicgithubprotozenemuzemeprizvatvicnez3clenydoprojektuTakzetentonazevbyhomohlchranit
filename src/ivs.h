#ifndef IVS_H
#define IVS_H

#include <string>
namespace IVS{
    typedef enum{
        //konstanty
        zero = 48,
        one = 49,
        two = 50,
        three = 51,
        four = 52,
        five = 53,
        six = 54,
        seven = 55,
        eight = 56,
        nine = 57,
        dot = 46,
        pi = 1,

        //operátory
        multiply = 42, 
        plus = 43, 
        minus = 45,
        divide = 47, 
        power = 94,
        mod = 37,
        factorial = 33,
        sqr = 2,

        //funkce
        equals = 61,
        clear = 99,
        del = 3

    } CalculatorButton;
    typedef enum{
        InsertFirstOperand, OperatorAdded, InsertSecondOperand
    } CalculatorState;

    class CalculatorException{
        public:
            CalculatorException(std::string message);
            void Print();
        private:
            std::string message;
    };

    class Operand{
        public:
            Operand();
            Operand(std::string sOp);
            Operand(double op);

            std::string ToString();
            double ToDouble();

            void Append(CalculatorButton c);
            void Erase();
        private:
            double _doubleValue;
            std::string _stringValue;

            bool validStr(std::string input);
            bool validChar(CalculatorButton c);

            std::string DoubleToStr(double val);
    };
    class Operator{
        public:
            explicit Operator();
            explicit Operator(Operand* o1, Operand* o2);
            explicit Operator(Operand* o1);
            virtual ~Operator();

            Operand* GetResult();
        private:
            virtual void execute();   
        protected:
            Operand* _result;
            Operand* _o1;
            Operand* _o2;

    };
    class Calculator{
        public:
            Calculator();
            void Press(CalculatorButton button);
            std::string GetScreenBuffer();
            std::string GetHistoryBuffer();
        private:
            CalculatorState _state;
            std::string  _screenBuffer;
            std::string  _historyBuffer;

            CalculatorButton _actualOperator;

            Operand* _o1;
            Operand* _o2;

            bool isConstant(CalculatorButton button);
            bool isOperator(CalculatorButton button);
            bool isFunction(CalculatorButton button);

            void execute();
            void redrawBuffers();
    };
};

#endif