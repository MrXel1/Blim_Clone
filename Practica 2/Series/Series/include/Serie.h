#include <iostream>
#include <fstream>
#include <cstring>
#include <string.h>
#include <cstdlib>
#include "ldl.h"
#include "cola.h"

#define TAM_LARGO 50
#define TAM_MEDIO 40
#define TAM_CORTO 3

class Series_TV
{
public:
    char Nombre[TAM_LARGO], Genero[TAM_LARGO], Director[TAM_LARGO], Temporadas[TAM_CORTO], Fecha[TAM_MEDIO];

    void Capturar();
    void Mostrar();
    void Buscar();
    void Modificar();
    void Eliminar();
} Serie;

Cola<Series_TV> cola;

int dimT, dimA, dimD, dimI, dimF, dimP, opc;

void Series_TV::Capturar()
{
    system("cls");

    fflush(stdin);
    cout<<"NOMBRE: ";
    cin.getline(Nombre,TAM_LARGO);
    cout<<"GENERO: ";
    cin.getline(Genero,TAM_LARGO);
    cout<<"DIRECTOR: ";
    cin.getline(Director,TAM_LARGO);
    cout<<"TEMPORADAS: ";
    cin.getline(Temporadas,TAM_CORTO);
    cout<<"ESTRENO: ";
    cin.getline(Fecha,TAM_MEDIO);

    ///Abrimos el archivo y se agregan los datos de acorde a sus dimensiones antes especificadas
    ofstream Archivo("Series.txt",ios::app);
    dimT = strlen(Nombre);
    dimA = strlen(Genero);
    dimD = strlen(Director);
    dimI = strlen(Temporadas);
    dimF = strlen(Fecha);

    ///Se agregan cada uno de los datos
    Archivo.write((char*)&dimT, sizeof(int));
    Archivo.write((char*)&Nombre, dimT);
    Archivo.write((char*)&dimA, sizeof(int));
    Archivo.write((char*)&Genero, dimA);
    Archivo.write((char*)&dimD, sizeof(int));
    Archivo.write((char*)&Director, dimD);
    Archivo.write((char*)&dimI, sizeof(int));
    Archivo.write((char*)&Temporadas, dimI);
    Archivo.write((char*)&dimF, sizeof(int));
    Archivo.write((char*)&Fecha, dimF);
    Archivo.close(); ///Se cierra el archivo

    cola.push(Serie); ///Los mismos datos se anexan a la estructura cola.

    cout << "SE AGREGO LA SERIE CON EXITO" << endl;
}

void Series_TV::Mostrar()
{
    ifstream lectura("Series.txt");
    ///Validamos que el archivo exista
    if(!lectura.good())
    {
        cout<<"\nEl archivo no existe...";
    }
    else
    {

            cout << left;
            cout << setw(18) << "NOMBRE ";
            cout << setw(18) << "GENERO ";
            cout << setw(18) << "DIRECTOR ";
            cout << setw(18) << "TEMPORADAS ";
            cout << setw(18) << "ESTRENO ";
            cout << endl;

        ///Abrimos el archivo en modo lectura

        while(!lectura.eof())
        {
            lectura.read((char*)&dimT, sizeof(int));
            lectura.read((char*)&Nombre, dimT);
            Nombre[dimT] = '\0';
            lectura.read((char*)&dimA, sizeof(int));
            lectura.read((char*)&Genero, dimA);
            Genero[dimA] = '\0';
            lectura.read((char*)&dimD, sizeof(int));
            lectura.read((char*)&Director, dimD);
            Director[dimD] = '\0';
            lectura.read((char*)&dimI, sizeof(int));
            lectura.read((char*)&Temporadas, dimI);
            Temporadas[dimI] = '\0';
            lectura.read((char*)&dimF, sizeof(int));
            lectura.read((char*)&Fecha, dimF);
            Fecha[dimF] = '\0';



            if(lectura.eof())
                break;



            cout << setw(18) << Nombre;
            cout << setw(18) << Genero;
            cout << setw(18) << Director;
            cout << setw(18) << Temporadas;
            cout << setw(18) << Fecha;
            cout << endl;


            if(lectura.eof())

                break;
        }
    }
    ///Cerramos el archivo
    lectura.close();
    ///Respetando los lineamientos de la estructura cola, mostramos el frente de esta.

    if(cola.empty())
    {


    }
    else
    {
                cout << setw(18) << cola.front().Nombre;
                cout << setw(18) << cola.front().Genero;
                cout << setw(18) << cola.front().Director;
                cout << setw(18) << cola.front().Temporadas;
                cout << setw(18) << cola.front().Fecha;
    }

}

void Series_TV::Buscar()
{
    ///Declaramos la variable para la busqueda
    char NombreBuscado[TAM_LARGO];
    int band = 0;
    system("cls");
    ///abrimoe el archivo en modo lectura
    ifstream lectura("Series.txt");
    if(!lectura.good())
    {
        cout<<"\nEl archivo no existe...";
    }
    else
    {
        fflush(stdin);
        cout << "INGRESE EL NOMBRE DE LA SERIE:  ";
        cin.getline(NombreBuscado,TAM_LARGO);

        while(!lectura.eof() && !band)
        {
            lectura.read((char*)&dimT, sizeof(int));
            lectura.read((char*)&Nombre, dimT);
            Nombre[dimT] = '\0';
            lectura.read((char*)&dimA, sizeof(int));
            lectura.read((char*)&Genero, dimA);
            Genero[dimA] = '\0';
            lectura.read((char*)&dimD, sizeof(int));
            lectura.read((char*)&Director, dimD);
            Director[dimD] = '\0';
            lectura.read((char*)&dimI, sizeof(int));
            lectura.read((char*)&Temporadas, dimI);
            Temporadas[dimI] = '\0';
            lectura.read((char*)&dimF, sizeof(int));
            lectura.read((char*)&Fecha, dimF);
            Fecha[dimF] = '\0';
            ///Hacemos la condicional de la busqueda
            if(strcmp(NombreBuscado, Nombre) == 0)
            {
                cout << endl;
                cout << "NOMBRE: " << Nombre << endl;
                cout << "GENERO: " << Genero << endl;
                cout << "DIRECTOR: " << Director << endl;
                cout << "TEMPORADAS: " << Temporadas << endl;
                cout << "ESTRENO: " << Fecha << endl;
                band = 1;
            }
        }
        if (!band)
        {
            ///Mandamos un error si el nombre buscado no existe
            cout << "NO SE ENCUENTRA LA SERIE QUE BUSCO" << endl;
        }
    }
    lectura.close();///Cerramos el archivo
}

void Series_TV::Modificar()
{
    /// Declaramos una bander y la variable del nombre a buscar
    int band = 0;
    char NombreBuscadoMod[TAM_LARGO];

    ///Abrimos el archivo en modo lectura
    ifstream lectura("Series.txt");
    if(!lectura.good())
    {
        cout<<"\nEl archivo no existe...";
    }
    else
    {
        cout << endl;
        cout << "-----MODIFICAR SERIE-----" << endl;
        fflush(stdin);
        cout << "INGRESE LA SERIE QUE DESEA MODIFICAR: ";
        cin.getline(NombreBuscadoMod, TAM_LARGO);
        while(!lectura.eof() && !band)
        {
            lectura.read((char*)&dimT, sizeof(int));
            lectura.read((char*)&Nombre, dimT);
            Nombre[dimT] = '\0';
            lectura.read((char*)&dimA, sizeof(int));
            lectura.read((char*)&Genero, dimA);
            Genero[dimA] = '\0';
            lectura.read((char*)&dimD, sizeof(int));
            lectura.read((char*)&Director, dimD);
            Director[dimD] = '\0';
            lectura.read((char*)&dimI, sizeof(int));
            lectura.read((char*)&Temporadas, dimI);
            Temporadas[dimI] = '\0';
            lectura.read((char*)&dimF, sizeof(int));
            lectura.read((char*)&Fecha, dimF);
            Fecha[dimF] = '\0';
            ///Aplicamos la condicional, si el nombre existe muestra los datos
            if(strcmp(NombreBuscadoMod, Nombre) == 0)
            {
                cout << endl;
                cout << "NOMBRE" << Nombre << endl;
                cout << "GENERO: " << Genero << endl;
                cout << "DIRECTOR: " << Director << endl;
                cout << "TEMPORADAS: " << Temporadas << endl;
                cout << "ESTRENO: " << Fecha << endl;
                band = 1;
                cout<<"DESEA MODIFICAR? SI=1 NO=0: "; ///Cuestionamos al usuario si realmente quiere modifivar
                cin>>opc;
            }

        }
        lectura.close(); ///Cerramos el archivo en modo lectura

        if(opc == 1)
        {
            ///Abrimos el archivo en modo escritura
            ///Y creamos un archivo temporal para aplicar las modificaciones
            ifstream lectura("Series.txt");
            ofstream temporal("temporal.txt", ios::app);
            while(!lectura.eof())
            {
                lectura.read((char*)&dimT, sizeof(int));
                lectura.read((char*)&Nombre, dimT);
                Nombre[dimT] = '\0';
                lectura.read((char*)&dimA, sizeof(int));
                lectura.read((char*)&Genero, dimA);
                Genero[dimA] = '\0';
                lectura.read((char*)&dimD, sizeof(int));
                lectura.read((char*)&Director, dimD);
                Director[dimD] = '\0';
                lectura.read((char*)&dimI, sizeof(int));
                lectura.read((char*)&Temporadas, dimI);
                Temporadas[dimI] = '\0';
                lectura.read((char*)&dimF, sizeof(int));
                lectura.read((char*)&Fecha, dimF);
                Fecha[dimF] = '\0';

                ///Una vez validado que los datos buscados existen en el archivo, hacemos el ingreso de los nuevos datos
                if(strcmp(NombreBuscadoMod, Nombre) == 0)
                {
                    system("cls");
                    cout << endl;
                    cout << "MODIFIQUE LOS NUEVOS VALORES" << endl;
                    fflush(stdin);
                    cout<<"NOMBRE: ";
                    cin.getline(Nombre,TAM_LARGO);
                    cout<<"GENERO: ";
                    cin.getline(Genero,TAM_LARGO);
                    cout<<"DIRECTOR: ";
                    cin.getline(Director,TAM_LARGO);
                    cout<<"TEMPORADAS: ";
                    cin.getline(Temporadas,TAM_CORTO);
                    cout<<"ESTRENO: ";
                    cin.getline(Fecha,TAM_MEDIO);

                    dimT = strlen(Nombre);
                    dimA = strlen(Genero);
                    dimD = strlen(Director);
                    dimI = strlen(Temporadas);
                    dimF = strlen(Fecha);
                }
                if(lectura.eof())
                    break;
                temporal.write((char*)&dimT, sizeof(int));
                temporal.write((char*)&Nombre, dimT);
                temporal.write((char*)&dimA, sizeof(int));
                temporal.write((char*)&Genero, dimA);
                temporal.write((char*)&dimD, sizeof(int));
                temporal.write((char*)&Director, dimD);
                temporal.write((char*)&dimI, sizeof(int));
                temporal.write((char*)&Temporadas, dimI);
                temporal.write((char*)&dimF, sizeof(int));
                temporal.write((char*)&Fecha, dimF);

                if(lectura.eof())
                    break;
            }
            temporal.close();///Se guardan y se cierra el archivo temporal
            lectura.close(); ///Cerramos el archivo series.txt
            remove("Series.txt");///Eliminamos el archivo original
            rename("temporal.txt", "Series.txt");///El archivo temporal se renombra y suple al aoriginal
        }
        if (!band)
        {
            ///Mandamos mensaje de error si el nombre no existe
            cout << "NO EXISTE LA SERIE" << endl;
        }
        else
        {
            ///Terminadas las modificaciones, mandamos mensaje de exito
            cout << "SE HAN MODIFICADO LOS DATOS :)";
        }
    }
}

void Series_TV::Eliminar()
{
    ///Declaramos bandera y la variable para la busqueda
    int band = 0;
    char NombreEliminar[TAM_LARGO];

    ///Abrimos el archivo en modo lectura
    ifstream lectura("Series.txt");
    if(!lectura.good())
    {
        ///Validamos que no este vacio
        cout<<"\nEl archivo no existe...";
    }
    else
    {

        fflush(stdin);
        cout << "INGRESE LA SERIE QUE DESEA ELIMINAR: ";
        cin.getline(NombreEliminar,TAM_LARGO);

        while(!lectura.eof() && !band)
        {
            lectura.read((char*)&dimT, sizeof(int));
            lectura.read((char*)&Nombre, dimT);
            Nombre[dimT] = '\0';
            lectura.read((char*)&dimA, sizeof(int));
            lectura.read((char*)&Genero, dimA);
            Genero[dimA] = '\0';
            lectura.read((char*)&dimD, sizeof(int));
            lectura.read((char*)&Director, dimD);
            Director[dimD] = '\0';
            lectura.read((char*)&dimI, sizeof(int));
            lectura.read((char*)&Temporadas, dimI);
            Temporadas[dimI] = '\0';
            lectura.read((char*)&dimF, sizeof(int));
            lectura.read((char*)&Fecha, dimF);
            Fecha[dimF] = '\0';

            if(strcmp(NombreEliminar, Nombre) == 0)
            {
                cout << endl;
                cout << "NOMBRE:" << Nombre << endl;
                cout << "GENERO: " << Genero << endl;
                cout << "DIRECTOR: " << Director << endl;
                cout << "TEMPORADAS: " << Temporadas << endl;
                cout << "ESTRENO: " << Fecha << endl;

                band = 1;
                cout<<"DESEAS ELIMINAR? SI=1 NO=0: "; ///Cuestionamos al usuario si realmente quiere hacer la eliminacion
                cin>>opc;
            }
        }
        lectura.close(); ///Cerramos el archivo en modo lectura

        if(opc == 1)
        {
            ifstream lectura("Series.txt"); ///Abrimos el archivo en modo lectura de nuevo
            ofstream temporal("temporal.txt", ios::app); ///Creamos un archivo temporal
            while(!lectura.eof())
            {

                lectura.read((char*)&dimT, sizeof(int));
                lectura.read((char*)&Nombre, dimT);
                Nombre[dimT] = '\0';
                lectura.read((char*)&dimA, sizeof(int));
                lectura.read((char*)&Genero, dimA);
                Genero[dimA] = '\0';
                lectura.read((char*)&dimD, sizeof(int));
                lectura.read((char*)&Director, dimD);
                Director[dimD] = '\0';
                lectura.read((char*)&dimI, sizeof(int));
                lectura.read((char*)&Temporadas, dimI);
                Temporadas[dimI] = '\0';
                lectura.read((char*)&dimF, sizeof(int));
                lectura.read((char*)&Fecha, dimF);
                Fecha[dimF] = '\0';

                if(strcmp(NombreEliminar, Nombre) != 0)
                {
                    if(lectura.eof())
                        break;
                    temporal.write((char*)&dimT, sizeof(int));
                    temporal.write((char*)&Nombre, dimT);
                    temporal.write((char*)&dimA, sizeof(int));
                    temporal.write((char*)&Genero, dimA);
                    temporal.write((char*)&dimD, sizeof(int));
                    temporal.write((char*)&Director, dimD);
                    temporal.write((char*)&dimI, sizeof(int));
                    temporal.write((char*)&Temporadas, dimI);
                    temporal.write((char*)&dimF, sizeof(int));
                    temporal.write((char*)&Fecha, dimF);
                    if(lectura.eof())
                        break;
                }
            }
            temporal.close();///CErramos el temporal
            lectura.close();///cerramos el original en modo lectura
            remove("Series.txt");///Eliminamos el archivo original
            rename("temporal.txt", "Series.txt");///renombramos y guardamos el archivo temporal como el original
        }
        if(band == 1 && opc == 1)
        {
            ///Mandamos mensjae de exito en la eliminacion
            cout << "SERIE ELIMINADA";
        }
        else if(band == 1 && opc == 2)
        {
            ///mandamos este mensaje si el usuario selecciono que no queria eliminar
            cout << "SERIE NO ELIMINADA";
        }
        else
        {
            ///Mensaje de error si la serie no existe
            cout << "SERIE NO ENCONTRADA";
        }
        if(!cola.empty())
        {
            int respuesta;
            ///Respetando los lineamientos de la cola, mostramos el mensaje si el usuario quiere eliminar el frente de esta
            cout << "NOMBRE: " << cola.front().Nombre << endl;
            cout << "GENERO: " << cola.front().Genero << endl;
            cout << "DIRECTOR" << cola.front().Director << endl;
            cout << "TEMPORADAS: " << cola.front().Temporadas << endl;
            cout << "ESTRENO: " << cola.front().Fecha << endl;
            cout << "DESEA ELIMAR EL FRENTE DE LA COLA?" << endl;
            cout << "1. SI" << endl;
            cout << "2. NO" << endl;
            cout << "INGRESE UNA OPCION: ";
            cin >> respuesta;
            if(respuesta == 1)
            {
                cola.pop();
                cout << "FRENTE ELIMINADO " << endl;
            }
            else
            {
                cout << "FRENTE DE LA COLA NO ELIMINADO" << endl;
            }
        }
    }
}
