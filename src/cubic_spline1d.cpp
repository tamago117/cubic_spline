#include "cubic_spline1d.hpp"
#include <algorithm>

CppCubicSpline1D::CppCubicSpline1D(std::vector<double> x, std::vector<double> y)
{
    this->x_vec = x;
    updateParameter(y);
}

template <class T> void CppCubicSpline1D::updateParameter(const T &y)
{
    a_.clear();
    b_.clear();
    c_.clear();
    d_.clear();
    w_.clear();

    ndata = y.size()-1;
    for(int i = 0; i <= ndata; ++i){
        a_.push_back(y[i]);
    }

    for(int i = 0; i < ndata; ++i){
        if(i == 0){
            c_.push_back(0.0);
        }else if(i == ndata){
            c_.push_back(0.0);
        }else{
            c_.push_back(3.0*(a_[i-1] - 2.0*a_[i] + a_[i+1]));
        }
    }

    for(int i = 0; i < ndata; ++i){
        if(i == 0){
            w_.push_back(0.0);
        }else{
            double tmp = 4.0 - w_[i-1];
            c_[i] = (c_[i]-c_[i-1])/tmp;
            w_.push_back(1.0/tmp);
        }
    }

    for(int i = ndata-1; i > 0; --i){
        c_[i] = c_[i] - c_[i+1]*w_[i];
    }

    for(int i = 0; i <= ndata; ++i){
        if(i == ndata){
            d_.push_back(0.0);
            b_.push_back(0.0);
        }else{
            d_.push_back((c_[i+1] - c_[i])/3.0);
            b_.push_back(a_[i+1] - a_[i] - c_[i] - d_[i]);
        }
    }
}

double CppCubicSpline1D::calc_pos(double x)
{
    if(ndata == -1){
        return 0;
    }

    if(x < x_vec.front()){
        return 0;
    }else if(x > x_vec.back()){
        return 0;
    }

    int j = int(floor(x));
    if(j < 0){
        j = 0;
    }else if(j >= a_.size()){
        j = (a_.size()-1);
    }
    double dt = x - j;

    return a_[j] + (b_[j] + (c_[j] + d_[j]*dt)*dt)*dt;
}

double CppCubicSpline1D::calc_first_derivative(double x)
{
    if(ndata == -1){
        return 0;
    }

    if(x < x_vec.front()){
        return 0;
    }else if(x > x_vec.back()){
        return 0;
    }

    int j = int(floor(x));
    if(j < 0){
        j = 0;
    }else if(j >= a_.size()){
        j = (a_.size()-1);
    }
    double dt = x - j;

    return b_[j] + (2.0*c_[j] + 3.0*d_[j]*dt)*dt;
}

double CppCubicSpline1D::calc_second_derivative(double x)
{
    if(ndata == -1){
        return 0;
    }

    if(x < x_vec.front()){
        return 0;
    }else if(x > x_vec.back()){
        return 0;
    }

    int j = int(floor(x));
    if(j < 0){
        j = 0;
    }else if(j >= a_.size()){
        j = (a_.size()-1);
    }
    double dt = x - j;

    return 2.0*c_[j] + 6.0*d_[j]*dt;
}