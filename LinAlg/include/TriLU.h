#ifndef TRILU_H
#define TRILU_H

#include <tnt.h>
#include "TriDiag.h"

//! LU-Zerlegung und Aufl�sung von linearen Gleichungssystemen mit einer tridiagonalen Matrix
/*!
 * Wir implementieren ausschlie�lich den Fall, dass die Berechnung der LU-Zerlegung
 * ohne Zeilenvertauschung durchf�hrbar ist.
 * Dies ist in sehr vielen Anwendungen garantiert.
 *
 * Wir verwenden die gleiche Notation wie in der Musterl�sung der �bungsaufgabe. 
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

        //! L�sung des linearen Gleichungssystems f�r die �bergebene rechte Seite
	    /*!
		 * \param rhs Rechte Seite, f�r die eine L�sung berechnet werden soll
	     * \return Berechnete L�sung. 
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

		//! Vorw�rtssubstitution f�r Ly=rhs
		/*!
		 * Der �bergebene Vektor rhs muss die korrekte L�nge besitzen,
		 * was nicht �berpr�ft wird.
		 *
		 * \param rhs Rechte Seite, f�r die die L�sung berechnet werden soll
		 * \return R�ckgabe ist die berechnete L�sung
		 */
		TNT::Vector<double> forwardSubstitution(TNT::Vector<double> rhs) const;
		//! R�ckw�rtsstubstition f�r Ux=y
		/*!
		* Der �bergebene Vektor rhs muss die korrekte L�nge besitzen,
		* was nicht �berpr�ft wird.
		*
		* Nach Aufruf der Funktion ist rhs �berschrieben!
		*
		* \param rhs Rechte Seite, f�r die die L�sung berechnet werden soll
		* \return R�ckgabe ist die berechnete L�sung
		*/
		TNT::Vector<double> backwardSubstition(TNT::Vector<double> rhs) const;
};
#endif
