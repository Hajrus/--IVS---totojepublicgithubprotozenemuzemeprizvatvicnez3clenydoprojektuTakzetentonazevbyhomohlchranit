/*********************************************************************************************************
 * Název projektu: IVS - Kalkulačka
 * Soubor: stddev.cpp
 * Datum: 25.03. 2020
 * Poslední změna: 23.04. 2020
 * Autoři: Kliš Michal (xklism00)
 *          Flek David (xflekd00)
 *          Široký Ondřej (xsirok09)
 *          Sladký Jan (xsladk09)
 * 
 * Popis: Testy matematické knihovny
 * 
 * *******************************************************************************************************/

/**
 * @file MathTest.cpp
 * @author Kliš Michal (xklism00)
 * @author Flek David (xflekd00)
 * @author Široký Ondřej (xsirok09)
 * @author Sladký Jan (xsladk09)
 * 
 * @brief Testy matematické knihovny
 */
#include "gtest/gtest.h"
#include "Math.h"

using namespace Math;

TEST(MathTests, Addition)
{
    EXPECT_DOUBLE_EQ(Add(100, 200), 300);
    EXPECT_DOUBLE_EQ(Add(100, -200), -100);
    EXPECT_DOUBLE_EQ(Add(-18, 200), 182);
    EXPECT_DOUBLE_EQ(Add(1.897, 3.54), 5.437);
    EXPECT_DOUBLE_EQ(Add(-95, 64.3), -30.7);
}

TEST(MathTests, Subtraction)
{
    EXPECT_DOUBLE_EQ(Sub(100, 200), -100);
    EXPECT_DOUBLE_EQ(Sub(100, -200), 300);
    EXPECT_DOUBLE_EQ(Sub(-18, 200), -218);
    EXPECT_DOUBLE_EQ(Sub(1.897, 3.54), -1.643);
    EXPECT_DOUBLE_EQ(Sub(-95, 64.3), -159.3);
}

TEST(MathTests, Multiplication)
{
    EXPECT_DOUBLE_EQ(Mult(100, 200), 20000);
    EXPECT_DOUBLE_EQ(Mult(100, -200), -20000);
    EXPECT_DOUBLE_EQ(Mult(-18, 200), -3600);
    EXPECT_DOUBLE_EQ(Mult(1.897, 3.54), 6.71538);
    EXPECT_DOUBLE_EQ(Mult(-95, 64.3), -6108.5);    
}

TEST(MathTests, Division)
{
    EXPECT_DOUBLE_EQ(Div(100, 200), 0.5);
    EXPECT_DOUBLE_EQ(Div(100, -200), -0.5);
    EXPECT_DOUBLE_EQ(Div(-18, 200), -0.09);
    EXPECT_DOUBLE_EQ(Div(1.897, 5), 0.3794);
    EXPECT_DOUBLE_EQ(Div(-95, 4), -23.75);
    EXPECT_ANY_THROW(Div(7.547963, 0));
    
}

TEST(MathTests, Factorial)
{
    EXPECT_DOUBLE_EQ(Factorial(0), 1);
    EXPECT_DOUBLE_EQ(Factorial(1), 1);
    EXPECT_DOUBLE_EQ(Factorial(2), 2);
    EXPECT_DOUBLE_EQ(Factorial(3), 6);
    EXPECT_DOUBLE_EQ(Factorial(13), 6227020800);
}
 
TEST(MathTests, Power)
{
    EXPECT_DOUBLE_EQ(Power(5, 4), 625);
    EXPECT_DOUBLE_EQ(Power(2.3, 7), 340.4825447);
    EXPECT_DOUBLE_EQ(Power(-6, 8), 1679616);
    EXPECT_DOUBLE_EQ(Power(-9, 5), -59049);
    EXPECT_DOUBLE_EQ(Power(-1.4, 4), 3.8416);
}

TEST(MathTests, GeneralRoot)
{
    EXPECT_NEAR(GeneralRoot(8, 2), 2.82842712474619, 1e-5);
    EXPECT_DOUBLE_EQ(GeneralRoot(9, 2), 3);
    EXPECT_NEAR(GeneralRoot(5, 4), 1.4953487812212, 1e-5);
    EXPECT_NEAR(GeneralRoot(65, 7),1.8154639203537, 1e-5);
    EXPECT_NEAR(GeneralRoot(19987, 2), 141.3753868252, 1e-5);
}

TEST(MathTests, ModuloOperation)
{
    EXPECT_DOUBLE_EQ(Mod(-7, -8), -7);
    EXPECT_DOUBLE_EQ(Mod(54, -8), 6);
    EXPECT_DOUBLE_EQ(Mod(13, 13), 0);
    EXPECT_DOUBLE_EQ(Mod(-9, 5), -4);
    EXPECT_DOUBLE_EQ(Mod(78, 7), 1);
    EXPECT_ANY_THROW(Mod(5, 0));
    
}