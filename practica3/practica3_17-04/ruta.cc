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
		   s+=element->nombre()+"/" ;
	}
	if(ruta.size()>1){
		s.pop_back();
	}
    return s;
}

void Ruta::ls() const {
	ruta.back()->ls(); // ls de directorio
}

// Busca <elemento> en la ruta. Si no lo encuentra lanza la excepcion
/*
shared_ptr<Nodo> Ruta::buscarElemento (const string elemento) const throw(noEncontrado) {
	
}
*/

void Ruta::cd(const string path) {
	list<shared_ptr<Directorio>> copy= ruta;
	try{
		string aux=path;
		while(aux!=""){
			size_t f= aux.find("/");
			string pri;
			if(f==0){
				pri="/";
			}
			else{
				pri=aux.substr(0,f);
			}
			
			// cout<<"Esto es pri "<<pri<<endl;
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
			else if (pri == "/") {
				shared_ptr<Directorio> aux= ruta.front(); 
				ruta.clear();
		    	ruta.push_front(aux);
			}
			else if (pri!= ".") {
				shared_ptr<Nodo> dest = ruta.back()->buscarElto(pri);
				shared_ptr<Directorio> destDir= dynamic_pointer_cast<Directorio>(dest);
				if(destDir!=nullptr)
					ruta.push_back(destDir);
			}
		}
	}
	catch(noEncontrado& e){
		cout<<path<<" no existe idiota."<<endl;
		cout<< e.what();
		ruta=copy;
	}
}

// Muestra por pantalla un número que es el tamaño del
// archivo, directorio o enlace dentro de la ruta actual identificado por la cadena de texto
// que se le pasa como parámetro. También se le puede pasar una ruta completa.
void Ruta::stat(const string element) {
	try{
		shared_ptr<Nodo> encontrado = ruta.back()->buscarElto(element);
		cout << encontrado->tamagno() << endl;
	}
	catch(noEncontrado& e){ // no es ruta relativa
		try { // probamos con la absoluta
			list<shared_ptr<Directorio>> copy = ruta;
			size_t pos = element.find_last_of("/"); // pos de la ultima "/" de <element>
			if (pos == string::npos) { // no ha encontrado
				throw rutaCdInvalida();
			}
			// cout << "La pos es " << pos << endl;
			// cout << "La ruta es " << element.substr(0, pos) << endl;
			// cout << "El nombre es " << element.substr(pos+1) << endl;
			if (pos == 0) { // caso especial, solo un nivel: "/a"
				// Necesitamos guardar la "/"
				this->cd("/");
			// ( equivalente a cd(element.substr(0, pos+1)) )
			}
			else { // Resto de casos, se quita la ultima "/"
				this->cd(element.substr(0, pos));
			}
			// cout << this->pwd() << endl;
			this->stat(element.substr(pos+1));
			ruta = copy; // volvemos a donde estabamos
		}
		catch (rutaCdInvalida e) { // ni relativa ni absoluta
			cout << element << " no existe." << endl;
		}
	}
}


// Cambia el tamaño de un archivo dentro de la
// ruta actual (no se le puede pasar como parámetro una ruta completa). Si el archivo no
// existe dentro de la ruta actual, se crea automáticamente con el nombre y tamaño
// espeficados. Si el archivo referenciado por “file” es en realidad un enlace a un archivo,
// también cambia su tamaño.
void Ruta::vim (const string file, const int size) const {
	try {
		shared_ptr<Nodo> encontrado = ruta.back()->buscarElto(file);
		encontrado->modificarTamagno(size);
		// cout << encontrado->tamagno() << endl;
	}
	catch(noEncontrado& e) { // no existia, lo creamos
		shared_ptr<Nodo> nuevo = make_shared<Archivo>(file, size);
		ruta.back()->agndir(nuevo);
		// cerr << "agnadido " << *nuevo << endl;
	}
}


void Ruta::mkdir(const string dir)  {
	try{
		// nota: lo del principio creo que no vale pa na
		/*shared_ptr<Nodo> foo = */ruta.back()->buscarElto(dir); 
		cout<<"Ya existe un elemento de nombre "<<dir<<endl;
	}
	catch(noEncontrado& e){
		shared_ptr<Directorio> p(new Directorio(dir));
    	ruta.back()->agndir(p);
	}
}


// Crea un enlace simbólico de nombre “dest” a que
// enlaza el elemento identificado mediante el nombre “orig”. “dest” no puede contener
// una ruta completa, pero “orig” sí, de tal modo que pueden crearse enlaces simbólicos
// entre elementos dentro de diferentes posiciones del árbol de directorios.
void Ruta::ln(const string orig, const string dest) {
	try { // Comprobamos que dest es nuevo
		ruta.back()->buscarElto(dest);
		cerr << "Ya existe un elemento de nombre " << dest << endl;
	}
	catch (const noEncontrado& e) { // dest correcto
		// buscamos orig:
		try { // Ruta relativa
			shared_ptr<Nodo> encontrado = ruta.back()->buscarElto(orig);
			shared_ptr<Enlace> enlace(new Enlace(dest, encontrado));
			ruta.back()->agndir(enlace);
			cout << enlace->info() << endl;
		}
		catch(noEncontrado& e){ // no es ruta relativa
			try { // probamos con la absoluta
				list<shared_ptr<Directorio>> copy = ruta;
				size_t pos = orig.find_last_of("/"); // pos de la ultima "/" de <orig>
				if (pos == string::npos) { // no ha encontrado
					throw rutaCdInvalida();
				}
				if (pos == 0) { // caso especial, solo un nivel: "/a"
					// Necesitamos guardar la "/"
					this->cd("/");
					// ( equivalente a cd(orig.substr(0, pos+1)) )
				}
				else { // Resto de casos, se quita la ultima "/"
					this->cd(orig.substr(0, pos));
				}
				shared_ptr<Nodo> encontrado = ruta.back()->buscarElto(orig.substr(pos+1));
				ruta = copy; // volvemos a donde estabamos
				shared_ptr<Enlace> enlace(new Enlace(dest, encontrado));
				ruta.back()->agndir(enlace);
				cout << enlace->info() << endl;
			}
			catch (rutaCdInvalida e) { // ni relativa ni absoluta
				cout << orig << " no existe." << endl;
			}
		}
	}
}

void Ruta::rm(const string e) const {
    
}