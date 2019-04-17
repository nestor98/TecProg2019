#include "enlace.h"
#include "nodo.h"
#include "excepcion_arbol_ficheros.h"



int Enlace::iteraciones = 0;

const int MAX_REC = 500; // Maximas llamadas recursivas en tamagno

Enlace::Enlace(const string nombre, const std::shared_ptr<Nodo> otroNodo) : 
			   Nodo(nombre), rutaEnlazada(otroNodo) 
{}

int Enlace::tamagno() const {
	int total;
	try {
		// cout << "Iteracion: "<< iteraciones << endl;
		if (iteraciones++ >= MAX_REC) {
			iteraciones = 0; // Reseteamos
			throw maxRecursividad(MAX_REC);
		}
		total = rutaEnlazada->tamagno();
	}
	catch (const maxRecursividad& e) {
		cerr << e.what() << endl;
		iteraciones = 0;
		total = 0;
	}
	return total;
}

string Enlace::info() const {
	return this->nombre() + " --> " + rutaEnlazada->nombre();
}

void Enlace::modificarTamagno(const int nuevoT) {
    rutaEnlazada->modificarTamagno(nuevoT);
}
