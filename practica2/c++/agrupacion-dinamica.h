#ifndef AGRUPACION_DINAMICA_H
#define AGRUPACION_DINAMICA_H

// Interfaz del TAD agrupación genérico. Pre-declaraciones:
// const int MAX = 40; En memoria dinamica no tenemos limite de tamaño

template<typename T>
class agrupacion_dinamica{
	
private: 
	//Mantenemos aqui los mismos atributos privados, ignorando aquellos que tengan que ver
	//con el iterador
	friend class Nodo;

	class Nodo {
	private:
		T dato;
		Nodo* ptSiguiente;
	public:
		// Constructor (invoca tb al de dato). nodo siguiente por defecto es nullptr
		Nodo(const T dato_,  Nodo* siguiente = nullptr) : dato(dato_), ptSiguiente(siguiente) {
			// ptSiguiente = siguiente;
		}

		friend class const_iterator;
		friend class agrupacion_dinamica;
	};
	Nodo* ptUltimo;
	int total; 

public:
//	Ahora la funcion iniciar de la estructura es el constructor. 
	agrupacion_dinamica() : ptUltimo(nullptr), total(0) {  
		//Si invocas a los constructores de los miembros privados no necesitas rellenar el código del constructor.
	}

	~agrupacion_dinamica() {  
		Nodo* actual = ptUltimo;
		Nodo* sig;
		while (actual != nullptr) {
			sig = actual->ptSiguiente;
			delete actual;
			actual = sig;
		}
	}

//	TODO: La funcion anyadir ahora es el metodo anyadir. Rellénalo. Para acceder a atributos
//	y métodos de la propia clase, deberás hacerlo a través del puntero this->
	void anyadir(const T& p) {
		ptUltimo = new Nodo(p, ptUltimo);
		total++;
	}

//	TODO: La funcion borrarUltimo se transforma tambien en un metodo. Rellénalo.
	bool borrarUltimo()	{
		bool sePuede = ptUltimo != nullptr;
		if (sePuede) {
			Nodo* aux = ptUltimo->ptSiguiente;
			delete[] ptUltimo;
			ptUltimo = aux;
			total--;
		}
		return sePuede;
	}

	//Declarando la clase const_iterator (iterador constante) como friend y como
	//clase local, conseguimos que pueda haber varios iteradores, cada uno de ellos
	//llevando su propio "puntero" a que parte de la estructura estamos
	friend class const_iterator;
    
	class const_iterator {
	private:
		//Al separar el iterador en una clase aparte, trasladamos los miembros privados que estaban
		//en el struct a esta clase. Además, mantenemos una referencia a la agrupacion_dinamica.
		Nodo* i;
		const agrupacion_dinamica<T>& c; // PUEDE QUE AQUI NO HAGA FALTA
	public:
		//Este constructor sirve como inicializador del iterador, tanto al principio como al final.
		const_iterator(const agrupacion_dinamica& c_, Nodo* i_) : c(c_) {
			i = i_; // Apunta al ultimo nodo añadido
		}
		
	//	En la definición por defecto de los iteradores, se separa el avance del iterador
	//	a la obtención del elemento apuntado por el iterador (que en la otra implementación ocurren
	//	en la misma función.
	
		//Este método redefine el operador de pre-incremento (++x).
		//Representa el avance del iterador.
		const_iterator& operator++() { 	
			i = i->ptSiguiente; // la estructura se recorre desde el último elemento introducido 
			 	 // hasta el primero (como si se tratara de una pila).  
			return (*this);
       	}

		//Este método redefine el operador de "apuntado" (*x)
		//Representa la obtención de lo apuntado por el iterador.
		const T& operator*()   const 
		{
			return i->dato;

			//TODO: Rellena este método para que devuelva el elemento T al que está apuntando el iterador.	
		} 


	//	En la definición por defecto de los iteradores, no existe la comprobación de si existe
	//	siguiente elemento. Por defecto las estructuras de datos devuelven iteradores al principio y al final,
	//	y para recorrer la estructura se compara el iterador que avanza con el iterador que apunta al final
	//	de la estructura.
	//
		bool operator!=(const const_iterator& that) const 
		{ 
			return ((&(this->c) != &(that.c)) || (this->i != that.i)); // Comparamos los indices
			//Devuelve true sii este iterador y el iterador "that" apuntan a sitios diferentes
		}		

	};

	//Observa como nuestra agrupacion_dinamica permite generar dos iteradores: uno al principio y otro al final.
	//El iterador que apunta al final de la agrupación se mantiene en este caso únicamente para hacer
	//la comprobación de que "existe siguiente".
	//Date cuenta que los valores que le pasamos como índice del iterador son para que se recorra la
	//estructura desde el último elemento (this->total - 1) hasta el primero (0).
	const_iterator begin() const { return const_iterator(*this, this->ptUltimo); }
	const_iterator end()   const { return const_iterator(*this, nullptr); }
};

#endif //fin de agrupacion_dinamica.h
