#pragma once
#ifndef BLACKSCHOLES_PRICE_CI_H
#define BLACKSCHOLES_PRICE_CI_H
#include <vector>

/*
The Price_CI class takes takes a price estimate, std deviation of prices obtained in Monte Carlo sims
 and number of simulations and allows to compute and print the estimated price as well as a 95% confidence level
 asymptotic confidence interval.
 The formula for the Confidence interval is estimate +- sqrt(stdev/num_sims) * q_0.975 where q_0.975 is
 the 0.975 quantile of the normal distrib.
*/
class Price_CI {
private:
    double price;
    double stdev;
    double num_sims;
    double compute_lb() const; // Compute lower bound of confidence interval
    double compute_ub() const; // Compute upper bound of confidence interval
public:
    Price_CI();
    Price_CI(double const& price, double const& stdev, double const& num_sims);
    void print_CI() const;
    void set_price(double price){this->price = price;};
    void set_stdev(double stdev){this->stdev = stdev;};
    void set_num_sims(int num_sims){this->num_sims = num_sims;};
    double get_lb() const {return compute_lb();};
    double get_ub() const {return compute_ub();};


};


#endif //BLACKSCHOLES_PRICE_CI_H
