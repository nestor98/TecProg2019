#pragma once
#include <iostream>



class Almacen
{
private:
	double capacidad;
public:
	Almacen();
	bool cabe(double vol){
		return vol<=capacidad;
	}
	bool guardar(? elemento){
		if(bool cond=cabe(elemento.vol()))
			contenedor.push_back(elemento);
		return cond;
	}
	
};





template<typename T extends Producto>
class Contenedor<T> : public Almacen, public Generico
{
private:
	std::list<T> contenedor;

public:
	Contenedor(const double cap, const string nom="") : capacidad(cap), nombre(nom), volumen(cap) {}
}



class Camion : public Almacen
{
private:
	std::list<Generico> contenedor;
public:
	Camion(const double cap) : capacidad(cap) {}
}



class Producto{
private:
	double volumen;
	std::string nombre;
public:
	Producto(double vol, const std::string nom) : volumen(vol), nombre(nom) {}

	double vol() const{ return volumen;}

}

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