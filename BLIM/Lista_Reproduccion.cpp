#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <vector>
using namespace std;

#include "Lista_Reproduccion.h"
Lista_Reproduccion::Lista_Reproduccion(){
	orden  = 0;
}

void Lista_Reproduccion::Agregar(Lista_Reproduccion &lr)
{
	Indice in;
    fflush(stdin);
    cout << endl;
	cout<<"ID: "<<endl;
    cin.getline(ID,15);
    cout << endl;
	cout<<"Nombre: "<<endl;
    cin.getline(Nombre,35);
	cout << endl;
	cout<<"Categoria: "<<endl;
    cin.getline(Categoria,35);
    cout << endl;
	cout<<"Duracion en minutos(Ej. 125): "<<endl;
    cin.getline(Duracion,20);
	cout << endl;
	cout<<"Anio de estreno: "<<endl;
    cin.getline(Anio,10);

    ofstream Peliculas("Peliculas.txt",ios::app);
    Peliculas.write((char*)&lr,sizeof(lr));
    in.pos=Peliculas.tellp();
    in.pos-=sizeof(lr);
    Peliculas.close();
    strcpy(in.ID,ID);
    ofstream Indice("Indice.txt",ios::app);
    Indice.write((char*)&in,sizeof(in));
    Indice.close();
    orden++;
}

void Lista_Reproduccion::Imprimir(Lista_Reproduccion &lr)
{
    ifstream Peli("Peliculas.txt");
    if(!Peli.good())
    {
        cout<<"No existe el archivo"<<endl;
    }
    else
    {
        while(!Peli.eof())
        {
            Peli.read((char*)&lr,sizeof(lr));
            if(Peli.eof())
                break;
            cout<<"ID:"<<lr.ID<<endl<<"Nombre: "<<lr.Nombre<<endl<<"Categoria: "<<lr.Categoria<<endl<<"Duracion:"<<lr.Duracion<<endl<<"Anio:"<<lr.Anio<<endl;
        }
    }
    Peli.close();
}

void Lista_Reproduccion::Buscar(Lista_Reproduccion &lr)
{
	
    char busqueda[15];
    int band=0;
    //cout<<"posicion "<<y.pos;
    ifstream Indi("Indice.txt");
    ifstream Peli("Peliculas.txt");
    if(!Indi.good())
    {
        cout<<"No existe el archivo"<<endl;
    }
    else
    {
    cout<<"\nID a buscar!"<<endl;
    cout<<endl<<"Ingrese el ID: "<<endl;
    fflush(stdin);cin.getline(busqueda,15);
    while(!Indi.eof())
    {
        Indi.read((char*)&in,sizeof(in));
        Peli.read((char*)&lr,sizeof(lr));
        if(Indi.eof())
        {
            break;
        }
        if(strcmp(in.ID,busqueda)==0)
        {
            
            //Peli.seekg(in.pos,ios::beg);
            //Peli.read((char*)&lr,sizeof(lr));
            cout<<"ID:"<<lr.ID<<endl<<"Nombre: "<<lr.Nombre<<endl<<"Categoria: "<<lr.Categoria<<endl<<"Duracion:"<<lr.Duracion<<endl<<"Anio:"<<lr.Anio<<endl;
            band=1;
            break;
        }
    }
    if(band==0)
    {
     cout<<"\n NO EXISTE REGISTRO....."<<endl;
    }
    }
    Indi.close();
    Peli.close();
}

void Lista_Reproduccion::Modificar(Lista_Reproduccion &lr)
{
     char busqueda[15];
     int band = 0;
     int opc = 0;
     ifstream Indi("Indice.txt");
     ifstream Peli("Peliculas.txt");
     if(!Indi.good())
    {
        cout<<"No existe el archivo"<<endl;
    }
     else
    {
		cout<<"\nID a modificar!"<<endl;
		cout<<endl<<"Ingrese el ID: ";
		fflush(stdin);cin.getline(busqueda,15);
		while(!Indi.eof())
		{
			opc=0;
			Indi.read((char*)&in,sizeof(in));
			Peli.read((char*)&lr,sizeof(lr));
			if(Indi.eof())
			{
			    break;
			}
			if(strcmp(in.ID,busqueda)==0 && band==0)
			{
			    //Peli.seekg(in.pos,ios::beg);
			
			    //Peli.read((char*)&lr,sizeof(lr));
			    if(Peli.eof())   break;
			    cout<<"ID:"<<lr.ID<<endl<<"Nombre: "<<lr.Nombre<<endl<<"Categoria: "<<lr.Categoria<<endl<<"Duracion:"<<lr.Duracion<<endl<<"Anio:"<<lr.Anio<<endl;
			    cout<<endl<<"Deseas modificarlo\n"<<"1.-Si   2.-No"<<endl;
				cin>>opc;
			    band=1;
			    Peli.close();
			    break;
			}//if de comparacion
		}//while
		Indi.close();
		Peli.close();
		if(opc==1)
		{
			fflush(stdin);
			ifstream indice("Indice.txt");
			ifstream Peliculas("Peliculas.txt");
			while(!indice.eof())
			{
			    indice.read((char*)&in,sizeof(in));
			    Peliculas.read((char*)&lr,sizeof(lr));
			    if(indice.eof())
			    {
			        break;
			    }
			    if(strcmp(in.ID,busqueda)==0)
			    {
			    	cout<<"Ingrese los Nuevos Datos:"<<endl;
			        cout << endl;
			        cout<<"Nombre: "<<endl;
			        cin.getline(Nombre,35);
			        cout << endl;
			        cout<<"Categoria: "<<endl;
			        cin.getline(Categoria,35);
			        cout << endl;
			        cout<<"Duracion en minutos(Ej. 125): "<<endl;
			        cin.getline(Duracion,20);
			        cout << endl;
			        cout<<"Anio de estreno: "<<endl;
			        cin.getline(Anio,10);
		    		
			    }
			    
			    ofstream c("temp.txt",ios::app);
				c.write((char*)&lr,sizeof(lr));
				
				ofstream d("tempind.txt",ios::app);
				d.write((char*)&in,sizeof(in));
				d.close();
				c.close();

		    	
			}//while archivo
		}
		Indi.close();
		Peli.close();
		if(band==0)
		{
			cout<<"\n NO EXISTE REGISTRO....."<<endl;
		}
	}
	if(band == 1 && opc == 1){
		remove("Peliculas.txt"); 
    	remove("Indice.txt");
		rename("tempind.txt","Indice.txt");
		rename("temp.txt","Peliculas.txt");
	}

}

void Lista_Reproduccion::Eliminar(Lista_Reproduccion &lr)
{
     char busqueda[15];
     int band = 0;
     int opc = 0;
     ifstream Indi("Indice.txt");
     ifstream Peli("Peliculas.txt");
     if(!Indi.good())
    {
        cout<<"No existe el archivo"<<endl;
    }
     else
    {
		cout<<"\nID a Eliminar!"<<endl;
		cout<<endl<<"Ingrese el ID: ";
		fflush(stdin);cin.getline(busqueda,15);
		while(!Indi.eof())
		{
			opc=0;
			Indi.read((char*)&in,sizeof(in));
			Peli.read((char*)&lr,sizeof(lr));
			if(Indi.eof())
			{
			    break;
			}
			if(strcmp(in.ID,busqueda)==0 && band==0)
			{
			    //Peli.seekg(in.pos,ios::beg);
			
			    //Peli.read((char*)&lr,sizeof(lr));
			    if(Peli.eof())   break;
			    cout<<"ID:"<<lr.ID<<endl<<"Nombre: "<<lr.Nombre<<endl<<"Categoria: "<<lr.Categoria<<endl<<"Duracion:"<<lr.Duracion<<endl<<"Anio:"<<lr.Anio<<endl;
			    cout<<endl<<"Deseas Eliminarlo?\n"<<"1.-Si   2.-No"<<endl;
				cin>>opc;
			    band=1;
			    Peli.close();
			    break;
			}//if de comparacion
		}//while
		Indi.close();
		Peli.close();
		if(opc==1)
		{
			fflush(stdin);
			ifstream indice("Indice.txt");
			ifstream Peliculas("Peliculas.txt");
			while(!indice.eof())
			{
			    indice.read((char*)&in,sizeof(in));
			    Peliculas.read((char*)&lr,sizeof(lr));
			    if(indice.eof())
			    {
			        break;
			    }
			    if(strcmp(in.ID,busqueda)==0)
			    {
		    		
			    }
			    else{
			    	ofstream c("temp.txt",ios::app);
					c.write((char*)&lr,sizeof(lr));
					
					ofstream d("tempind.txt",ios::app);
					d.write((char*)&in,sizeof(in));
					d.close();
					c.close();
				}
			    

		    	
			}//while archivo
		}
		Indi.close();
		Peli.close();
		if(band==0)
		{
			cout<<"\n NO EXISTE REGISTRO....."<<endl;
		}
	}
	if(band == 1 && opc == 1){
		remove("Peliculas.txt"); 
    	remove("Indice.txt");
		rename("tempind.txt","Indice.txt");
		rename("temp.txt","Peliculas.txt");
	}

}

void Lista_Reproduccion::Mostrar_Indice(Lista_Reproduccion &lr)
{
    ifstream Indi("Indice.txt");
    if(!Indi.good())
    {
        cout<<"No existe el archivo"<<endl;
    }
    else
    {
        while(!Indi.eof())
        {
            Indi.read((char*)&in,sizeof(in));
            if(Indi.eof())
                break;
            cout<<"ID:"<<in.ID<<endl<<endl;
        }
    }
    Indi.close();
}
