#ifndef OPERATOR_H
#define OPERATOR_H

#include "ivs.h"

namespace IVS{
    class Plus : private Operator{
        using Operator::Operator;
        private:
            void execute() override; 
    };
    class Minus : private Operator{
        using Operator::Operator;
        private:
            void execute() override; 
    };
    class Multiply : private Operator{
        using Operator::Operator;
        private:
            void execute() override; 
    };
    class Divide : private Operator{
        using Operator::Operator;
        private:
            void execute() override; 
    };
    class Power : private Operator{
        using Operator::Operator;
        private:
            void execute() override; 
    };
    class Sqrt : private Operator{
        using Operator::Operator;
        private:
            void execute() override; 
    };
    class Mod : private Operator{
        using Operator::Operator;
        private:
            void execute() override; 
    };
    class Factorial : private Operator{
        using Operator::Operator;
        private:
            void execute() override; 
    };
};


#endif