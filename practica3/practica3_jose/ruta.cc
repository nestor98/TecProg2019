#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ruta.h"
#include "elemento.h"

#include <list>


class Ruta {
		Ruta(std::string nom) nombre(nom)		
		
		std::string Ruta::pwd(){
			return nombre;
		}
		
		void Ruta::ls(){
			ls();
		}

		void cd(std::string path){
			//busca el directorio de dentro de la lista.
			// preguntas si el archivo encontrado es un directorio.
			// Si no se dan ninguna de las dos cosas salta una excepción.

		}
		
		void vim( std::string file, int size){
			//si el nombre del archivo no está en la lista se crea un archivo con ese nombre.
			// Si es un enlace a un archivo, se tambien se cambia su tamaño.
			try{

			}
			catch{


			}

		}

		void mkdir(std::string dir){
			//Añade a la lista un directorio con este nombre.
			//Si ya existe, salta una excepción
			try{

			}
			catch{


			}
			
		}

		void ln(std::string orig, std::string dest){
			//Crea un enlace simbolico.
			//Orig es una ruta completa.
		}


		void rm(std::string e){
			//elimina el elemento de nombre e. Se le pude pasar una ruta completa.
			//Si es un directorio, es recursivo, todo lo que hay dentro se va a tomar por culo.
			//Los enlaces a elementos borrados, siguen enlazados a ese elemento. En suma, si quieres borras un archivo, tienes que borrarlo a él y a todos los enlaces, uno por uno y de manera manual.
		}



}
