#pragma once
#include "PathDependentOption.h"
#include <vector>
class AsianArithmetic : public PathDependentOption
{
public:
	AsianArithmetic();
	AsianArithmetic(double const& K, double const& T);

	double payoff(std::vector<double> const& prices_vector) const;
	void print() const;
	~AsianArithmetic();

private:
	std::vector<double> prices_vector;
	
};

