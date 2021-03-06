// ---------------------------------------------------------------------------
// Beispielprogramm f�r die Verwendung von GaussSeidel
// ---------------------------------------------------------------------------
#include <iostream>
#include <iomanip>
#include <fstream>

#include <tnt.h>

#include "utils.h"
#include "GaussSeidel.h"

using namespace std;

/*!
* \example GaussSeidelTest.cpp
*
* Einlesen eines linearen Gleichungssystems mit voll besetzter Matrix und L�sung
* mit dem Gauss-Seidel-Verfahren.
*/
int main(void)
{
	ifstream input;
	string fileName;

	// Einlesen der Matrix
	fileName = "matrix1.txt";
	input.open(fileName.c_str(), std::ios::in);
	if (input.fail()) {
		std::cerr << "Eingabedatei " << fileName << " existiert nicht!" << endl;
		return 2;
	}


	TNT::Matrix<double> A;
	TNT::Vector<double> b;
	TNT::Vector<double> start;

	input >> A;
	input >> b;
	input >> start;

	input.close();

	GaussSeidel einzelschritt(A, b, 0.005, 1000);

	TNT::Vector<double> x = einzelschritt.solve(start);

	einzelschritt.print();

	TNT::Vector<double> correct(b.size(), 1.0);

	std::cout << "Die exakte Loesung" << std::endl;
	std::cout << std::fixed << std::setprecision(6) << correct << std::endl;

	std::cout << "Die berechnete Loesung" << std::endl;
	std::cout << std::fixed << std::setprecision(6)  << x << std::endl;

	std::cout << std::scientific << "Die Maximumsnorm der Abweichung " << normMaximum(x - correct) << std::endl;

	return EXIT_SUCCESS;
}
