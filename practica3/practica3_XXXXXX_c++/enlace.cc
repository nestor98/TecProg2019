#include "enlace.h"
#include "nodo.h"

Enlace::Enlace(const string nombre) : Nodo(nombre) {}
    

int Enlace::tamagno()  {
    return rutaEnlazada->tamagno();
}

bool Enlace::modificarTamagno(const int nuevoT) {
    
}


