#ifndef __ENLACE__
#define __ENLACE__

// SEPARAR EN .H Y .CPP

#include "ruta.h"
#include "fichero.h"

class Enlace:public Fichero {
private:
	Ruta& rutaEnlace; // Donde esta el propio enlace
	Ruta& rutaEnlazada; // A donde apunta
public:
	Enlace();
	// devuelve el tamagno del enlace (0 supongo)
	int tamagno() const override;

	// Altera el tam. del archivo a <nuevoT>. Devuelve true sii ha sido posible?
	bool modificarTamagno(const int nuevoT);
};




#endif