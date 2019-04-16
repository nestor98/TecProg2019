#include "archivo.h"
#include "nodo.h"

Archivo::Archivo(const string nombre, const int _tam) : Nodo(nombre), tam(_tam) {}
    

int Archivo::tamagno() const {
    return tam;
}

void Archivo::modificarTamagno(const int nuevoT) {
    tam = nuevoT;
}


