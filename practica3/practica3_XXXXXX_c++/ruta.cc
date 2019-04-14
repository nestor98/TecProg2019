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
		shared_ptr<Directorio> aux= ruta.front(); 
		ruta.clear();
    	ruta.push_front(aux);
	}
	else if (path!= ".") {
		//Esto no es lo más eficiente. Seguro que se puede mejorar.
		if(path.substr(0,1)=="/"){
			list<shared_ptr<Directorio>> rutaAux= ruta;
			this->cd("/"); //Recursivo
			this->cd(path.substr(1,path.size()-1));
			//vacia todo.
			//comprueba si existen todo los directorios.
			//Llenalo con los componentes de la cadena.
			//Si salta una excepcion vuelve a cargar ruta con lo que había antes.
		}
		else{
			string aux=path;
			while(aux!=""){
				cout<<"Entra como:"<<aux<<endl;
				size_t f= path.find("/");
				shared_ptr<Directorio> dest = ruta.back()->buscarElto(aux.substr(0,f));
				ruta.push_back(dest);
				if(f!=-1){
					aux=aux.substr(f+1);
				}
				else{
					aux="";
				}
				cout<<"Sale como:"<<aux<<endl;
			}
		}
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