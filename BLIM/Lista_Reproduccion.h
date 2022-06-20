#ifndef LISTA_REPRODUCCION_H
#define LISTA_REPRODUCCION_H


class Indice
{
    public:
    char ID[15];
    long int pos;

};


class Lista_Reproduccion{
    protected:
        char ID[15], Nombre[35], Categoria[35], Duracion[20], Anio[10];
        int orden;
        Indice in;
    public:
        Lista_Reproduccion();

        void Agregar(Lista_Reproduccion &);
        void Imprimir(Lista_Reproduccion &);
        void Buscar(Lista_Reproduccion &);
        void Modificar(Lista_Reproduccion &);
        void Eliminar(Lista_Reproduccion &);
        void Mostrar_Indice(Lista_Reproduccion &);
};


#endif
