#include <string>
#include <vector>
#include <iostream>
#include "include/cubic_spline2d.hpp"
#include "include/matplotlibcpp.h"

namespace plt = matplotlibcpp;

int main(int argc, char **argv)
{
    std::vector<double> x{0.0, 4.0, 2.0, 3.0, 1.0};
    std::vector<double> y{0.0, 1.0, 2.0, 3.0, 1.0};

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

    plt::scatter(x, y);
    plt::plot(rx, ry);
    plt::show();

    return 0;
}