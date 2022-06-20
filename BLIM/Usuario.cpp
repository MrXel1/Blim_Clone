#include "Usuario.h"
#include <iostream>
#include <cstdlib>
#include <string.h>
#include <fstream>

void Usuario::EncriptarAux()
{
 int a,b,c,d,e,f,g,h,i;
   a=strlen(codigoUsuario);
   b=strlen(nombreUsuario);
   c=strlen(apellidoUsuario);
   d=strlen(edad);
   e=strlen(contrasenia);
   f=strlen(direccion);
   g=strlen(telefono);
   h=strlen(tipoMembresia);
   char sep=129;
   char crypto = 128;
   ofstream File("AuxUsuarios.txt",ios::app);
   for(i=0;i<a;i++)
   {
       codigoUsuario[i]=codigoUsuario[i]^crypto;
       File.write((char *)&codigoUsuario[i],1);

   }
   File.write((char *)&sep,1);

   for(i=0;i<b;i++)
   {
       nombreUsuario[i]=nombreUsuario[i]^crypto;
       File.write((char *)&nombreUsuario[i],1);

   }
   File.write((char *)&sep,1);
   for(i=0;i<c;i++)
   {
       apellidoUsuario[i]=apellidoUsuario[i]^crypto;
       File.write((char *)&apellidoUsuario[i],1);

   }
   File.write((char *)&sep,1);
   for(i=0;i<d;i++)
   {
       edad[i]=edad[i]^crypto;
       File.write((char *)&edad[i],1);

   }
   File.write((char *)&sep,1);
   for(i=0;i<e;i++)
   {
       contrasenia[i]=contrasenia[i]^crypto;
       File.write((char *)&contrasenia[i],1);

   }
   File.write((char *)&sep,1);
   for(i=0;i<f;i++)
   {
       direccion[i]=direccion[i]^crypto;
       File.write((char *)&direccion[i],1);

   }
   File.write((char *)&sep,1);
      for(i=0;i<g;i++)
   {
       telefono[i]=telefono[i]^crypto;
       File.write((char *)&telefono[i],1);

   }
   File.write((char *)&sep,1);
      for(i=0;i<h;i++)
   {
       tipoMembresia[i]=tipoMembresia[i]^crypto;
       File.write((char *)&tipoMembresia[i],1);

   }
   File.write((char *)&sep,1);
   File.close();
}

void Usuario::Encriptar()
{
 int a,b,c,d,e,f,g,h,i;
   a=strlen(codigoUsuario);
   b=strlen(nombreUsuario);
   c=strlen(apellidoUsuario);
   d=strlen(edad);
   e=strlen(contrasenia);
   f=strlen(direccion);
   g=strlen(telefono);
   h=strlen(tipoMembresia);
   char sep = 129;
   char crypto = 128;
   ofstream File("Usuarios.txt",ios::app);
   for(i=0;i<a;i++)
   {
       codigoUsuario[i]=codigoUsuario[i]^crypto;
       File.write((char *)&codigoUsuario[i],1);

   }
   File.write((char *)&sep,1);

   for(i=0;i<b;i++)
   {
       nombreUsuario[i]=nombreUsuario[i]^crypto;
       File.write((char *)&nombreUsuario[i],1);

   }
   
   File.write((char *)&sep,1);
   for(i=0;i<c;i++)
   {
       apellidoUsuario[i]=apellidoUsuario[i]^crypto;
       File.write((char *)&apellidoUsuario[i],1);

   }
   File.write((char *)&sep,1);
   for(i=0;i<d;i++)
   {
       edad[i]=edad[i]^crypto;
       File.write((char *)&edad[i],1);

   }
   File.write((char *)&sep,1);
   for(i=0;i<e;i++)
   {
       contrasenia[i]=contrasenia[i]^crypto;
       File.write((char *)&contrasenia[i],1);

   }
   File.write((char *)&sep,1);
   for(i=0;i<f;i++)
   {
       direccion[i]=direccion[i]^crypto;
       File.write((char *)&direccion[i],1);

   }
   File.write((char *)&sep,1);
      for(i=0;i<g;i++)
   {
       telefono[i]=telefono[i]^crypto;
       File.write((char *)&telefono[i],1);

   }
   File.write((char *)&sep,1);
      for(i=0;i<h;i++)
   {
       tipoMembresia[i]=tipoMembresia[i]^crypto;
       File.write((char *)&tipoMembresia[i],1);

   }
   File.write((char *)&sep,1);
   File.close();
}

void Usuario::Desencriptar()
{
	char crypto = 128;
   int a,b,c,d,e,f,g,h,i;
   a=strlen(codigoUsuario);
   b=strlen(nombreUsuario);
   c=strlen(apellidoUsuario);
   d=strlen(edad);
   e=strlen(contrasenia);
   f=strlen(direccion);
   g=strlen(telefono);
   h=strlen(tipoMembresia);
   for(i=0;i<a;i++)
   {
       codigoUsuario[i]=codigoUsuario[i]^crypto;

   }
   for(i=0;i<b;i++)
   {
       nombreUsuario[i]=nombreUsuario[i]^crypto;
       
   }
   
   for(i=0;i<c;i++)
   {
       apellidoUsuario[i]=apellidoUsuario[i]^crypto;
   }
   for(i=0;i<d;i++)
   {
       edad[i]=edad[i]^crypto;
   }
   for(i=0;i<e;i++)
   {
       contrasenia[i]=contrasenia[i]^crypto;
   }
   for(i=0;i<f;i++)
   {
       direccion[i]=direccion[i]^crypto;
   }
   for(i=0;i<g;i++)
   {
       telefono[i]=telefono[i]^crypto;
   }
   for(i=0;i<h;i++)
   {
       tipoMembresia[i]=tipoMembresia[i]^crypto;
   }

}

void Usuario::Agregar()
{
   cout<<endl<<" [-] Codigo del Usuario: ";
   fflush(stdin);
   cin.getline(codigoUsuario,30);
   cout<<endl<<" [-] Nombre del Usuario: ";
   cin.getline(nombreUsuario,30);
   cout<<endl<<" [-] Apellido del Usuario: ";
   cin.getline(apellidoUsuario,30);
   cout<<endl<<" [-] Edad: ";
   cin.getline(edad,4);
   cout<<endl<<" [-] Contraseña: ";
   cin.getline(contrasenia,30);
   cout<<endl<<" [-] Direccion: ";
   cin.getline(direccion,30);
   cout<<endl<<" [-] Telefono: ";
   cin.getline(telefono,30);
   cout<<endl<<" [-] Tipo de Membresia: ";
   cin.getline(tipoMembresia,30);
   Encriptar();
   cout << "\n\t\t Usuario agregado con exito....";
}

void Usuario::Imprimir()
{
	char sep=129;
    ifstream fileRead("Usuarios.txt");
    int i;
    if(!fileRead.good())
        cout<<"No existe el Archivo "<<endl;
    else
    {
        while(!fileRead.eof())
        {
            i=0;
            do
            {
                fileRead.read((char *)&codigoUsuario[i],1);
                if(fileRead.eof())
                    break;
                i++;
            }while(codigoUsuario[i-1]!=sep);
            codigoUsuario[i-1]='\0';
            if(fileRead.eof())
                break;

             i=0;
            do
            {
                fileRead.read((char *)&nombreUsuario[i],1);
                if(fileRead.eof())
                    break;
                i++;
            }while(nombreUsuario[i-1]!=sep);
            nombreUsuario[i-1]='\0';
            if(fileRead.eof())
                break;

             i=0;
            do
            {
                fileRead.read((char *)&apellidoUsuario[i],1);
                if(fileRead.eof())
                    break;
                i++;
            }while(apellidoUsuario[i-1]!=sep);
            apellidoUsuario[i-1]='\0';
            if(fileRead.eof())
                break;

             i=0;
            do
            {
                fileRead.read((char *)&edad[i],1);
                if(fileRead.eof())
                    break;
                i++;
            }while(edad[i-1]!=sep);
            edad[i-1]='\0';
            if(fileRead.eof())
                break;

             i=0;
            do
            {
                fileRead.read((char *)&contrasenia[i],1);
                if(fileRead.eof())
                    break;
                i++;
            }while(contrasenia[i-1]!=sep);
            contrasenia[i-1]='\0';
            if(fileRead.eof())
                break;

             i=0;
            do
            {
                fileRead.read((char *)&direccion[i],1);
                if(fileRead.eof())
                    break;
                i++;
            }while(direccion[i-1]!=sep);
            direccion[i-1]='\0';
            if(fileRead.eof())
                break;
             i=0;
            do
            {
                fileRead.read((char *)&telefono[i],1);
                if(fileRead.eof())
                    break;
                i++;
            }while(telefono[i-1]!=sep);
            telefono[i-1]='\0';
            if(fileRead.eof())
                break;
             i=0;
            do
            {
                fileRead.read((char *)&tipoMembresia[i],1);
                if(fileRead.eof())
                    break;
                i++;
            }while(tipoMembresia[i-1]!=sep);
            tipoMembresia[i-1]='\0';

            if(fileRead.eof())
                break;

            Desencriptar();
            cout<<endl<<" [-] Codigo del cliente: "<<codigoUsuario<<endl;
            cout<<" [-] Nombre del Cliente: "<<nombreUsuario<<endl;
            cout<<" [-] Apellido del Cliente: "<<apellidoUsuario<<endl;
            cout<<" [-] Edad del Cliente: "<<edad<<endl;
            cout<<" [-] Contraseña de la Cuenta: "<<contrasenia<<endl;
            cout<<" [-] Direccion: "<<direccion<<endl;
            cout<<" [-] Telefono: "<<telefono<<endl;
            cout<<" [-]Tipo de Membresia: "<<tipoMembresia<<endl;
            cout<<endl<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;

        }
    }
    fileRead.close();
}

void Usuario::Buscar()
{
	char sep = 129;
    ifstream fileRead("Usuarios.txt");
    int i;
    string Busqueda;
    if(!fileRead.good())
        cout<<"No existe el Archivo "<<endl;
    else
    {
        cout<<"Dame el codigo del Usuario a Buscar: ";
        fflush(stdin);
        getline(cin,Busqueda);
        while(!fileRead.eof())
        {
            i=0;
            do
            {
                fileRead.read((char *)&codigoUsuario[i],1);
                if(fileRead.eof())
                    break;
                i++;
            }while(codigoUsuario[i-1]!=sep);
            codigoUsuario[i-1]='\0';
            if(fileRead.eof())
                break;

             i=0;
            do
            {
                fileRead.read((char *)&nombreUsuario[i],1);
                if(fileRead.eof())
                    break;
                i++;
            }while(nombreUsuario[i-1]!=sep);
            nombreUsuario[i-1]='\0';
            if(fileRead.eof())
                break;

             i=0;
            do
            {
                fileRead.read((char *)&apellidoUsuario[i],1);
                if(fileRead.eof())
                    break;
                i++;
            }while(apellidoUsuario[i-1]!=sep);
            apellidoUsuario[i-1]='\0';
            if(fileRead.eof())
                break;

             i=0;
            do
            {
                fileRead.read((char *)&edad[i],1);
                if(fileRead.eof())
                    break;
                i++;
            }while(edad[i-1]!=sep);
            edad[i-1]='\0';
            if(fileRead.eof())
                break;

             i=0;
            do
            {
                fileRead.read((char *)&contrasenia[i],1);
                if(fileRead.eof())
                    break;
                i++;
            }while(contrasenia[i-1]!=sep);
            contrasenia[i-1]='\0';
            if(fileRead.eof())
                break;

             i=0;
            do
            {
                fileRead.read((char *)&direccion[i],1);
                if(fileRead.eof())
                    break;
                i++;
            }while(direccion[i-1]!=sep);
            direccion[i-1]='\0';
            if(fileRead.eof())
                break;
             i=0;
            do
            {
                fileRead.read((char *)&telefono[i],1);
                if(fileRead.eof())
                    break;
                i++;
            }while(telefono[i-1]!=sep);
            telefono[i-1]='\0';
            if(fileRead.eof())
                break;
             i=0;
            do
            {
                fileRead.read((char *)&tipoMembresia[i],1);
                if(fileRead.eof())
                    break;
                i++;
            }while(tipoMembresia[i-1]!=sep);
            tipoMembresia[i-1]='\0';
            if(fileRead.eof())
                break;

            Desencriptar();
            if(Busqueda==codigoUsuario)
            {
	            cout<<endl<<" [-] Codigo del cliente: "<<codigoUsuario<<endl;
	            cout<<" [-] Nombre del Cliente: "<<nombreUsuario<<endl;
	            cout<<" [-] Apellido del Cliente: "<<apellidoUsuario<<endl;
	            cout<<" [-] Edad del Cliente: "<<edad<<endl;
	            cout<<" [-] Contraseña de la Cuenta: "<<contrasenia<<endl;
	            cout<<" [-] Direccion: "<<direccion<<endl;
	            cout<<" [-] Telefono: "<<telefono<<endl;
	            cout<<" [-]Tipo de Membresia: "<<tipoMembresia<<endl;
            }
        }
    }
    fileRead.close();
}

void Usuario::Modificar()
{
    ifstream fileRead("Usuarios.txt");
    char sep = 129;
	int i;
    string Busqueda;
    if(!fileRead.good())
        cout<<"No existe el Archivo "<<endl;
    else
    {
        cout<<"Dame el codigo del Usuario a Modificar: ";
        fflush(stdin);
        getline(cin,Busqueda);
        while(!fileRead.eof())
        {
            i=0;
            do
            {
                fileRead.read((char *)&codigoUsuario[i],1);
                if(fileRead.eof())
                    break;
                i++;
            }while(codigoUsuario[i-1]!=sep);
            codigoUsuario[i-1]='\0';
            if(fileRead.eof())
                break;

             i=0;
            do
            {
                fileRead.read((char *)&nombreUsuario[i],1);
                if(fileRead.eof())
                    break;
                i++;
            }while(nombreUsuario[i-1]!=sep);
            nombreUsuario[i-1]='\0';
            if(fileRead.eof())
                break;

             i=0;
            do
            {
                fileRead.read((char *)&apellidoUsuario[i],1);
                if(fileRead.eof())
                    break;
                i++;
            }while(apellidoUsuario[i-1]!=sep);
            apellidoUsuario[i-1]='\0';
            if(fileRead.eof())
                break;

             i=0;
            do
            {
                fileRead.read((char *)&edad[i],1);
                if(fileRead.eof())
                    break;
                i++;
            }while(edad[i-1]!=sep);
            edad[i-1]='\0';
            if(fileRead.eof())
                break;

             i=0;
            do
            {
                fileRead.read((char *)&contrasenia[i],1);
                if(fileRead.eof())
                    break;
                i++;
            }while(contrasenia[i-1]!=sep);
            contrasenia[i-1]='\0';
            if(fileRead.eof())
                break;

             i=0;
            do
            {
                fileRead.read((char *)&direccion[i],1);
                if(fileRead.eof())
                    break;
                i++;
            }while(direccion[i-1]!=sep);
            direccion[i-1]='\0';
            if(fileRead.eof())
                break;
             i=0;
            do
            {
                fileRead.read((char *)&telefono[i],1);
                if(fileRead.eof())
                    break;
                i++;
            }while(telefono[i-1]!=sep);
            telefono[i-1]='\0';
            if(fileRead.eof())
                break;
             i=0;
            do
            {
                fileRead.read((char *)&tipoMembresia[i],1);
                if(fileRead.eof())
                    break;
                i++;
            }while(tipoMembresia[i-1]!=sep);
            tipoMembresia[i-1]='\0';
            if(fileRead.eof())
                break;

            Desencriptar();
            if(Busqueda==codigoUsuario)
            {
               cout<<endl<<" [-] Codigo del Usuario: ";
               fflush(stdin);
               cin.getline(codigoUsuario,30);
               cout<<endl<<" [-] Nombre del Usuario: ";
               cin.getline(nombreUsuario,30);
               cout<<endl<<" [-] Apellido del Usuario: ";
               cin.getline(apellidoUsuario,30);
               cout<<endl<<" [-] Edad: ";
               cin.getline(edad,4);
               cout<<endl<<" [-] Contraseña: ";
               cin.getline(contrasenia,30);
               cout<<endl<<" [-] Direccion: ";
               cin.getline(direccion,30);
               cout<<endl<<" [-] Telefono: ";
               cin.getline(telefono,30);
               cout<<endl<<" [-] Tipo de Membresia: ";
               cin.getline(tipoMembresia,30);
               EncriptarAux();

            }
            else
            {
                EncriptarAux();
            }
        }
    }
    fileRead.close();
    remove ("Usuarios.txt");
    rename("AuxUsuarios.txt","Usuarios.txt");
}

void Usuario::Eliminar()
{
    ifstream fileRead("Usuarios.txt");
    int i;
    char sep = 129;
    string Busqueda;
    if(!fileRead.good())
        cout<<"No existe el Archivo "<<endl;
    else
    {
        cout<<"Dame el Codigo del Cliente a Eliminar: ";
        fflush(stdin);
        getline(cin,Busqueda);
        while(!fileRead.eof())
        {
            i=0;
            do
            {
                fileRead.read((char *)&codigoUsuario[i],1);
                if(fileRead.eof())
                    break;
                i++;
            }while(codigoUsuario[i-1]!=sep);
            codigoUsuario[i-1]='\0';
            if(fileRead.eof())
                break;

            i=0;
            do
            {
                fileRead.read((char *)&nombreUsuario[i],1);
                if(fileRead.eof())
                    break;
                i++;
            }while(nombreUsuario[i-1]!=sep);
            nombreUsuario[i-1]='\0';
            if(fileRead.eof())
                break;

            i=0;
            do
            {
                fileRead.read((char *)&apellidoUsuario[i],1);
                if(fileRead.eof())
                    break;
                i++;
            }while(apellidoUsuario[i-1]!=sep);
            apellidoUsuario[i-1]='\0';
            if(fileRead.eof())
                break;

            i=0;
            do
            {
                fileRead.read((char *)&edad[i],1);
                if(fileRead.eof())
                    break;
                i++;
            }while(edad[i-1]!=sep);
            edad[i-1]='\0';
            if(fileRead.eof())
                break;

            i=0;
            do
            {
                fileRead.read((char *)&contrasenia[i],1);
                if(fileRead.eof())
                    break;
                i++;
            }while(contrasenia[i-1]!=sep);
            contrasenia[i-1]='\0';
            if(fileRead.eof())
                break;

            i=0;
            do
            {
                fileRead.read((char *)&direccion[i],1);
                if(fileRead.eof())
                    break;
                i++;
            }while(direccion[i-1]!=sep);
            direccion[i-1]='\0';
            if(fileRead.eof())
                break;

            i=0;
            do
            {
                fileRead.read((char *)&telefono[i],1);
                if(fileRead.eof())
                    break;
                i++;
            }while(telefono[i-1]!=sep);
            telefono[i-1]='\0';
            if(fileRead.eof())
                break;

            i=0;
            do
            {
                fileRead.read((char *)&tipoMembresia[i],1);
                if(fileRead.eof())
                    break;
                i++;
            }while(tipoMembresia[i-1]!=sep);
            tipoMembresia[i-1]='\0';
            if(fileRead.eof())
                break;

            Desencriptar();
            if(Busqueda==codigoUsuario)
            {
            cout<<endl<<" [-] Codigo del cliente: "<<codigoUsuario<<endl;
            cout<<" [-] Nombre del Cliente: "<<nombreUsuario<<endl;
            cout<<" [-] Apellido del Cliente: "<<apellidoUsuario<<endl;
            cout<<" [-] Edad del Cliente: "<<edad<<endl;
            cout<<" [-] Contraseña de la Cuenta: "<<contrasenia<<endl;
            cout<<" [-] Direccion: "<<direccion<<endl;
            cout<<" [-] Telefono: "<<telefono<<endl;
            cout<<" [-]Tipo de Membresia: "<<tipoMembresia<<endl;

               cout<<"ELIMINANDO REGISTRO.....LISTO "<<endl;

            }
            else
            {
                EncriptarAux();
            }


        }
    }
    fileRead.close();
    remove ("Usuarios.txt");
    rename("AuxUsuarios.txt","Usuarios.txt");
}
