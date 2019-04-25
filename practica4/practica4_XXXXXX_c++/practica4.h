#pragma once
#include <iostream>
#include <list>

template <typename T>
class Almacen
{
private:
	double capacidad;
	std::list<T> contenedor;

public:
	Almacen(const double cap) : capacidad(cap) {}

	bool guardar(const T& elemento) {
		bool ok = capacidad >= elemento.vol();
		if(ok) {
			contenedor.push_back(elemento);
		}
		return ok;
	}
	virtual void anyadir(T elemento) {}
};




class Producto {
private:
	double volumen;
	std::string nombre;
public:
	Producto(double vol, const std::string nom) : volumen(vol), nombre(nom) {}

	double vol() const {
		return volumen;
	}

};

class Generico : public Producto
{
public:
	Generico();
	~Generico();
	
};

class Toxico : public Producto
{
public:
	Toxico();
	~Toxico();
	
};

class SerVivo : public Producto
{
public:
	SerVivo();
	~SerVivo();
	
};

template <typename T>
class Contenedor : public Almacen<T>, public Generico
{
private:
	

public:
	Contenedor(const double cap, const std::string nom = "") : Almacen<T>(cap), Producto(cap, nom) {}

};




class Camion : public Almacen<Generico>
{
private:

public:
	Camion(const double cap) : Almacen<Generico>(cap) {}


};
