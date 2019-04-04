#include "ruta.h"
#include <iostream>
#include <memory>
#include <list>
#include "directorio.h"
#include "archivo.h"
#include "enlace.h"

Ruta::Ruta(const Directorio& raiz) : ruta(raiz) {
    ruta.push_front(raiz);
}

std::string Ruta::pwd() const {
    for(element:ruta){
    	cout <<"/"<< element;
    }
    cout<<end;
}

void Ruta::ls() const {
	ruta.back()->ls(); // ls de directorio
}

// Busca <elemento> en la ruta. Si no lo encuentra lanza la excepcion
std::shared_ptr<Nodo> Ruta::buscarElemento (const std::string elemento) const throw(noEncontrado) {
	bool encontrado = false;
	for (direc : ruta.back().listar()) {
		direc.
	}




	if (!encontrado) {
		throw noEncontrado();
	}
}

void Ruta::cd(const std::string path) {
    
}


void Ruta::stat(const std::string element) const {
    
}

void Ruta::vim(const std::string file, const int size) const {
    
}

void Ruta::mkdir(const std::string dir) const {
    
}

void Ruta::ln(const std::string orig, const std::string dest) const {
    
}

void Ruta::rm(const std::string e) const {
    
}