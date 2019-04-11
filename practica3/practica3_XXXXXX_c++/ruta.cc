#include "ruta.h"
#include <iostream>
#include <memory>
#include <list>
#include "directorio.h"
#include "archivo.h"
#include "enlace.h"

using namespace std;
Ruta::Ruta(const Directorio& raiz) {
	std::shared_ptr<Directorio> p = make_shared<Directorio>(raiz);
    ruta.push_front(p);
}

std::string Ruta::pwd() const {
	std::string s;
    for(auto element : ruta){
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
	// for (auto nodo : ruta.back().listar()) {
	// 	if (nodo.nombre() == elemento) {
	// 		encontrado = true;
	// 		buscado = nodo;
	// 		break;
	// 	}
	// }
	if (!encontrado) {
		throw noEncontrado();
	}
}


void Ruta::cd(const std::string path) {
	if (path == ".."){
		if(ruta.size() > 1){
			ruta.pop_back();
		}
		else{
			//Lazar excepción
		}
	}
	else if (path == "/") {
		ruta.erase(ruta.begin(),ruta.end());
		//Esto lo tengo que revisar. Hay que mover una posicion el primero y el ultimo.
		//Cuando compile lo probaré.

	}
	else if (path!= ".") {
		size_t f= path.find("/");
		std::shared_ptr<Nodo> dest = ruta.back()->buscarElto(path.substr(0,f));
		ruta.push_back(dest);
		if(f!=-1){
			this->cd(path.substr(f+1,path.size()));
		}
	}
	
    
}


void Ruta::stat(const std::string element) const {
    
}

void Ruta::vim(const std::string file, const int size) const {
    
}

void Ruta::mkdir(const std::string dir)  {
	std::shared_ptr<Directorio> p(new Directorio(dir));
    ruta.push_back(p);
}

void Ruta::ln(const std::string orig, const std::string dest) const {
    
}

void Ruta::rm(const std::string e) const {
    
}