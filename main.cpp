#include <string>
#include <vector>
#include <iostream>
#include "cubic_spline2d.hpp"
#include "matplotlibcpp.h"

namespace plt = matplotlibcpp;

int main(int argc, char **argv)
{
    std::vector<double> x{1.0, 2.0, 3.0, 5.0, 8.0, 10.0, 5.0, 0.0};
    std::vector<double> y{1.0, 3.0, 7.0, 3.0, 6.0, 7.0, 13.0, 10.0};

    CppCubicSpline2D cppCubicSpline2D(x, y);
    std::vector<std::vector<double>> output_path;
    cppCubicSpline2D.calc_spline_course(output_path);

    std::vector<double> rx;
    std::vector<double> ry;
    for (int i = 0; i < output_path.size(); i++)
    {
        rx.push_back(output_path[i][0]);
        ry.push_back(output_path[i][1]);
    }

    /*std::vector<double> x{0,1,2,3};
    std::vector<double> y{2.7,6,5,6.5};
    CppCubicSpline1D cppCubicSpline(sx, sy);
    std::vector<double> rx;
    std::vector<double> ry;
    for(double i=0.0;i<=sy.size();i+=0.1){
       rx.push_back(i);
       ry.push_back(cppCubicSpline.calc_pos(i));
    }*/

    plt::scatter(x, y, 10);
    plt::plot(rx, ry);
    plt::show();

    return 0;
}