#include "gtest/gtest.h"
#include "Math.h"

class MathTests : public ::testing::Test
{
    protected:
        Math m;
};
 
TEST_F(MathTests, Addition)
{
    EXPECT_EQ(m.Add(100, 200), 300);
    EXPECT_EQ(m.Add(100, -200), -100);
    EXPECT_EQ(m.Add(-18, 200), 182);
    EXPECT_EQ(m.Add(1.897, 3.54), 5.437);
    EXPECT_EQ(m.Add(-95, 64.3), -30.7);
}

TEST_F(MathTests, Subtraction)
{
    EXPECT_EQ(m.Sub(100, 200), -100);
    EXPECT_EQ(m.Sub(100, -200), 300);
    EXPECT_EQ(m.Sub(-18, 200), -218);
    EXPECT_EQ(m.Sub(1.897, 3.54), -1.643);
    EXPECT_EQ(m.Sub(-95, 64.3), -159.3);
}

TEST_F(MathTests, Multiplication)
{
    EXPECT_EQ(m.Mult(100, 200), 20000);
    EXPECT_EQ(m.Mult(100, -200), -20000);
    EXPECT_EQ(m.Mult(-18, 200), -3600);
    EXPECT_EQ(m.Mult(1.897, 3.54), 6.71538);
    EXPECT_EQ(m.Mult(-95, 64.3), -6108.5);
    
}

TEST_F(MathTests, Division)
{
    EXPECT_EQ(m.Div(100, 200), 0.5);
    EXPECT_EQ(m.Div(100, -200), -0.5);
    EXPECT_EQ(m.Div(-18, 200), -0.09);
    EXPECT_EQ(m.Div(1.897, 5), 0.3794);
    EXPECT_EQ(m.Div(-95, 4), -23.75);
    
}

TEST_F(MathTests, Factorial)
{
    EXPECT_EQ(m.Factorial(0), 1);
    EXPECT_EQ(m.Factorial(1), 1);
    EXPECT_EQ(m.Factorial(2), 2);
    EXPECT_EQ(m.Factorial(3), 6);
    EXPECT_EQ(m.Factorial(13), 6227020800);    
}
 
TEST_F(MathTests, Power)
{
    EXPECT_EQ(m.Power(5, 4), 625);
    EXPECT_EQ(m.Power(2.3, 7), 340.4825447);
    EXPECT_EQ(m.Power(-6, 8), -1679616);
    EXPECT_EQ(m.Power(-9, 5), -59049);
    EXPECT_EQ(m.Power(-1.4, 4), 3.8416);
}

TEST_F(MathTests, GeneralRoot)
{
    
}

TEST_F(MathTests, ModuloOperation)
{
    EXPECT_EQ(m.Mod(-7, -8), -7);
    EXPECT_EQ(m.Mod(54, -8), 6);
    EXPECT_EQ(m.Mod(13, 13), 0);
    EXPECT_EQ(m.Mod(-9, 5), -4);
    EXPECT_EQ(m.Mod(78, 7), 1);
    
}