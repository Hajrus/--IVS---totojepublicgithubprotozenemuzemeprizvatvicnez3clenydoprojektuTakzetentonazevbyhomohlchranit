#ifndef OPERATOR_H
#define OPERATOR_H

#include "ivs.h"

namespace IVS{
    class Plus : public Operator{
        using Operator::Operator;
        private:
            void execute(); 
    };
    class Minus : public Operator{
        using Operator::Operator;
        private:
            void execute(); 
    };
    class Multiply : public Operator{
        using Operator::Operator;
        private:
            void execute(); 
    };
    class Divide : public Operator{
        using Operator::Operator;
        private:
            void execute(); 
    };
    class Power : public Operator{
        using Operator::Operator;
        private:
            void execute(); 
    };
    class Sqrt : public Operator{
        using Operator::Operator;
        private:
            void execute(); 
    };
    class Mod : public Operator{
        using Operator::Operator;
        private:
            void execute(); 
    };
    class Factorial : public Operator{
        using Operator::Operator;
        private:
            void execute(); 
    };
};


#endif