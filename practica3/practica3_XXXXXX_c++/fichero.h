#ifndef __FICHERO__
#define __FICHERO__


#include <list>
#include "ruta.h"
#include "elemento.h"

class Fichero {
private:
	Ruta& ruta;
public:
	Fichero(Ruta& ruta_) : ruta(ruta) ;
};




#endif