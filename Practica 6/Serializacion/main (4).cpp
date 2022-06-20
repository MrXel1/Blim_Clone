#include <iostream>
#include <string.h>
#include <fstream>
#include <cstdlib>
#include <windows.h>

#define TAM_LARGO 35
#define TAM_MEDIO 25

using namespace std;

class HistorialUsuario
{
public:
    char nombre[TAM_LARGO], cuenta[TAM_MEDIO];
    int numeroPeliculas, numeroSeries, numeroProgramas;
} Historial;

class IndiceN
{
public:
    char nombre[TAM_LARGO];
    long int posicion;
} ObjINDI;

class nodo
{
public:
    char nombre[TAM_LARGO], cuenta[TAM_MEDIO];
    int numeroPeliculas, numeroSeries, numeroProgramas;
    nodo *siguiente;
    nodo *anterior;
};

typedef nodo *pnodo;

class Lista
{
public:
    pnodo inicio,fin;
    int tam;
    void Inicializar();
    void Agregar();
    void Mostrar();
    void Modificar();
    void Eliminar();
    void Buscar();
    void Cargar();
} lista;

void pausa();

void Lista::Inicializar()
{
    inicio=NULL;
    fin=NULL;
    tam=0;
}

void Lista::Agregar()
{
    ofstream DocumentoGlobal("DocPrincipal.bin",ios::app);
    ofstream DocumentoIndice("Indice.bin",ios::app);
    if(tam==0)
    {
        system("cls");
        cout << endl << endl;
        cout << "\t\t\t    ***************************" << endl;
        cout << "\t\t\t    ** HISTORIAL DEL USUARIO **" << endl;
        cout << "\t\t\t    **        [AGREGAR]      **" << endl;
        cout << "\t\t\t    ***************************" << endl << endl << endl;

        pnodo nuevo=new nodo;
        fflush(stdin);
        cout<<"\n\t\t[+] Nombre de usuario: ";
        cin.getline(Historial.nombre,TAM_LARGO);
        cout<<"\n\t\t[+] Cuenta: ";
        cin.getline(Historial.cuenta,TAM_MEDIO);
        cout<<"\n\t\t[+] Numero de Peliculas vistas recientemente: ";
        cin >> Historial.numeroPeliculas;
        cout<<"\n\t\t[+] Numero de Series vistas recientemente: ";
        cin >> Historial.numeroSeries;
        cout<<"\n\t\t[+] Numero de Programas vistos recientemente: ";
        cin >> Historial.numeroProgramas;

        strcpy(nuevo->nombre,Historial.nombre);
        strcpy(nuevo->cuenta,Historial.cuenta);
        nuevo->numeroPeliculas = Historial.numeroPeliculas;
        nuevo->numeroSeries = Historial.numeroSeries;
        nuevo->numeroProgramas = Historial.numeroProgramas;

        DocumentoGlobal.write((char *)&Historial,sizeof(Historial));
        inicio=nuevo;
        inicio->anterior=NULL;
        fin=nuevo;
        fin->siguiente=NULL;
        strcpy(ObjINDI.nombre,Historial.nombre);
        DocumentoGlobal.seekp(0,DocumentoGlobal.end);
        ObjINDI.posicion=DocumentoGlobal.tellp();
        ObjINDI.posicion=ObjINDI.posicion-sizeof(Historial);
        DocumentoIndice.write((char *)&ObjINDI,sizeof(ObjINDI));
        tam++;
    }
    else
    {
        pnodo nuevo=new nodo;

        system("cls");
        cout << endl << endl;
        cout << "\t\t\t    ***************************" << endl;
        cout << "\t\t\t    ** HISTORIAL DEL USUARIO **" << endl;
        cout << "\t\t\t    **        [AGREGAR]      **" << endl;
        cout << "\t\t\t    ***************************" << endl << endl << endl;

        fflush(stdin);
        cout<<"\n\t\t[+] Nombre de usuario: ";
        cin.getline(Historial.nombre,TAM_LARGO);
        cout<<"\n\t\t[+] Cuenta: ";
        cin.getline(Historial.cuenta,TAM_MEDIO);
        cout<<"\n\t\t[+] Numero de Peliculas vistas recientemente: ";
        cin >> Historial.numeroPeliculas;
        cout<<"\n\t\t[+] Numero de Series vistas recientemente: ";
        cin >> Historial.numeroSeries;
        cout<<"\n\t\t[+] Numero de Programas vistos recientemente: ";
        cin >> Historial.numeroProgramas;

        strcpy(nuevo->nombre,Historial.nombre);
        strcpy(nuevo->cuenta,Historial.cuenta);
        nuevo->numeroPeliculas = Historial.numeroPeliculas;
        nuevo->numeroSeries = Historial.numeroSeries;
        nuevo->numeroProgramas = Historial.numeroProgramas;

        DocumentoGlobal.write((char *)&Historial,sizeof(Historial));
        fin->siguiente=nuevo;
        nuevo->anterior=fin;
        fin=nuevo;
        fin->siguiente=NULL;
        strcpy(ObjINDI.nombre,Historial.nombre);
        DocumentoGlobal.seekp(0,DocumentoGlobal.end);
        ObjINDI.posicion=DocumentoGlobal.tellp();
        ObjINDI.posicion=ObjINDI.posicion-sizeof(Historial);
        DocumentoIndice.write((char *)&ObjINDI,sizeof(ObjINDI));
        tam++;
    }

    cout << "\n\n\t\t Datos agregados con exito....";

    DocumentoGlobal.close();
    DocumentoIndice.close();
}

void Lista::Mostrar()
{
    pnodo actual=inicio;

    if(tam==0)
        cout<<"No hay elementos... "<<endl;
    else
    {
        system("cls");
        cout << endl << endl;
        cout << "\t\t\t***********************************" << endl;
        cout << "\t\t\t** [LISTA HISTORIAL DE USUARIOS] **" << endl;
        cout << "\t\t\t***********************************" << endl << endl;
        cout<< "-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-" << endl;

        while(actual!=NULL)
        {
            cout << "[-] Nombre de usuario   : " << actual->nombre << endl;
            cout << "[-] Tipo de Cuenta      : " << actual->cuenta << endl << endl;
            cout << "[-] Peliculas vistas recientemente : " << actual->numeroPeliculas << endl;
            cout << "[-] Series vistas recientemente    : " << actual->numeroSeries << endl;
            cout << "[-] Programas vistos recientemente : " << actual->numeroProgramas << endl;
            cout<< "-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-" << endl;

            actual=actual->siguiente;
        }
    }
}

void Lista::Modificar()
{
    if(tam==0)
        cout<<"No hay nada que modificar "<<endl;
    else
    {
        ofstream DocumentoAuxGlobal("AuxDocPrincipal.bin",ios::app);
        ofstream DocumentoAuxIndice("AuxDocIndice.bin",ios::app);
        ifstream LecturaDocGlobal("DocPrincipal.bin");
        ifstream LecturaDocIndice("Indice.bin");
        string comparaNombre;
        bool flag=false;
        pnodo actual=inicio;
        if(!LecturaDocIndice.good())
            cout<<"No Existe el Archivo "<<endl;
        else
        {
            system("cls");
            cout << endl << endl;
            cout << "\t\t\t   *************************" << endl;
            cout << "\t\t\t   ** MODIFICAR HISTORIAL **" << endl;
            cout << "\t\t\t   *************************" << endl << endl;
            fflush(stdin);
            cout << "[?] Ingrese el Nombre a Modificar: ";
            fflush(stdin);
            getline(cin,comparaNombre);
            while(actual!=NULL)
            {
                LecturaDocIndice.read((char *)&ObjINDI,sizeof(ObjINDI));
                LecturaDocGlobal.seekg(ObjINDI.posicion);
                LecturaDocGlobal.read((char *)&Historial,sizeof(Historial));
                if(LecturaDocIndice.eof())
                    break;
                if(comparaNombre==actual->nombre)
                {
                    flag=true;

                    cout << endl << "\t[?] Ingrese los nuevos datos:" << endl;
                    fflush(stdin);
                    cout<<"\n\t\t[+] Nombre de usuario: ";
                    cin.getline(Historial.nombre,TAM_LARGO);
                    cout<<"\n\t\t[+] Cuenta: ";
                    cin.getline(Historial.cuenta,TAM_MEDIO);
                    cout<<"\n\t\t[+] Numero de Peliculas vistas recientemente: ";
                    cin >> Historial.numeroPeliculas;
                    cout<<"\n\t\t[+] Numero de Series vistas recientemente: ";
                    cin >> Historial.numeroSeries;
                    cout<<"\n\t\t[+] Numero de Programas vistos recientemente: : ";
                    cin >> Historial.numeroProgramas;

                    strcpy(actual->nombre,Historial.nombre);
                    strcpy(actual->cuenta,Historial.cuenta);
                    actual->numeroPeliculas = Historial.numeroPeliculas;
                    actual->numeroSeries = Historial.numeroSeries;
                    actual->numeroProgramas = Historial.numeroProgramas;

                    DocumentoAuxGlobal.write((char *)&Historial,sizeof(Historial));
                    strcpy(ObjINDI.nombre,Historial.nombre);
                    DocumentoAuxIndice.write((char *)&ObjINDI,sizeof(ObjINDI));

                    cout << endl << "\t[!] Datos Modificados correctamente..." << endl;
                }
                actual=actual->siguiente;
            }
        }
        if(flag==false)
            cout << endl << "\t[!] No se encontro coincidencias con el Nombre ingresado..." << endl;

        DocumentoAuxGlobal.close();
        DocumentoAuxIndice.close();
        LecturaDocGlobal.close();
        LecturaDocIndice.close();
        remove("Indice.bin");
        rename("AuxDocIndice.bin","Indice.bin");
        remove("DocPrincipal.bin");
        rename("AuxDocPrincipal.bin","DocPrincipal.bin");
    }
}

void Lista::Eliminar()
{
    if(tam==0)
        cout<<"No hay nada que eliminar "<<endl;
    else
    {
        string comparaNombre;
        bool flag=false;
        pnodo actual=inicio,sup;
        ofstream DocumentoAuxGlobal("AuxDocPrincipal.bin",ios::app);
        ofstream DocumentoAuxIndice("AuxDocIndice.bin",ios::app);
        ifstream LecturaDocGlobal("DocPrincipal.bin");
        ifstream LecturaDocIndice("Indice.bin");
        if(!LecturaDocIndice.good())
            cout<<"No Existe el Archivo "<<endl;
        else
        {
            system("cls");
            cout << endl << endl;
            cout << "\t\t\t    *************************" << endl;
            cout << "\t\t\t    **  ELIMINA HISTORIAL  **" << endl;
            cout << "\t\t\t    *************************" << endl << endl;
            cin.ignore();
            cout << "\t\t[?] Ingrese el Nombre para Eliminar: ";
            getline(cin,comparaNombre);
            while(actual!=NULL)
            {
                LecturaDocIndice.read((char *)&ObjINDI,sizeof(ObjINDI));
                LecturaDocGlobal.seekg(ObjINDI.posicion);
                LecturaDocGlobal.read((char *)&Historial,sizeof(Historial));
                if(LecturaDocIndice.eof())
                    break;
                if(comparaNombre==actual->nombre)
                {
                    flag=true;
                    sup=actual;
                    if(actual==inicio)
                    {
                        if(tam==1)
                        {
                            cout << endl;
                            cout << "\t[-] Nombre de usuario   : " << actual->nombre << endl;
                            cout << "\t[-] Tipo de Cuenta      : " << actual->cuenta << endl << endl;
                            cout << "\t[-] Peliculas vistas recientemente : " << actual->numeroPeliculas << endl;
                            cout << "\t[-] Series vistas recientemente    : " << actual->numeroSeries << endl;
                            cout << "\t[-] Programas vistos recientemente : " << actual->numeroProgramas << endl;
                            cout<<endl;
                        }
                        else
                        {
                            inicio=actual->siguiente;
                            inicio->anterior=NULL;

                            cout << endl;
                            cout << "\t[-] Nombre de usuario   : " << actual->nombre << endl;
                            cout << "\t[-] Tipo de Cuenta      : " << actual->cuenta << endl << endl;
                            cout << "\t[-] Peliculas vistas recientemente : " << actual->numeroPeliculas << endl;
                            cout << "\t[-] Series vistas recientemente    : " << actual->numeroSeries << endl;
                            cout << "\t[-] Programas vistos recientemente : " << actual->numeroProgramas << endl;
                            cout<<endl;
                        }

                    }
                    else
                    {
                        if(actual==fin)
                        {
                            fin=fin->anterior;
                            fin->siguiente=NULL;
                            cout << endl;
                            cout << "\t[-] Nombre de usuario   : " << actual->nombre << endl;
                            cout << "\t[-] Tipo de Cuenta      : " << actual->cuenta << endl << endl;
                            cout << "\t[-] Peliculas vistas recientemente : " << actual->numeroPeliculas << endl;
                            cout << "\t[-] Series vistas recientemente    : " << actual->numeroSeries << endl;
                            cout << "\t[-] Programas vistos recientemente : " << actual->numeroProgramas << endl;
                            cout<<endl;
                        }
                        else
                        {
                            actual->siguiente->anterior=actual->anterior;
                            actual->anterior->siguiente=actual->siguiente;
                            cout << endl;
                            cout << "\t[-] Nombre de usuario   : " << actual->nombre << endl;
                            cout << "\t[-] Tipo de Cuenta      : " << actual->cuenta << endl << endl;
                            cout << "\t[-] Peliculas vistas recientemente : " << actual->numeroPeliculas << endl;
                            cout << "\t[-] Series vistas recientemente    : " << actual->numeroSeries << endl;
                            cout << "\t[-] Programas vistos recientemente : " << actual->numeroProgramas << endl;
                            cout<<endl;
                        }
                    }
                    delete(sup);
                    tam--;
                    cout << "\t[...] Eliminando Registro";
                    Sleep(300); cout << ".";
                    Sleep(300); cout << ".";
                    Sleep(300); cout << "." << endl << endl;
                    cout << "[!] El registro ha sido eliminado correctamente";
                }
                else
                {
                    DocumentoAuxGlobal.write((char *)&Historial,sizeof(Historial));
                    strcpy(ObjINDI.nombre,actual->nombre);
                    DocumentoAuxGlobal.seekp(0,DocumentoAuxGlobal.end);
                    ObjINDI.posicion=DocumentoAuxGlobal.tellp();
                    ObjINDI.posicion=ObjINDI.posicion-sizeof(Historial);
                    DocumentoAuxIndice.write((char*)&ObjINDI,sizeof(ObjINDI));
                }
                actual=actual->siguiente;
            }
        }
        if(flag==false)
            cout << endl <<"\t[!] No se encontro coincidencia con el Nombre ingresado..."<<endl;

        DocumentoAuxGlobal.close();
        DocumentoAuxIndice.close();
        LecturaDocGlobal.close();
        LecturaDocIndice.close();
        remove("Indice.bin");
        rename("AuxDocIndice.bin","Indice.bin");
        remove("DocPrincipal.bin");
        rename("AuxDocPrincipal.bin","DocPrincipal.bin");
    }
}

void Lista::Buscar()
{
    if(tam==0)
        cout<<"No hay nada que Buscar"<<endl;
    else
    {
        string comparaNombre;
        bool flag=false;
        pnodo actual=inicio;
        system("cls");
        cout << endl << endl;
        cout << "\t\t\t    ************************" << endl;
        cout << "\t\t\t    ** [BUSCAR HISTORIAL] **" << endl;
        cout << "\t\t\t    ************************" << endl << endl;
        cout << "\t\t[?] Ingrese el Nombre a buscar: ";
        cin.ignore();
        getline(cin,comparaNombre);
        while(actual!=NULL)
        {
            if(comparaNombre==actual->nombre)
            {
                flag=true;
                cout << endl;
                cout << "\t[-] Nombre de usuario   : " << actual->nombre << endl;
                cout << "\t[-] Tipo de Cuenta      : " << actual->cuenta << endl << endl;
                cout << "\t[-] Peliculas vistas recientemente : " << actual->numeroPeliculas << endl;
                cout << "\t[-] Series vistas recientemente    : " << actual->numeroSeries << endl;
                cout << "\t[-] Programas vistos recientemente : " << actual->numeroProgramas << endl;
                cout<<endl;
            }
            actual=actual->siguiente;
        }
        if(flag==false)
            cout << endl <<"\t[!] No se encontro coincidencia con el Nombre ingresado..."<<endl;
    }
}

void Lista::Cargar()
{
    ifstream DocumentoGlobal("DocPrincipal.bin");

    if(DocumentoGlobal.is_open())
    {
        while(!DocumentoGlobal.eof())
        {
            DocumentoGlobal.read((char *)&Historial,sizeof(Historial));
            pnodo nuevo = new nodo;

            strcpy(nuevo->nombre,Historial.nombre);
            strcpy(nuevo->cuenta,Historial.cuenta);
            nuevo->numeroPeliculas = Historial.numeroPeliculas;
            nuevo->numeroSeries = Historial.numeroSeries;
            nuevo->numeroProgramas = Historial.numeroProgramas;
            if(tam == 0 && !DocumentoGlobal.eof())
            {
                inicio=nuevo;
                inicio->anterior=NULL;
                fin=nuevo;
                fin->siguiente=NULL;
                tam++;
            }
            else if(tam > 0 && !DocumentoGlobal.eof())
            {
                fin->siguiente=nuevo;
                nuevo->anterior=fin;
                fin=nuevo;
                fin->siguiente=NULL;
                tam++;
            }
        }
    }
    DocumentoGlobal.close();
}

int main()
{
    char opcion[5];

    lista.Cargar();
    do
    {
        system("cls");
        cout << endl << endl;
        cout << "\t\t -----------------------------------------" << endl;
        cout << "\t\t |             SERIALIZACION             |" << endl;
        cout << "\t\t -----------------------------------------" << endl << endl;

        cout << "\t\t MENU HISTORIAL DE USUARIO" << endl;
        cout << "\t\t [1] CAPTURAR\n"
             << "\t\t [2] MOSTRAR\n"
             << "\t\t [3] MODIFICAR\n"
             << "\t\t [4] ELIMINAR\n"
             << "\t\t [5] BUSCAR\n"
             << "\t\t [6] SALIR" << endl;
        cout << "\t\t [/] Ingrese el numero deseado: ";
        cin>>opcion;

        if(strcmp(opcion,"1")== 0)
        {
            system("cls");
            lista.Agregar();
            system("pause>>cls");
        }

        if(strcmp(opcion,"2")== 0)
        {
            system("cls");
            lista.Mostrar();
            system("pause>>cls");
        }

        if(strcmp(opcion,"3")== 0)
        {
            system("cls");
            lista.Modificar();
            system("pause>>cls");
        }

        if(strcmp(opcion,"4")== 0)
        {
            system("cls");
            lista.Eliminar();
            system("pause>>cls");
        }

        if(strcmp(opcion,"5")== 0)
        {
            system("cls");
            lista.Buscar();
            system("pause>>cls");
        }

        if(strcmp(opcion,"6")== 0)
        {
            break;
        }

    }while(strcmp(opcion,"6")!= 0);

    system("cls");
    cout << "\n\n\t\t Saliendo del sistema";
    Sleep(300); cout << ".";
    Sleep(300); cout << ".";
    Sleep(300); cout << ".";
    Sleep(300); cout << "." << endl;
}

void pausa()
{
    cout << endl << "Presione entrar para continuar . . .";
    fflush(stdin);
    getchar();
    fflush(stdin);
}
