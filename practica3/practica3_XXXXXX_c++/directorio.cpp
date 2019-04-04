#include "directorio.h"
#include <list>
#include "ruta.h"
#include "nodo.h"


Directorio::Directorio(const std::string nombre) : Nodo(nombre) {}


std::shared_ptr<std::list<std::shared_ptr<Nodo>>> Directorio::listar() const {
	return std::shared_ptr<std::list<std::shared_ptr<Nodo>>>(nodos);
}

void Directorio::ls(){
	for (ptNodo : this.listar()) {
		cout << *ptNodo << "  ";
	}
	cout << endl;
}

// Devuelve el indice del elemento en la lista de hijos del directorio
int Directorio::buscarElto(const Nodo& buscado) const throw(noEncontrado) {
	bool encontrado = false;
	int indice = 0;
	for (auto nodo : this.listar()) {
		if (nodo.nombre() == elemento) {
			encontrado = true;
			break;
		}
		else {
			indice++;
		}
	}
	if (!encontrado) {
		throw noEncontrado();
	}
	return indice;
}