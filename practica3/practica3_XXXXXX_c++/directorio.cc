#include "directorio.h"
#include <list>

#include "nodo.h"


Directorio::Directorio(const string nombre) : Nodo(nombre) {}


void Directorio::ls() const {
	for (auto ptNodo : nodos) {
		cout << ptNodo->nombre() <<endl;
	}
}

int Directorio::tamagno() const {
	int tam=0;
	for (auto nodo : nodos){
		tam += nodo->tamagno();
	}
	return tam;
}

void Directorio::modificarTamagno(const int nuevoT) {
	cerr << "Imposible modificar el tamagno de un directorio" << endl;
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

void Directorio::eliminarElto(const string e){
	bool encontrado = false;
	for (auto it1=nodos.begin(); it1!=nodos.end(); ++it1) {
		if ((*it1)->nombre() == e) {
			encontrado = true;
			nodos.erase(it1);
			break;
		}
	}
	if (!encontrado) {
		throw noEncontrado();
	}	
}