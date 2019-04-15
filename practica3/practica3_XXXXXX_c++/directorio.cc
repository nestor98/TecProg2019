#include "directorio.h"
#include <list>

#include "nodo.h"


Directorio::Directorio(const string nombre) : Nodo(nombre) {}


void Directorio::ls() const {
	for (auto ptNodo : nodos) {
		cout << ptNodo->nombre() << "  ";
	}
	cout << endl;
}

int Directorio::tamagno(){
	int tam=0;
	for (auto nodo : nodos){
		tam+= nodo->tamagno();
	}
}

void Directorio::agndir(const shared_ptr<Nodo> p){
	nodos.push_back(p);
	//METER UNA EXCEPCION. EN CASO DE QUE EXISTA UN DIRECTORIO DE NOMBRE DIR.
}


//

// Devuelve el indice del elemento en la lista de hijos del directorio
shared_ptr<Nodo> Directorio::buscarElto(const string elemento) const throw(noEncontrado){
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
