#include <string>
#include <vector>

#include <gtest/gtest.h>

#include "cubic_spline2d.hpp"

const double EPSILON = 0.01;


class CubicSplineTest : public ::testing::Test
{
 protected:
    CubicSplineTest() : cppCubicSpline2D(x, y)
    {
        cppCubicSpline2D.calc_spline_course(output_path, 0.1);
    }


    std::vector<double> x{1.0, 2.0, 3.0, 5.0, 8.0, 10.0, 5.0, 0.0};
    std::vector<double> y{1.0, 3.0, 7.0, 3.0, 6.0, 7.0, 13.0, 10.0};

    CppCubicSpline2D cppCubicSpline2D;
    std::vector<std::vector<double>> output_path;

};

TEST_F(CubicSplineTest, Test_pointNum)
{
    // x, y, yaw, curvature
    EXPECT_EQ(4, output_path.front().size());
}

TEST_F(CubicSplineTest, Test_pathOutput)
{
    EXPECT_LE(2, output_path.size());
}





/*
https://www.mathkuro.com/c-cpp/gtest-primer/

EXPECT_TRUE(condition);	condition == true	
EXPECT_FALSE(condition);	condition == false	
EXPECT_EQ(val1, val2);	val1 == val2	std::string比較可能
EXPECT_NE(val1, val2);	val1 != val2	std::string比較可能
EXPECT_LT(val1, val2);	val1 < val2	std::string比較可能
EXPECT_LE(val1, val2);	val1 <= val2	std::string比較可能
EXPECT_GT(val1, val2);	val1 > val2	std::string比較可能
EXPECT_GE(val1, val2);	val1 >= val2	std::string比較可能
EXPECT_STREQ(str1, str2);	二つの文字列が等しい	C文字列用(char*等)
EXPECT_STRNE(str1, str2);	二つの文字列が等しくない	C文字列用(char*等)
EXPECT_STRCASEEQ(str1, str2);	大文字小文字を無視した場合、二つの文字列が等しい	C文字列用(char*等)
EXPECT_STRCASENE(str1, str2);	大文字小文字を無視した場合、二つの文字列が等しくない	C文字列用(char*等)
EXPECT_THROW(func, exception);	funcが指定したexceptionを投げる	
EXPECT_ANY_THROW(func);	funcが何らかの例外を投げる。	
EXPECT_NO_THROW(func);	funcが一切例外を投げない。	
EXPECT_FLOAT_EQ(val1, val2);	2つのfloat値がほぼ等しい	4 ULPs 以内
EXPECT_DOUBLE_EQ(val1, val2);	2つのdouble値がほぼ等しい	4 ULPs 以内
EXPECT_NEAR(val1, val2, abs);	val1とval2の差がabs以内に収まる	
EXPECT_THAT(val, matcher);	googlemockのMatcherを使用する
*/