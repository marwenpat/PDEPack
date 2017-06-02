#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cmath>

#include "utils.h"
#include "GaussSeidel.h"  

GaussSeidel::GaussSeidel() : Iterative() {}

// Konstruktor mit Koeffizientenmatrix
GaussSeidel::GaussSeidel(TNT::Matrix<double> matrix, TNT::Vector<double> rhs) 
	: Iterative(matrix, rhs), xalt(n) {}

GaussSeidel::GaussSeidel(TNT::Matrix<double> matrix, TNT::Vector<double> rhs, double epsilon, unsigned int maxI)
	: Iterative(matrix, rhs, epsilon, maxI), xalt(n) {}

//! Wir überprüfen nicht, ob die Dimension von Start zum linearen Gleichungssystem passt
void GaussSeidel::iterate()
{
	unsigned int i, j;
	double sum(0.0);

	xalt = x;
	for (i = 0; i < n; i++)
	{
		sum = 0.0;
		for (j = 0; j < i; j++)
			sum += A[i][j] * x[j];
		for (j = i + 1; j < n; j++)
			sum += A[i][j] * x[j];
		// Wir haben im Konstruktor überprüft, dass die
		// Diagonalelemente ok sind.
		x[i] = (b[i] - sum) / A[i][i];

	}
	noI++;

	if (compareVectorMaximumNorm(xalt, x, localEpsilon))
		stop();
}

void GaussSeidel::print() const
{
	std::cout << "Einzelschrittverfahren fuer lineare Gleichungssysteme" << std::endl;
	Iterative::print();
}