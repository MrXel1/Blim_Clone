#ifndef SERIES_H
#define SERIES_H
#include<iostream>

using namespace std;

class Series
{
    public:
        Series(){}

        void setnombre(const string &value);
        string getnombre() const;

        void setcategoria(const string &value);
        string getcategoria() const;

        void settemporadas(const string &value);
        string gettemporadas() const;

        void setepisodios(const string &value);
        string getepisodios() const;

        void setduracion(const string &value);
        string getduracion() const;

        void setanio(const string &value);
        string getanio() const;

        void setCodigo(const string &value);
        string getCodigo() const;

        void setBandera(const string &value);
        string getBandera() const;

        friend ostream& operator << (ostream &out, const Series &t)
        {
            out<<t.getnombre() <<","
               <<t.getcategoria() <<","
               <<t.gettemporadas() <<","
               <<t.getepisodios() <<","
               <<t.getduracion() <<","
               <<t.getanio() <<","
               <<t.getCodigo() <<","
               <<t.getBandera() <<",";
            return out;
        }

    private:
        string nombre;
        string categoria;
        string temporadas;
        string episodios;
        string duracion;
        string anio;
        string codigo;
        string bandera;
};


#endif
