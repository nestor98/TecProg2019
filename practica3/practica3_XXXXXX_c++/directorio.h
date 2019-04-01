#ifndef __DIRECTORIO__
#define __DIRECTORIO__

#include <iostream>
#include <list>
#include "ruta.h"
#include "fichero.h"

class Directorio : public Fichero {
private:
	std::string ruta;
	std::list<Fichero&> ficheros;
public:
	Directorio();
};




#endif