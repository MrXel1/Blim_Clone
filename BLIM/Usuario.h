#ifndef USUARIO_H
#define USUARIO_H


#include <fstream>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <sstream>

using namespace std;

class Usuario
{

    private:
        char codigoUsuario[30];
        char nombreUsuario[30];
        char apellidoUsuario[30];
        char edad[4];
        char contrasenia[30];
        char direccion[30];
        char telefono[30];
        char tipoMembresia[30];

    public:
        Usuario(){}

        void Agregar();
		void Imprimir();
		void Buscar();
		void Modificar();
		void Eliminar();
        void Encriptar();
        void Desencriptar();
        void EncriptarAux();

};

#endif
