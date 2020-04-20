#ifndef OPERATOR_H
#define OPERATOR_H

#include "ivs.h"

namespace IVS{
    class Plus : public Operator{
        using Operator::Operator;
        public:
            Operand* execute(); 
    };
    class Minus : public Operator{
        using Operator::Operator;
        public:
            Operand* execute(); 
    };
    class Multiply : public Operator{
        using Operator::Operator;
        public:
            Operand* execute(); 
    };
    class Divide : public Operator{
        using Operator::Operator;
        public:
            Operand* execute(); 
    };
    class Power : public Operator{
        using Operator::Operator;
        public:
            Operand* execute(); 
    };
    class Sqrt : public Operator{
        using Operator::Operator;
        public:
            Operand* execute(); 
    };
    class Mod : public Operator{
        using Operator::Operator;
        public:
            Operand* execute(); 
    };
    class Factorial : public Operator{
        using Operator::Operator;
        public:
            Operand* execute(); 
    };
};


#endif