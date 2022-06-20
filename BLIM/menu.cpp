#include "menu.h"
#include "list.h"
#include<stdio.h>
#include<stdlib.h>

menu::menu()
{
    string op;
    Series serie;
    coding();
    while(true)
    {
        cout << endl;
        cout << " \t           *****    *     *****   *       *        " << endl;
        cout << " \t           *    *   *       *     * *   * *        " << endl;
        cout << " \t           *****    *       *     *   *   *        " << endl;
        cout << " \t           *    *   *       *     *       *        " << endl;
        cout << " \t           *****    ****  *****   *       *        " << endl;
        cout << endl;
        cout << " \t+------------------------------------------------+" << endl;
        cout << " \t|                 MENU PRINCIPAL                 |" << endl;
        cout << " \t+------------------------------------------------+" << endl;
        cout << " \t|                   Series TV                    |" << endl;
        cout << " \t+------------------------------------------------+" << endl;
        cout << " \t|                                                |" << endl;
        cout << " \t|     [1] Agregar Serie TV                       |" << endl;
        cout << " \t|                                                |" << endl;
        cout << " \t|     [2] Mostrar Serie TV                       |" << endl;
        cout << " \t|                                                |" << endl;
        cout << " \t|     [3] Buscar  Serie TV                       |" << endl;
        cout << " \t|                                                |" << endl;
        cout << " \t|     [4] Modificar Serie TV                     |" << endl;
        cout << " \t|                                                |" << endl;
        cout << " \t|     [5] Eliminacion Fisica                     |" << endl;
        cout << " \t|                                                |" << endl;
        cout << " \t|     [6] Eliminacion Logica                     |" << endl;
        cout << " \t|                                                |" << endl;
        cout << " \t|     [7] Activar Serie TV                       |" << endl;
        cout << " \t|                                                |" << endl;
        cout << " \t|     [8] Cifrado Huffman                        |" << endl;
        cout << " \t|                                                |" << endl;
        cout << " \t|     [9] Descifrado Huffman                     |" << endl;
        cout << " \t|                                                |" << endl;
        cout << " \t|   [0] Salir                                    |" << endl;
        cout << " \t|                                                |" << endl;
        cout << " \t+------------------------------------------------+" << endl;
        cout << endl;
        cout << "\tQue deseas hacer?: ";
        getline(cin,op);

        if(op == "1")
        {
            system("cls");
            crearS(serie);
            escribir(serie);
        }
        else if(op == "2")
        {
            system("cls");
            MostrarS();

        }
        else if(op == "3")
        {
            system("cls");
            BuscarS();
        }
        else if(op == "4")
        {
            system("cls");
            ModificarS();
        }
        else if(op == "5")
        {
            system("cls");
            Eliminar_F_S();
        }
        else if(op == "6")
        {
            system("cls");
            Eliminar_L_S();
        }
        else if(op == "7")
        {
            system("cls");
            ActivarS();
        }
        else if(op == "8")
        {
            system("cls");
            Huffman();
        }
        else if(op == "9")
        {
            system("cls");
            descifrado();
        }
        else if(op == "0")
        {
            cout << endl;
            cout << " \t+------------------------------------------------+" << endl;
            cout << " \t|                 HASTA LUEGO                    |" << endl;
            cout << " \t+------------------------------------------------+" << endl <<endl;
            system("PAUSE");
            break;
        }
        else
        {
            cout<<"\n\tERROR!! Opcion NO Valida"<<endl;
        }
        cout<<endl;
        system("PAUSE");
        system("cls");
    }
}

void menu::crearS(Series &t)
{
    string temporal, a="1";

    cout << " \t+----------------------------+" << endl;
    cout << " \t|         NUEVA SERIE        |" << endl;
    cout << " \t+----------------------------+" << endl;

    cout << "\tIngrese el Nombre: ";
    getline(cin, temporal);
    t.setnombre(temporal);

    cout << "\tIngrese la Categoria: ";
    getline(cin, temporal);
    t.setcategoria(temporal);

    cout << "\tCantidad de Temporadas: ";
    getline(cin, temporal);
    t.settemporadas(temporal);

    cout << "\tCantidad de Episodios: ";
    getline(cin, temporal);
    t.setepisodios(temporal);

    cout << "\tDuracion: ";
    getline(cin, temporal);
    t.setduracion(temporal);

    cout << "\tAnio de Estreno: ";
    getline(cin, temporal);
    t.setanio(temporal);

    int i=getcont();
    i++;
    string cod = to_string(i);
    t.setCodigo(cod);
    setcont(i);

    t.setBandera(a);
    cout<<"\n\tSerie Agregada"<<endl;
}

void menu::escribir(const Series &t)
{
    ofstream escribir("SeriesTv.txt", ios::app);
    if(!escribir.is_open())
    {
        cout<<"\n\tError Al Abrir El Archivo"<<endl;
        return;
    }
    escribir<<t;
    escribir.close();
}

void menu::mostrar(Series &t)
{
    cout <<endl<< "\t [+] Nombre: " <<t.getnombre()<<endl;
    cout << "\t [+] Categoria: " <<t.getcategoria()<<endl;
    cout << "\t [+] Temporadas: " <<t.gettemporadas()<<endl;
    cout << "\t [+] Episodios: " <<t.getepisodios()<<endl;
    cout << "\t [+] Duracion: " <<t.getduracion()<<endl;
    cout << "\t [+] Anio: " <<t.getanio()<<endl;
    cout << "\t [+] Codigo: " <<t.getCodigo()<<endl;
}

void menu::MostrarS()
{
    Series t_temp;
    ifstream leer("SeriesTv.txt");
    string temporal;
    if(!leer.good())
    {
       cout<<"\n\tError Al Abrir El Archivo"<<endl;
    }
    else
    {
        cout << " \t+----------------------------+" << endl;
        cout << " \t|         SERIES TV          |" << endl;
        cout << " \t+----------------------------+" << endl;
        while (!leer.eof())
        {
            getline(leer, temporal,',');
            t_temp.setnombre(temporal);

            getline(leer, temporal,',');
            t_temp.setcategoria(temporal);

            getline(leer, temporal,',');
            t_temp.settemporadas(temporal);

            getline(leer, temporal,',');
            t_temp.setepisodios(temporal);

            getline(leer, temporal,',');
            t_temp.setduracion(temporal);

            getline(leer, temporal,',');
            t_temp.setanio(temporal);

            getline(leer, temporal,',');
            t_temp.setCodigo(temporal);

            getline(leer, temporal,',');
            t_temp.setBandera(temporal);
            if(leer.eof())
            {
                break;
            }
            if(t_temp.getBandera() == "1")
            {
                mostrar(t_temp);
            }
        }
        leer.close();
    }
}

void menu::coding()
{
    ifstream c("SeriesTv.txt");
    string temporal,temporal2;
    int i;
    if(!c.good())
    {
        cout<<"\n\tError Al Abrir El Archivo"<<endl;
        return;
    }
    else
    {
        while(!c.eof())
        {
            getline(c,temporal,',');
            getline(c,temporal,',');
            getline(c,temporal,',');
            getline(c,temporal,',');
            getline(c,temporal,',');
            getline(c,temporal,',');
            getline(c,temporal,',');
            getline(c,temporal2,',');
            if(c.eof())
            {
                break;
            }
            i=stoi(temporal);
            setcont(i);
        }
    }
    c.close();
}

void menu::BuscarS()
{
    ifstream busqueda("SeriesTv.txt");
    string temporal;
    Series t_temp;
    if(!busqueda.good())
    {
        cout<<"\n\tError Al Abrir El Archivo"<<endl;
        return;
    }
    else
    {
        string code;
        bool band = false;

        cout << " \t+----------------------------+" << endl;
        cout << " \t|      BUSCAR SERIE TV       |" << endl;
        cout << " \t+----------------------------+" << endl;
        cout << " \t Ingresa el Codigo: ";
        getline(cin,code);

        while(!busqueda.eof())
        {
            getline(busqueda,temporal,',');
            t_temp.setnombre(temporal);

            getline(busqueda,temporal,',');
            t_temp.setcategoria(temporal);

            getline(busqueda,temporal,',');
            t_temp.settemporadas(temporal);

            getline(busqueda,temporal,',');
            t_temp.setepisodios(temporal);

            getline(busqueda,temporal,',');
            t_temp.setduracion(temporal);

            getline(busqueda,temporal,',');
            t_temp.setanio(temporal);

            getline(busqueda,temporal,',');
            t_temp.setCodigo(temporal);

            getline(busqueda,temporal,',');
            t_temp.setBandera(temporal);

            if(code == t_temp.getCodigo() && t_temp.getBandera() == "1")
            {
                cout << "\n\tSerie Encontrada" << endl;
                mostrar(t_temp);
                band = true;
                break;
            }
            if(busqueda.eof())
            {
                break;
            }
        }
        if(band == false)
        {
            cout << "\n\tSerie NO Encontrada" << endl;
        }
        busqueda.close();
    }
}

void menu::ModificarS()
{
    ifstream old("SeriesTv.txt");
    ofstream copia("copia.txt", ios::app);
    Series t;
    bool band = false;
    string temporal, temp2;
    if(!old.good())
    {
        cout<<"\n\tError Al Abrir El Archivo"<<endl;
        return;
    }
    else
    {
        cout << " \t+----------------------------+" << endl;
        cout << " \t|     MODIFICAR SERIE TV     |" << endl;
        cout << " \t+----------------------------+" << endl;
        cout << " \tIngresa el Codigo: ";

        string code;
        getline(cin,code);

        while(!old.eof())
        {
            getline(old,temporal,',');
            t.setnombre(temporal);

            getline(old,temporal,',');
            t.setcategoria(temporal);

            getline(old,temporal,',');
            t.settemporadas(temporal);

            getline(old,temporal,',');
            t.setepisodios(temporal);

            getline(old,temporal,',');
            t.setduracion(temporal);

            getline(old,temporal,',');
            t.setanio(temporal);

            getline(old,temporal,',');
            t.setCodigo(temporal);

            getline(old,temporal,',');
            t.setBandera(temporal);

            if(code == t.getCodigo() && t.getBandera() == "1")
            {
                cout<<endl<<"\tIngrese los NUEVOS Datos\n"<<endl;

                cout << "\tIngrese el Nombre: ";
                getline(cin, temp2);
                t.setnombre(temp2);

                cout << "\tIngrese la Categoria: ";
                getline(cin, temp2);
                t.setcategoria(temp2);

                cout << "\tCantidad de Temporadas: ";
                getline(cin, temp2);
                t.settemporadas(temp2);

                cout << "\tCantidad de Episodios: ";
                getline(cin, temp2);
                t.setepisodios(temp2);

                cout << "\tDuracion: ";
                getline(cin, temp2);
                t.setduracion(temp2);

                cout << "\tAnio de Estreno: ";
                getline(cin, temp2);
                t.setanio(temp2);

                temp2 = "1";
                t.setBandera(temp2);
                cout<<endl<<" \tSerie Modificada"<<endl;
                band = true;
            }
            copia<<t;
        }
        if(band == false)
        {
            cout << "\n\tSerie NO Encontrada" << endl;
        }
        old.close();
        copia.close();
        remove("SeriesTv.txt");
        rename("copia.txt","SeriesTv.txt");
    }
}

void menu::Eliminar_F_S()
{
    ifstream eliminar("SeriesTv.txt");
    bool band = false;
    Series t;
    string temporal;

    if(!eliminar.good())
    {
        cout<<"\n\tError Al Abrir El Archivo"<<endl;
        return;
    }
    else
    {
        cout << " \t+----------------------------+" << endl;
        cout << " \t|     ELIMINAR SERIE TV      |" << endl;
        cout << " \t+----------------------------+" << endl;
        cout << " \tIngresa el Codigo: ";

        string code;
        getline(cin,code);

        ofstream copia("copia.txt");
        while(!eliminar.eof())
        {
            getline(eliminar,temporal,',');
            t.setnombre(temporal);

            getline(eliminar,temporal,',');
            t.setcategoria(temporal);

            getline(eliminar,temporal,',');
            t.settemporadas(temporal);

            getline(eliminar,temporal,',');
            t.setepisodios(temporal);

            getline(eliminar,temporal,',');
            t.setduracion(temporal);

            getline(eliminar,temporal,',');
            t.setanio(temporal);

            getline(eliminar,temporal,',');
            t.setCodigo(temporal);

            getline(eliminar,temporal,',');
            t.setBandera(temporal);

            if(eliminar.eof())
            {
                break;
            }
            if(code != t.getCodigo())
            {
                band = true;
                copia<<t;
            }
            if(t.getBandera() == "0")
            {
                band = true;
                copia<<t;
            }
        }
        if(band == true)
        {
            cout << "\n\tSerie Eliminada" << endl;
        }
        else
        {
            cout << "\n\tSerie NO Encontrada" << endl;
        }
        eliminar.close();
        copia.close();
        remove("SeriesTv.txt");
        rename("copia.txt","SeriesTv.txt");
    }
}

void menu::Eliminar_L_S()
{
    ifstream eliminar("SeriesTv.txt");
    ofstream copia("copia.txt");
    Series t;
    string temporal;

    cout << " \t+----------------------------+" << endl;
    cout << " \t|     ELIMINAR SERIE TV      |" << endl;
    cout << " \t+----------------------------+" << endl;

    cout << " \tIngresa el Codigo: ";
    string code;

    bool band = false;
    getline(cin,code);

    if(!eliminar.good())
    {
        cout<<"\n\tError Al Abrir El Archivo"<<endl;
        return;
    }
    else
    {
        while(!eliminar.eof())
        {
            getline(eliminar,temporal,',');
            t.setnombre(temporal);

            getline(eliminar,temporal,',');
            t.setcategoria(temporal);

            getline(eliminar,temporal,',');
            t.settemporadas(temporal);

            getline(eliminar,temporal,',');
            t.setepisodios(temporal);

            getline(eliminar,temporal,',');
            t.setduracion(temporal);

            getline(eliminar,temporal,',');
            t.setanio(temporal);

            getline(eliminar,temporal,',');
            t.setCodigo(temporal);

            getline(eliminar,temporal,',');
            t.setBandera(temporal);

            if(eliminar.eof())
            {
                break;
            }
            if(code == t.getCodigo())
            {
                temporal = "0";
                t.setBandera(temporal);
                band = true;
            }
            copia<<t;
        }
        if(band == true)
        {
            cout << "\n\tSerie Eliminada" << endl;
        }
        else
        {
            cout << "\n\tSerie NO Encontrada" << endl;
        }
        eliminar.close();
        copia.close();
        remove("SeriesTv.txt");
        rename("copia.txt","SeriesTv.txt");
    }
}

void menu::ActivarS()
{
    ifstream activar("SeriesTv.txt");
    ofstream copia("copia.txt");
    Series t;
    string temporal;

    bool band = false;

    if(!activar.good())
    {
        cout<<"\n\tError Al Abrir El Archivo"<<endl;
        return;
    }
    else
    {
        cout << " \t+----------------------------+" << endl;
        cout << " \t|      ACTIVAR SERIE TV      |" << endl;
        cout << " \t+----------------------------+" << endl;

        cout << " \tIngresa el Codigo: ";
        string code;
        getline(cin,code);

        while(!activar.eof())
        {
            getline(activar,temporal,',');
            t.setnombre(temporal);

            getline(activar,temporal,',');
            t.setcategoria(temporal);

            getline(activar,temporal,',');
            t.settemporadas(temporal);

            getline(activar,temporal,',');
            t.setepisodios(temporal);

            getline(activar,temporal,',');
            t.setduracion(temporal);

            getline(activar,temporal,',');
            t.setanio(temporal);

            getline(activar,temporal,',');
            t.setCodigo(temporal);

            getline(activar,temporal,',');
            t.setBandera(temporal);

            if(code == t.getCodigo() && t.getBandera() == "0")
            {
                temporal = "1";
                t.setBandera(temporal);
                band = true;
            }
            if(activar.eof())
            {
                break;
            }
            copia<<t;
        }
        if(band==true)
        {
            cout << "\n\tSerie Restaurada" << endl;
        }
        else
        {
            cout << "\n\tSerie NO Encontrada" << endl;
        }
        activar.close();
        copia.close();
        remove("SeriesTv.txt");
        rename("copia.txt","SeriesTv.txt");
    }
}

void menu::Huffman()
{
    cargarFrase();
    mostrarLista();
    listaOrdenada();
    mostrarListaArbol();
    mostrarDiccionario();
}

void menu::cargarFrase()
{
    ifstream archivo("SeriesTv.txt");

    string aux;
    string frase;

    if(!archivo.good())
    {
        cout<<"\n\tError Al Abrir El Archivo"<<endl;
        return;
    }
    else
    {
        lista.clear();

        while(!archivo.eof())
        {
            getline(archivo,aux);
            frase += aux;
            if(archivo.eof())
            {
                break;
            }
        }
        cout << frase << endl;

        int tam = frase.length();

        for(int i = 0; i < tam; i++)
        {
            NodoL * nodo = lista.findDataChar(frase[i]);

            if(nodo == nullptr)
            {
                lista.insertData(lista.getLast(), 1, frase[i]);
            }
            else
            {
                nodo->aumentarFrecuencia();
            }
        }
    }
    archivo.close();
    texto = frase;
    getchar();
}

void menu::mostrarLista()
{
    system("cls");
    cout << " \t+----------------------------+" << endl;
    cout << " \t|    LISTA DE CARACTERES     |" << endl;
    cout << " \t+----------------------------+" << endl;

    cout<<"Frase: " << texto<<endl;
    cout<<"\nLista de Caracteres: \n"<<endl;
    lista.imprimirLista();
    getchar();
}

void menu::listaOrdenada()
{
    system("cls");
    cout << " \t+----------------------------+" << endl;
    cout << " \t|       LISTA ORDENADA       |" << endl;
    cout << " \t+----------------------------+" << endl;

    cout<<"\nLista Ordenada Ascendentemente: \n"<<endl;
    lista.ordenarLista();
    lista.imprimirLista();
    getchar();
}

void menu::mostrarListaArbol()
{
    system("cls");
    cout << " \t+----------------------------+" << endl;
    cout << " \t|       LISTA A ARBOL        |" << endl;
    cout << " \t+----------------------------+" << endl;

    lista.convertirToArbol();
    lista.mostrarArbol(lista.getFirst(), 0);

    string a = lista.stringTotal;

    system("cls");
    int x,y;
    x=60;
    y=10;

    lista.mostrarArbol2(lista.getFirst(),x,y);
    getchar();

    system("cls");
    lista.mostrarArbol3(lista.getFirst(),0);
    getchar();
}

void menu::mostrarDiccionario()
{
    cout << " \t+----------------------------+" << endl;
    cout << " \t|    DICCIONARIO DE DATOS    |" << endl;
    cout << " \t+----------------------------+" << endl;

    lista.diccionario(lista.getFirst(),0);

    cout << " \t+----------------------------+" << endl;
    cout << " \t|    TRADUCCION DE CADENA    |" << endl;
    cout << " \t+----------------------------+" << endl;

    lista.transformarConDiccionario(texto);
    lista.empaquetar();
    string a = lista.cifrado;

    cout << "\tC: "<<a<<endl;
    lista.guardarDiccionario();
}

void menu::descifrado()
{
    lista.leerArchivo();
}

void menu::setcont(int value)
{
    cont = value;
}

int menu::getcont() const
{
    return cont;
}

void menu::setTexto(const string &value)
{
    texto = value;
}

string menu::getTexto() const
{
    return texto;
}
