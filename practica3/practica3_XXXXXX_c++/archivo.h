#ifndef __ARCHIVO__
#define __ARCHIVO__

// SEPARAR EN .H Y .CPP
#include <iostream>
#include "nodo.h"

class Archivo : public Nodo {
private:
	int tam;
public:
	Archivo(const string nombre);
	// devuelve el tamagno del arch
	
	int tamagno() override;

	// Altera el tam. del archivo a <nuevoT>. Devuelve true sii ha sido posible?
	bool modificarTamagno(const int nuevoT);
};

#endif