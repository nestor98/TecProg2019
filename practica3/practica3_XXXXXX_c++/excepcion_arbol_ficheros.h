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
		return "No se puede cambiar de directorio."; // Esta en principio no saca nada por pantalla
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
		std::string respuestaStr = "Maximas (" + std::to_string(MAX_LLAMADAS) + ") llamadas recursivas alcanzadas";
		// std::cout << respuestaStr << std::endl;
		return respuestaStr.c_str();
	}
};





/*
class arbol_ficheros_error : public arbol_ficheros_error {

public:
	// arbol_ficheros_error() {}

	const char* what() const override {
		return ""; // Esta en principio no saca nada por pantalla
	}

};
*/

// class out_of_range : public arbol_ficheros_error {

// public:
// 	out_of_range() {}

// 	const char* what() const override {
// 		return ""; // Esta en principio no saca nada por pantalla
// 	}

// }

#endif