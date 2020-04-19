#ifndef OPERATOR_H
#define OPERATOR_H

#include "ivs.h"

namespace IVS{
    class Plus : public Operator{
        using Operator::Operator;
        private:
            void execute() override; 
    };
    class Minus : public Operator{
        using Operator::Operator;
        private:
            void execute() override; 
    };
    class Multiply : public Operator{
        using Operator::Operator;
        private:
            void execute() override; 
    };
    class Divide : public Operator{
        using Operator::Operator;
        private:
            void execute() override; 
    };
    class Power : public Operator{
        using Operator::Operator;
        private:
            void execute() override; 
    };
    class Sqrt : public Operator{
        using Operator::Operator;
        private:
            void execute() override; 
    };
    class Mod : public Operator{
        using Operator::Operator;
        private:
            void execute() override; 
    };
    class Factorial : public Operator{
        using Operator::Operator;
        private:
            void execute() override; 
    };
};


#endif