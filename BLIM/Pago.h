#ifndef PAGO_H
#define PAGO_H

class Pago
{
	private:
		int id;
		char nombre[ 35 ];
		char direccion[ 40 ];
		char ciudad[ 40 ];
		char sueldo[ 10 ];

		static Pago eliminarEnArchDatos( const int idAEliminar );
		static void eliminarEnListaTargeta( const int idAEliminar );
		static bool modificarEnArchDatos( const int, const Pago &registroReemplazo );
		static int buscarEnListaNombres( const std::string &nombreABuscar );

		void ayudanteMetodosEstablecer(char *atributo, const std::string &valorAtributo,
			const int tamMaximo);

	public:
		Pago(){}
		Pago( const Pago & );
		void setNombre( const std::string &valorNombre );
		void setDireccion( const std::string &valorDireccion );
		void setCiudad( const std::string &valorCiudad );
		void setSueldo( const std::string &valorSueldo );
		void setId( const int valorId );
		std::string getNombre() const;
		int getId() const;
		friend std::ostream &operator<<( std::ostream &salida, const Pago &empleado );
		
		
        static bool eliminar( const int idAEliminar, Pago &registroEliminado );
        static bool modificar( const int idAModificar, const Pago &reemplazo );
        static void buscarPorNombre( const std::string &nombreABuscar );
        static void inicializar();
        static void guardar();
        static void agregar( const Pago &nuevoPago );
        static void mostrarTodo();
        static void mostrarListas();
        static int existeId( const int idABuscar );
        static Pago pedirPago( bool debePedirId = true );
        static bool buscarPorId( const int idABuscar, Pago &resultado );
};

#endif
