#ifndef __DIRECTORIO__
#define __DIRECTORIO__


#include <list>
#include "ruta.h"
#include "elemento.h"

class Directorio:public Elemento {
private:
	Ruta& ruta;
	std::list<Elemento> 
public:
	Directorio();
};




#endif