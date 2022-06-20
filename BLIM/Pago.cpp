#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>
#include <string.h>
#include "ListaLigada.h"
#include "Pago.h"

using namespace std;

/* Función para mostrar una lista ligada */
template < typename E >
void mostrar( ListaLigada< E > &L );

// prototipo de función
string convertirAMayusculas(const string &cadena);

/* Para guardar y recuperar la lista de nombres desde el archivo */
struct IndiceNombre
{
	char nombre[ 35 ] ;
	int enlace;
};

/* Para guardar y recuperar la lista de nrrs y de enlaces desde el archivo */
struct IndiceEnlace
{
	int id;
	int enlace;
};

// declaración de las listas
ListaLigada< string > listaIndicesNombres;
ListaLigada< int > listaTargeta;
ListaLigada< int > listaEnlaces;


/* Constructor copia */
Pago::Pago( const Pago &origen )
{
	id = origen.getId();
	strcpy( nombre, origen.nombre );
	strcpy( direccion, origen.direccion );
	strcpy( ciudad, origen.ciudad );
	strcpy( sueldo, origen.sueldo );
}


/* Establece el id del empleado */
void Pago::setId( const int valorId )
{
	id = valorId;
}

/* Establece el sueldo del empleado */
void Pago::setSueldo( const string &valorSueldo )
{
	ayudanteMetodosEstablecer(sueldo, valorSueldo, 10);
}

/* Establece el nombre del empleado */
void Pago::setNombre( const string &valorNombre )
{
	ayudanteMetodosEstablecer(nombre, valorNombre, 35);
}

/* Establece la direccion del empleado */
void Pago::setDireccion( const string &valorDireccion )
{
	ayudanteMetodosEstablecer(direccion, valorDireccion, 40);
}

/* Establece la ciudad del empleado */
void Pago::setCiudad( const string &valorCiudad )
{
	ayudanteMetodosEstablecer(ciudad, valorCiudad, 40);
}

/* Retorna el id del empleado */
int Pago::getId() const
{
	return id;
}

/* Retorna el nombre del empleado */
string Pago::getNombre() const
{
	return nombre;
}

/* Sobrecarga del operador << para imprimir un empleado */
ostream &operator<<( ostream &salida, const Pago &pago )
{
    salida << "ID:        "  << pago.getId() << endl
           << "Nombre:    "  << pago.getNombre() << endl
           << "Direccion: "  << pago.direccion << endl
           << "Ciudad:    "  << pago.ciudad << endl
           << "Tarjeta:   "  << pago.sueldo << endl;

    return salida;
}


/* Método para establecer los valores de los atributos de tipo cadena */
void Pago::ayudanteMetodosEstablecer(char *atributo, const string &valorAtributo,
			const int tamMaximo)
{
	int longitud = valorAtributo.size();
	longitud = ( longitud < tamMaximo ? longitud : tamMaximo );
	valorAtributo.copy( atributo, longitud );
	atributo[ longitud ] = '\0';
}


/* Elimina un registro del archivo de datos, si la operación se realiza con éxito
retorna true y el registro se pone en valor, en caso contrario retorna false */
bool Pago::eliminar( const int idAEliminar, Pago &registroEliminado )
{
	Pago antiguoPago;

	if(Pago::buscarPorId(idAEliminar, antiguoPago)) // si existe el registro
	{
		int posicionEncontradoNombre = Pago::buscarEnListaNombres(antiguoPago.getNombre());
		listaIndicesNombres.irAPosicion(posicionEncontradoNombre);

		listaEnlaces.irAPosicion(listaIndicesNombres.obtenerEnlace());
		int posicionAnterior = listaEnlaces.posicionActual();

		// si el primer elemento es el que se va a eliminar
		if(listaEnlaces.obtenerElemento() == idAEliminar)
		{
			int enlace = listaEnlaces.obtenerEnlace();
			listaIndicesNombres.irAPosicion(posicionEncontradoNombre);

			if(enlace == -1) // si solo había un registro con ese nombre
				listaIndicesNombres.eliminar(); // eliminar el nombre de la lista de nombres

			else // si no, reacomodar el enlace
				listaIndicesNombres.cambiarEnlace(enlace);

			listaEnlaces.modificar(-1, -1); // simula una eliminación
		}
		else
		{
			while(listaEnlaces.obtenerEnlace() != -1 && listaEnlaces.obtenerElemento() != idAEliminar)
			{
				posicionAnterior = listaEnlaces.posicionActual();
				listaEnlaces.irAPosicion(listaEnlaces.obtenerEnlace());
			}

			int nuevoEnlace = listaEnlaces.obtenerEnlace();
			listaEnlaces.modificar(-1, -1); // simula una eliminación

			//posicionEncontradoEliminar = listaEnlaces.posicionActual();
			listaEnlaces.irAPosicion(posicionAnterior);
			listaEnlaces.cambiarEnlace(nuevoEnlace);
		}

		Pago::eliminarEnListaTargeta(idAEliminar);
		registroEliminado = Pago::eliminarEnArchDatos(idAEliminar);

		return true;
	}

	return false;
}

/* Modifica un empleado, se encarga de reacomodar los enlaces dependiendo del
nuevo nombre agregado */
bool Pago::modificar( const int idAModificar, const Pago &reemplazo )
{
	string nuevoNombre = convertirAMayusculas(reemplazo.getNombre());
	Pago antiguoPago;
	int posicionEncontradoModificar;

	if(Pago::buscarPorId(idAModificar, antiguoPago)) // si existe el registro
	{
		string antiguoNombre = convertirAMayusculas(antiguoPago.getNombre());

		if(nuevoNombre != antiguoNombre) // solo hay reacomodo si los nombres son distintos
		{
			int posicionEncontradoNombre = Pago::buscarEnListaNombres(antiguoNombre);
			listaIndicesNombres.irAPosicion(posicionEncontradoNombre);

			listaEnlaces.irAPosicion(listaIndicesNombres.obtenerEnlace());
			int posicionAnterior = listaEnlaces.posicionActual();

			// si el primer id de la lista de enlaces es el del registro a modificar
			if(listaEnlaces.obtenerElemento() == idAModificar)
			{
				int enlace = listaEnlaces.obtenerEnlace();
				posicionEncontradoModificar = listaEnlaces.posicionActual();
				if(enlace == -1) // si era el único entonces eliminar el nombre
				{
					listaIndicesNombres.irAPosicion(posicionEncontradoNombre);
					listaIndicesNombres.eliminar();
				}
				else // si no entonces reacomodar el enlace
				{
					listaIndicesNombres.irAPosicion(posicionEncontradoNombre);
					listaIndicesNombres.cambiarEnlace(enlace);
				}
			}
			else // si el id del registro a eliminar no es el primero de listaEnlaces
			{
				// mientras no se encuentre el id
				while(listaEnlaces.obtenerEnlace() != -1 && listaEnlaces.obtenerElemento() != idAModificar)
				{
					posicionAnterior = listaEnlaces.posicionActual();
					listaEnlaces.irAPosicion(listaEnlaces.obtenerEnlace());
				}

				// racomodar el enlace
				int nuevoEnlace = listaEnlaces.obtenerEnlace();
				posicionEncontradoModificar = listaEnlaces.posicionActual();
				listaEnlaces.irAPosicion(posicionAnterior);
				listaEnlaces.cambiarEnlace(nuevoEnlace);
			}

			int pos = Pago::buscarEnListaNombres(nuevoNombre);
			if(pos != -1) // si el nuevo nombre ya existe
			{
				// reacomodar el enlace
				listaIndicesNombres.irAPosicion(pos);
				int enlaceN = listaIndicesNombres.obtenerEnlace();
				listaIndicesNombres.cambiarEnlace(posicionEncontradoModificar);

				listaEnlaces.irAPosicion(posicionEncontradoModificar);
				listaEnlaces.cambiarEnlace(enlaceN);
			}
			else // el nuevo nombre no existe
			{
				// inserta un nuevo nombre en listaIndicesNombre apuntando
				// la posición del id a modificar
				listaIndicesNombres.ponAlFinal(nuevoNombre, posicionEncontradoModificar);

				// el enlace del id del empleado a modificar debe apuntar a -1
				listaEnlaces.irAPosicion(posicionEncontradoModificar);
				listaEnlaces.cambiarEnlace(-1);
			}
		}

		if(Pago::modificarEnArchDatos(idAModificar, reemplazo)) // modifica en el archivo
			return true;
	}

	return false;
}


/* Muestra todas las listas */
void Pago::mostrarListas()
{
	cout << "Lista de nombres: ";
	mostrar( listaIndicesNombres );

	cout << "Lista de enlaces: ";
	mostrar( listaEnlaces );

	cout << "Lista de id's y tarjetas: ";
	mostrar( listaTargeta );
}

/* Método estático que retorna un Empleado con los datos que el usuario
ingresó*/
Pago Pago::pedirPago( bool debePedirId )
{
	string cadena;
	Pago pagoARetornar;

	if(debePedirId)
	{
		cout << "Ingresa el ID: ";
		fflush( stdin );
		getline( cin, cadena );
		int valorId = atoi(cadena.c_str());

		while(valorId == 0) // el valor no es un número o es un cero
		{
			cout << "Valor invalido, intentalo de nuevo: ";
			fflush( stdin );
			getline( cin, cadena );
			valorId = atoi(cadena.c_str());
		}

		while( Pago::existeId( atoi( cadena.c_str() ) ) != -1 ) // el empleado ya existe
		{
			cout << "Ese ID ya existe Ingresa otro: ";
			fflush( stdin );
			getline( cin, cadena );
		}

		pagoARetornar.setId( atoi(cadena.c_str()) );
	}

	cout << "Ingrese el nombre del pago: ";
    fflush( stdin );
    getline( cin, cadena );
    pagoARetornar.setNombre( cadena );

    cout << "Ingrese la direccion: ";
    fflush( stdin );
    getline( cin, cadena );
    pagoARetornar.setDireccion( cadena );

    cout << "Ingrese la ciudad: ";
    fflush( stdin );
    getline( cin, cadena );
    pagoARetornar.setCiudad( cadena );

    cout << "Ingrese el numero de tarjeta: ";
    fflush( stdin );
    getline( cin, cadena );
    pagoARetornar.setSueldo( cadena );

    return pagoARetornar;
}


/* Muestra todos los empleados del archivo de datos */
void Pago::mostrarTodo()
{
	Pago pago;
	ifstream archivo( "pagos.txt", ios::in );
	if( !archivo )
		cout << "No existe el archivo" << endl;
	else
	{
		cout << endl;
		while( !archivo.eof() )
		{
			archivo.read( ( char * ) &pago, sizeof( Pago ) );
			if( !archivo.eof() )
				cout << pago << endl << endl;
		}
	}
	archivo.close();
}

/* Retorna la posición en donde se encuentra el id del empleado, en caso
de que no existiera retorna -1 */
int Pago::existeId( const int idABuscar )
{
	listaTargeta.irAlInicio();
	for( int i = 0; i < listaTargeta.obtenerTamanio(); i++ )
		if( listaTargeta.obtenerElemento() == idABuscar )
			return listaTargeta.obtenerEnlace();
		else
			listaTargeta.siguiente();
	return -1;
}



/* Retorna la posición en donde se encuentra el nombreABuscar, en caso
de que no se encontrase se retorna -1 */
int Pago::buscarEnListaNombres( const string &nombreABuscar )
{
	string nombreABuscarCanonico = convertirAMayusculas(nombreABuscar);
	listaIndicesNombres.irAlInicio();
	for( int i = 0; i < listaIndicesNombres.obtenerTamanio(); i++ )
		if( listaIndicesNombres.obtenerElemento() == nombreABuscarCanonico )
			return listaIndicesNombres.posicionActual();
		else
			listaIndicesNombres.siguiente();
	return -1;
}


/* Elimina un empleado del archivo de datos, el empleado eliminado se retorna */
Pago Pago::eliminarEnArchDatos( const int idAEliminar )
{
	ifstream datos( "pagos.txt", ios::in );
	ofstream temporal( "temporal.txt", ios::out );
	Pago registro;
	Pago registroARetornar;

	while( !datos.eof() )
	{
		datos.read( ( char * ) &registro, sizeof( Pago ) );
		if(!datos.eof())
		{
			if( registro.getId() != idAEliminar )
				temporal.write( ( char * ) &registro, sizeof( Pago ) );
			else
				registroARetornar = registro;
		}
	}
	datos.close();
	temporal.close();
	remove( "pagos.txt" );
	rename( "temporal.txt", "pagos.txt" );

	return registroARetornar;
}

/* Elimina un elemento de la lista de listaNrrs y reacomoda las posiciones relativas de
cada registro del archivo de datos */
void Pago::eliminarEnListaTargeta( const int idAEliminar )
{
	int posicion = Pago::existeId( idAEliminar );
	listaTargeta.irAPosicion( posicion );
	listaTargeta.eliminar();

	// el nrr de los registros mayores a posicion deben disminuirse en 1
	for( int i = posicion; i < listaTargeta.obtenerTamanio(); i++ )
	{
		listaTargeta.cambiarEnlace( listaTargeta.obtenerEnlace() - 1 );
		listaTargeta.siguiente();
	}
}

/* Método estático que busca el id de un empleado, si se encuentra retorna true
y coloca el registro en resultado, en caso contrario retorna false*/
bool Pago::buscarPorId( const int idABuscar, Pago &resultado )
{
	long int posByte;
	ifstream datos( "pagos.txt", ios::in );

	if( !datos )
		cout << "No existe el archivo" << endl;
	else
	{
		listaTargeta.irAlInicio();
		for( int i = 0; i < listaTargeta.obtenerTamanio(); i++ )
		{
			if( listaTargeta.obtenerElemento() == idABuscar )
			{
				posByte = listaTargeta.obtenerEnlace() * sizeof( Pago );
				datos.seekg( posByte, ios::beg );
				datos.read( ( char * ) &resultado, sizeof( Pago ) );
				datos.close();
				return true;
			}
			listaTargeta.siguiente();
		}
	}
	datos.close();
	return false;
}

/* Muestra todos los empleados que tienen un nombre dado */
void Pago::buscarPorNombre( const string &nombreABuscar )
{
	ifstream datos( "pagos.txt", ios::in );
	int indiceRegistro;
	long int posByte;
	Pago temporal;
	bool yaTermino = false;
	string nombreABuscarCanonico = convertirAMayusculas(nombreABuscar);

	if( !datos )
		cout << "No existe el archivo" << endl;
	else
	{
		int posEncontrado = Pago::buscarEnListaNombres( nombreABuscarCanonico );
		if( !( posEncontrado == -1 ) ) // si existe el nombre
		{
			cout << endl;
			listaIndicesNombres.irAPosicion( posEncontrado );
			listaEnlaces.irAPosicion( listaIndicesNombres.obtenerEnlace() );
			do
			{
				indiceRegistro = Pago::existeId( listaEnlaces.obtenerElemento() );
				posByte = indiceRegistro * sizeof( Pago ); // clacula la posición de inicio del registro en el archivo
				datos.seekg( posByte, ios::beg ); // se mueve a donde inicia el registro
				datos.read( ( char * ) &temporal, sizeof( temporal ) );
				cout << temporal << endl << endl;

				if( listaEnlaces.obtenerEnlace() == -1  )
					yaTermino = true;
				else
					listaEnlaces.irAPosicion( listaEnlaces.obtenerEnlace() );
			}while( yaTermino == false );
		}
		else
			cout << "No se encontraron resultados" << endl;
	}
	datos.close();
}

/* Inserta un nuevo registro en el archivo de datos */
void Pago::agregar( const Pago &nuevoPago)
{
	string cadenaNombre;

    ofstream archivo( "pagos.txt", ios::app );
    if( Pago::existeId( nuevoPago.getId() ) == -1 )
    {
	    archivo.write( ( char * ) &nuevoPago, sizeof( Pago ) );
	    listaTargeta.ponAlFinal( nuevoPago.getId(), listaTargeta.obtenerTamanio() );

	    cadenaNombre = convertirAMayusculas(nuevoPago.getNombre());
	    int posEncontrado = Pago::buscarEnListaNombres( cadenaNombre );

	    if( posEncontrado != -1 ) // si ya existe el nombre
	    {
	    	listaIndicesNombres.irAPosicion( posEncontrado );
	    	listaEnlaces.ponAlFinal( nuevoPago.getId(), listaIndicesNombres.obtenerEnlace() );
	    	listaIndicesNombres.cambiarEnlace( listaEnlaces.obtenerTamanio() - 1 );
	    }
	    else // si no existe el nombre
	    {
	    	listaEnlaces.ponAlFinal( nuevoPago.getId(), -1 );
	    	listaIndicesNombres.ponAlFinal( cadenaNombre, listaEnlaces.obtenerTamanio() - 1 );
	    }
	}
	else
		cout << "No se agrego, el ID ya existe" << endl;
    archivo.close();
}


/* Modifica un registro del archivo de datos */
bool Pago::modificarEnArchDatos( const int idAModificar, const Pago &registroReemplazo )
{
	fstream datos( "pagos.txt", ios::in | ios::out );
	if( datos )
	{
		int posDeRegistro = Pago::existeId( idAModificar );

		if(posDeRegistro != -1) // si existe el registro
		{
			int posByte = posDeRegistro * sizeof( Pago );
			datos.seekg( posByte, ios::beg );
			datos.write( ( char * ) &registroReemplazo, sizeof( Pago ) );

			return true;
		}
	}

	datos.close();

	return false;
}

/* Método que se debe llamar primero. Este método inicializa las listas con los
datos de los archivos */
void Pago::inicializar()
{
	IndiceNombre indiceNombre;
	IndiceEnlace indiceEnlace;
	string cadenaNombre;

	ifstream indiceNombres( "listaNombres.txt", ios::in );
	ifstream indiceEnlaces( "listaEnlaces.txt", ios::in );
	ifstream indiceTargeta( "listaTargeta.txt", ios::in );

	if( !indiceNombres || !indiceEnlaces || !indiceTargeta ) // si los archivos no existen los crea
	{
		ofstream indiceNombres( "listaNombres.txt", ios::out );
		ofstream indiceEnlaces( "listaEnlaces.txt", ios::out );
		ofstream indiceTargeta( "listaTargeta.txt", ios::out );
	}
	else
	{
		// archivo de índices para el nombre
		listaIndicesNombres.irAlInicio();
		while( !indiceNombres.eof() )
		{
			indiceNombres.read( ( char * ) &indiceNombre, sizeof( IndiceNombre ) );
			if( !indiceNombres.eof() )
			{
				cadenaNombre = indiceNombre.nombre;
				listaIndicesNombres.ponAlFinal( cadenaNombre, indiceNombre.enlace );
			}
			cadenaNombre.clear();
		}

		// archivo de indice ligado para nombre
		listaEnlaces.irAlInicio();
		while( !indiceEnlaces.eof() )
		{
			indiceEnlaces.read( ( char * ) &indiceEnlace, sizeof( IndiceEnlace ) );
			if( !indiceEnlaces.eof() )
				listaEnlaces.ponAlFinal( indiceEnlace.id, indiceEnlace.enlace );
		}

		// archivo de inidice de nrr's para los datos de empleados
		listaTargeta.irAlInicio();
		while( !indiceTargeta.eof() )
		{
			indiceTargeta.read( ( char * ) &indiceEnlace, sizeof( IndiceEnlace ) );
			if( !indiceTargeta.eof() )
				listaTargeta.ponAlFinal( indiceEnlace.id, indiceEnlace.enlace );
		}
	}

	indiceNombres.close();
	indiceEnlaces.close();
	indiceTargeta.close();
}

/* Método que se debe llamar al cerrar el programa. Este método guarda las listas
en su respectivo archivo */
void Pago::guardar()
{
	ofstream indiceNombres( "listaNombres.txt", ios::out );
	ofstream indiceEnlaces( "listaEnlaces.txt", ios::out );
	ofstream indiceTargeta( "listaTargeta.txt", ios::out );

	// guarda la lista de nombres
	IndiceNombre indiceNombre;
	listaIndicesNombres.irAlInicio();
	for( int i = 0; i < listaIndicesNombres.obtenerTamanio(); i++ )
	{
		for( int j = 0; j < sizeof( indiceNombre.nombre ); indiceNombre.nombre[ j++ ] = '\0' );
		strcpy( indiceNombre.nombre, listaIndicesNombres.obtenerElemento().c_str() );
		indiceNombre.enlace = listaIndicesNombres.obtenerEnlace();
		indiceNombres.write( ( char * ) &indiceNombre, sizeof( IndiceNombre ) );
		listaIndicesNombres.siguiente();
	}

	// guarda la lista de enlaces
	IndiceEnlace indiceEnlace;
	listaEnlaces.irAlInicio();
	for( int i = 0; i < listaEnlaces.obtenerTamanio(); i++ )
	{
		indiceEnlace.id = listaEnlaces.obtenerElemento();
		indiceEnlace.enlace = listaEnlaces.obtenerEnlace();
		indiceEnlaces.write( ( char * ) &indiceEnlace, sizeof( IndiceEnlace ) );
		listaEnlaces.siguiente();
	}

	// guarda la lista de nrr's
	listaTargeta.irAlInicio();
	for( int i = 0; i < listaTargeta.obtenerTamanio(); i++ )
	{
		indiceEnlace.id = listaTargeta.obtenerElemento();
		indiceEnlace.enlace = listaTargeta.obtenerEnlace();
		indiceTargeta.write( ( char * ) &indiceEnlace, sizeof( IndiceEnlace ) );
		listaTargeta.siguiente();
	}

	indiceNombres.close();
	indiceEnlaces.close();
	indiceTargeta.close();
}


/* Convierte un string a mayúsculas y lo retorna */
string convertirAMayusculas(const string &cadena)
{
	string cadenaEnMayusculas = cadena;

	for(size_t i = 0; i < cadena.length(); i++)
		cadenaEnMayusculas[i] = toupper(cadena[i]);

	return cadenaEnMayusculas;
}


/* Muetra el contenido de una lista ligada */
template < typename E >
void mostrar( ListaLigada< E > &L )
{
	int posOriginal = L.posicionActual();
	L.irAlInicio();

	cout << "[";
	for( int i = 0; i < L.obtenerTamanio(); i++ )
	{
		cout << L.obtenerElemento() << "->" << L.obtenerEnlace();
		if( !( i == ( L.obtenerTamanio() - 1 ) ) )
		{
			cout << ",  ";
			L.siguiente();
		}
	}
	cout << "]" << endl;
}
