#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
#include <vector>
#include <utility>

class Polynomial
{
public:
	Polynomial(); // constructor
	~Polynomial(); // destructor

	void enterTerms(); // from Polynomial_app.cpp
	void printPolynomial() const; // display function

	// Comment 1:
	// This overloads the addition operator (+) to add two Polynomials.
	Polynomial operator+(const Polynomial& p) const;

	// Comment 2:
	// This overloads the subtraction operator (-) to subtract two Polynomials.
	Polynomial operator-(const Polynomial& p) const;

	// Comment 3:
	// This overloads the assignment operator (=) to assign one Polynomial to another.
	Polynomial& operator=(const Polynomial& p);

	// Comment 4:
	// This overloads the addition assignment operator (+=).
	Polynomial& operator+=(const Polynomial& p);

	// Comment 5:
	// This overloads the subtraction assignment operator (-=)
	Polynomial& operator-=(const Polynomial& p);

private:

	// Comment 6:
	// This is the internal representation of a Polynomial as a vector of terms.
	// Each term contains a coefficient and an exponent.
	std::vector<std::pair<int, int>> coefficientAndExponent;
};

#endif