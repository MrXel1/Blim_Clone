#include "Series.h"

void Series::setnombre(const string &value)
{
    nombre = value;
}

string Series::getnombre() const
{
    return nombre;
}

void Series::setcategoria(const string &value)
{
    categoria = value;
}

string Series::getcategoria() const
{
    return categoria;
}

void Series::settemporadas(const string &value)
{
    temporadas = value;
}

string Series::gettemporadas() const
{
    return temporadas;
}

void Series::setepisodios(const string &value)
{
    episodios = value;
}

string Series::getepisodios() const
{
    return episodios;
}

void Series::setduracion(const string &value)
{
    duracion = value;
}

string Series::getduracion() const
{
    return duracion;
}

void Series::setanio(const string &value)
{
    anio = value;
}

string Series::getanio() const
{
    return anio;
}

void Series::setCodigo(const string &value)
{
    codigo = value;
}

string Series::getCodigo() const
{
    return codigo;
}

void Series::setBandera(const string &value)
{
    bandera = value;
}

string Series::getBandera() const
{
    return bandera;
}
