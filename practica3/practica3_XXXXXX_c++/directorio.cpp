#include "directorio.h"
#include <list>
#include "ruta.h"
#include "nodo.h"

Directorio::Directorio() {
    
}

std::list<std::shared_ptr<Nodo>> Directorio::listar() const {
	return nodos;
}


void Directorio::ls(){
	for (ptNodo : this.listar()) {
		cout << *ptNodo << "  ";
	}
	cout << endl;
}

