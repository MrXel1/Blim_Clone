#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H
#include "Pelicula.h"
#include <list>
#include <conio.h>
#include <algorithm>
#include <iomanip>
#include <iostream>

using namespace std;

class Administrador
{
   public:
        //FUNCIONES
        void Agregar(const Pelicula &p);
        void Mostrar();
        void Eliminar(const string &nombre);
        void Respaldar();
        void Recuperar();
        void Buscar(const Pelicula &p);

        //FUNCIONES MODIFICAR
        void ModificarNombre(const Pelicula &p);
        void ModificarGenero(const Pelicula &p);
        void ModificarEstreno(const Pelicula &p);
        void ModificarIdioma(const Pelicula &p);

        //FUNCION MODIFICAR TODO
        void ModificarTodo(const Pelicula &p);

    private:
        list<Pelicula>peliculas;
};

#endif // ADMINISTRADOR_H
