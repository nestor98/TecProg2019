#ifndef __DIRECTORIO__
#define __DIRECTORIO__

#include <iostream>
#include <memory>
#include <list>
#include "ruta.h"
#include "nodo.h"

class Directorio : public Nodo {
private:
	std::list<std::shared_ptr<Nodo>> nodos;
public:
	Directorio(const std::string nombre);

	void ls() const;
	std::list<std::shared_ptr<Nodo>> listar() const;
};

#endif