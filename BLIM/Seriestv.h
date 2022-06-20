#ifndef SERIESTV_H
#define SERIESTV_H

#include <fstream>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <sstream>

using namespace std;

class Seriestv
{

    protected:

        string nombre;

		string categoria;

		int Temporadas;
		int Episodios;

		string duracion;

		string anio;

    public:
        Seriestv(){}

        void Agregar();
		void Imprimir();
		void Buscar();
		void Modificar();
		void Eliminar();

};

#endif // SERIESTV_H
