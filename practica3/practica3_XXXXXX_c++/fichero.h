#ifndef __FICHERO__
#define __FICHERO__


#include <list>
#include "ruta.h"
// #include ".h"

class Fichero {
// private:
// 	Ruta& ruta;
public:
	Fichero();
	// Devuelve una referencia a la ruta del fichero
	const Ruta& ruta() const;
	// Devuelve el tamagno del fichero
	virtual int tamagno() const;


};




#endif