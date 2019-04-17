#ifndef __EXCEPCION__
#define __EXCEPCION__

#include <iostream>
#include <exception>

#include <list>
// #include ".h"

class arbol_ficheros_error {
private:
	std::string nom;
public:
	arbol_ficheros_error(const std::string nombre) : nom(nombre)  {}
	virtual ~arbol_ficheros_error() {}
	virtual const char* what() const {}

};




class noEncontrado : public arbol_ficheros_error {

public:
	noEncontrado() : arbol_ficheros_error("No encontrado") {}
	~noEncontrado() {}
	const char* what() const override {
		return ""; // Esta en principio no saca nada por pantalla
	}

};


class rutaCdInvalida : public arbol_ficheros_error {

public:
	rutaCdInvalida() : arbol_ficheros_error("Ruta cd invalida") {}
	~rutaCdInvalida(){}
	const char* what() const override {
		return "No se puede cambiar a ese directorio."; // Esta en principio no saca nada por pantalla
	}

};



class nombreInvalido : public arbol_ficheros_error {

public:
	nombreInvalido() : arbol_ficheros_error("nombre invalido") {}
	~nombreInvalido(){}
	const char* what() const override {
		return "El nombre no puede contener /"; // Esta en principio no saca nada por pantalla
	}

};



class maxRecursividad : public arbol_ficheros_error {
private:
	int MAX_LLAMADAS;
public:
	maxRecursividad(const int max) : arbol_ficheros_error("Maxima recursividad"), MAX_LLAMADAS(max){}

	~maxRecursividad(){}

	int maxLlamadas() const {
		return MAX_LLAMADAS;
	}

	const char* what() const override {
		return "Maximas llamadas recursivas alcanzadas.";
	}
};




/*

class out_of_range{

public:
	out_of_range() {}

	const char* what() const {
		return "Numero de parametros invalido.";
	}

};*/

#endif