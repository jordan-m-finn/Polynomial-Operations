#include "Jordan_Finn_Polynomial.h"

// constructor
Polynomial::Polynomial() {}

// Comment 7:
// This function first, prompts the user to enter the number of polynomial terms.
// Second, the loop inputs the coefficient and exponent for each term by prompting
// the user for a coefficient and an exponent.
// Lastly, this stores the coefficient and exponent as a pair into a vector.
void Polynomial::enterTerms()
{
	int numOfPolynomials;
	
	std::cout << "Enter number of polynomial terms: ";
	std::cin >> numOfPolynomials;
	std::cout << std::endl;

	for (int i = 0; i < numOfPolynomials; ++i)
	{
		int coefficient;
		int exponent;

		std::cout << "Enter coefficient: ";
		std::cin >> coefficient;
		
		std::cout << "Enter exponent: ";
		std::cin >> exponent;

		coefficientAndExponent.push_back(std::make_pair(coefficient, exponent));

		std::cout << std::endl;
	}
}

// Comment 8:
// This function loops through each term in the Polynomial and displays
// them. If the end of the Polynomial has been reached 0 is displayed after
// the + sign.
void Polynomial::printPolynomial() const
{
	for (const auto& setOfCAndE : coefficientAndExponent)
	{
		std::cout << setOfCAndE.first << "x^" << setOfCAndE.second << "+";
	}
	std::cout << "0";
	std::cout << std::endl;
}

// Comment 9:
// This function overloads the assignment operator (+) to add
// two Polynomials. It does this by copying terms from both
// Polynomials to the result Polynomial.
Polynomial Polynomial::operator+(const Polynomial& p) const
{
	Polynomial result;

	for (const std::pair<int, int>& setOfCAndE : coefficientAndExponent)
	{
		result.coefficientAndExponent.push_back(setOfCAndE);
	}
	for (const std::pair<int, int>& setOfCAndE : p.coefficientAndExponent)
	{
		result.coefficientAndExponent.push_back(setOfCAndE);
	}

	return result;
}

// Comment 10:
// This function overloads the assignment operator (-) to subtract
// two Polynomials. It does this by copying terms from the first
// Polynomial and subtracting terms from the second.
Polynomial Polynomial::operator-(const Polynomial& p) const
{
	Polynomial result;

	for (const std::pair<int, int>& setOfCAndE : coefficientAndExponent)
	{
		result.coefficientAndExponent.push_back(setOfCAndE);
	}
	for (const std::pair<int, int>& setOfCAndE : p.coefficientAndExponent)
	{
		result.coefficientAndExponent.push_back(std::make_pair(-setOfCAndE.first, setOfCAndE.second));
	}

	return result;
}

// Comment 11:
// This function overloads the assignment operator (=) to set
// the Polynomial on the left of the = sign to the value of the
// Polynomial on the right.
Polynomial& Polynomial::operator=(const Polynomial& p)
{
	if (this != &p)
	{
		coefficientAndExponent = p.coefficientAndExponent;
	}
	return *this;
}

// Comment 12:
// This function overloads the assignment operator (+=) to add
// the Polynomial on the right of the += sign to the value of the
// Polynomial on the left and then stores that result in the same
// Polynomial.
Polynomial& Polynomial::operator+=(const Polynomial& p)
{
	for (const std::pair<int, int>& setOfCAndE : p.coefficientAndExponent)
	{
		bool found = false;
		for (auto& i : coefficientAndExponent)
		{
			if (i.second == setOfCAndE.second)
			{
				i.first += setOfCAndE.first;
				found = true;
				break;
			}
		}
		if (!found)
		{
			coefficientAndExponent.push_back(setOfCAndE);
		}
	}
	return *this;
}

// Comment 13:
// This function overloads the assignment operator (-=) to subtract
// the Polynomial on the right of the += sign to the value of the
// Polynomial on the left and then stores that result in the same
// Polynomial.
Polynomial& Polynomial::operator-=(const Polynomial& p)
{
	for (const std::pair<int, int>& setOfCAndE : p.coefficientAndExponent)
	{
		bool found = false;
		for (std::pair<int, int>& i : coefficientAndExponent)
		{
			if (i.second == setOfCAndE.second)
			{
				i.first -= setOfCAndE.first;
				found = true;
				break;
			}
		}
		if (!found)
		{
			coefficientAndExponent.push_back(std::make_pair(-setOfCAndE.first, setOfCAndE.second));
		}
	}
	return *this;
}

// destructor
Polynomial::~Polynomial() {}