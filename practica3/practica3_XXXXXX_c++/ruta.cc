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
shared_ptr<Directorio> Ruta::buscarElemento (const string elemento) const throw(noEncontrado) {
	bool encontrado = false;
	shared_ptr<Directorio> buscado;
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
	list<shared_ptr<Directorio>> copy= ruta;
	try{
		string aux=path;
		while(aux!=""){
			size_t f= aux.find("/");
			string pri=aux.substr(0,f);
			if(f!=-1){
				aux=aux.substr(f+1);
			}
			else{
				aux="";
			}
			if (pri == ".."){
				if(ruta.size() > 1){
					ruta.pop_back();
				}
				else{
					throw rutaCdInvalida();
				}
			}
			else if (path == "/") {
				shared_ptr<Directorio> aux= ruta.front(); 
				ruta.clear();
		    	ruta.push_front(aux);
			}
			else if (path!= ".") {
				shared_ptr<Directorio> dest = ruta.back()->buscarElto(pri);
				ruta.push_back(dest);
			}
		}
	}
	catch(noEncontrado& e){
		cout<< e.what();
		ruta=copy;
	}
}


void Ruta::stat(const string element) const {
    
}

void Ruta::vim(const string file, const int size) const {
    
}

void Ruta::mkdir(const string dir)  {
	shared_ptr<Directorio> p(new Directorio(dir));
    ruta.back()->agndir(p);
    cout<<"SE HA CREADO"<<endl;
    cout<<ruta.back()->nombre()<<endl;
}

void Ruta::ln(const string orig, const string dest) const {
    
}

void Ruta::rm(const string e) const {
    
}