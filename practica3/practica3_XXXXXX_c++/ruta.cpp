#include "ruta.h"
#include <iostream>
#include <memory>
#include <list>
#include "directorio.h"
#include "archivo.h"
#include "enlace.h"

Ruta::Ruta(const Directorio& raiz) {
	std::shared_ptr<Directorio> p (raiz);
    ruta.push_front(p);
}

std::string Ruta::pwd() const {
	std::string s;
    for(element:ruta){
    	s+="/" + element->nombre();
    }
    return s;
}

void Ruta::ls() const {
	ruta.back()->ls(); // ls de directorio
}

// Busca <elemento> en la ruta. Si no lo encuentra lanza la excepcion
std::shared_ptr<Nodo> Ruta::buscarElemento (const std::string elemento) const throw(noEncontrado) {
	bool encontrado = false;
	std::shared_ptr<Nodo> buscado;
	for (auto nodo : ruta.back().listar()) {
		if (nodo.nombre() == elemento) {
			encontrado = true;
			buscado = nodo;
			break;
		}
	}
	



	if (!encontrado) {
		throw noEncontrado();
	}
}

void Ruta::cd(const std::string path) {

	switch(path){
		case ".":
			//No hace nada.
			break;
		case "..":
			if(ruta.size() > 1){
				ruta.pop_back();
			}
			else{
				//Lazar excepción
			}
			break;
		case "/":
			ruta.erase(ruta.begin(),ruta.end());
			//Esto lo tengo que revisar. Hay que mover una posicion el primero y el ultimo.
			//Cuando compile lo probaré.
			break;
		default: 
			size_t f= path.find("/");
			ruta.back()->buscarElto(path.substr(0,f))
			ruta.push_back(path.substr(0,f));
			if(f!=-1){
				ruta.cd(path.substr(f+1,path.size()));
			}
			break;
	}
    
}


void Ruta::stat(const std::string element) const {
    
}

void Ruta::vim(const std::string file, const int size) const {
    
}

void Ruta::mkdir(const std::string dir) const {
    Directorio d(dir);
    //NO es tan facil. Estoy trabajando con punteros.
    ruta.push_back(d);
}

void Ruta::ln(const std::string orig, const std::string dest) const {
    
}

void Ruta::rm(const std::string e) const {
    
}