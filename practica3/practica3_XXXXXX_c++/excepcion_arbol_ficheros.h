#ifndef __EXCEPCION__
#define __EXCEPCION__

#include <iostream>
#include <exception>

#include <list>
// #include ".h"

class ExcepcionArbolFicheros {
private:
	std::string nom;
public:
	ExcepcionArbolFicheros(const std::string nombre) : nom(nombre)  {}
	virtual ~ExcepcionArbolFicheros() {}
	virtual const char* what() const{};

};




class noEncontrado : public ExcepcionArbolFicheros {

public:
	noEncontrado() : ExcepcionArbolFicheros("No encontrado") {}
	~noEncontrado(){}
	const char* what() const override {
		return ""; // Esta en principio no saca nada por pantalla
	}

};


class rutaCdInvalida : public ExcepcionArbolFicheros {

public:
	rutaCdInvalida() : ExcepcionArbolFicheros("Ruta cd invalida") {}
	~rutaCdInvalida(){}
	const char* what() const override {
		return "No se puede cambiar de directorio."; // Esta en principio no saca nada por pantalla
	}

};



/*
class arbol_ficheros_error : public ExcepcionArbolFicheros {

public:
	// arbol_ficheros_error() {}

	const char* what() const override {
		return ""; // Esta en principio no saca nada por pantalla
	}

};
*/

// class out_of_range : public ExcepcionArbolFicheros {

// public:
// 	out_of_range() {}

// 	const char* what() const override {
// 		return ""; // Esta en principio no saca nada por pantalla
// 	}

// }

#endif