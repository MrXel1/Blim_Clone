#ifndef USUARIOS_H
#define USUARIOS_H

#include <fstream>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <sstream>

using namespace std;

class Usuarios
{

    protected:

        string nombre;
        string contrasena;
        string subUsuarios[3];
        int edad[4];

    public:
       Usuarios();

        void Agregar();
		void Imprimir();
		void Buscar();
		void Modificar();
		void Eliminar();

};

#endif // USUARIOS_H
