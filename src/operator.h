#ifndef OPERATOR_H
#define OPERATOR_H

#include "ivs.h"

namespace IVS{
    /**
     * @brief Oprerátor pro sčítání
     * operátor pro základní matematickou operaci sčítání
     */  
    class Plus : public Operator{
        using Operator::Operator;
        public:
            Operand* execute(); 
    };
    /**
     * @brief Oprerátor pro odčítání
     * operátor pro základní matematickou operaci odčítání
     */  
    class Minus : public Operator{
        using Operator::Operator;
        public:
            Operand* execute(); 
    };
    /**
     * @brief Oprerátor pro násobení
     * operátor pro základní matematickou operaci násobení
     */  
    class Multiply : public Operator{
        using Operator::Operator;
        public:
            Operand* execute(); 
    };
    /**
     * @brief Oprerátor pro dělení
     * operátor pro základní matematickou operaci dělení
     */  
    class Divide : public Operator{
        using Operator::Operator;
        public:
            Operand* execute(); 
    };
    /**
     * @brief Oprerátor pro umocnění
     * operátor pro základní matematickou operaci umocnění
     */  
    class Power : public Operator{
        using Operator::Operator;
        public:
            Operand* execute(); 
    };
    /**
     * @brief Oprerátor pro odmocnění
     * operátor pro základní matematickou operaci odmocnění
     */
    class Sqrt : public Operator{
        using Operator::Operator;
        public:
            Operand* execute(); 
    };
    /**
     * @brief Oprerátor pro modulo
     * operátor pro matematickou operaci modulo
     */
    class Mod : public Operator{
        using Operator::Operator;
        public:
            Operand* execute(); 
    };
    /**
     * @brief Oprerátor pro výpočet faktoriálu
     * operátor pro výpočet faktoriálu. Obsahuje jen jeden operand.
     */
    class Factorial : public Operator{
        using Operator::Operator;
        public:
            Operand* execute(); 
    };
};


#endif