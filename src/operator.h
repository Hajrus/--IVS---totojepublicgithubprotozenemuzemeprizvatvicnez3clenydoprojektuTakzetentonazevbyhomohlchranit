#ifndef OPERATOR_H
#define OPERATOR_H

#include "ivs.h"

namespace IVS{
    class Plus : public, private Operator{
        using Operator::Operator;
        private:
            void execute() override; 
    };
    class Minus : public, private Operator{
        using Operator::Operator;
        private:
            void execute() override; 
    };
    class Multiply : public, private Operator{
        using Operator::Operator;
        private:
            void execute() override; 
    };
    class Divide : public, private Operator{
        using Operator::Operator;
        private:
            void execute() override; 
    };
    class Power : public, private Operator{
        using Operator::Operator;
        private:
            void execute() override; 
    };
    class Sqrt : public, private Operator{
        using Operator::Operator;
        private:
            void execute() override; 
    };
    class Mod : public, private Operator{
        using Operator::Operator;
        private:
            void execute() override; 
    };
    class Factorial : public, private Operator{
        using Operator::Operator;
        private:
            void execute() override; 
    };
};


#endif