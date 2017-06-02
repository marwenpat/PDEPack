// ---------------------------------------------------------------------------
// Einlesen und L�sen eines tridiagonalen LGS
// ---------------------------------------------------------------------------
#include <cmath>
#include <iostream>

#include <tnt.h>
#include "utils.h"

#include "TriDiag.h"
#include "TriLU.h"

using namespace std;

/*!
 * \example LU-Zerlegung und L�sung
 *
 * LU-Zerlegung f�r tridiagonale Matrizen. 
 * 
 * Wir instanziieren eine tridiagonale Matrix mit konstanten
 * Elementen in den Diagonalen, f�hren eine LU-Zerlegung
 * durch und verwenden den ersten Einheitsvektor als rechte Seite.
 *
 * Wir evaluieren die L�sung, indem wir sie mit der Matrix multiplizieren
 * und mit dem ersten Einheitsvektor vergleichen. Die Abweichung sollte
 * gering sein!
 */
int main(void)
{
	int n(5);

	TriDiag tri(n, 2.0, -1.0, -1.0);

	// LU instanziieren und L�sung ausgeben
	TriLU lu(tri);

	// LU-Zerlegung ausgeben
	lu.print();

	// Rechte Seite
	TNT::Vector<double> rhs = unitVector(0, n);
	TNT::Vector<double> x = lu.solve(rhs);

	std::cout << "Die berechnete Loesung" << std::endl;
	std::cout << x;

	// Probe
	TNT::Vector<double> ax(tri.ATimesX(x));
	std::cout << "Wir berechnen A*x:" << std::endl;
	std::cout << ax;

	std::cout << std::scientific << "Die Abweichung zwischen der rechten Seite und A*X: " << normMaximum(ax - rhs) << std::endl;
    return 0;
}
