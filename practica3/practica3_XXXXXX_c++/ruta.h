#ifndef __RUTA__
#define __RUTA__

#include <iostream>
#include "directorio.h"
#include "archivo.h"
#include "enlace.h"

class Ruta {
private:
	Directorio& ruta;
public:
	Ruta(const Directorio& raiz);

	// Devuelve la ruta completa, con todos los nombres de los directorios
	// desde la raíz hasta el directorio actual concatenados y separados por el separador “/”.
	str pwd() const;

	// Muestra por pantalla los nombres de todos los ficheros, directorios y
	// enlaces contenidos en la ruta actual, cada uno de ellos en una línea diferente, sin
	// ningún dato más.
	void ls();

	// Cambia la ruta a otro directorio (path), pasándole el nombre del
	// directorio al que quiere cambiar. Hay tres casos especiales: “.” se refiere al directorio
	// actual, “..” se refiere al directorio anterior en el árbol de directorios y “/” se refiere a la
	// raíz del árbol de directorios. También se le puede pasar como parámetro una ruta
	// completa (varios directorios separados por “/”).
	void cd(STR path);

	// Muestra por pantalla un número que es el tamaño del
	// archivo, directorio o enlace dentro de la ruta actual identificado por la cadena de texto
	// que se le pasa como parámetro. También se le puede pasar una ruta completa.
	void stat(STR element);

	// Cambia el tamaño de un archivo dentro de la
	// ruta actual (no se le puede pasar como parámetro una ruta completa). Si el archivo no
	// existe dentro de la ruta actual, se crea automáticamente con el nombre y tamaño
	// espeficados. Si el archivo referenciado por “file” es en realidad un enlace a un archivo,
	// también cambia su tamaño.◦ void mkdir(STR dir): Crea un directorio dentro de la ruta actual. No se le puede
	// pasar como parámetro una ruta completa.
	void vim(STR file, int size);

	// Crea un enlace simbólico de nombre “dest” a que
	// enlaza el elemento identificado mediante el nombre “orig”. “dest” no puede contener
	// una ruta completa, pero “orig” sí, de tal modo que pueden crearse enlaces simbólicos
	// entre elementos dentro de diferentes posiciones del árbol de directorios.
	void ln(STR orig, STR dest);

 	// Elimina un elemento dentro de la ruta actual (puede pasársele
	// como parámetro una ruta completa). Si es un archivo es simplemente eliminado. Si es
	// un enlace elimina el enlace pero no lo enlazado. Si es un directorio, elimina el directorio
	// y todo su contenido. Los enlaces a elementos borrados, sin embargo, siguen
	// enlazando al elemento borrado. Así pues, para eliminar completamente un elemento
	// hay que borrar el elemento y todos los enlaces que apuntan a dicho elemento de forma
	// manual.
	void rm(STR e);
};

#endif