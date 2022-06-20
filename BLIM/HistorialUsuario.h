#ifndef HISTORIALUSUARIO_H
#define HISTORIALUSUARIO_H


class Indice1
{
    public:
    char ID[10];
    long int pos;

};

class HistorialUsuario
{
    protected:
	    char ID[10], nombre[35], cuenta[35];
	    int NumPeliculas, NumSeries;
	    Indice1 y;
	    int orden;
    
    public:
		HistorialUsuario();
	    void Agregar(HistorialUsuario &);
	    void Imprimir(HistorialUsuario &);
	    void Buscar(HistorialUsuario &);
	    void Modificar(HistorialUsuario &);
	    void Eliminar(HistorialUsuario &);
	    void Mostrar_Indice(HistorialUsuario &);
};


#endif
