#pragma once
#include <iostream>



class Almacen
{
private:
	double capacidad;
public:
	Almacen();
	bool guardar(? elemento){
		if(cond=((capacidad-elemento.volumen)>0)
			contenedor.push_back(elemento);
		return cond;
	}
	
};





template<typename T>
class Contenedor<T> : public Almacen, public Generico
{
private:
	std::list<T> contenedor;

public:
	Contenedor(const double cap) : capacidad(cap) {}
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