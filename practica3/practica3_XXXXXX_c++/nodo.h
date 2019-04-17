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
	// static int iteraciones;

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
	virtual int tamagno() const {}

	// Modifica el tamagno del fichero (a nuevoT)
	virtual void modificarTamagno(const int nuevoT) {}

	virtual void ls() const {}

	virtual void agndir(const shared_ptr<Nodo> p) {}

	virtual shared_ptr<Nodo> buscarElto(const string elemento) const {}

};

// Devuelve el nombre del nodo

inline std::ostream& operator<< (std::ostream& os, const Nodo& n) {
	return os << n.nombre();
}

#endif