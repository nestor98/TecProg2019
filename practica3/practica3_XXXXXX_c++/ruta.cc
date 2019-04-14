#include "ruta.h"
#include <iostream>
#include <memory>
#include <list>
#include "directorio.h"
#include "archivo.h"
#include "enlace.h"

using namespace std;
Ruta::Ruta(const Directorio& raiz) {
	shared_ptr<Directorio> p = make_shared<Directorio>(raiz);
    ruta.push_front(p);
}

string Ruta::pwd() const {
	string s;
    for(auto element : ruta){
    	s+="/" + element->nombre();
    }
    return s;
}

void Ruta::ls() const {
	ruta.back()->ls(); // ls de directorio
}

// Busca <elemento> en la ruta. Si no lo encuentra lanza la excepcion
shared_ptr<Nodo> Ruta::buscarElemento (const string elemento) const throw(noEncontrado) {
	bool encontrado = false;
	shared_ptr<Nodo> buscado;
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


void Ruta::cd(const string path) {
	if (path == ".."){
		try{
			if(ruta.size() > 1){
				ruta.pop_back();
			}
			else{
				throw rutaCdInvalida();
			}
		}
		catch(rutaCdInvalida& e){
			cout<< e.what()<<endl;
		}
	}
	else if (path == "/") {
		ruta.erase(ruta.begin(),ruta.end());
		//Esto lo tengo que revisar. Hay que mover una posicion el primero y el ultimo.
		//Cuando compile lo probaré.

	}
	else if (path!= ".") {
		size_t f= path.find("/");
		shared_ptr<Nodo> dest = ruta.back()->buscarElto(path.substr(0,f));
		ruta.push_back(dest);
		if(f!=-1){
			this->cd(path.substr(f+1,path.size()));
		}
	}
	
    
}


void Ruta::stat(const string element) const {
    
}

void Ruta::vim(const string file, const int size) const {
    
}

void Ruta::mkdir(const string dir)  {
	shared_ptr<Directorio> p(new Directorio(dir));
    ruta.push_back(p);
}

void Ruta::ln(const string orig, const string dest) const {
    
}

void Ruta::rm(const string e) const {
    
}