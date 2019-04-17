#include "enlace.h"
#include "nodo.h"

Enlace::Enlace(const string nombre, const std::shared_ptr<Nodo> otroNodo) : 
				Nodo(nombre), rutaEnlazada(otroNodo) {}

int Enlace::tamagno() const {
    return rutaEnlazada->tamagno();
}

string Enlace::info() const {
	return this->nombre() + " --> " + rutaEnlazada->nombre();
}

void Enlace::modificarTamagno(const int nuevoT) {
    rutaEnlazada->modificarTamagno(nuevoT);
}
