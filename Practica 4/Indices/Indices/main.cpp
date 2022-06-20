#include <iostream>
#include <string.h>
#include <fstream>
#include <cstdlib>

#define TAM_LARGO 35
#define TAM_MEDIO 25
#define TAM_CORTO 15

using namespace std;

void pausa();

class DetallesUsuario
{
public:
    char Nombre[TAM_LARGO], Correo[TAM_LARGO], Password[TAM_LARGO], Telefono[TAM_CORTO],Cuenta[TAM_MEDIO];

} Detalles;

class Indice
{
public:
    char Nombre[TAM_LARGO];
    long int posicion;
} ObjINDI;

class nodo
{
public:
    char Nombre[TAM_LARGO], Correo[TAM_LARGO], Password[TAM_LARGO], Telefono[TAM_CORTO], Cuenta[TAM_MEDIO];
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
} li;

void Lista::Inicializar()
{
    inicio=NULL;
    fin=NULL;
    tam=0;
}

void Lista::Agregar()
{
    ofstream DocumentoGlobal("DocPrincipal.txt",ios::app);
    ofstream DocumentoIndice("Indice.txt",ios::app);
    if(tam==0)
    {
        system("cls");
        cout << endl << endl;
        cout << "\t\t\t     **************************" << endl;
        cout << "\t\t\t     ** DETALLES DEL USUARIO **" << endl;
        cout << "\t\t\t     **       [AGREGAR]      **" << endl;
        cout << "\t\t\t     **************************" << endl << endl << endl;

        pnodo nuevo=new nodo;
        fflush(stdin);
        cout<<"\n\t\t[+] Nombre: ";
        cin.getline(Detalles.Nombre,TAM_LARGO);
        cout<<"\n\t\t[+] Correo: ";
        cin.getline(Detalles.Correo,TAM_LARGO);
        cout<<"\n\t\t[+] Password: ";
        cin.getline(Detalles.Password,TAM_LARGO);
        cout<<"\n\t\t[+] Telefono: ";
        cin.getline(Detalles.Telefono,TAM_CORTO);
        cout<<"\n\t\t[+] Cuenta: ";
        cin.getline(Detalles.Cuenta,TAM_MEDIO);

        strcpy(nuevo->Nombre,Detalles.Nombre);
        strcpy(nuevo->Correo,Detalles.Correo);
        strcpy(nuevo->Password,Detalles.Password);
        strcpy(nuevo->Telefono,Detalles.Telefono);
        strcpy(nuevo->Cuenta,Detalles.Cuenta);
        DocumentoGlobal.write((char *)&Detalles,sizeof(Detalles));
        inicio=nuevo;
        inicio->anterior=NULL;
        fin=nuevo;
        fin->siguiente=NULL;
        strcpy(ObjINDI.Nombre,Detalles.Nombre);
        DocumentoGlobal.seekp(0,DocumentoGlobal.end);
        ObjINDI.posicion=DocumentoGlobal.tellp();
        ObjINDI.posicion=ObjINDI.posicion-sizeof(Detalles);
        DocumentoIndice.write((char *)&ObjINDI,sizeof(ObjINDI));
        tam++;
    }
    else
    {
        pnodo nuevo=new nodo;

        system("cls");
        cout << endl << endl;
        cout << "\t\t\t     **************************" << endl;
        cout << "\t\t\t     ** DETALLES DEL USUARIO **" << endl;
        cout << "\t\t\t     **       [AGREGAR]      **" << endl;
        cout << "\t\t\t     **************************" << endl << endl << endl;

        fflush(stdin);
        cout<<"\n\t\t[+] Nombre: ";
        cin.getline(Detalles.Nombre,TAM_LARGO);
        cout<<"\n\t\t[+] Correo: ";
        cin.getline(Detalles.Correo,TAM_LARGO);
        cout<<"\n\t\t[+] Password: ";
        cin.getline(Detalles.Password,TAM_LARGO);
        cout<<"\n\t\t[+] Telefono: ";
        cin.getline(Detalles.Telefono,TAM_CORTO);
        cout<<"\n\t\t[+] Cuenta: ";
        cin.getline(Detalles.Cuenta,TAM_MEDIO);

        strcpy(nuevo->Nombre,Detalles.Nombre);
        strcpy(nuevo->Correo,Detalles.Correo);
        strcpy(nuevo->Password,Detalles.Password);
        strcpy(nuevo->Telefono,Detalles.Telefono);
        strcpy(nuevo->Cuenta,Detalles.Cuenta);


        DocumentoGlobal.write((char *)&Detalles,sizeof(Detalles));
        fin->siguiente=nuevo;
        nuevo->anterior=fin;
        fin=nuevo;
        fin->siguiente=NULL;
        strcpy(ObjINDI.Nombre,Detalles.Nombre);
        DocumentoGlobal.seekp(0,DocumentoGlobal.end);
        ObjINDI.posicion=DocumentoGlobal.tellp();
        ObjINDI.posicion=ObjINDI.posicion-sizeof(Detalles);
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
        cout << "\t\t\t     ***********************" << endl;
        cout << "\t\t\t     ** [LISTA USUARIOS] **" << endl;
        cout << "\t\t\t     ***********************" << endl << endl << endl;

        while(actual!=NULL)
        {
            cout << endl;
            cout << "[-]Nombre  : " << actual->Nombre << endl;
            cout << "[-]Correo   : " << actual->Correo << endl;
            cout << "[-]Password: " << actual->Password << endl;
            cout << "[-]Telefono  : " << actual->Telefono << endl;
            cout << "[-]Cuenta   : " << actual->Cuenta << endl;
            cout<<endl;

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
        ofstream DocumentoAuxGlobal("AuxDocPrincipal.txt",ios::app);
        ofstream DocumentoAuxIndice("AuxDocIndice.txt",ios::app);
        ifstream LecturaDocGlobal("DocPrincipal.txt");
        ifstream LecturaDocIndice("Indice.txt");
        string comparaNombre;
        bool flag=false;
        pnodo actual=inicio;
        if(!LecturaDocIndice.good())
            cout<<"No Existe el Archivo "<<endl;
        else
        {
            system("cls");
            cout << endl << endl;
            cout << "\t\t\t    ************************" << endl;
            cout << "\t\t\t    ** MODIFICAR DETALLES **" << endl;
            cout << "\t\t\t    ************************" << endl << endl;
            fflush(stdin);
            cout << "[?] Ingrese el Nombre a Modificar: ";
            fflush(stdin);
            getline(cin,comparaNombre);
            while(actual!=NULL)
            {
                LecturaDocIndice.read((char *)&ObjINDI,sizeof(ObjINDI));
                LecturaDocGlobal.seekg(ObjINDI.posicion);
                LecturaDocGlobal.read((char *)&Detalles,sizeof(Detalles));
                if(LecturaDocIndice.eof())
                    break;
                if(comparaNombre==actual->Nombre)
                {
                    flag=true;

                    fflush(stdin);
                    cout<<"\n\t\t[+]INGRESE Nombre: ";
                    cin.getline(Detalles.Nombre,TAM_LARGO);
                    cout<<"\n\t\t[+]INGRESE Correo: ";
                    cin.getline(Detalles.Correo,TAM_LARGO);
                    cout<<"\n\t\t[+]INGRESE Password: ";
                    cin.getline(Detalles.Password,TAM_LARGO);
                    cout<<"\n\t\t[+]INGRESE Telefono: ";
                    cin.getline(Detalles.Telefono,TAM_CORTO);
                    cout<<"\n\t\t[+]INGRESE Cuenta: ";
                    cin.getline(Detalles.Cuenta,TAM_MEDIO);

                    strcpy(actual->Nombre,Detalles.Nombre);
                    strcpy(actual->Correo,Detalles.Correo);
                    strcpy(actual->Password,Detalles.Password);
                    strcpy(actual->Telefono,Detalles.Telefono);
                    strcpy(actual->Cuenta,Detalles.Cuenta);

                    DocumentoAuxGlobal.write((char *)&Detalles,sizeof(Detalles));
                    strcpy(ObjINDI.Nombre,Detalles.Nombre);
                    DocumentoAuxIndice.write((char *)&ObjINDI,sizeof(ObjINDI));
                }
                else
                {
                    DocumentoAuxGlobal.write((char *)&Detalles,sizeof(Detalles));
                    DocumentoAuxIndice.write((char *)&ObjINDI,sizeof(ObjINDI));
                }
                actual=actual->siguiente;
            }
        }
        if(flag==false)
            cout<<"No se encontro ninguna Nombre con ese indice"<<endl;

        DocumentoAuxGlobal.close();
        DocumentoAuxIndice.close();
        LecturaDocGlobal.close();
        LecturaDocIndice.close();
        remove("Indice.txt");
        rename("AuxDocIndice.txt","Indice.txt");
        remove("DocPrincipal.txt");
        rename("AuxDocPrincipal.txt","DocPrincipal.txt");
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
        ofstream DocumentoAuxGlobal("AuxDocPrincipal.txt",ios::app);
        ofstream DocumentoAuxIndice("AuxDocIndice.txt",ios::app);
        ifstream LecturaDocGlobal("DocPrincipal.txt");
        ifstream LecturaDocIndice("Indice.txt");
        if(!LecturaDocIndice.good())
            cout<<"No Existe el Archivo "<<endl;
        else
        {
            system("cls");
            cout << endl << endl;
            cout << "\t\t\t     ***********************" << endl;
            cout << "\t\t\t     **  ELIMINA USUARIO  **" << endl;
            cout << "\t\t\t     ***********************" << endl << endl;
            cin.ignore();
            cout << "[?] Ingrese el Nombre para Eliminar: ";
            getline(cin,comparaNombre);
            while(actual!=NULL)
            {
                LecturaDocIndice.read((char *)&ObjINDI,sizeof(ObjINDI));
                LecturaDocGlobal.seekg(ObjINDI.posicion);
                LecturaDocGlobal.read((char *)&Detalles,sizeof(Detalles));
                if(LecturaDocIndice.eof())
                    break;
                if(comparaNombre==actual->Nombre)
                {
                    flag=true;
                    sup=actual;
                    if(actual==inicio)
                    {
                        if(tam==1)
                        {
                            cout << endl;
                            cout << "[-]Nombre  : " << actual->Nombre << endl;
                            cout << "[-]Correo   : " << actual->Correo << endl;
                            cout << "[-]Password: " << actual->Password << endl;
                            cout << "[-]Telefono  : " << actual->Telefono << endl;
                            cout << "[-]Cuenta   : " << actual->Cuenta << endl;
                            cout<<endl;
                        }
                        else
                        {
                            inicio=actual->siguiente;
                            inicio->anterior=NULL;

                            cout << endl;
                            cout << "[-]Nombre  : " << actual->Nombre << endl;
                            cout << "[-]Correo   : " << actual->Correo << endl;
                            cout << "[-]Password: " << actual->Password << endl;
                            cout << "[-]Telefono  : " << actual->Telefono << endl;
                            cout << "[-]Cuenta   : " << actual->Cuenta << endl;
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
                            cout << "[-]Nombre  : " << actual->Nombre << endl;
                            cout << "[-]Correo   : " << actual->Correo << endl;
                            cout << "[-]Password: " << actual->Password << endl;
                            cout << "[-]Telefono  : " << actual->Telefono << endl;
                            cout << "[-]Cuenta   : " << actual->Cuenta << endl;
                            cout<<endl;
                        }
                        else
                        {
                            actual->siguiente->anterior=actual->anterior;
                            actual->anterior->siguiente=actual->siguiente;
                        }
                    }
                    delete(sup);
                    tam--;
                    cout<<"Eliminando Registro...\nListo"<<endl;

                }
                else
                {
                    DocumentoAuxGlobal.write((char *)&Detalles,sizeof(Detalles));
                    strcpy(ObjINDI.Nombre,actual->Nombre);
                    DocumentoAuxGlobal.seekp(0,DocumentoAuxGlobal.end);
                    ObjINDI.posicion=DocumentoAuxGlobal.tellp();
                    ObjINDI.posicion=ObjINDI.posicion-sizeof(Detalles);
                    DocumentoAuxIndice.write((char*)&ObjINDI,sizeof(ObjINDI));
                }
                actual=actual->siguiente;
            }
        }
        if(flag==false)
            cout<<"No se encontro ninguna Nombre en el indice"<<endl;

        DocumentoAuxGlobal.close();
        DocumentoAuxIndice.close();
        LecturaDocGlobal.close();
        LecturaDocIndice.close();
        remove("Indice.txt");
        rename("AuxDocIndice.txt","Indice.txt");
        remove("DocPrincipal.txt");
        rename("AuxDocPrincipal.txt","DocPrincipal.txt");
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
        cout << "\t\t\t     **********************" << endl;
        cout << "\t\t\t     ** [BUSCAR USUARIO] **" << endl;
        cout << "\t\t\t     **********************" << endl << endl;
        cout << "\t\t[?] Ingrese el Nombre a buscar: ";
        cin.ignore();
        getline(cin,comparaNombre);
        while(actual!=NULL)
        {
            if(comparaNombre==actual->Nombre)
            {
                flag=true;
                cout << endl;
                cout << "[-]Nombre  : " << actual->Nombre << endl;
                cout << "[-]Correo   : " << actual->Correo << endl;
                cout << "[-]Password: " << actual->Password << endl;
                cout << "[-]Telefono  : " << actual->Telefono << endl;
                cout << "[-]Cuenta   : " << actual->Cuenta << endl;
                cout<<endl;
            }
            actual=actual->siguiente;
        }
        if(flag==false)
            cout<<"No se encontro ningun Nombre con ese indice"<<endl;
    }
}

int main()
{
    char opcion[5];
    do
    {
        system("cls");
        cout << endl << endl;
        cout << "\t\t -----------------------------------------" << endl;
        cout << "\t\t |               INDIZACION              |" << endl;
        cout << "\t\t -----------------------------------------" << endl << endl;

        cout << "\t\t MENU DETALLES DE USUARIO" << endl;
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
            li.Agregar();
            system("pause>>cls");
        }

        if(strcmp(opcion,"2")== 0)
        {
            system("cls");
            li.Mostrar();
            system("pause>>cls");
        }

        if(strcmp(opcion,"3")== 0)
        {
            system("cls");
            li.Modificar();
            system("pause>>cls");
        }

        if(strcmp(opcion,"4")== 0)
        {
            system("cls");
            li.Eliminar();
            system("pause>>cls");
        }

        if(strcmp(opcion,"5")== 0)
        {
            system("cls");
            li.Buscar();
            system("pause>>cls");
        }

        if(strcmp(opcion,"6")== 0)
        {
            break;
        }

    }
    while(opcion != "6");

    system("cls");
    cout << "\n\n\t\t Saliendo del sistema....";
    system("pause>>cls");
}

void pausa()
{
    system("PAUSE");
}
