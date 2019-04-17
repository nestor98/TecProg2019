#ifndef __ARCHIVO__
#define __ARCHIVO__

// SEPARAR EN .H Y .CPP
#include <iostream>
#include "nodo.h"

class Archivo : public Nodo {
private:
	int tam;
public:
	Archivo(const string nombre, const int _tam);
	// devuelve el tamagno del arch
	
	int tamagno() const override;

	// Altera el tam. del archivo a <nuevoT>.
	void modificarTamagno(const int nuevoT) override;
};

#endif