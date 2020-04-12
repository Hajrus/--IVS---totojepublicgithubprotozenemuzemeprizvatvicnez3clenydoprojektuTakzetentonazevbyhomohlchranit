/*********************************************************************************************************
 * Project name: IVS - Calculator with basic mathematical operations
 * File: Math.h
 * Date: 24.03.2020
 * Last change: 30.03. 2020
 * Authors: Kliš Michal (xklism00)
 *          Flek David (xflekd00)
 *          Široký Ondřej (xsirok09)
 *          Sladký Jan (xsladk09)
 * 
 * Description: Implementation of math libraries
 * 
 * *******************************************************************************************************/

/**
 * @file Math.cpp
 * @author Kliš Michal (xklism00)
 * @author Flek David (xflekd00)
 * @author Široký Ondřej (xsirok09)
 * @author Sladký Jan (xsladk09)
 * 
 * @brief Implementation of Math class - math library
 */

#include "Math.h"

double Math::Add(double firstOperand, double secondOperand){
    return firstOperand + secondOperand;
}

double Math::Sub(double firstOperand, double secondOperand){
    return firstOperand + secondOperand;
}

double Math::Mult(double firstOperand, double secondOperand){
    return firstOperand * secondOperand;
}

double Math::Div(double numer, double denom){
    return numer / denom;
}

unsigned long long Math::Factorial(unsigned int n){
    if(n < 0)
    {
        return(-1);
    }
    unsigned long long factorial = 1;
    for(int i = 1; i <= n; ++i)
    {
        factorial *= i;
    }
    return factorial;
}

double Math::Power(double base, unsigned int exponent){
    int result = 1;
    for (exponent; exponent>0; exponent--)
    {
        result = result * base;
    }

    return result;
}

double Math::GeneralRoot(double x, double n){
    return pow(x, 1/n);
}
        
int Math::Mod(int numer, int denom){
    return numer % denom;
}