#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Pagos.h"

#define NUMREGISTROS 100
#define CONTENEDOR   4


using namespace std;

// constructor
Pagos::Pagos( void )
{
    for( int i = 0; i < sizeof( Id ); Id[ i++ ] = '\0' );
    for( int i = 0; i < sizeof( Nombre ); Nombre[ i++ ] = '\0' );
    for( int i = 0; i < sizeof( Banco ); Banco[ i++ ] = '\0' );
    for( int i = 0; i < sizeof( Cantidad ); Cantidad[ i++ ] = '\0' );
}


bool Pagos::contiene( const string &idABuscar )
{
    if( buscarId( idABuscar ) == -1 )
        return false;
    return true;
}


Pagos Pagos::pedirRegistro( void )
{
    Pagos registroARetornar;
    string cadena;

    cout << endl << "ID: ";
    fflush( stdin );
    getline( cin, cadena );
    while( contiene( cadena ) || cadena.size() == 0 )
    {
        cout << "Ese ID ya existe o la cadena es invalida: ";
        fflush( stdin );
        getline( cin, cadena );
    }
    registroARetornar.setId( cadena );

    cout << "Nombre: ";
    fflush( stdin );
    getline( cin, cadena );
    registroARetornar.setNombre( cadena );

    cout << "Banco: ";
    fflush( stdin );
    getline( cin, cadena );
    registroARetornar.setBanco( cadena );
    
    cout << "Cantidad: ";
    fflush( stdin );
    getline( cin, cadena );
    registroARetornar.setCantidad( cadena );

    return registroARetornar;
}



void Pagos::genera( void )
{
    Pagos pago;
    int contador = 0;
    ofstream archivo( "ArchivoDispersion.txt", ios::app );
    if( !archivo )
        cout << "No se pudo crear el archivo" << endl;
    else
        for( int i = 0; i < NUMREGISTROS; i++ )
        {
        	// indica cuantos registros hay en el contenedor
        	archivo.write( ( char * ) &contador, sizeof( int ) );
        	for( int j = 0; j < CONTENEDOR; j++ )
            	archivo.write( ( char * ) &pago, sizeof( Pagos ) );
        }
    archivo.close();
}

int Pagos::dispersion( const char llave[ 12 ] )
{
    // llena la el sobrante de la llave con espacios
    char llaveCopia[ 12 ];
    strcpy( llaveCopia, llave );
    if( strlen( llaveCopia ) < 12 )
        for( int i = strlen( llaveCopia ); i < 12; i++ )
            llaveCopia[ i ] = ' ';
    llaveCopia[ 12 ] = '\0';

    // realiza el algoritmo
    long sum = 0;
    int j = 0;
    while( j < 12 )
    {
        sum = ( sum + 100 * llaveCopia[ j ] + llaveCopia[ j + 1 ] )  % 20000;
        j += 2;
    }
    return ( sum % 99 ); // retorna la posición donde se guardará el registros.
}

// retorna la posición donde se encontro el registro
long int Pagos::buscarId( const string &idABuscar )
{
    Pagos pago;
    int contador, posIndice;
    long int posByte;

    ifstream archivo( "ArchivoDispersion.txt", ios::in );
    if( !archivo )
    {
        cout << "El archivo no existe" << endl;
        archivo.close();
        return -1;
    }

    posIndice = dispersion( idABuscar.c_str() );
    posByte = posIndice * ( ( sizeof( Pagos ) * CONTENEDOR ) + sizeof( int ) );
    archivo.seekg( posByte, ios::beg );
    archivo.read( ( char * ) &contador, sizeof( int ) );
    if( contador > 0 )
    {
        for( int i = 0; i < CONTENEDOR; i++ )
        {
            archivo.read( ( char * ) &pago, sizeof( Pagos ) );
            if( strcmp( pago.Id, idABuscar.c_str() ) == 0 )
            {
                posByte = ( long )archivo.tellg() - sizeof( Pagos );
                archivo.close();
                return posByte;
            }
        }
    }

    archivo.close();
    return -1;
}

void Pagos::setId( const string &valorId )
{
    int longitud = valorId.size();
    longitud = ( longitud < 12 ? longitud : 11 );
    valorId.copy( Id, longitud );
    Id[ longitud ] = '\0';
}

void Pagos::setNombre( const string &valorNombre )
{
    int longitud = valorNombre.size();
    longitud = ( longitud < 35 ? longitud : 34 );
    valorNombre.copy( Nombre, longitud );
    Nombre[ longitud ] = '\0';
}

void Pagos::setBanco( const string &valorProveedor )
{
    int longitud = valorProveedor.size();
    longitud = ( longitud < 35 ? longitud : 34 );
    valorProveedor.copy( Banco, longitud );
    Banco[ longitud ] = '\0';
}

void Pagos::setCantidad( const string &valorPrecio )
{
    int longitud = valorPrecio.size();
    longitud = ( longitud < 12 ? longitud : 11 );
    valorPrecio.copy( Cantidad, longitud );
    Cantidad[ longitud ] = '\0';
}

ostream &operator<<( ostream &salida, const Pagos &pagos )
{
    salida << "ID:        " << pagos.Id << endl
            << "Producto:  " << pagos.Nombre << endl
            << "Banco: " << pagos.Banco << endl
            << "Cantidad:    " << pagos.Cantidad << endl;

    return salida;
}

bool Pagos::agregar( const Pagos &nuevoPago )
{
    Pagos pago;
    string cadena;
    int posIndice, contador;
    long int posByte;
    string idString = nuevoPago.Id;

    if( contiene( idString ) )
        return false;

    fstream archivo( "ArchivoDispersion.txt", ios::in | ios::out );
    posIndice = dispersion( nuevoPago.Id );
    cout << "Se guardara en la posicion indice: " << posIndice << endl;
    posByte = posIndice * ( sizeof( Pagos ) * CONTENEDOR + sizeof( int ) );
    archivo.seekg( posByte, ios::beg );
    archivo.read( ( char * ) &contador, sizeof( int ) ); // lee el numero de registros en el contador
    if( contador < CONTENEDOR ) // si el contenedor no esta lleno
    {
        // aumenta el contador y lo escribe
        contador++;
        archivo.seekg( posByte, ios::beg );
        archivo.write( ( char * ) &contador, sizeof( int ) );

        // escribe el nuevo registro en el contenedor
        for( int i = 0; i < CONTENEDOR; i++ )
        {
            archivo.read( ( char * ) &pago, sizeof( Pagos ) );
            if( pago.Id[ 0 ] == '\0' )
            {
                archivo.seekg( ( long )archivo.tellg() - sizeof( Pagos ), ios::beg );
                archivo.write( ( char * ) &nuevoPago, sizeof( Pagos ) );
                archivo.close();
                return true;
            }
        }

    }
    else
        cout << endl << "No hay mas espacio para este registro" << endl;
    archivo.close();
    return false;
}

void Pagos::mostrar( void )
{
    Pagos pago;
    int contador;
    long int posByte;

    ifstream archivo( "ArchivoDispersion.txt", ios::in );
    if( !archivo )
        cout << "No existe el archivo" << endl;
    else
    {
        cout << endl;
        for( int i = 0; i < NUMREGISTROS; i++ )
        {
            archivo.read( ( char * ) &contador, sizeof( int ) );
            if( contador > 0 )
            {
                for( int j = 0; j < CONTENEDOR; j++ )
                {
                    archivo.read( ( char * ) &pago, sizeof( Pagos ) );
                    if( pago.Id[ 0 ] != '\0' )
                        cout << pago << endl;
                }
            }
            else
                archivo.seekg( sizeof( Pagos ) * CONTENEDOR, ios::cur );
        }
    }
    archivo.close();
}

bool Pagos::buscar( const string &idABuscar, Pagos &pagoEncontrado )
{
    long int posByte;

    if( !contiene( idABuscar ) )
        return false;

    ifstream archivo( "ArchivoDispersion.txt", ios::in );
    if( !archivo )
    {
        cout << "El archivo no existe" << endl;
        archivo.close();
        return false;
    }
    
    posByte = buscarId( idABuscar );
    archivo.seekg( posByte, ios::beg );
    archivo.read( ( char * ) &pagoEncontrado, sizeof( Pagos ) );
    archivo.close();
    return true;
}

bool Pagos::modificar( const string &idAModificar, const Pagos &pagoNuevo )
{
    Pagos registroLimpio, pago;
    int posIndiceAntiguo, posIndiceNuevo, contador;
    long int posByteAntiguo, posByteNuevo;

    if( !contiene( idAModificar ) )
        return false;

    fstream archivo( "ArchivoDispersion.txt", ios::in | ios::out );
    if( !archivo )
    {
        cout << "El archivo no exite" << endl;
        archivo.close();
        return false;
    }

    posIndiceAntiguo = dispersion( idAModificar.c_str() );
    posByteAntiguo = buscarId( idAModificar );
    posIndiceNuevo = dispersion( pagoNuevo.Id );
    posByteNuevo = posIndiceNuevo * ( sizeof( Pagos ) * CONTENEDOR + sizeof( int ) );

    if( posByteAntiguo == posByteNuevo )
    {
        archivo.seekg( posByteAntiguo, ios::beg );
        archivo.write( ( char * ) &pagoNuevo, sizeof(  Pagos) );
    }
    else
    {
        // quita el registro antiguo y resta uno al contador del contenedor
        archivo.seekg( posByteAntiguo, ios::beg );
        archivo.write( ( char * ) &registroLimpio, sizeof( Pagos ) );
        posByteAntiguo = posIndiceAntiguo * ( sizeof( Pagos ) * CONTENEDOR + sizeof( int ) );
        archivo.seekg( posByteAntiguo, ios::beg );
        archivo.read( ( char * ) &contador, sizeof( int ) );
        contador--; 
        archivo.seekg( posByteAntiguo, ios::beg );
        archivo.write( ( char * ) &contador, sizeof( int ) );

        // intenta meter el nuevo registro en la nueva posicion
        archivo.seekg( posByteNuevo, ios::beg );
        archivo.read( ( char * ) &contador, sizeof( int ) );
        if( contador < CONTENEDOR )
        {
            // aumenta el contador y lo escribe
            contador++;
            archivo.seekg( posByteNuevo, ios::beg );
            archivo.write( ( char * ) &contador, sizeof( int ) );

            // escribe el nuevo registro en el contenedor
            for( int i = 0; i < CONTENEDOR; i++ )
            {
                archivo.read( ( char * ) &pago, sizeof( Pagos ) );
                if( pago.Id[ 0 ] == '\0' ) // si el lugar no esta ocupado
                {
                    archivo.seekg( ( long )archivo.tellg() - sizeof( Pagos ), ios::beg );
                    archivo.write( ( char * ) &pagoNuevo, sizeof( Pagos ) );
                    archivo.close();
                    return true;
                }
            }
        }
        else // el contenedor esta lleno
            return false;
    }
} // fin funcion modificar

bool Pagos::eliminar( const string &idAEliminar, Pagos &destinoEliminado )
{
    Pagos pago;
    int posIndice, posByte, contador;

    if( !contiene( idAEliminar ) )
        return false;

    fstream archivo( "ArchivoDispersion.txt", ios::in | ios::out );
    if( !archivo )
    {
        cout << "El archivo no exite" << endl;
        archivo.close();
        return false;
    } 

    posIndice = dispersion( idAEliminar.c_str() );
    posByte = buscarId( idAEliminar );

    archivo.seekg( posByte, ios::beg );
    archivo.read( ( char * ) &destinoEliminado, sizeof(  Pagos) );
    archivo.seekg( posByte, ios::beg );
    archivo.write( ( char * ) &pago, sizeof(  Pagos) );

    posByte = posIndice * ( sizeof( Pagos ) * CONTENEDOR + sizeof( int ) );
    archivo.seekg( posByte, ios::beg );
    archivo.read( ( char * ) &contador, sizeof( int ) );
    contador--;
    archivo.seekg( posByte, ios::beg );
    archivo.write( ( char * ) &contador, sizeof( int ) );
    archivo.close();
    return true;
}

