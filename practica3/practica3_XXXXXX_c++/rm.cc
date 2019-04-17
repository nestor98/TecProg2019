void Ruta::rm(const string e) {
    try{
    	ruta.back()->eliminarElto(e);
	}
	catch(noEncontrado& f){ // no es ruta relativa
		try { // probamos con la absoluta
			list<shared_ptr<Directorio>> copy = ruta;
			size_t pos = e.find_last_of("/"); // pos de la ultima "/" de <e>
			if (pos == string::npos) { // no ha encontrado
				throw rutaCdInvalida();
			}
			// cout << "La pos es " << pos << endl;
			// cout << "La ruta es " << e.substr(0, pos) << endl;
			// cout << "El nombre es " << e.substr(pos+1) << endl;
			this->cd(e.substr(0, pos));
			this->rm(e.substr(pos+1));
			ruta = copy; // volvemos a donde estabamos
		}
		catch (rutaCdInvalida ff) { // ni relativa ni absoluta
			cout << e << " no existe." << endl;
		}
	}
}

//Copiar en directorio.h y directorio.cc
void eliminarElto(const string e);


void Directorio::eliminarElto(const string e){
	bool encontrado = false;
	for (auto it1=nodos.begin(); it1!=nodos.end(); ++it1) {
		if ((*it1)->nombre() == e) {
			encontrado = true;
			nodos.erase(it1);
			break;
		}
	}
	if (!encontrado) {
		throw noEncontrado();
	}	
}
