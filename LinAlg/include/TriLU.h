#ifndef TRILU_H
#define TRILU_H

#include <tnt.h>
#include "TriDiag.h"

//! LU-Zerlegung und Auflösung von linearen Gleichungssystemen mit einer tridiagonalen Matrix
/*!
 * Wir implementieren ausschließlich den Fall, dass die Berechnung der LU-Zerlegung
 * ohne Zeilenvertauschung durchführbar ist.
 * Dies ist in sehr vielen Anwendungen garantiert.
 *
 * Wir verwenden die gleiche Notation wie in der Musterlösung der Übungsaufgabe. 
 *
 * Die Diagonale des Faktors L ist durch 1 gegeben.
 */
class TriLU
{
public:
    
        //! Defaultkonstruktor
	    /*!
	     *  n wird 0 gesetzt.
		 */
	    TriLU();

        //! Konstruktor mit einer Koeffizientenmatrix
        /*!
		 * Analog zur TNT::LU Zerlegung wird die LU-Zerlegung direkt 
		 * im Konstruktor berechnet.
		 *
         * \param matrix Instanz einer tridiagonalen Matrix
         */
		TriLU(TriDiag matrix);

        //! Lösung des linearen Gleichungssystems für die übergebene rechte Seite
	    /*!
		 * \param rhs Rechte Seite, für die eine Lösung berechnet werden soll
	     * \return Berechnete Lösung. 
	     */
		TNT::Vector<double> solve(TNT::Vector<double> rhs) const;

        //! Ausgabe der Inhalt der Instanz auf der Konsole
        void print() const;

		//! Abfragen der Dimension des Gleichungssystems
		int getLDA() const;

private:

		//! Dimension des Gleichungssystems
		int n;
		//! Zeiger auf eine Instanz einer tridiagonalen Matrix
		TriDiag A;
		//! Vektor mit der unteren Diagonale des Faktors L
		TNT::Vector<double> l;
		//! Vektor mit der Diagonale des Faktors U
		TNT::Vector<double> d;
		//! Vektor mit der oberen Nebendiagonale des Faktors U
		TNT::Vector<double> u;

		//! Berechnung der LU-Zerlegung ohne Zeilenvertauschung
		/*!
		* @return 0 Elimination erfolgreich
		*         1 Elimination abgebrochen, Diagonalelement zu klein
		*/
		short decompose();

		//! Vorwärtssubstitution für Ly=rhs
		/*!
		 * Der übergebene Vektor rhs muss die korrekte Länge besitzen,
		 * was nicht überprüft wird.
		 *
		 * \param rhs Rechte Seite, für die die Lösung berechnet werden soll
		 * \return Rückgabe ist die berechnete Lösung
		 */
		TNT::Vector<double> forwardSubstitution(TNT::Vector<double> rhs) const;
		//! Rückwärtsstubstition für Ux=y
		/*!
		* Der übergebene Vektor rhs muss die korrekte Länge besitzen,
		* was nicht überprüft wird.
		*
		* Nach Aufruf der Funktion ist rhs überschrieben!
		*
		* \param rhs Rechte Seite, für die die Lösung berechnet werden soll
		* \return Rückgabe ist die berechnete Lösung
		*/
		TNT::Vector<double> backwardSubstition(TNT::Vector<double> rhs) const;
};
#endif
