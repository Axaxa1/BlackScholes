#include "MonteCarloPricer.h"
#include <iostream>


MonteCarloPricer::MonteCarloPricer()
{
	this->num_sims = 1000;
	this->n_steps = 250;
	this->prices_vector = new std::vector<double>(250, 0);
}

MonteCarloPricer::MonteCarloPricer(int const& num_sims)
{
	this->num_sims = num_sims;
	this->n_steps = 250;
	this->prices_vector = new std::vector<double>(250, 0);
}

MonteCarloPricer::MonteCarloPricer(int const& num_sims, int const& n_steps)
{
	this->num_sims = num_sims;
	this->n_steps = n_steps;
	this->prices_vector = new std::vector<double>(n_steps, 0);
}

void MonteCarloPricer::setNumSims(int const& num_sims)
{
	this->num_sims = 1000;
}

int MonteCarloPricer::getNumSims()
{
	return num_sims;
}

void MonteCarloPricer::showPrices()
{
	for (int i = 0; i < n_steps; i++) {
		std::cout << (*prices_vector)[i] << " ";
	}
	std::cout << std::endl;
}

MonteCarloPricer::~MonteCarloPricer()
{
	delete prices_vector;
}


