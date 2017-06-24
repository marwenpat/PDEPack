#ifndef VISUTIL
#define VISUTIL

#include <tnt.h>

//! \addtogroup visutil visutil - N�tzliches, Konstanten, ...
/*! \addtogroup visutil
  *  @{
  */
  
//! Ausgabe einer Linie als VTK-Datei
/*!
 * Die VTK-Datei kann mit ParaView oder dem VTK-Framework
 * ge�ffnet und damit eine Visualisierung erstellt werden.
 *
 * \param fileName Dateiname
 * \param x Vektor mit den x-Koordinaten der Diskretisierung
 * \param y Vektor mit den y-Koordinaten der Diskretisierung
 * \return Fehlercodes
 *
 * 0 = success
 * 1 = Fehler beim �ffnen der Ausgabedatei
 */
short storeLine(string fileName, 
	            TNT::Vector<double> x, 
				TNT::Vector<double> y);


 /*! @}  end doxygen addtogroup visutil */	
#endif // VISUTIL
