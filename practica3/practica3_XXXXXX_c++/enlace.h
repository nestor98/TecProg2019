#ifndef __ENLACE__
#define __ENLACE__

// SEPARAR EN .H Y .CPP
#include <iostream>
#include "ruta.h"
#include "nodo.h"

class Enlace:public Nodo {
private:
	std::string rutaEnlace; // Donde esta el propio enlace
	std::string rutaEnlazada; // A donde apunta
public:
	Enlace();
	// devuelve el tamagno del enlace (0 supongo)
	int tamagno() const override;

	// Altera el tam. del archivo a <nuevoT>. Devuelve true sii ha sido posible?
	bool modificarTamagno(const int nuevoT);
};




#endif