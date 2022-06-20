#ifndef PAGOS_H
#define PAGOS_H

#include <iostream>
#include <fstream>

class Pagos
{
    private:
        char Id[ 12 ];
        char Nombre[ 35 ];
        char Banco[ 35 ];
        char Cantidad[ 10 ];

        int dispersion( const char llave[ 12 ] );
        long int buscarId( const  std::string & );
    public:
        Pagos( void );
        Pagos( const Pagos & );
        void setId( const std::string & );
        void setNombre( const std::string & );
        void setBanco( const std::string & );
        void setCantidad( const std::string & );

        friend std::ostream &operator<<( std::ostream &, const Pagos & );

        bool agregar( const Pagos & );
        void mostrar( void );
        bool buscar( const std::string &, Pagos & );
        bool eliminar( const std::string &, Pagos & );
        bool modificar( const std::string &, const Pagos & );
        void mostrarIndice( void );
        Pagos pedirRegistro( void );
        bool contiene( const std::string & );
        void genera( void );
};

#endif
