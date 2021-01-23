#include "Price_CI.h"
#include <iostream>
#include <cmath>
Price_CI::Price_CI() {
    this->price = 0.0;
    this->stdev = 0.0;
    this->num_sims = 1;
}
Price_CI::Price_CI(const double &price, const double &stdev, const double &num_sims) {
    this->price = price;
    this->stdev = stdev;
    this->num_sims = num_sims;
}

double Price_CI::compute_lb() const {
    return price - sqrt(stdev / static_cast<double>(num_sims)) * 1.960;
}

double Price_CI::compute_ub() const {
    return price + sqrt(stdev / static_cast<double>(num_sims)) * 1.960;
}

void Price_CI::print_CI() const {
    double lb = compute_lb();
    double ub = compute_ub();
    std::cout<<"Estimated price : "<<price<<std::endl;
    std::cout<<"Asymptotic Confidence Interval at level 95% : ";
    std::cout<<"["<<lb<<" , "<<ub<<"]"<<std::endl<<std::endl;
}

