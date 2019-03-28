#ifndef __ARCHIVO__
#define __ARCHIVO__

// SEPARAR EN .H Y .CPP
#include <list>
#include "ruta.h"
#include "fichero.h"

class Archivo:public Fichero {
private:
	Ruta& ruta;
	int tamagno;
public:
	Archivo();
};




#endif