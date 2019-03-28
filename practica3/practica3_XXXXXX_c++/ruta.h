#ifndef __RUTA__
#define __RUTA__

#include <iostream>
#include "directorio.h"
#include "archivo.h"
#include "enlace.h"

class Ruta {
private:
	std::string ruta;
public:
	Ruta(const Directorio& raiz);
};

#endif