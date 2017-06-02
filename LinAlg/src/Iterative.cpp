#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cmath>

#include "utils.h"
#include "Iterative.h"  

Iterative::Iterative() : n(0), localEpsilon(Eps), 
                         maxIter(0), noI(0),
						 shouldStop(false), finished(false) {}

// Konstruktor mit Koeffizientenmatrix
Iterative::Iterative(TNT::Matrix<double> matrix, TNT::Vector<double> rhs)
	: n(matrix.num_rows()), A(matrix), b(rhs), localEpsilon(Eps), 
	maxIter(100), noI(0), shouldStop(false), finished(false)
{
    // Wir überprüfen, ob die Diagonalelemente nicht zu klein sind
	for (unsigned int i = 0; i < n; i++)
		if (fabs(A[i][i]) < Eps)
			std::cerr << "Das Diagonallement " << i << " im Iterative-Verfahren ist zu klein!" << std::endl;
}

// Konstruktor mit Koeffizientenmatrix
Iterative::Iterative(TNT::Matrix<double> matrix, TNT::Vector<double> rhs, 
	                 double epsilon, unsigned int maxI)
	: n(matrix.num_rows()), A(matrix), b(rhs), localEpsilon(epsilon), 
	maxIter(maxI), noI(0), shouldStop(false), finished(false)
{
	// Wir überprüfen, ob die Diagonalelemente nicht zu klein sind
	for (unsigned int i = 0; i < n; i++)
		if (fabs(A[i][i]) < Eps)
			std::cerr << "Das Diagonalelement " << i << " im Iterative-Verfahren ist zu klein!" << std::endl;
}

// Wir überprüfen nicht, ob die Dimension von Start zum linearen Gleichungssystem passt
TNT::Vector<double> Iterative::solve(TNT::Vector<double> start)
{
	// Nur durchführen, wenn das Verfahren noch nicht beendet ist
	if (!shouldStop) 
	{
		// Den Vektor x für die aktuelle Näherung initialisieren
		x = start;
		// do-while-Schleife
		do {
			iterate();
			++noI;
		} while (!shouldStop && noI < maxIter);
	}
	finished = true;
	return x;
}

void Iterative::print() const
{
	// Defaultanzahl Nachkommastellen abfragen, um sie
	// am Ende der Funktion wieder zu rekonstruieren
	std::streamsize defaultPrecision = std::cout.precision();
	std::cout.precision(3);

	std::cout << "Die Koeffizientenmatrix" << std::endl;
	std::cout << A << std::endl;

	std::cout << std::endl << "Die rechte Seite" << std::endl;
	std::cout << std::fixed << std::setprecision(3) << b;
	
    // Falls die Iteration durchgeführt wurde, steht hier die
	// Anzahl der durchgeführten Iterationen
	if (finished) {
		std::cout << "Das Verfahren wurde durchgefuehrt" << std::endl;
		std::cout << "Die Durchfuehrung der Iteration benoetigte " << noI << " Iterationen" << std::endl;
	}
	std::cout.precision(defaultPrecision);
	std::cout << std::scientific << "Die verwendete Abbruchgenauigkeit ist " << localEpsilon << std::endl;
}