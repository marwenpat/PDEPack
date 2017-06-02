// ---------------------------------------------------------------------------
// Einlesen und Lösen eines tridiagonalen LGS
// ---------------------------------------------------------------------------
#include <cmath>
#include <iostream>

#include <tnt.h>

#include "TriDiag.h"

using namespace std;

/*!
 * \example TriDiag
 *
 * Wir testen die Variante, die drei Vektoren für die Speicherung
 * verwendet.
*/
int main(void)
{
	int n(5);

	TriDiag tri(n, 2.0, -1.0, -1.0);

	tri.print();

	// ATimesX testen
	TNT::Vector<double> x(n, 1.0);
	std::cout << "Test der Multiplikation mit einem Vektor" << std::endl;
	std::cout << "Das Ergebnis muss der Vektor (1,0,0,0,1) sein!" << std::endl;
	std::cout << tri.ATimesX(x);

	TNT::Vector<double> a(n, 4.0), b(n - 1, -1.0), c(n - 1, -1.0);
	TriDiag tri2(a, b, c);

	tri2.print();

	// ATimesX testen
	std::cout << "Test der Multiplikation mit einem Vektor" << std::endl;
	std::cout << "Das Ergebnis muss der Vektor (3, 2, 2, 2,  3) sein!" << std::endl;
	std::cout << tri2.ATimesX(x);

    return 0;
}
