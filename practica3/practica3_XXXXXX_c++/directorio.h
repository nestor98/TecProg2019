#ifndef __DIRECTORIO__
#define __DIRECTORIO__


#include <list>
#include "ruta.h"
#include "fichero.h"

class Directorio:public Fichero {
private:
	Ruta& ruta;
	std::list<Fichero> 
public:
	Directorio();
};




#endif