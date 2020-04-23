/*********************************************************************************************************
 * Název projektu: IVS - Kalkulačka
 * Soubor: Math.cpp
 * Datum: 24.03.2020
 * Poslední změna: 22.04. 2020
 * Autoři: Kliš Michal (xklism00)
 *          Flek David (xflekd00)
 *          Široký Ondřej (xsirok09)
 *          Sladký Jan (xsladk09)
 * 
 * Popis: Implementace knihovny zakladních matematckých operací
 * 
 * *******************************************************************************************************/

/**
 * @file Math.cpp
 * @author Kliš Michal (xklism00)
 * @author Flek David (xflekd00)
 * @author Široký Ondřej (xsirok09)
 * @author Sladký Jan (xsladk09)
 * 
 * @brief Knihovna zakladních matematckých operací
 */

#include <cmath> 
#include "Math.h"


double Math::Add(double firstOperand, double secondOperand){
    return firstOperand + secondOperand;
}

double Math::Sub(double firstOperand, double secondOperand){
    return firstOperand - secondOperand;
}

double Math::Mult(double firstOperand, double secondOperand){
    return firstOperand * secondOperand;
}

double Math::Div(double numer, double denom){
    if(denom == 0)
    {
        throw("Nelze dělit nulou");
    }
    return numer / denom;
}

unsigned long long Math::Factorial(unsigned int n){
    unsigned long long factorial = 1;
    for(unsigned int i = 1; i <= n; ++i)
    {
        factorial *= i;
    }
    return factorial;
}

double Math::Power(double base, unsigned int exponent){
    double result = 1;
    for (; exponent>0; exponent--)
    {
        result = result * base;
    }

    return result;
}

double Math::GeneralRoot(double x, double n){
    return std::pow(x, 1/n);
}
        
int Math::Mod(int numer, int denom){
    if(denom == 0)
    {
        throw("Nelze dělit nulou");
    }
    return numer % denom;
}