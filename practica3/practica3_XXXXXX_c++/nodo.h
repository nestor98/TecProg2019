#ifndef __NODO__
#define __NODO__

#include <iostream>
#include <memory>
#include <list>
#include "excepcion_arbol_ficheros.h"
// #include ".h"
using namespace std;
class Nodo {
private:
	std::string nom;
public:
	Nodo(const std::string nombre) : nom(nombre) {}

	std::string nombre() const {
		return nom;
	}

	// Cambia el nombre del nodo
	std::string renombrar(const std::string nuevoNom) {
		nom = nuevoNom;
	}

	// Devuelve el tamagno del fichero
	virtual int tamagno()  {}

	virtual void ls() const {}

	virtual shared_ptr<Nodo> buscarElto(const string elemento) const {}
};


// Devuelve el nombre del nodo
std::ostream& operator<< (std::ostream& os, const Nodo& n) {
	return os << n.nombre();
}



#endif