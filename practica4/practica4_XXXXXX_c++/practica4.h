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
class Contenedor<T>{
private:
	std::list<T> contenedor;

public:
	Contenedor(const double cap) : capacidad(cap) {}
}



class Camion{
private:
	std::list<Contenedor> contenedor; //Tambien se tienen que poner productos.
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

class Generico
{
public:
	Generico();
	~Generico();
	
};

class Toxico
{
public:
	Toxico();
	~Toxico();
	
};

class SerVivo
{
public:
	SerVivo();
	~SerVivo();
	
};