#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "elemento.h"
#include "ruta.h"

class Archivo : public Elemento {
	ruta& ruta;
	int tamanyo;

}
