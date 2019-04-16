#ifndef __ENLACE__
#define __ENLACE__

// SEPARAR EN .H Y .CPP
#include <memory>
#include <iostream>
#include "nodo.h"

class Enlace:public Nodo {
private:
	std::shared_ptr<Nodo> rutaEnlazada; // A donde apunta
public:
	Enlace(const string nombre);
	// devuelve el tamagno del enlace (0 supongo)
	int tamagno() const override;

	// Altera el tam. del archivo enlazado a <nuevoT>.
	void modificarTamagno(const int nuevoT) override;
};




#endif