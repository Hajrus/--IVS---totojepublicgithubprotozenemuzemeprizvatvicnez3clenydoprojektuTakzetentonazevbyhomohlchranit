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
 * Description: Header file of math library
 * 
 * *******************************************************************************************************/

#ifndef MATH_LIB_H_
#define MATH_LIB_H_

#include <math.h>

/**
 * @file Math.h
 * @author Kliš Michal (xklism00)
 * @author Flek David (xflekd00)
 * @author Široký Ondřej (xsirok09)
 * @author Sladký Jan (xsladk09)
 * 
 * @brief Math header file - math library
 */


/**
 * Math, implementation of mathematical library for Calculator 
 * with basic mathematical operations
 * 
 * @brief Math - Calculator with basic mathematical operations
 */  
namespace Math
{
    /**
     * @brief Add
     * Addition
     * @param firstOperand First operand of addition
     * @param secondOperand Second operand of addition
     * @return returns the result of the addition
     */
    double Add(double firstOperand, double secondOperand);

    /**
     * @brief Sub
     * Subtraction
     * @param firstOperand First operand of subtraction
     * @param secondOperand Second operand of subtraction
     * @return returns the result of the subtraction
     */
    double Sub(double firstOperand, double secondOperand);
    
    /**
     * @brief Mult
     * Multiplication
     * @param firstOperand First operand of multiplication
     * @param secondOperand Second operand of multiplication
     * @return returns the result of the multiplication
     */
    double Mult(double firstOperand, double secondOperand);
    
    /**
     * @brief Div
     * Division
     * @param numer Value of the quotient numerator
     * @param denom Value of the quotient denominator
     * @return returns the result of the division
     */
    double Div(double numer, double denom);

    /**
     * @brief Factorial
     * @param n nonnegative integer
     * @return returns the result of the factorial
     */
    unsigned long long Factorial(unsigned int n);

    /**
     * @brief Power
     * Power - For b^a -  a-th power of b.
     * @param base Base of a power
     * @param exponent Exponent of a power
     * @return returns the result of a power
     */
    double Power(double base, unsigned int exponent);

    /**
     * @brief GeneralRoot
     * General root - n√x -  n-th root of a number x.
     * @param x n√x -  n-th root of a number x
     * @param n n√x -  n-th root of a number x
     * @return returns the result of  General root
     */
    double GeneralRoot(double x, double n);
    
    /**
     * @brief Mod
     * Modulo operation
     * @param numer Value of the quotient numerator
     * @param denom Value of the quotient denominator.
     * @return returns the remainder of dividing the arguments
     */
    int Mod(int numer, int denom);
};

#endif /* MATH_LIB_H_ */