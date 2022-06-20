#include <iostream>
#include "Pelicula.h"
#include "Administrador.h"

using namespace std;

int main()
{
    system("COLOR 0A");

    Administrador a;
    string opc;

    a.Recuperar();

    while (true)
    {
        //MENU
        cout << "-----PELICULAS-----" << endl;
        cout << "1) Agregar Pelicula" << endl; //LISTO
        cout << "2) Mostrar Peliculas" << endl; //LISTO
        cout << "3) Buscar Peliculas" << endl; //LISTO
        cout << "4) Modificar Pelicula" << endl; //LISTO "Varias Opciones"
        cout << "5) Eliminar Pelicula" << endl; //LISTO
        cout << "0) SALIR" << endl;
        cout << "-------------------" << endl;
        cout << endl;
        cout << "Ingresa una opcion: ";

        getline(cin,opc);

        //Opcion 1 "Agregar Peliculas"
        if (opc=="1")
        {
            Pelicula p;
            cin >> p;
            a.Agregar(p);
            a.Respaldar();
            cin.ignore();

        }

        //Opcion 2 "Mostrar Peliculas"
        else if (opc=="2")
        {
            a.Mostrar();
            cin.ignore();
        }

        //Opcion 3 "Buscar Peliculas"
        else if (opc=="3")
        {
            Pelicula p;
            a.Buscar(p);
            cin.ignore();
        }

        //Opcion 4 "Modificar Pelicula"
        else if (opc=="4")
        {
            while (true)
            {
                cout << "-----MODIFICAR-----" << endl;
                cout << "1) MODIFICAR NOMBRE" << endl;
                cout << "2) MODIFICAR GENERO" << endl;
                cout << "3) MODIFICAR ESTRENO" << endl;
                cout << "4) MODIFICAR IDIOMA" << endl;
                cout << "5) MODIFICAR TODOS LOS ATRIBUTOS" << endl;
                cout << "0) SALIR" << endl;
                cout << "-------------------" << endl;
                cout << "Ingrese una opcion: ";
                getline(cin,opc);

                if (opc=="1")
                {
                    Pelicula p;
                    a.ModificarNombre(p);
                    a.Respaldar();
                    cin.ignore();
                }
                else if (opc=="2")
                {
                    Pelicula p;
                    a.ModificarGenero(p);
                    a.Respaldar();
                    cin.ignore();
                }
                else if (opc=="3")
                {
                    Pelicula p;
                    a.ModificarEstreno(p);
                    a.Respaldar();
                    cin.ignore();
                }
                else if (opc=="4")
                {
                    Pelicula p;
                    a.ModificarIdioma(p);
                    a.Respaldar();
                    cin.ignore();
                }
                else if (opc=="5")
                {
                    Pelicula p;
                    a.ModificarTodo(p);
                    a.Respaldar();
                    cin.ignore();
                }
                else if (opc=="0")
                {
                    return main();
                }
            }
        }

        //Opcion 5 "Eliminar Pelicula"
        else if (opc=="5")
        {
            string nombre;
            cout << "Ingrese la pelicula a borrar: ";
            cin >> nombre;

            a.Eliminar(nombre);
            cout << "PELICULA ELIMINADA" << endl;
            cin.ignore();
            a.Respaldar();
            cin.ignore();
        }

        //Opcion 0 "SALIR"
        else if (opc=="0")
        {
            break;
        }
    }


    return 0;
}
