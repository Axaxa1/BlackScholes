#include "Asian.h"
#include <iostream>

AsianArithmetic::AsianArithmetic()
{
	this->setStrike(100);
	this->setMaturity(1);
}

AsianArithmetic::AsianArithmetic(double const& K, double const& T)
{
	this->setStrike(K);
	this->setMaturity(T);
}

double AsianArithmetic::payoff(std::vector<double> const& prices_vector) const
{
	double mean = 0;
	for (int i = 0; i < static_cast<int>(prices_vector.size()); i++) {
		mean += prices_vector[i];
	}
	return mean / static_cast<double>(prices_vector.size());
}

void AsianArithmetic::print() const
{
	std::cout << "-- Asian Option --" << std::endl;
	PathDependentOption::print();
}

AsianArithmetic::~AsianArithmetic()
{
}
