#ifndef __ARCHIVO__
#define __ARCHIVO__

// SEPARAR EN .H Y .CPP
#include <list>
#include "ruta.h"
#include "elemento.h"

class Archivo:public Elemento {
private:
	Ruta& ruta;
	int tamagno;
public:
	Archivo();
};




#endif