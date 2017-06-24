#ifndef VISUTIL
#define VISUTIL

#include <tnt.h>

//! \addtogroup visutil visutil - Nützliches, Konstanten, ...
/*! \addtogroup visutil
  *  @{
  */
  
//! Ausgabe einer Linie als VTK-Datei
/*!
 * Die VTK-Datei kann mit ParaView oder dem VTK-Framework
 * geöffnet und damit eine Visualisierung erstellt werden.
 *
 * \param fileName Dateiname
 * \param x Vektor mit den x-Koordinaten der Diskretisierung
 * \param y Vektor mit den y-Koordinaten der Diskretisierung
 * \return Fehlercodes
 *
 * 0 = success
 * 1 = Fehler beim Öffnen der Ausgabedatei
 */
short storeLine(string fileName, 
	            TNT::Vector<double> x, 
				TNT::Vector<double> y);


 /*! @}  end doxygen addtogroup visutil */	
#endif // VISUTIL
