#include <iostream>
#include <gtest/gtest.h>
#include "example.h"
#include "triangle.h"

using namespace std;

TEST(Example, foo_1)
{
	Example ex;
	ASSERT_EQ(1,ex.foo());
}

TEST(Example, foo_2)
{
	Example ex;
	ASSERT_NE(0,ex.foo());
}

TEST(Triangle, Equilateral)
{
    ASSERT_EQ(1, triangle(1, 1, 1)); // Equilateral triangle
}

TEST(Triangle, Isosceles)
{
    ASSERT_EQ(2, triangle(2, 2, 3)); // Isosceles triangle
}

TEST(Triangle, Scalene)
{
    ASSERT_EQ(3, triangle(3, 4, 5)); // Scalene triangle
}

TEST(Triangle, EquilateralDuplicate)
{
    ASSERT_EQ(1, triangle(1, 1, 1));
}

TEST(Triangle, InvalidTriangle_SumOfTwoSidesEqualThird)
{
    ASSERT_EQ(-1, triangle(1, 1, 2));
}

TEST(Triangle, InvalidTriangle_SumOfTwoSidesLessThanThird)
{
    ASSERT_EQ(-1, triangle(1, 2, 3));
}

TEST(Triangle, InvalidTriangle_SumOfTwoSidesLessThanThird_2)
{
    ASSERT_EQ(-1, triangle(1, 3, 2));
}

TEST(Triangle, InvalidTriangle_ZeroLengthSide)
{
    ASSERT_EQ(-1, triangle(1, 0, 2));
}

TEST(Triangle, InvalidTriangle_SumOfTwoSidesEqualThird_2)
{
    ASSERT_EQ(-1, triangle(1, 1, 3));
}

int main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
