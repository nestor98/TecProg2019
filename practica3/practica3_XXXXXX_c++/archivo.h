#ifndef __ARCHIVO__
#define __ARCHIVO__

// SEPARAR EN .H Y .CPP
#include <iostream>
#include "ruta.h"
#include "nodo.h"

class Archivo : public Nodo {
private:
	int tam; // Tamagno
public:
	Archivo();
	// devuelve el tamagno del arch
	int tamagno() const override;

	// Altera el tam. del archivo a <nuevoT>. Devuelve true sii ha sido posible?
	bool modificarTamagno(const int nuevoT);
};

#endif