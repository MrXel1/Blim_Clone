#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstring>
#include "lsl.h"

#define TAM_LARGO 50
#define TAM_MEDIO 20
#define TAM_CORTO 16

using namespace std;


class Usuario
{
public:
    char Nombre[TAM_LARGO], User[TAM_CORTO], Password[TAM_MEDIO];

    void Capturar();
    void Mostrar();
    void Buscar();
    void Modificar();
    void Eliminar();
    void Cargar();
} Registro;

LSL<Usuario> lista;

int dimN, dimC, dimPassword, opc;

void Usuario::Capturar()
{
    system("cls");
    cout << endl << endl;
    cout << "\t\t\t     **********************" << endl;
    cout << "\t\t\t     ** SECCION CAPTURAR **" << endl;
    cout << "\t\t\t     **********************" << endl << endl << endl;

    fflush(stdin);
    cout<<"\n\t\t[+] Nombre: ";
    cin.getline(Nombre,TAM_LARGO);
    cout<<"\n\t\t[+] Usuario: ";
    cin.getline(User,TAM_CORTO);
    cout<<"\n\t\t[+] Contraseña   : ";
    cin.getline(Password,TAM_MEDIO);

    ofstream Archivo("Usuarios.txt",ios::app);
    dimN = strlen(Nombre);
    dimC = strlen(User);
    dimPassword = strlen(Password);

    Archivo.write((char*)&dimN, sizeof(int));
    Archivo.write((char*)&Nombre, dimN);
    Archivo.write((char*)&dimC, sizeof(int));
    Archivo.write((char*)&User, dimC);
    Archivo.write((char*)&dimPassword, sizeof(int));
    Archivo.write((char*)&Password, dimPassword);
    Archivo.close();

    lista.push_back(Registro);

    cout << "\n\t\t Usuario Creado correctamente...";
}

void Usuario::Mostrar()
{
    ifstream lectura("Usuarios.txt");

    if(!lectura.good())
    {
        cout<<"\nEl archivo no existe...";
    }
    else
    {
        cout << endl;
        cout << "\t\t     **********************" << endl;
        cout << "\t\t     ** SECCION  MOSTRAR **" << endl;
        cout << "\t\t     **********************" << endl << endl;
        while(!lectura.eof())
        {
            lectura.read((char*)&dimN, sizeof(int));
            lectura.read((char*)&Nombre, dimN);
            Nombre[dimN] = '\0';
            lectura.read((char*)&dimC, sizeof(int));
            lectura.read((char*)&User, dimC);
            User[dimC] = '\0';
            lectura.read((char*)&dimPassword, sizeof(int));
            lectura.read((char*)&Password, dimPassword);
            Password[dimPassword] = '\0';

            if(lectura.eof())
                break;

            cout << "[-]Nombre : " << Nombre << endl;
            cout << "[-]User : " << User << endl;
            cout << "[-]Password    : " << Password << endl;
            cout << "-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-" << endl;

            if(lectura.eof())
                break;
        }
    }
    lectura.close();
    cout << "\t\t     **********************" << endl;
    cout << "\t\t     **   MOSTRAR LISTA  **" << endl;
    cout << "\t\t     **********************" << endl << endl << endl;
    for(size_t i=0; i<lista.size(); ++i)
    {
        cout << "[-]Nombre : " << lista[i].Nombre << endl;
        cout << "[-]User : " << lista[i].User << endl;
        cout << "[-]Password    : " << lista[i].Password << endl;
        cout << "-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-" << endl;
    }
}

void Usuario::Buscar()
{
    char NombreBuscado[TAM_LARGO];
    int band = 0;
    system("cls");

    ifstream lectura("Usuarios.txt");
    if(!lectura.good())
    {
        cout<<"\nEl archivo no existe...";
    }
    else
    {
        cout << endl << endl;
        cout << "\t\t\t     **********************" << endl;
        cout << "\t\t\t     **  SECCION BUSCAR  **" << endl;
        cout << "\t\t\t     **********************" << endl << endl;
        fflush(stdin);
        cout << "\t\t[?] Ingrese el Nombre a buscar: ";
        cin.getline(NombreBuscado,TAM_LARGO);

        while(!lectura.eof() && !band)
        {
            lectura.read((char*)&dimN, sizeof(int));
            lectura.read((char*)&Nombre, dimN);
            Nombre[dimN] = '\0';
            lectura.read((char*)&dimC, sizeof(int));
            lectura.read((char*)&User, dimC);
            User[dimC] = '\0';
            lectura.read((char*)&dimPassword, sizeof(int));
            lectura.read((char*)&Password, dimPassword);
            Password[dimPassword] = '\0';

            if( strcmp(NombreBuscado, Nombre) == 0)
            {
                cout << endl;
                cout << "[-]Nombre : " << Nombre << endl;
                cout << "[-]User : " << User << endl;
                cout << "[-]Password    : " << Password << endl;
                band = 1;
            }
        }
        if (!band)
        {
            cout << "NO SE ENCUENTRA EL PRODUCTO..." << endl;
        }
    }
    lectura.close();
}

void Usuario::Modificar()
{
    int band = 0;
    char NombreBuscadoMod[TAM_LARGO];


    ifstream lectura("Usuarios.txt");
    if(!lectura.good())
    {
        cout<<"\nEl archivo no existe...";
    }
    else
    {
        cout << endl << endl;
        cout << "\t\t\t    ***********************" << endl;
        cout << "\t\t\t    ** SECCION MODIFICAR **" << endl;
        cout << "\t\t\t    ***********************" << endl << endl;
        fflush(stdin);
        cout << "[?] Ingrese el Nombre a buscar y posteriormente a Modificar: ";
        cin.getline(NombreBuscadoMod, TAM_LARGO);
        while(!lectura.eof() && !band)
        {
            lectura.read((char*)&dimN, sizeof(int));
            lectura.read((char*)&Nombre, dimN);
            Nombre[dimN] = '\0';
            lectura.read((char*)&dimC, sizeof(int));
            lectura.read((char*)&User, dimC);
            User[dimC] = '\0';
            lectura.read((char*)&dimPassword, sizeof(int));
            lectura.read((char*)&Password, dimPassword);
            Password[dimPassword] = '\0';

            if(strcmp(NombreBuscadoMod, Nombre) == 0)
            {
                cout << endl;
                cout << "[-]Nombre : " << Nombre << endl;
                cout << "[-]User : " << User << endl;
                cout << "[-]Password    : " << Password << endl;
                band = 1;
                cout<<"DESEA MODIFICAR?\n1.SI\n0.NO\n>: ";
                cin>>opc;
            }

        }
        lectura.close();

        if(opc == 1)
        {
            ifstream lectura("Usuarios.txt");
            ofstream temporal("temporal.txt", ios::app);
            while(!lectura.eof())
            {
                lectura.read((char*)&dimN, sizeof(int));
                lectura.read((char*)&Nombre, dimN);
                Nombre[dimN] = '\0';
                lectura.read((char*)&dimC, sizeof(int));
                lectura.read((char*)&User, dimC);
                User[dimC] = '\0';
                lectura.read((char*)&dimPassword, sizeof(int));
                lectura.read((char*)&Password, dimPassword);
                Password[dimPassword] = '\0';

                if(strcmp(NombreBuscadoMod, Nombre) == 0)
                {
                    system("cls");
                    cout << endl;
                    cout << "MODIFIQUE LOS NUEVOS VALORES" << endl << endl;
                    fflush(stdin);
                    cout<<"\n\t\t[+] Nombre: ";
                    cin.getline(Nombre,TAM_LARGO);
                    cout<<"\n\t\t[+] User: ";
                    cin.getline(User,TAM_LARGO);
                    cout<<"\n\t\t[+] Password: ";
                    cin.getline(Password,TAM_LARGO);

                    dimN = strlen(Nombre);
                    dimC = strlen(User);
                    dimPassword = strlen(Password);
                }
                if(lectura.eof())
                    break;
                temporal.write((char*)&dimN, sizeof(int));
                temporal.write((char*)&Nombre, dimN);
                temporal.write((char*)&dimC, sizeof(int));
                temporal.write((char*)&User, dimC);
                temporal.write((char*)&dimPassword, sizeof(int));
                temporal.write((char*)&Password, dimPassword);

                if(lectura.eof())
                    break;
            }
            temporal.close();
            lectura.close();
            remove("Usuarios.txt");
            rename("temporal.txt", "Usuarios.txt");
        }

    }
    cout << "\n\n\t\t Usuario modificado con exito....";
    lista.clear();
    Cargar();
}

void Usuario::Eliminar()
{
    int band = 0;
    char NombreEliminar[TAM_LARGO];

    ifstream lectura("Usuarios.txt");
    if(!lectura.good())
    {
        cout<<"\nEl archivo no existe...";
    }
    else
    {
        cout << endl << endl;
        cout << "\t\t\t     **********************" << endl;
        cout << "\t\t\t     ** SECCION ELIMINAR **" << endl;
        cout << "\t\t\t     **********************" << endl << endl;
        fflush(stdin);
        cout << "[?] Ingrese el Nombre para Eliminar: ";
        cin.getline(NombreEliminar,TAM_LARGO);

        while(!lectura.eof() && !band)
        {
            lectura.read((char*)&dimN, sizeof(int));
            lectura.read((char*)&Nombre, dimN);
            Nombre[dimN] = '\0';
            lectura.read((char*)&dimC, sizeof(int));
            lectura.read((char*)&User, dimC);
            User[dimC] = '\0';
            lectura.read((char*)&dimPassword, sizeof(int));
            lectura.read((char*)&Password, dimPassword);
            Password[dimPassword] = '\0';

            if(strcmp(NombreEliminar, Nombre) == 0)
            {
                cout << endl;
                cout << "[-]Nombre : " << Nombre << endl;
                cout << "[-]User : " << User << endl;
                cout << "[-]Password    : " << Password << endl;
                band = 1;
                cout<<"DESEAS ELIMINAR?\n1.- SI\n0.- NO\n>: ";
                cin>>opc;
            }
        }
        lectura.close();

        if(opc == 1)
        {
            ifstream lectura("Usuarios.txt");
            ofstream temporal("temporal.txt", ios::app);
            while(!lectura.eof())
            {

                lectura.read((char*)&dimN, sizeof(int));
                lectura.read((char*)&Nombre, dimN);
                Nombre[dimN] = '\0';
                lectura.read((char*)&dimC, sizeof(int));
                lectura.read((char*)&User, dimC);
                User[dimC] = '\0';
                lectura.read((char*)&dimPassword, sizeof(int));
                lectura.read((char*)&Password, dimPassword);
                Password[dimPassword] = '\0';

                if(strcmp(NombreEliminar, Nombre) != 0)
                {
                    if(lectura.eof())
                        break;
                    temporal.write((char*)&dimN, sizeof(int));
                    temporal.write((char*)&Nombre, dimN);
                    temporal.write((char*)&dimC, sizeof(int));
                    temporal.write((char*)&User, dimC);
                    temporal.write((char*)&dimPassword, sizeof(int));
                    temporal.write((char*)&Password, dimPassword);
                    if(lectura.eof())
                        break;
                }
            }
            temporal.close();
            lectura.close();
            remove("Usuarios.txt");
            rename("temporal.txt", "Usuarios.txt");
        }
    }
    lista.clear();
    Cargar();
}

void Usuario::Cargar()
{
    ifstream lectura("Usuarios.txt");

    if(lectura.good())
    {
        while(!lectura.eof())
        {
            lectura.read((char*)&dimN, sizeof(int));
            lectura.read((char*)&Nombre, dimN);
            Nombre[dimN] = '\0';
            lectura.read((char*)&dimC, sizeof(int));
            lectura.read((char*)&User, dimC);
            User[dimC] = '\0';
            lectura.read((char*)&dimPassword, sizeof(int));
            lectura.read((char*)&Password, dimPassword);
            Password[dimPassword] = '\0';

            if(lectura.eof())
                break;

            lista.push_back(Registro);

            if(lectura.eof())
                break;
        }
    }
    lectura.close();
}

int main()
{
    char opcion [5];

    Registro.Cargar();
    do
    {
        system("cls");
        cout << endl << endl;
        cout << "\t\t -----------------------------------------" << endl;
        cout << "\t\t |       REGISTROS DE LONGITUD FIJA      |" << endl;
        cout << "\t\t |             CLASE USUARIO             |" << endl;
        cout << "\t\t -----------------------------------------" << endl << endl;
        cout << "\t\t MENU" << endl;
        cout << "\t\t [1] CAPTURAR" << endl;
        cout << "\t\t [2] MOSTRAR" << endl;
        cout << "\t\t [3] BUSCAR" << endl;
        cout << "\t\t [4] MODIFICAR" << endl;
        cout << "\t\t [5] ELIMINAR" << endl;
        cout << "\t\t [6] SALIR" << endl;
        cout << "\t\t [/] Ingrese el numero deseado: ";
        cin>>opcion;

        if(strcmp(opcion, "1") == 0)
        {
            system("cls");
            Registro.Capturar();
            system("pause>>cls");
        }

        if(strcmp(opcion, "2")== 0)
        {
            system("cls");
            Registro.Mostrar();
            system("pause>>cls");
        }

        if(strcmp(opcion, "3")== 0)
        {
            system("cls");
            Registro.Buscar();
            system("pause>>cls");
        }

        if(strcmp(opcion, "4")== 0)
        {
            system("cls");
            Registro.Modificar();
            system("pause>>cls");
        }

        if(strcmp(opcion, "5")== 0)
        {
            system("cls");
            Registro.Eliminar();
            system("pause>>cls");
        }

        if(strcmp(opcion, "6")== 0)
        {
            break;
        }

    }
    while(opcion != "6");

    system("cls");
    cout << "\n\n\t\t Saliendo del sistema..." << endl;
    system("pause>>cls");
    return 0;
}
