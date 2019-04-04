#include "ruta.h"
#include <iostream>
#include <memory>
#include "directorio.h"
#include "archivo.h"
#include "enlace.h"

Ruta::Ruta(const Directorio& raiz) {
    ruta = raiz;
}

std::string Ruta::pwd() const {
    
}

void Ruta::ls() const {
    
}

void Ruta::cd(const std::string path) {
    
}

void Ruta::stat(const std::string element) const {
    
}

void Ruta::vim(const std::string file, const int size) const {
    
}

void Ruta::mkdir(const std::string dir) const {
    
}

void Ruta::ln(const std::string orig, const std::string dest) const {
    
}

void Ruta::rm(const std::string e) const {
    
}