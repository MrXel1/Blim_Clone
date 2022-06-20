#include "Administrador.h"
#include "Pelicula.h"
#include <fstream>
#include <algorithm>
#include <iostream>
#include <conio.h>
#include <iomanip>

void Administrador::Agregar(const Pelicula &p)
{
    peliculas.push_front(p);
}

void Administrador::Mostrar()
{
    cout << left;
    cout << setw(18) << "NOMBRE";
    cout << setw(18) << "GENERO";
    cout << setw(18) << "ESTRENO";
    cout << setw(18) << "IDIOMA";
    cout << endl;

    for (auto it = peliculas.begin(); it != peliculas.end(); it++) {
        cout << *it;
    }
}

void Administrador::Respaldar()
{
  ofstream archivo("respaldo.txt");
  if (archivo.is_open())
  {
      for(auto it = peliculas.begin(); it != peliculas.end(); ++it)
      {
        Pelicula &p = *it;
        archivo << p.getNombre() << endl;
        archivo << p.getGenero()   << endl;
        archivo << p.getEstreno() << endl;
        archivo << p.getIdioma()  << endl;

      }
      archivo.close();
  }


}

void Administrador::Recuperar()
{
    ifstream archivo("respaldo.txt");
    if (archivo.is_open())
    {
        string temp;

        while (true)
        {

            Pelicula p;
            getline(archivo, temp);
            if(archivo.eof())
            {
            break;
            }
            p.setNombre(temp);

            getline(archivo,temp);
            p.setGenero(temp);

            getline(archivo,temp);
            p.setEstreno(temp);

            getline(archivo,temp);
            p.setIdioma(temp);

            Agregar(p);

        }
        archivo.close();
    }
}

void Administrador::Eliminar(const string &nombre)
{
    for(auto it = peliculas.begin(); it != peliculas.end(); it++)
    {
        Pelicula &p = *it;
        if(nombre == p.getNombre()){
            peliculas.erase(it);
            break;
        }
    }

}

//BUSCADOR
void Administrador::Buscar(const Pelicula &p)
{
    string noma;
    cout<<" NOMBRE DE LA PELICULA QUE DESEA BUSCAR: ";
    getline(cin, noma);

    for(auto it = peliculas.begin();it!=peliculas.end();it++)
    {
        Pelicula &p=*it;
        if(noma == p.getNombre())
        {
            string nombreA;
            cout<<"PELICULA ENCONTRADA"<<endl;
            cout<<"NOMBRE:"<<p.getNombre()<<endl;
            cout<<"GENERO:"<<p.getGenero()<<endl;
            cout<<"ESTRENO:"<<p.getEstreno()<<endl;
            cout<<"IDIOMA:"<<p.getIdioma()<<endl;
        }
    }
}

//MODIFICAR TODO
void Administrador::ModificarTodo(const Pelicula &p)
{
    string noma;
    cout<<"NOMBRE DE LA PELICULA A MODIFICAR: ";
    getline(cin, noma);

    for(auto it = peliculas.begin();it!=peliculas.end();it++)
    {
        Pelicula &p=*it;
        if(noma == p.getNombre())
        {
            string nombreA,gen,est,idi;

            cout<<"---PELICULA ENCONTRADA---"<<endl;
            cout<<"NOMBRE:"<<p.getNombre()<<endl;
            cout<<"GENERO:"<<p.getGenero()<<endl;
            cout<<"ESTRENO:"<<p.getEstreno()<<endl;
            cout<<"IDIOMA:"<<p.getIdioma()<<endl;

            //NOMBRE
            cout<<"INGRESE NUEVO NOMBRE: ";
            cin>>nombreA;

            p.setNombre(nombreA);

            //GENERO
            cout<<"INGRESE NUEVO GENERO: ";
            cin>>gen;

            p.setGenero(gen);


            //ESTRENO
            cout<<"INGRESE NUEVA AÑO DE ESTRENO: ";
            cin>>est;

            p.setEstreno(est);


            //IDIOMA
            cout<<"INGRESE NUEVO IDIOMA: ";
            cin>>idi;

            p.setIdioma(idi);


            break;


        }
    }

}

//MODIFICAR'S
void Administrador::ModificarNombre(const Pelicula &p)
{
    string noma;
    cout<<"NOMBRE DE LA PELICULA A MODIFICAR: ";
    getline(cin, noma);

    for(auto it = peliculas.begin();it!=peliculas.end();it++)
    {
        Pelicula &p=*it;
        if(noma == p.getNombre())
        {
            string nombreA;
            cout<<"---PELICULA ENCONTRADA---"<<endl;
            cout<<"NOMBRE:"<<p.getNombre()<<endl;
            cout<<"GENERO:"<<p.getGenero()<<endl;
            cout<<"ESTRENO:"<<p.getEstreno()<<endl;
            cout<<"IDIOMA:"<<p.getIdioma()<<endl;

            cout<<"INGRESE NUEVO NOMBRE: "<<endl;
            cin>>nombreA;

            p.setNombre(nombreA);
            cout<<"NOMBRE MODIFICADO"<<endl;

            break;


        }
    }

}

void Administrador::ModificarGenero(const Pelicula &p)
{
    string gen;
    cout<<" NOMBRE DE LA PELICULA A MODIFICAR: ";
    getline(cin, gen);

    for(auto it = peliculas.begin();it!=peliculas.end();it++)
    {
        Pelicula &p=*it;
        if(gen == p.getNombre())
        {
            string nombreA;
            cout<<"---PELICULA ENCONTRADA---"<<endl;
            cout<<"NOMBRE:"<<p.getNombre()<<endl;
            cout<<"GENERO:"<<p.getGenero()<<endl;
            cout<<"ESTRENO:"<<p.getEstreno()<<endl;
            cout<<"IDIOMA:"<<p.getIdioma()<<endl;

            cout<<"INGRESE EL NUEVO GENERO: "<<endl;
            cin>>gen;

            p.setGenero(gen);
            cout<<"GENERO MODIFICADO"<<endl;

            break;


        }
    }

}

void Administrador::ModificarEstreno(const Pelicula &p)
{
    string gen;
    cout<<"NOMBRE DE LA PELICULA A MODIFICAR: ";
    getline(cin, gen);

    for(auto it = peliculas.begin();it!=peliculas.end();it++)
    {
        Pelicula &p=*it;
        if(gen == p.getNombre())
        {
            string nombreA;
            cout<<"---PELICULA ENCONTRADA---"<<endl;
            cout<<"NOMBRE:"<<p.getNombre()<<endl;
            cout<<"GENERO:"<<p.getGenero()<<endl;
            cout<<"ESTRENO:"<<p.getEstreno()<<endl;
            cout<<"IDIOMA:"<<p.getIdioma()<<endl;

            cout<<"INGRESE EL AÑO DE ESTRENO NUEVO: "<<endl;
            cin>>gen;

            p.setEstreno(gen);
            cout<<"AÑO DE ESTRENO MODIFICADO"<<endl;

            break;


        }
    }

}

void Administrador::ModificarIdioma(const Pelicula &p)
{
    string gen;
    cout<<"NOMBRE DE LA PELICULA A MODIFICAR: ";
    getline(cin, gen);

    for(auto it = peliculas.begin();it!=peliculas.end();it++)
    {
        Pelicula &p=*it;
        if(gen == p.getNombre())
        {
            string nombreA;
            cout<<"---PELICULA ENCONTRADA---"<<endl;
            cout<<"NOMBRE:"<<p.getNombre()<<endl;
            cout<<"GENERO:"<<p.getGenero()<<endl;
            cout<<"ESTRENO:"<<p.getEstreno()<<endl;
            cout<<"IDIOMA:"<<p.getIdioma()<<endl;

            cout<<"INGRESE EL NUEVO IDIOMA: ";
            cin>>gen;

            p.setIdioma(gen);
            cout<<"IDIOMA MODIFICADO"<<endl;

            break;


        }
    }

}





