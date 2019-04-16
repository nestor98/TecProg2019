#include "enlace.h"
#include "nodo.h"

Enlace::Enlace(const string nombre) : Nodo(nombre) {}
    

int Enlace::tamagno() const {
    return rutaEnlazada->tamagno();
}

bool Enlace::modificarTamagno(const int nuevoT) {
    
}


