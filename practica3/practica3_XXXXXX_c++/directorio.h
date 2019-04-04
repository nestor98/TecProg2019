#ifndef __DIRECTORIO__
#define __DIRECTORIO__

#include <iostream>
#include <list>
#include "ruta.h"
#include "nodo.h"

class Directorio : public Nodo {
private:
	std::string ruta;
	std::list<Nodo*> nodos;
public:
	Directorio();
};




#endif