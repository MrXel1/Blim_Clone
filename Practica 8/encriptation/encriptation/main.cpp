#include <iostream>
#include <cstdlib>
#include <string.h>
#include <fstream>

using namespace std;

class Usuario
{
private:
    char codigoUsuario[30];
    char nombreUsuario[30];
    char Usuario[30];
    char Password[30];
    char tipoMembresia[30];
public:
    void AgregarUsuario();
    void MostrarUsuario();
    void ModificarUsuario();
    void EliminarUsuario();
    void BuscarUsuario();
    void Encriptar();
    void Desencriptar();
    void EncriptarAux();
};
void Usuario::EncriptarAux()
{
    int a,b,c,d,e,i;
    a=strlen(codigoUsuario);
    b=strlen(nombreUsuario);
    c=strlen(Usuario);
    d=strlen(Password);
    e=strlen(tipoMembresia);
    char sep='|';
    ofstream File("AuxUsuarios.txt",ios::app);
    for(i=0; i<a; i++)
    {
        codigoUsuario[i]=codigoUsuario[i]^'x';
        File.write((char *)&codigoUsuario[i],1);

    }
    File.write((char *)&sep,1);

    for(i=0; i<b; i++)
    {
        nombreUsuario[i]=nombreUsuario[i]^'x';
        File.write((char *)&nombreUsuario[i],1);

    }
    File.write((char *)&sep,1);
    for(i=0; i<c; i++)
    {
        Usuario[i]=Usuario[i]^'x';
        File.write((char *)&Usuario[i],1);

    }
    File.write((char *)&sep,1);
    for(i=0; i<d; i++)
    {
        Password[i]=Password[i]^'x';
        File.write((char *)&Password[i],1);

    }
    File.write((char *)&sep,1);
    for(i=0; i<e; i++)
    {
        tipoMembresia[i]=tipoMembresia[i]^'x';
        File.write((char *)&tipoMembresia[i],1);

    }

    File.write((char *)&sep,1);
    File.close();
}
void Usuario::Encriptar()
{
    int a,b,c,d,e,i;
    a=strlen(codigoUsuario);
    b=strlen(nombreUsuario);
    c=strlen(Usuario);
    d=strlen(Password);
    e=strlen(tipoMembresia);
    char sep='|';
    ofstream File("Usuarios.txt",ios::app);
    for(i=0; i<a; i++)
    {
        codigoUsuario[i]=codigoUsuario[i]^'x';
        File.write((char *)&codigoUsuario[i],1);

    }
    File.write((char *)&sep,1);

    for(i=0; i<b; i++)
    {
        nombreUsuario[i]=nombreUsuario[i]^'x';
        File.write((char *)&nombreUsuario[i],1);

    }
    File.write((char *)&sep,1);
    for(i=0; i<c; i++)
    {
        Usuario[i]=Usuario[i]^'x';
        File.write((char *)&Usuario[i],1);

    }
    File.write((char *)&sep,1);
    for(i=0; i<d; i++)
    {
        Password[i]=Password[i]^'x';
        File.write((char *)&Password[i],1);

    }
    File.write((char *)&sep,1);
    for(i=0; i<e; i++)
    {
        tipoMembresia[i]=tipoMembresia[i]^'x';
        File.write((char *)&tipoMembresia[i],1);

    }
    File.write((char *)&sep,1);
    File.close();

}
void Usuario::Desencriptar()
{
    int a,b,c,d,e,i;
    a=strlen(codigoUsuario);
    b=strlen(nombreUsuario);
    c=strlen(Usuario);
    d=strlen(Password);
    e=strlen(tipoMembresia);
    for(i=0; i<a; i++)
    {
        codigoUsuario[i]=codigoUsuario[i]^'x';

    }
    for(i=0; i<b; i++)
    {
        nombreUsuario[i]=nombreUsuario[i]^'x';
    }

    for(i=0; i<c; i++)
    {
        Usuario[i]=Usuario[i]^'x';
    }
    for(i=0; i<d; i++)
    {
        Password[i]=Password[i]^'x';
    }
    for(i=0; i<e; i++)
    {
        tipoMembresia[i]=tipoMembresia[i]^'x';
    }

}
void Usuario::AgregarUsuario()
{
    cout<<"Codigo del Usuario: ";
    fflush(stdin);
    cin.getline(codigoUsuario,30);
    cout<<"Nombre del Usuario: ";
    cin.getline(nombreUsuario,30);
    cout<<"Usuario: ";
    cin.getline(Usuario,30);
    cout<<"Password: ";
    cin.getline(Password,30);
    cout<<"Tipo de Membresia: ";
    cin.getline(tipoMembresia,30);
    Encriptar();

    cout << "\n\t\t Usuario agregado con exito....";
}
void Usuario::MostrarUsuario()
{
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
            }
            while(codigoUsuario[i-1]!='|');
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
            }
            while(nombreUsuario[i-1]!='|');
            nombreUsuario[i-1]='\0';
            if(fileRead.eof())
                break;

            i=0;
            do
            {
                fileRead.read((char *)&Usuario[i],1);
                if(fileRead.eof())
                    break;
                i++;
            }
            while(Usuario[i-1]!='|');
            Usuario[i-1]='\0';
            if(fileRead.eof())
                break;
            i=0;
            do
            {
                fileRead.read((char *)&Password[i],1);
                if(fileRead.eof())
                    break;
                i++;
            }
            while(Password[i-1]!='|');
            Password[i-1]='\0';
            if(fileRead.eof())
                break;
            i=0;
            do
            {
                fileRead.read((char *)&tipoMembresia[i],1);
                if(fileRead.eof())
                    break;
                i++;
            }
            while(tipoMembresia[i-1]!='|');
            tipoMembresia[i-1]='\0';

            if(fileRead.eof())
                break;

            Desencriptar();
            cout<<"Codigo del Usuario: "<<codigoUsuario<<endl;
            cout<<"Nombre del Usuario: "<<nombreUsuario<<endl;
            cout<<"Usuario: "<<Usuario<<endl;
            cout<<"Password: "<<Password<<endl;
            cout<<"Tipo de Membresia: "<<tipoMembresia<<endl;
            cout<<"_______________________________________________________________________________"<<endl;

        }
    }
    fileRead.close();

}
void Usuario::ModificarUsuario()
{
    ifstream fileRead("Usuarios.txt");
    int i;
    string comparaCodigo;
    if(!fileRead.good())
        cout<<"No existe el Archivo "<<endl;
    else
    {
        cout<<"Dame el codigo del Usuario a Modificar: ";
        fflush(stdin);
        getline(cin,comparaCodigo);
        while(!fileRead.eof())
        {
            i=0;
            do
            {
                fileRead.read((char *)&codigoUsuario[i],1);
                if(fileRead.eof())
                    break;
                i++;
            }
            while(codigoUsuario[i-1]!='|');
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
            }
            while(nombreUsuario[i-1]!='|');
            nombreUsuario[i-1]='\0';
            if(fileRead.eof())
                break;

            i=0;
            do
            {
                fileRead.read((char *)&Usuario[i],1);
                if(fileRead.eof())
                    break;
                i++;
            }
            while(Usuario[i-1]!='|');
            Usuario[i-1]='\0';
            if(fileRead.eof())
                break;
            i=0;
            do
            {
                fileRead.read((char *)&Password[i],1);
                if(fileRead.eof())
                    break;
                i++;
            }
            while(Password[i-1]!='|');
            Password[i-1]='\0';
            if(fileRead.eof())
                break;
            i=0;
            do
            {
                fileRead.read((char *)&tipoMembresia[i],1);
                if(fileRead.eof())
                    break;
                i++;
            }
            while(tipoMembresia[i-1]!='|');
            tipoMembresia[i-1]='\0';
            if(fileRead.eof())
                break;
            Desencriptar();
            if(comparaCodigo==codigoUsuario)
            {
                cout<<"Codigo del Usuario: ";
                fflush(stdin);
                cin.getline(codigoUsuario,30);
                cout<<"Nombre del Usuario: ";
                cin.getline(nombreUsuario,30);
                cout<<"Usuario: ";
                cin.getline(Usuario,30);
                cout<<"Password: ";
                cin.getline(Password,30);
                cout<<"Tipo de Membresia: ";
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

    cout << "\n\t\t Usuario modificado con exito....";
}
void Usuario::EliminarUsuario()
{
    ifstream fileRead("Usuarios.txt");
    int i;
    string comparaCodigo;
    if(!fileRead.good())
        cout<<"No existe el Archivo "<<endl;
    else
    {
        cout<<"Dame el codigo del Usuario a Eliminar: ";
        fflush(stdin);
        getline(cin,comparaCodigo);
        while(!fileRead.eof())
        {
            i=0;
            do
            {
                fileRead.read((char *)&codigoUsuario[i],1);
                if(fileRead.eof())
                    break;
                i++;
            }
            while(codigoUsuario[i-1]!='|');
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
            }
            while(nombreUsuario[i-1]!='|');
            nombreUsuario[i-1]='\0';
            if(fileRead.eof())
                break;

            i=0;
            do
            {
                fileRead.read((char *)&Usuario[i],1);
                if(fileRead.eof())
                    break;
                i++;
            }
            while(Usuario[i-1]!='|');
            Usuario[i-1]='\0';
            if(fileRead.eof())
                break;
            i=0;
            do
            {
                fileRead.read((char *)&Password[i],1);
                if(fileRead.eof())
                    break;
                i++;
            }
            while(Password[i-1]!='|');
            Password[i-1]='\0';
            if(fileRead.eof())
                break;
            i=0;
            do
            {
                fileRead.read((char *)&tipoMembresia[i],1);
                if(fileRead.eof())
                    break;
                i++;
            }
            while(tipoMembresia[i-1]!='|');
            tipoMembresia[i-1]='\0';
            if(fileRead.eof())
                break;
            Desencriptar();
            if(comparaCodigo==codigoUsuario)
            {
                cout<<"Codigo del Usuario: "<<codigoUsuario<<endl;
                cout<<"Nombre del Usuario: "<<nombreUsuario<<endl;
                cout<<"Usuario: "<<Usuario<<endl;
                cout<<"Password: "<<Password<<endl;
                cout<<"Tipo de Membresia: "<<tipoMembresia<<endl<<endl;

                cout<<"ELIMINANDO USUARIO.....LISTO "<<endl;

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
void Usuario::BuscarUsuario()
{
    ifstream fileRead("Usuarios.txt");
    int i;
    string comparaCodigo;
    if(!fileRead.good())
        cout<<"No existe el Archivo "<<endl;
    else
    {
        cout<<"Dame el codigo del Usuario a Buscar: ";
        fflush(stdin);
        getline(cin,comparaCodigo);
        while(!fileRead.eof())
        {
            i=0;
            do
            {
                fileRead.read((char *)&codigoUsuario[i],1);
                if(fileRead.eof())
                    break;
                i++;
            }
            while(codigoUsuario[i-1]!='|');
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
            }
            while(nombreUsuario[i-1]!='|');
            nombreUsuario[i-1]='\0';
            if(fileRead.eof())
                break;

            i=0;
            do
            {
                fileRead.read((char *)&Usuario[i],1);
                if(fileRead.eof())
                    break;
                i++;
            }
            while(Usuario[i-1]!='|');
            Usuario[i-1]='\0';
            if(fileRead.eof())
                break;
            i=0;
            do
            {
                fileRead.read((char *)&Password[i],1);
                if(fileRead.eof())
                    break;
                i++;
            }
            while(Password[i-1]!='|');
            Password[i-1]='\0';
            if(fileRead.eof())
                break;
            i=0;
            do
            {
                fileRead.read((char *)&tipoMembresia[i],1);
                if(fileRead.eof())
                    break;
                i++;
            }
            while(tipoMembresia[i-1]!='|');
            tipoMembresia[i-1]='\0';
            if(fileRead.eof())
                break;
            Desencriptar();
            if(comparaCodigo==codigoUsuario)
            {

                cout<<"Codigo del Usuario: "<<codigoUsuario<<endl;
                cout<<"Nombre del Usuario: "<<nombreUsuario<<endl;
                cout<<"Usuario: "<<Usuario<<endl;
                cout<<"Password: "<<Password<<endl;
                cout<<"Tipo de Membresia: "<<tipoMembresia<<endl<<endl;
            }


        }
    }
    fileRead.close();
}
int main ()
{
    Usuario usua;
    char opc [10];
    do
    {
        system("cls");
        cout << "\n\n\n\t\t\t *-*-* ENCRIPTACION *-*-*";
        cout << "\n\t\t\t [1]- Agregar Usuario.";
        cout << "\n\t\t\t [2]- Mostrar.";
        cout << "\n\t\t\t [3]- Buscar.";
        cout << "\n\t\t\t [4]- Modificar.";
        cout << "\n\t\t\t [5]- Eliminar.";
        cout << "\n\t\t\t [6]- Salir.";
        cout << "\n\t\t\t Saleccione opcion: ";
        cin >> opc;

        if(strcmp(opc,"1")== 0)
        {
            system("cls");
            usua.AgregarUsuario();
            system("pause>>cls");
        }
        if(strcmp(opc,"2") == 0)
        {
            system("cls");
            usua.MostrarUsuario();
            system("pause>>cls");
        }
        if(strcmp(opc,"3") == 0)
        {
            system("cls");
            usua.BuscarUsuario();
            system("pause>>cls");
        }
        if(strcmp(opc,"4") == 0)
        {
            system("cls");
            usua.ModificarUsuario();
            system("pause>>cls");
        }
        if(strcmp(opc, "5") == 0)
        {
            system("cls");
            usua.EliminarUsuario();
            system("pause>>cls");
        }
        if(strcmp(opc, "6") == 0)
        {
            break;
        }

    }while (opc != "6");
    system("cls");
    cout << "\n\n\t\t Saliendo del programa";
    system("pause>>cls");
}
