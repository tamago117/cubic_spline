#pragma once
#include <vector>
#include <math.h>
#include <iostream>
#include "cubic_spline1d.hpp"

/**
 *  @brief Cubic Spline header library
 *
 *  @usage
 *    vector<double> sy{2.7,6,5,6.5};
 *    CppCubicSpline cppCubicSpline(sy);
 *    vector<double> rx;
 *    vector<double> ry;
 *    for(double i=0.0;i<=3.2;i+=0.1){
 *       rx.push_back(i);
 *       ry.push_back(cppCubicSpline.Calc(i));
 *    }
**/

class CppCubicSpline2D
{
    public:
        CppCubicSpline2D(const std::vector<double> &x, const std::vector<double> &y);
        void calc_spline_course(std::vector<std::vector<double>>& output_path, float ds = 0.1);
    private:
        std::vector<double> distances;
        std::vector<double> x_vec;
        CppCubicSpline1D sx;
        CppCubicSpline1D sy;

        std::vector<double> calc_s(const std::vector<double>& x, const std::vector<double>& y);
        double calc_curvature(double s);
        double calc_yaw(double s);
};

