#include "directorio.h"
#include <list>
#include "ruta.h"
#include "nodo.h"

Directorio::Directorio() {
    
}

void Directorio::ls(){
	for element:nodos{
		cout<< element<< "  ";
	}
	cout<<endl;
}

