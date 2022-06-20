#include "Pelicula.h"

Pelicula::Pelicula()
{

}

Pelicula::Pelicula(const string &nombre, const string &genero, const string &estreno, const string &idioma)
{
    this->nombre = nombre;
    this->genero = genero;
    this->estreno = estreno;
    this->idioma = idioma;
}

//Setter y Getter NOMBRE
void Pelicula::setNombre(const string &v)
{
    nombre = v;
}

string Pelicula::getNombre()
{
    return nombre;
}

//Setter y Getter GENERO
void Pelicula::setGenero(const string &v)
{
    genero = v;
}

string Pelicula::getGenero()
{
    return genero;
}

//Setter y Getter ESTRENO
void Pelicula::setEstreno(const string &v)
{
    estreno = v;
}

string Pelicula::getEstreno()
{
    return estreno;
}

//Setter y Getter IDIOMA
void Pelicula::setIdioma(const string &v)
{
    idioma = v;
}

string Pelicula::getIdioma()
{
    return idioma;
}
