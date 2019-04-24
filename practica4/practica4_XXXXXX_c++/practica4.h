#pragma once
#include <iostream>





template<typename T>
class Contenedor<T>{
private:
	double capacidad;
	std::list<T> contenedor;

public:
	Contenedor(const double cap) : capacidad(cap) {}
}



class Camion{
private:
	double capacidad;
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

