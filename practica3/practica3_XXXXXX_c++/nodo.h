#ifndef __NODO__
#define __NODO__

#include <iostream>

#include <list>
#include "ruta.h"
// #include ".h"

class Nodo {
private:
	std::string nombre;
public:
	// Nodo();


	string nombre() const {
		return nombre;
	}

	// Cambia el nombre del nodo
	string renombrar(const std::string nuevoNom) const {
		nombre = nuevoNom;
	}

	// Devuelve el tamagno del fichero
	virtual int tamagno() const = 0;

};

// Devuelve el nombre del nodo
ostream& operator<< (ostream& os, const Nodo& n) {
	return os << n.nombre;
}




#endif