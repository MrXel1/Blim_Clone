#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>

#include "Series.h"
#include "list.h"

using namespace std;

class menu
{
    public:
        menu();

        void crearS(Series &t);
        void mostrar(Series &t);
        void escribir(const Series &t);
        void MostrarS();
        void coding();

        void BuscarS();
        void ModificarS();
        void Eliminar_F_S();
        void Eliminar_L_S();
        void ActivarS();

        void Huffman();
        void cargarFrase();
        void mostrarLista();
        void listaOrdenada();
        void mostrarListaArbol();

        void mostrarDiccionario();

        void descifrado();

        void setcont(int value);
        int getcont() const;

        void setTexto(const string &value);
        string getTexto() const;

    private:
        int cont=0;
        List lista;
        string texto;

};

#endif // MENU_H
