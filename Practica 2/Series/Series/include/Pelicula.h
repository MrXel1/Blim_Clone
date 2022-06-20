#ifndef PELICULA_H
#define PELICULA_H

#include <iostream>
#include <iomanip>
#include <list>
#include <conio.h>
#include <algorithm>
#include <ostream>

using namespace std;

class Pelicula
{
    private:
        string nombre, genero, estreno, idioma;

    public:
        Pelicula();

        Pelicula(const string &nombre, const string &genero, const string &estreno, const string &idioma);

        //Setter y Getter NOMBRE
        void setNombre(const string &v);
        string getNombre();

        //Setter y Getter GENERO
        void setGenero(const string &v);
        string getGenero();

        //Setter y Getter ESTRENO
        void setEstreno(const string &v);
        string getEstreno();

        //Setter y Getter IDIOMA
        void setIdioma(const string &v);
        string getIdioma();

        //Sobrecarga operador insercion
        friend ostream& operator<<(ostream &out, const Pelicula &p)
        {
            out << left;
            out << setw(18) << p.nombre;
            out << setw(18) << p.genero;
            out << setw(18) << p.estreno;
            out << setw(18) << p.idioma;
            out << endl;
            return out;
        }

        //Sobrecarga operador extraccion
        friend istream& operator>>(istream &in, Pelicula &p)
        {
            //NOMBRE
            cout << "NOMBRE: ";
            getline(cin, p.nombre);

            //GENERO
            cout << "GENERO: ";
            getline(cin, p.genero);

            //ESTRENO
            cout << "ESTRENO: ";
            getline(cin, p.estreno);

            //IDIOMA
            cout << "IDIOMA: ";
            getline(cin, p.idioma);

            return in;
        }

        //Sobrecarga de operador de comparacion
        bool operator==(const Pelicula& p)
        {
            return nombre == p.nombre;
        }

        bool operator==(const Pelicula& p) const
        {
            return nombre == p.nombre;
        }

};

#endif // PELICULA_H
