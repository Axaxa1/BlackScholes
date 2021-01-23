#include "Complex.h"

Complex::Complex()
{
	max_T = 0;
}

Complex::Complex(std::string const& name)
{
	max_T = 0;
	this->name = name;
}

void Complex::buyOption(EuropeanCall const& option)
{
	european_call.push_back(EuropeanCall(option));
	max_T = std::max(max_T, option.getMaturity());
}

void Complex::buyOption(EuropeanPut const& option)
{
	european_put.push_back(EuropeanPut(option));
	max_T = std::max(max_T, option.getMaturity());
}

void Complex::buyOption(DigitalCall const& option)
{
	digital_call.push_back(DigitalCall(option));
	max_T = std::max(max_T, option.getMaturity());
}

void Complex::buyOption(DigitalPut const& option)
{
	digital_put.push_back(DigitalPut(option));
	max_T = std::max(max_T, option.getMaturity());
}

void Complex::buyOption(AsianArithmeticCall const& option)
{
	asian_arithmetic_call.push_back(AsianArithmeticCall(option));
	max_T = std::max(max_T, option.getMaturity());
}

void Complex::buyOption(AsianArithmeticPut const& option)
{
	asian_arithmetic_put.push_back(AsianArithmeticPut(option));
	max_T = std::max(max_T, option.getMaturity());
}

void Complex::buyOption(AsianGeometricCall const& option)
{
	asian_geometric_call.push_back(AsianGeometricCall(option));
	max_T = std::max(max_T, option.getMaturity());
}

void Complex::buyOption(AsianGeometricPut const& option)
{
	asian_geometric_put.push_back(AsianGeometricPut(option));
	max_T = std::max(max_T, option.getMaturity());
}

void Complex::buyOption(EuropeanCall const& option, double const& multiplier)
{
	EuropeanCall new_option = EuropeanCall(option);
	new_option.setMultiplier(multiplier);
	european_call.push_back(new_option);
	max_T = std::max(max_T, new_option.getMaturity());

}

void Complex::buyOption(EuropeanPut const& option, double const& multiplier)
{
	EuropeanPut new_option = EuropeanPut(option);
	new_option.setMultiplier(multiplier);
	european_put.push_back(new_option);
	max_T = std::max(max_T, new_option.getMaturity());
}

void Complex::buyOption(DigitalCall const& option, double const& multiplier)
{
	DigitalCall new_option = DigitalCall(option);
	new_option.setMultiplier(multiplier);
	digital_call.push_back(new_option);
	max_T = std::max(max_T, new_option.getMaturity());
}

void Complex::buyOption(DigitalPut const& option, double const& multiplier)
{
	DigitalPut new_option = DigitalPut(option);
	new_option.setMultiplier(multiplier);
	digital_put.push_back(new_option);
	max_T = std::max(max_T, new_option.getMaturity());
}

void Complex::buyOption(AsianArithmeticCall const& option, double const& multiplier)
{
	AsianArithmeticCall new_option = AsianArithmeticCall(option);
	new_option.setMultiplier(multiplier);
	asian_arithmetic_call.push_back(new_option);
	max_T = std::max(max_T, new_option.getMaturity());
}

void Complex::buyOption(AsianArithmeticPut const& option, double const& multiplier)
{
	AsianArithmeticPut new_option = AsianArithmeticPut(option);
	new_option.setMultiplier(multiplier);
	asian_arithmetic_put.push_back(new_option);
	max_T = std::max(max_T, new_option.getMaturity());
}

void Complex::buyOption(AsianGeometricCall const& option, double const& multiplier)
{
	AsianGeometricCall new_option = AsianGeometricCall(option);
	new_option.setMultiplier(multiplier);
	asian_geometric_call.push_back(new_option);
	max_T = std::max(max_T, new_option.getMaturity());
}

void Complex::buyOption(AsianGeometricPut const& option, double const& multiplier)
{
	AsianGeometricPut new_option = AsianGeometricPut(option);
	new_option.setMultiplier(multiplier);
	asian_geometric_put.push_back(new_option);
	max_T = std::max(max_T, new_option.getMaturity());
}

/*Complex Complex::operator=(Complex const& options)
{
	this->european_call = options.european_call;
	this->european_put = options.european_put;
	this->digital_call = options.digital_call;
	this->digital_put = options.digital_put;
	this->asian_arithmetic_call = options.asian_arithmetic_call;
	this->asian_arithmetic_put = options.asian_arithmetic_put;
	this->asian_geometric_call = options.asian_geometric_call;
	this->asian_geometric_put = options.asian_geometric_put;

	this->max_T = options.max_T;
	this->name = options.name;
}*/

Complex Complex::operator+(Complex const& options) const
{
	Complex res = sum(options);
	res.setName(name + " + " + options.getName());
	return res;
}

Complex& Complex::operator+=(Complex const& options)
{
	european_call.insert(european_call.end(), options.european_call.begin(), options.european_call.end());
	european_put.insert(european_put.end(), options.european_put.begin(), options.european_put.end());
	digital_call.insert(digital_call.end(), options.digital_call.begin(), options.digital_call.end());
	digital_put.insert(digital_put.end(), options.digital_put.begin(), options.digital_put.end());
	asian_arithmetic_call.insert(asian_arithmetic_call.end(), options.asian_arithmetic_call.begin(), options.asian_arithmetic_call.end());
	asian_arithmetic_put.insert(asian_arithmetic_put.end(), options.asian_arithmetic_put.begin(), options.asian_arithmetic_put.end());
	asian_geometric_call.insert(asian_geometric_call.end(), options.asian_geometric_call.begin(), options.asian_geometric_call.end());
	asian_geometric_put.insert(asian_geometric_put.end(), options.asian_geometric_put.begin(), options.asian_geometric_put.end());

	max_T = std::max(max_T, options.max_T);
	name +=  " + " + options.getName();

	return *this;
}

Complex Complex::operator-(Complex const& options) const
{
	Complex res = Complex(options);
	res.setMultiplier(-1);
	res = sum(res);
	res.setName(name + " - " + options.getName());
	return res;
}

Complex& Complex::operator-=(Complex const& options)
{
	Complex copy(options);
	copy.setMultiplier(-1);
	european_call.insert(european_call.end(), copy.european_call.begin(), copy.european_call.end());
	european_put.insert(european_put.end(), copy.european_put.begin(), copy.european_put.end());
	digital_call.insert(digital_call.end(), copy.digital_call.begin(), copy.digital_call.end());
	digital_put.insert(digital_put.end(), copy.digital_put.begin(), copy.digital_put.end());
	asian_arithmetic_call.insert(asian_arithmetic_call.end(), copy.asian_arithmetic_call.begin(), copy.asian_arithmetic_call.end());
	asian_arithmetic_put.insert(asian_arithmetic_put.end(), copy.asian_arithmetic_put.begin(), copy.asian_arithmetic_put.end());
	asian_geometric_call.insert(asian_geometric_call.end(), copy.asian_geometric_call.begin(), copy.asian_geometric_call.end());
	asian_geometric_put.insert(asian_geometric_put.end(), copy.asian_geometric_put.begin(), copy.asian_geometric_put.end());

	max_T = std::max(max_T, copy.max_T);
	name += " - " + copy.getName();

	return *this;
}

Complex Complex::operator*(double const& x)
{
	this->setMultiplier(x);
	return *this;
}

Complex Complex::operator/(double const& x)
{
	this->setMultiplier(1/x);
	return *this;
}

double Complex::getMaturity() const
{
	return max_T;
}

std::string Complex::getName() const
{
	return name;
}

void Complex::setName(std::string const& name)
{
	this->name = name;
}

void Complex::setMultiplier(double const& multiplier)
{
	for (int i = 0; i < static_cast<int>(european_call.size()); i++) {
		european_call[i].setMultiplier(european_call[i].getMultiplier() * multiplier);
	}
	for (int i = 0; i < static_cast<int>(european_put.size()); i++) {
		european_put[i].setMultiplier(european_put[i].getMultiplier() * multiplier);
	}
	for (int i = 0; i < static_cast<int>(digital_call.size()); i++) {
		digital_call[i].setMultiplier(digital_call[i].getMultiplier() * multiplier);
	}
	for (int i = 0; i < static_cast<int>(digital_put.size()); i++) {
		digital_put[i].setMultiplier(digital_put[i].getMultiplier() * multiplier);
	}
	for (int i = 0; i < static_cast<int>(asian_arithmetic_call.size()); i++) {
		asian_arithmetic_call[i].setMultiplier(asian_arithmetic_call[i].getMultiplier() * multiplier);
	}
	for (int i = 0; i < static_cast<int>(asian_arithmetic_put.size()); i++) {
		asian_arithmetic_put[i].setMultiplier(asian_arithmetic_put[i].getMultiplier() * multiplier);
	}
	for (int i = 0; i < static_cast<int>(asian_geometric_call.size()); i++) {
		asian_geometric_call[i].setMultiplier(asian_geometric_call[i].getMultiplier() * multiplier);
	}
	for (int i = 0; i < static_cast<int>(asian_geometric_put.size()); i++) {
		asian_geometric_put[i].setMultiplier(asian_geometric_put[i].getMultiplier() * multiplier);
	}
}

double Complex::payoff(std::vector<double> const& prices_vector) const
{
	double sum = 0.0;
	for (int i = 0; i < static_cast<int>(european_call.size()); i++) {
		sum += european_call[i].payoff(prices_vector);
	}
	for (int i = 0; i < static_cast<int>(european_put.size()); i++) {
		sum += european_put[i].payoff(prices_vector);
	}
	for (int i = 0; i < static_cast<int>(digital_call.size()); i++) {
		sum += digital_call[i].payoff(prices_vector);
	}
	for (int i = 0; i < static_cast<int>(digital_put.size()); i++) {
		sum += digital_put[i].payoff(prices_vector);
	}
	for (int i = 0; i < static_cast<int>(asian_arithmetic_call.size()); i++) {
		sum += asian_arithmetic_call[i].payoff(prices_vector);
	}
	for (int i = 0; i < static_cast<int>(asian_arithmetic_put.size()); i++) {
		sum += asian_arithmetic_put[i].payoff(prices_vector);
	}
	for (int i = 0; i < static_cast<int>(asian_geometric_call.size()); i++) {
		sum += asian_geometric_call[i].payoff(prices_vector);
	}
	for (int i = 0; i < static_cast<int>(asian_geometric_put.size()); i++) {
		sum += asian_geometric_put[i].payoff(prices_vector);
	}
	return sum;
}

void Complex::print() const
{
	std::cout << "** Complex Option : "<< name << " ** "<< std::endl;
	std::cout << "Max maturity : " << max_T << std::endl;
	std::cout << "Composed of " << std::endl;
	for (int i = 0; i < static_cast<int>(european_call.size()); i++) {
		std::cout << "* ";
		european_call[i].print();
	}
	for (int i = 0; i < static_cast<int>(european_put.size()); i++) {
		std::cout << "* ";
		european_put[i].print();
	}
	for (int i = 0; i < static_cast<int>(digital_call.size()); i++) {
		std::cout << "* ";
		digital_call[i].print();
	}
	for (int i = 0; i < static_cast<int>(digital_put.size()); i++) {
		std::cout << "* ";
		digital_put[i].print();
	}
	for (int i = 0; i < static_cast<int>(asian_arithmetic_call.size()); i++) {
		std::cout << "* ";
		asian_arithmetic_call[i].print();
	}
	for (int i = 0; i < static_cast<int>(asian_arithmetic_put.size()); i++) {
		std::cout << "* ";
		asian_arithmetic_put[i].print();
	}
	for (int i = 0; i < static_cast<int>(asian_geometric_call.size()); i++) {
		std::cout << "* ";
		asian_geometric_call[i].print();
	}
	for (int i = 0; i < static_cast<int>(asian_geometric_put.size()); i++) {
		std::cout << "* ";
		asian_geometric_put[i].print();
	}
}

Complex::~Complex()
{
}

Complex Complex::sum(Complex const& options) const
{
	Complex res = Complex(options);
	res.european_call.insert(res.european_call.end(), european_call.begin(), european_call.end());
	res.european_put.insert(res.european_put.end(), european_put.begin(), european_put.end());
	res.digital_call.insert(res.digital_call.end(), digital_call.begin(), digital_call.end());
	res.digital_put.insert(res.digital_put.end(), digital_put.begin(), digital_put.end());
	res.asian_arithmetic_call.insert(res.asian_arithmetic_call.end(), asian_arithmetic_call.begin(), asian_arithmetic_call.end());
	res.asian_arithmetic_put.insert(res.asian_arithmetic_put.end(), asian_arithmetic_put.begin(), asian_arithmetic_put.end());
	res.asian_geometric_call.insert(res.asian_geometric_call.end(), asian_geometric_call.begin(), asian_geometric_call.end());
	res.asian_geometric_put.insert(res.asian_geometric_put.end(), asian_geometric_put.begin(), asian_geometric_put.end());
	
	res.max_T = std::max(res.max_T, max_T);

	return res;
}
