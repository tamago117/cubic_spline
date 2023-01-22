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
    cppCubicSpline2D.calc_spline_course(output_path, 0.1);

    std::vector<double> rx;
    std::vector<double> ry;
    for (int i = 0; i < output_path.size(); i++)
    {
        rx.push_back(output_path[i][0]);
        ry.push_back(output_path[i][1]);
    }

    plt::scatter(x, y, 10);
    plt::plot(rx, ry);
    for(int i=0;i<rx.size();i++){
        plt::arrow(rx[i], ry[i], 0.1*cos(output_path[i][2]), 0.1*sin(output_path[i][2]));
    }
    plt::show();

    return 0;
}