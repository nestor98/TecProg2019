#ifndef __DIRECTORIO__
#define __DIRECTORIO__

#include <iostream>
#include <memory>
#include <list>
#include "nodo.h"


using namespace std;

class Directorio : public Nodo {
private:
	list<shared_ptr<Nodo>> nodos;
public:
	Directorio(const string nombre);

	int tamagno() const override;

	void modificarTamagno(const int nuevoT) override;

	void ls() const override;

	void agndir(const shared_ptr<Nodo> p) override;
	//
	shared_ptr<Nodo> buscarElto(const string elemento) const throw(noEncontrado) override;

};

#endif