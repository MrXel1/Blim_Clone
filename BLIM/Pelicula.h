#ifndef PELICULA_H
#define PELICULA_H

#include <fstream>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <sstream>
using namespace std;

class Pelicula
{
	protected:
		string Nombre;
		string Categoria;
		string Duracion;
		string Anio;
	public:
		Pelicula();
		
		void Agregar();
		void Imprimir();
		void Buscar();
		void Modificar();
		void Eliminar();
};

#endif
