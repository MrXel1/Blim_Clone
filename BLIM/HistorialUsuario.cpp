#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <vector>

using namespace std;

#include "HistorialUsuario.h"

HistorialUsuario::HistorialUsuario(){
	orden = 0;
}

void HistorialUsuario::Agregar(HistorialUsuario &H)
{
    cout<<"\n\tNuevo Historial"<<endl;
    fflush(stdin);
    cout<<"\n\t[x] ID: ";
    cin.getline(ID,10);
    cout<<"\n\t[x] Nombre de usuario: ";
    cin.getline(nombre,35);
    cout<<"\n\t[x] Cuenta: ";
    cin.getline(cuenta,35);
    cout<<"\n\t[x] Numero de Peliculas vistas: ";
    cin >> NumPeliculas;
    cout<<"\n\t[x] Numero de Series vistas: ";
    cin >> NumSeries;
    fflush(stdin);

    ofstream a("Historial.bin",ios::app);
    a.write((char*)&H,sizeof(H));
    y.pos=a.tellp();
    y.pos-=sizeof(H);
    a.close();
    strcpy(y.ID,ID);
    ofstream b("Indice.bin",ios::app);
    b.write((char*)&y,sizeof(y));
    b.close();
    orden++;
}

void HistorialUsuario::Imprimir(HistorialUsuario &H)
{
    ifstream a("Historial.bin");
    if(!a.good())
    cout<<"\n\tNo existe el archivo";
    else
    {
        cout<<"\n\tHistoriales de Cuentas"<<endl;
        while(!a.eof())
        {
            a.read((char*)&H,sizeof(H));
            if(a.eof())
            break;
            cout<<"\n\t[x] ID: "<<H.ID<<endl<<"\t[x] Nombre de usuario: "<<H.nombre<<endl<<"\t[x] Cuenta: "<<H.cuenta<<endl<<"\t[x] Numero de Peliculas vistas: "<<H.NumPeliculas<<endl<<"\t[x] Numero de Series vistas: "<<H.NumSeries<<endl;
        }
    }
    a.close();
}

void HistorialUsuario::Buscar(HistorialUsuario &H)
{
    char busqueda[10];
    int band=0;
    ifstream Indi("Indice.bin");
    ifstream Histo("Historial.bin");
    if(!Indi.good())
    {
        cout<<"No existe el archivo"<<endl;
    }
    else
    {
    cout<<"\n\tCuenta a Buscar!"<<endl;
    cout<<"\n\tIngrese ID: ";
    fflush(stdin);cin.getline(busqueda,10);
    while(!Indi.eof())
    {
        Indi.read((char*)&y,sizeof(y));
        Histo.read((char*)&H,sizeof(H));
        if(Indi.eof())
        {
            break;
        }
        if(strcmp(y.ID,busqueda)==0)
        {
            cout<<"\n\t[x] ID: "<<H.ID<<endl<<"\t[x] Nombre de usuario: "<<H.nombre<<endl<<"\t[x] Cuenta: "<<H.cuenta<<endl<<"\t[x] Numero de Peliculas vistas: "<<H.NumPeliculas<<endl<<"\t[x] Numero de Series vistas: "<<H.NumSeries<<endl;
            band=1;
            break;
        }
    }
    if(band==0)
    {
     cout<<"\n\tNO EXISTE REGISTRO....."<<endl;
    }
    }
    Indi.close();
    Histo.close();

}

void HistorialUsuario::Modificar(HistorialUsuario &H)
{
     char busqueda[10];
     int band = 0;
     int opc = 0;
     ifstream Indi("Indice.bin");
     ifstream Historial("Historial.bin");
     if(!Indi.good())
    {
        cout<<"\n\tNo existe el archivo"<<endl;
    }
     else
    {
        cout<<"\n\tCuenta a Modificar!"<<endl;
        cout<<"\n\tIngrese ID: ";
		fflush(stdin);cin.getline(busqueda,10);
		while(!Indi.eof())
		{
			opc=0;
			Indi.read((char*)&y,sizeof(y));
			Historial.read((char*)&H,sizeof(H));
			if(Indi.eof())
			{
			    break;
			}
			if(strcmp(y.ID,busqueda)==0 && band==0)
			{
			    if(Historial.eof())   break;
			    cout<<"\n\t[x] ID: "<<H.ID<<endl<<"\t[x] Nombre de usuario: "<<H.nombre<<endl<<"\t[x] Cuenta: "<<H.cuenta<<endl<<"\t[x] Numero de Peliculas vistas: "<<H.NumPeliculas<<endl<<"\t[x] Numero de Series vistas: "<<H.NumSeries<<endl;
			    cout<<endl<<"\n\tDeseas Modificarlo?\n"<<"\n\t1.-Si   2.-No"<<"\n\n\tDame la Opcion: ";
				cin>>opc;
			    band=1;
			    Historial.close();
			    break;
			}//if de comparacion
		}//while
		Indi.close();
		Historial.close();
		if(opc==1)
		{
			fflush(stdin);
			ifstream indice("Indice.bin");
			ifstream Hist("Historial.bin");
			while(!indice.eof())
			{
			    indice.read((char*)&y,sizeof(y));
			    Hist.read((char*)&H,sizeof(H));
			    if(indice.eof())
			    {
			        break;
			    }
			    if(strcmp(y.ID,busqueda)==0)
			    {
                    fflush(stdin);
			    	cout<<"\n\tIngrese los Nuevos Datos:"<<endl;
			        cout << endl;
                    cout<<"\n\t[x] Nombre de usuario: ";
                    cin.getline(nombre,35);
                    cout<<"\n\t[x] Cuenta: ";
                    cin.getline(cuenta,35);
                    cout<<"\n\t[x] Numero de Peliculas vistas: ";
                    cin >> NumPeliculas;
                    cout<<"\n\t[x] Numero de Series vistas: ";
                    cin >> NumSeries;
                    fflush(stdin);
			    }

			    ofstream c("temp.bin",ios::app);
				c.write((char*)&H,sizeof(H));

				ofstream d("tempind.bin",ios::app);
				d.write((char*)&y,sizeof(y));
				d.close();
				c.close();


			}//while archivo
		}
		Indi.close();
		Historial.close();
		if(band==0)
		{
			cout<<"\n\tNO EXISTE REGISTRO....."<<endl;
		}
	}
	if(band == 1 && opc == 1){
		remove("Historial.bin");
    	remove("Indice.bin");
		rename("tempind.bin","Indice.bin");
		rename("temp.bin","Historial.bin");
	}
}

void HistorialUsuario::Eliminar(HistorialUsuario &H)
{
     char busqueda[10];
     int band = 0;
     int opc = 0;
     ifstream Indi("Indice.bin");
     ifstream Histo("Historial.bin");
     if(!Indi.good())
    {
        cout<<"\n\tNo existe el archivo"<<endl;
    }
     else
    {
		cout<<"\n\tID a Eliminar!"<<endl;
		cout<<endl<<"\n\tIngrese el ID: ";
		fflush(stdin);cin.getline(busqueda,10);
		while(!Indi.eof())
		{
			opc=0;
			Indi.read((char*)&y,sizeof(y));
			Histo.read((char*)&H,sizeof(H));
			if(Indi.eof())
			{
			    break;
			}
			if(strcmp(y.ID,busqueda)==0 && band==0)
			{
			    if(Histo.eof())   break;
			    cout<<"\n\t[x] ID: "<<H.ID<<endl<<"\t[x] Nombre de usuario: "<<H.nombre<<endl<<"\t[x] Cuenta: "<<H.cuenta<<endl<<"\t[x] Numero de Peliculas vistas: "<<H.NumPeliculas<<endl<<"\t[x] Numero de Series vistas: "<<H.NumSeries<<endl;
			    cout<<endl<<"\n\tDeseas Eliminarlo?\n"<<"\n\t1.-Si   2.-No"<<"\n\n\tDame la Opcion: ";
				cin>>opc;
			    band=1;
			    Histo.close();
			    break;
			}//if de comparacion
		}//while
		Indi.close();
		Histo.close();
		if(opc==1)
		{
			fflush(stdin);
			ifstream indice("Indice.bin");
			ifstream His("Historial.bin");
			while(!indice.eof())
			{
			    indice.read((char*)&y,sizeof(y));
			    His.read((char*)&H,sizeof(H));
			    if(indice.eof())
			    {
			        break;
			    }
			    if(strcmp(y.ID,busqueda)==0)
			    {

			    }
			    else{
			    	ofstream c("temp.bin",ios::app);
					c.write((char*)&H,sizeof(H));

					ofstream d("tempind.bin",ios::app);
					d.write((char*)&y,sizeof(y));
					d.close();
					c.close();
				}
			}//while archivo
		}
		Indi.close();
		Histo.close();
		if(band==0)
		{
			cout<<"\n\tNO EXISTE REGISTRO....."<<endl;
		}
	}
	if(band == 1 && opc == 1){
		remove("Historial.bin");
    	remove("Indice.bin");
		rename("tempind.bin","Indice.bin");
		rename("temp.bin","Historial.bin");
	}
}

void HistorialUsuario::Mostrar_Indice(HistorialUsuario &H)
{
    ifstream Indi("Indice.bin");
    if(!Indi.good())
    {
        cout<<"No existe el archivo"<<endl;
    }
    else
    {
        while(!Indi.eof())
        {
            Indi.read((char*)&y,sizeof(y));
            if(Indi.eof())
                break;
            cout<<"\n\tID:"<<y.ID<<endl<<endl;
        }
    }
    Indi.close();
}
