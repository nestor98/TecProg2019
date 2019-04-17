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
	Enlace(const string nombre, const std::shared_ptr<Nodo> otroNodo);
	// devuelve el tamagno del enlace (0 supongo)
	int tamagno() const override;

	string info() const;

	// Altera el tam. del archivo enlazado a <nuevoT>.
	void modificarTamagno(const int nuevoT) override;
};




#endif