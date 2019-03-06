//Similar a los includes de C++, traemos aquellas clases que nos seran utiles
import java.lang.Iterable;
import java.util.Iterator;
import java.util.NoSuchElementException;
import java.lang.UnsupportedOperationException;


//En Java, no existe el concepto de pre-declaracion ni de funcion. Java es un 
//lenguaje puramente orientado a objetos, por lo que todo son clases.
//
//El uso de programación paramétrica no requiere ninguna palabra clave. Directamente ponemos
//el tipo parámetro entre corchetes.
//Para hacer uso de iteradores, implementamos el interfaz Iterable<T>. Esto es un mecanismo
//básico de la herencia en Java que es inevitable en este caso y sobre el que hablaremos
//más adelante en clase de teoría.
public class AgrupacionDinamica<T> implements Agrupacion<T> {
	//Esta es la única forma que tiene Java de declarar valores inmutables.
	// private static final int MAX = 40; es dinamica

	//Habrás notado que en Java no hay bloques "private" y "public", sino que es una palabra clave
	//que se pone en cada elemento (atributo o método).
	protected Nodo<T> ptUltimo; // Puntero??
	protected int total;

	protected class Nodo<T> {
		private T dato;
		private Nodo siguiente; // Supongo que las referencias son asi tal cual...

		public Nodo(T dato_, Nodo siguienteN) {
			// No se yo si esto es asi...
			dato = dato_;
			siguiente = siguienteN; 
		}
	}

	//El constructor de Java llama a los constructores de los parámetros dentro del bloque de código.
	@SuppressWarnings("unchecked")
	public AgrupacionDinamica() {
		ptUltimo = null; // nullptr supongo
		total = 0;
	}

	public boolean anyadir(T t) {
		ptUltimo = new Nodo(t, ptUltimo); // a ver si chuta
		total++;
		return true; // Creo que la f tiene que ser boolean si o si
	}

	public boolean borrarUltimo() {
		boolean posible = total>0; // o ptUltimo != null
		if (posible) {
			total--;
			ptUltimo = ptUltimo.siguiente;
			// Se supone que java borrara automaticamente el dato (garbage collector?)
		}
		return posible;
	}

	//Esta clase representa a un iterador sobre la agrupación. De nuevo, por el comportamiento estándar de los
	//iteradores en Java, deberemos utilizar la herencia.
	private class IteradorAgrupacionDinamica<T> implements Iterator<T> 
	{

		//Aquí declaramos los atributos
		// AgrupacionDinamica<T> ag; // Puede que sobre aqui

		private AgrupacionDinamica<T>.Nodo<T> i;

		//Este es el constructor del iterador.
		private IteradorAgrupacionDinamica(AgrupacionDinamica<T> ag) {
			// this.ag = ag;	
			i = ag.ptUltimo;
		}

		//Todos los iteradores deben de implementar un método que devuelva
		//si hay siguiente elemento (o no).
		public boolean hasNext() {
			return i!=null;
		}

		//Todos los iteradores deben de implementar un método que devuelva el elemento
		//en la posción actual y avance el iterador. Por construcción, este método debe
		//lanzar una excepción si no existe el siguiente elemento.
		//Recuerda que se recorren desde el último al primero.
		public T next() throws NoSuchElementException
		{
			//Aquí lanzamos la excepción
			if (!hasNext()) throw new NoSuchElementException();
			else {
				T d = i.dato;
				i = i.siguiente;
				return d; // Devuelve el apuntado y avanza el iter
			}
		}
 
		//Los iteradores en Java tienen que tener este método, también. Para no implementarlo (no lo vamos
		//a usar y nuestra definición de agrupación no lo incluye) simplemente lanzamos una excepción.
		public void remove() throws UnsupportedOperationException 
		{
			throw new UnsupportedOperationException();
		}
	}

	//Este método de la estructura de datos simplemente devuelve un nuevo iterador con el que recorrerse la estructura de datos.
	public Iterator<T> iterator() {
		return new IteradorAgrupacionDinamica<T>(this);
	}
}
