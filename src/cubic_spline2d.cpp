#include "cubic_spline2d.hpp"
#include <iostream>

template <class T> CppCubicSpline2D::CppCubicSpline2D(const std::vector<T> &x, const std::vector<T> &y) : sx(calc_s(x, y), x), sy(calc_s(x, y), y)
{
    //error checking
    if(x.size() != y.size()){
        std::cerr << "vector size mismatch" << std::endl;
    }
    if(x.size() <= 2){
        std::cerr << "vector size must be more than 2" << std::endl;
    }

    distances = calc_s(x, y);
}

void CppCubicSpline2D::calc_spline_course(std::vector<std::vector<double>>& output_path, float ds)
{
    output_path.clear();

    double s;
    while(true)
    {
        s += ds;
        distances.push_back(s);
        std::vector<double> point(3);
        point[0] = sx.calc_pos(s);    //x
        point[1] = sy.calc_pos(s);    //y
        point[2] = calc_yaw(s);       //angle
        point[3] = calc_curvature(s); //curvature
        output_path.push_back(point);

        if(s > distances.back()){
            break;
        }
    }
}

std::vector<double> CppCubicSpline2D::calc_s(const std::vector<double>& x, const std::vector<double>& y)
{
    std::vector<double> distance_vec{0};

    int length = x.size();
    for(int i=1; i<length; ++i)
    {
        double ds = sqrt(pow(x[i+1]-x[i], 2) + pow(y[i+1]-y[i], 2));
        distance_vec.push_back(ds);
    }

    return distance_vec;
}

double CppCubicSpline2D::calc_curvature(double s)
{
    double dx = sx.calc_first_derivative(s);
    double ddx = sx.calc_second_derivative(s);
    double dy = sy.calc_first_derivative(s);
    double ddy = sy.calc_second_derivative(s);

    return (ddy*dx - ddx*dy) / pow(pow(dx, 2) + pow(dy, 2), 1.5);
}

double CppCubicSpline2D::calc_yaw(double s)
{
    double dx = sx.calc_first_derivative(s);
    double dy = sy.calc_first_derivative(s);

    return atan2(dy, dx);
}