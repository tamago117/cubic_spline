#pragma once
#include <vector>
#include <math.h>
#include <iostream>

/**
 *  @brief Cubic Spline header library
 *
 *  @usage
 *    vector<double> sy{2.7,6,5,6.5};
 *    CppCubicSpline cppCubicSpline(sy);
 *    vector<double> rx;
 *    vector<double> ry;
 *    for(double i=0.0;i<=sy.size();i+=0.1){
 *       rx.push_back(i);
 *       ry.push_back(cppCubicSpline.Calc(i));
 *    }
**/

class CppCubicSpline1D
{
    private:
        std::vector<double> a_;
        std::vector<double> b_;
        std::vector<double> c_;
        std::vector<double> d_;
        std::vector<double> w_;
        int ndata;
        std::vector<double> x_vec;

        int search_index(double value);

    public:
        CppCubicSpline1D(std::vector<double> x, std::vector<double> y);
        template <class T> void updateParameter(const T &y);
        double calc_pos(double x);
        double calc_first_derivative(double x);
        double calc_second_derivative(double x);
};
