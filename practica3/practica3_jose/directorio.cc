
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include <list>
#include "elemento.h"
#include "ruta.h"
#include "directorio.h"

class Directorio : public elemento {
	public:
		void Directorio::ls(){
			for (int i : elementos) i.nombre();	
		}
}
