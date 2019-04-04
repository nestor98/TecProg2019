#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include <list>
#include "elemento.h"
#include "ruta.h"

class Directorio : public elemento {
	private:
		Ruta& ruta;
		std::list<elemento> elementos;
	public:
		void ls();

}
