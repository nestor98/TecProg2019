#include "directorio.h"
#include <list>

#include "nodo.h"


Directorio::Directorio(const string nombre) : Nodo(nombre) {}


void Directorio::ls() const {
	for (auto ptNodo : nodos) {
		cout << *ptNodo << "  ";
	}
	cout << endl;
}

// Devuelve el indice del elemento en la lista de hijos del directorio
shared_ptr<Nodo> Directorio::buscarElto(const string elemento) const throw(noEncontrado) {
	bool encontrado = false;
	shared_ptr<Nodo> buscado = nullptr;
	for (auto nodo : nodos) {
		if (nodo->nombre() == elemento) {
			encontrado = true;
			buscado = nodo;
			break;
		}
	}
	if (!encontrado) {
		throw noEncontrado();
	}
	return buscado;
}