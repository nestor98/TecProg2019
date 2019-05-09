// #pragma once  // al compilador no le gusta esto porque solo hay un archivo
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



class ProductoNoNecesariamenteGenerico {
private:
	double volumen;
	std::string nombre;
public:
	ProductoNoNecesariamenteGenerico(double vol, const std::string nom) : volumen(vol), nombre(nom) {}

	~ProductoNoNecesariamenteGenerico(){}

	double vol() const {
		return volumen;
	}

};


class Generico : public ProductoNoNecesariamenteGenerico
{
public:
	Generico(double vol, const std::string nom) : ProductoNoNecesariamenteGenerico(vol, nom) {}
	~Generico() {}
	
};

class Producto : public Generico {
public:
	Producto(double vol, const std::string nom) : Generico(vol, nom) {}

	~Producto(){}
};

class Toxico : public ProductoNoNecesariamenteGenerico
{
public:
	Toxico(double vol, const std::string nom) : ProductoNoNecesariamenteGenerico(vol, nom) {}
	~Toxico() {}
	
};

class SerVivo : public ProductoNoNecesariamenteGenerico
{
public:
	SerVivo(double vol, const std::string nom) : ProductoNoNecesariamenteGenerico(vol, nom) {}
	~SerVivo() {}
	
};

template <typename T>
class Contenedor : public Almacen<T>, public Generico
{
public:
	Contenedor(const double cap, const std::string nom = "") : Almacen<T>(cap), Generico(cap, nom) {}

	~Contenedor() {}
};

class Camion : public Almacen<Generico>
{
public:
	Camion(const double cap) : Almacen<Generico>(cap) {}

	~Camion() {}

};