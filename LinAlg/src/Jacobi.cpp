#include "utils.h"
#include "Jacobi.h"  

Jacobi::Jacobi() : Iterative() {}

// Konstruktor mit Koeffizientenmatrix
Jacobi::Jacobi(TNT::Matrix<double> matrix, TNT::Vector<double> rhs) 
	: Iterative(matrix, rhs), xalt(n) {}

Jacobi::Jacobi(TNT::Matrix<double> matrix, TNT::Vector<double> rhs, double epsilon, unsigned int maxI)
	: Iterative(matrix, rhs, epsilon, maxI), xalt(n) {}

//! Wir überprüfen nicht, ob die Dimension von Start zum linearen Gleichungssystem passt
void Jacobi::iterate()
{
	unsigned int i, j;
	double sum(0.0);

	// Werte von x auf xalt kopieren
	xalt = x;
	for (i = 0; i < n; i++)
	{
		sum = 0.0;
		for (j = 0; j < i; j++)
			sum += A[i][j] * xalt[j];
		for (j = i + 1; j < n; j++)
			sum += A[i][j] * xalt[j];
		// Wir haben im Konstruktor überprüft, dass die
		// Diagonalelemente ok sind.
		x[i] = (b[i] - sum) / A[i][i];

	}
	noI++;

	if (compareVectorMaximumNorm(xalt, x, localEpsilon))
		stop();
}

void Jacobi::print() const
{
	std::cout << "Gesamtschrittverfahren fuer lineare Gleichungssysteme" << std::endl;
	Iterative::print();
}