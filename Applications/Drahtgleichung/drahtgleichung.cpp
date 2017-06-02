// ---------------------------------------------------------------------------
// Lösung der eindimensionalen Drahtgleichung
// Literatur: van Kan, Segal, Vermolen: 
// Numerical Methods in Scientific Computing, Absatz 3.1 "The cable equation"
// ---------------------------------------------------------------------------
#include <cmath>
#include <iostream>

#include <tnt.h>
#include "utils.h"

#include "TriDiag.h"
#include "TriLU.h"

using namespace std;

/*!
 * \example Drahtgleichung
 */
int main(void)
{
    int n(10);

    TriDiag tri(n, 2.0, -1.0, -1.0);

    // LU instanziieren und Lösung ausgeben
    TriLU lu(tri);

    // Rechte Seite
    TNT::Vector<double> rhs(n);
    rhs[0] = 0.1;
    rhs[1] = 0.2;
    rhs[2] = 0.3;
    rhs[3] = 0.4;
    rhs[4] = 0.5;
    rhs[5] = 0.5;
    rhs[6] = 0.4;
    rhs[7] = 0.3;
    rhs[8] = 0.2;
    rhs[9] = 0.1;

    TNT::Vector<double> x = lu.solve(rhs);

    std::cout << "Die berechnete Loesung" << std::endl;
    std::cout << x;

    // Probe
    TNT::Vector<double> ax(tri.ATimesX(x));
    std::cout << "Wir berechnen A*x:" << std::endl;
    std::cout << ax;

    std::cout << std::scientific << "Die Abweichung zwischen der rechten Seite und A*X: " << normMaximum(ax - rhs) << std::endl;

    // Die Lösung als csv oder anderes Format ausgeben, damit wir das grafisch ausgeben können!
    return 0;
}
