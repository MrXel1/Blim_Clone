//Librerias
#include <iostream>
using namespace std;

//Clases
#include "Pelicula.h"
#include "Seriestv.h"
#include "Usuarios.h"
#include "Lista_Reproduccion.h"
#include "Pago.h"
#include "HistorialUsuario.h"
#include "Pagos.h"
#include "Usuario.h"
#include "menu.h"

//Protoipos de Funciones
int menu1();
int menu2();
int menu3();
int menu4();
int menu5();
int menu6();
int menu7();
int menu8();
int menu9();

//Programa Principal
int main(int argc, char** argv){
	//Variables
	int opc,opc1;
	string respuesta;
    string idABuscar, idAModificar, idAEliminar;
    
	//Objetos
	Pelicula CatalogoP;
	Seriestv CatalogoS;
	Usuarios usuario;
	Lista_Reproduccion lr;
	Pago pago, nuevo, pagoBuscar, pagoEliminado;
	HistorialUsuario H;
	Pagos pag, pagBuscar, pagoModificar, pagoEliminar, pagoAgregar;
	Usuario usuarios;
	
	//Inicializaciones
	Pago::inicializar();
	pag.genera();
	
	do{
		opc = menu1();
		switch(opc){
			case 1:{
				system("cls");
				opc1 = menu2();
				switch(opc1){
					case 1:{
					    cout << endl;
						cout<<"Agregar"<<endl;
						CatalogoP.Agregar();
						break;
					}
					case 2:{
					    cout << endl;
						cout<<"Imprimir"<<endl<<endl;
						CatalogoP.Imprimir();
						break;
					}
					case 3:{
					    cout << endl;
						cout<<"Buscar"<<endl;
						CatalogoP.Buscar();
						break;
					}
					case 4:{
					    cout << endl;
						cout<<"Modificar"<<endl;
						CatalogoP.Modificar();
						break;
					}
					case 5:{
					    cout << endl;
						cout<<"Eliminar"<<endl;
						CatalogoP.Eliminar();
						break;
					}
					case 0:{
						cout<<endl<<"Regresando al menu principal"<<endl<<endl;
						break;
					}
				}
				break;
			}
			case 2:{
				system("cls");
				opc1 = menu3();
				switch(opc1){
					case 1:{
					    cout << endl;
						cout<<"Agregar"<<endl;
						CatalogoS.Agregar();
						break;
					}
					case 2:{
					    cout << endl;
						cout<<"Imprimir"<<endl<<endl;
						CatalogoS.Imprimir();
						break;
					}
					case 3:{
					    cout << endl;
						cout<<"Buscar"<<endl;
						CatalogoS.Buscar();
						break;
					}
					case 4:{
					    cout << endl;
						cout<<"Modificar"<<endl;
						CatalogoS.Modificar();
						break;
					}
					case 5:{
					    cout << endl;
						cout<<"Eliminar"<<endl;
						CatalogoS.Eliminar();
						break;
					}
					case 0:{
						cout<<endl<<"Gracias por utilizar el programa"<<endl<<endl;
						break;
					}
				}
				break;
			}
			case 3:{
				system("cls");
				opc1 = menu4();
				switch(opc1){
					case 1:{
					    cout << endl;
						cout<<"Agregar"<<endl;
		            usuario.Agregar();
						break;
					}
					case 2:{
					    cout << endl;
						cout<<"Imprimir"<<endl<<endl;
						usuario.Imprimir();
						break;
					}
					case 3:{
					    cout << endl;
						cout<<"Buscar"<<endl;
						usuario.Buscar();
						break;
					}
					case 4:{
					    cout << endl;
						cout<<"Modificar"<<endl;
						usuario.Modificar();
						break;
					}
					case 5:{
					    cout << endl;
						cout<<"Eliminar"<<endl;
						usuario.Eliminar();
						break;
					}
					case 0:{
						cout<<endl<<"Gracias por utilizar el programa"<<endl<<endl;
						break;
					}
				}
				break;
			}
			case 4:{
				system("cls");
				opc1 = menu5();
				switch(opc1){
					case 1:{
					    cout << endl;
						cout<<"Agregar"<<endl;
						lr.Agregar(lr);
						break;
					}
					case 2:{
					    cout << endl;
						cout<<"Imprimir"<<endl<<endl;
						lr.Imprimir(lr);
						break;
					}
					case 3:{
					    cout << endl;
						cout<<"Buscar"<<endl;
						lr.Buscar(lr);
						break;
					}
					case 4:{
					    cout << endl;
						cout<<"Modificar"<<endl;
						lr.Modificar(lr);
						break;
					}
					case 5:{
					    cout << endl;
						cout<<"Eliminar"<<endl;
						lr.Eliminar(lr);
						break;
					}
					case 6:{
					    cout << endl;
						cout<<"Mostrar Indice"<<endl;
						lr.Mostrar_Indice(lr);
						break;
					}
					case 0:{
						cout<<endl<<"Gracias por utilizar el programa"<<endl<<endl;
						break;
					}
				}
				break;
			}
			case 5:{
				system("cls");
				opc1 = menu6();
				switch(opc1)
			    {
			    	case 1: // agregar
			    		nuevo = Pago::pedirPago();
			    		Pago::agregar( nuevo );
			    		break;
		
			    	case 2: // mostrar
			    		Pago::mostrarTodo();
			    		break;
		
		            case 3: // buscar por id
		                cout << "Ingrese el ID a buscar: ";
		                fflush( stdin );
		                cin >> respuesta;
		
		                if( Pago::buscarPorId( atoi( respuesta.c_str() ), pagoBuscar ) )
		                    cout << pagoBuscar << endl << endl;
		                else
		                    cout << "El registro no existe" << endl;
		                break;
		
		            case 4: // buscar por nombre
		            	cout << "Ingresa el nombre a buscar: ";
		            	fflush( stdin );
		            	getline( cin, respuesta );
		            	Pago::buscarPorNombre( respuesta );
		            	break;
		
		            case 5: // modificar
		                cout << "Ingrese el ID del pago a modificar: ";
		                fflush( stdin );
		                cin >> respuesta;
		
		                if(Pago::existeId(atoi(respuesta.c_str())) != -1) // si existe el empleado
		                {
							// se pide un nuevo registro pero no se pide el id porque
							// el id no se puede modificar
		                	nuevo = Pago::pedirPago(false);
							// al nuevo registro se le pone el id antiguo
							nuevo.setId(atoi(respuesta.c_str()));
		
							// intento de modificar el registro
		                	if(pago.modificar( atoi(respuesta.c_str()), nuevo ))
								cout << "Pago modificado con exito" << endl;
							else
								cout << "Ocurrio un error al modificar el pago" << endl;
		                }
		                else
		                    cout << "No existe el pago" << endl;
		                break;
		
		            case 6: // eliminar
		                cout << "Ingrese el ID del pago a eliminar: ";
		                fflush( stdin );
		                cin >> respuesta;
		
		                if( Pago::existeId( atoi(respuesta.c_str()) ) != -1 ) // si existe el empleado
		                {
			                if( Pago::eliminar( atoi(respuesta.c_str()), pagoEliminado ) )
			                {
			                	cout << endl << pagoEliminado << endl;
			                	cout << "PAGO ELIMINADO CON EXITO" << endl;
			                }
			                else
			                    cout << "No se elimino el pago" << endl;
			            }
			            else
			            	cout << "No existe el pago" << endl;
		                break;
		
		            case 8:
		            	Pago::mostrarListas();
		            	break;
			    }
				break;
			}
			case 6:{
				system("cls");
				opc1 = menu7();
				switch(opc1)
		        {
		
		            case 1:
		
		                H.Agregar(H);
		                break;
		
		            case 2:
		
		                H.Imprimir(H);
		                break;
		
		            case 3:
		
		                H.Buscar(H);
		                break;
		
		            case 4:
		
		                H.Modificar(H);
		                break;
		
		            case 5:
		
		                 H.Eliminar(H);
		                 break;
		
		            case 6:
		
		                H.Mostrar_Indice(H);
		                break;
		        }
				break;
			}
			case 7:{
				system("cls");
				opc1 = menu8();
				switch(opc1)
		        {
		          case 1:
		            pagoAgregar = pag.pedirRegistro();
		            if( pag.agregar( pagoAgregar ) )
		                cout << "Pago realizado" << endl;
		            else
		                cout << "Pago no realizado" << endl;
		            break;
		
		          case 2:
		            system( "cls" );
		            pag.mostrar();
		            break;
		
		          case 3:
		            cout << "Ingrese el ID del pago a buscar: ";
		            fflush( stdin );
		            getline( cin, idABuscar );
		            if( pag.buscar( idABuscar, pagBuscar ) )
		                cout << endl << pagBuscar << endl;
		            else
		                cout << "No existe el pago" << endl;
		            break;
		
		          case 4:
		            cout << "Ingrese el ID del pago a modificar: ";
		            fflush( stdin );
		            getline( cin, idAModificar );
		            if( pag.buscar( idAModificar, pagBuscar ) )
		            {
		                cout << endl << pagoBuscar << endl;
		                cout << "Desea modificarlo?" << endl;
		                cout << "1) Si" << endl;
		                cout << "2) No" << endl;
		                cin >> opc;
		
		                if( opc == 1 )
		                {
		                    pagoModificar = pag.pedirRegistro();
		                    if( pag.modificar( idAModificar, pagoModificar ) )
		                        cout << endl << "Pago modificado con exito" << endl;
		                    else
		                        cout << endl << "No se pudo modificar" << endl;
		                }
		            }
		            else
		                cout << "No existe el pago" << endl;
		            break;
		
		          case 5:
		            cout << "Ingrese el ID del pago a eliminar: ";
		            fflush( stdin );
		            getline( cin, idAEliminar );
		            if( pag.buscar( idAEliminar, pagBuscar ) )
		            {
		                cout << endl << pagoBuscar << endl;
		                cout << "Desea eliminarlo?" << endl;
		                cout << "1) Si" << endl;
		                cout << "2) No" << endl;
		                cin >> opc;
		
		                if( opc == 1 )
		                    if( pag.eliminar( idAEliminar, pagoEliminar ) )
		                        cout << endl << pagoEliminar << endl << "SE ELIMINO DE FORMA CORRECTA" << endl;
		                    else
		                        cout << "NO SE PUDO ELIMINAR" << endl;
		            }
		            else
		                cout << "No existe el pago" << endl;
		            break;
		        }
				break;
			}
			case 8:{
				system("cls");
				opc1 = menu9();
				switch(opc1){
					case 1:{
					    cout << endl;
						cout<<"Agregar Usuario"<<endl;
		                usuarios.Agregar();
						break;
					}
					case 2:{
					    cout << endl;
						cout<<"Impresion de Usuarios"<<endl<<endl;
						usuarios.Imprimir();
						break;
					}
					case 3:{
					    cout << endl;
						cout<<"Buscar Usuario"<<endl;
						usuarios.Buscar();
						break;
					}
					case 4:{
					    cout << endl;
						cout<<"Modificar Usuario"<<endl;
						usuarios.Modificar();
						break;
					}
					case 5:{
					    cout << endl;
						cout<<"Eliminar Usuario"<<endl;
						usuarios.Eliminar();
						break;
					}
					case 0:{
						cout<<endl<<"Gracias por utilizar el programa"<<endl<<endl;
						break;
					}
				}
				break;
			}
			case 9:{
				system("cls");
				menu compress;
				break;
			}
			case 0:{
				cout<<"Saliendo..."<<endl;
				break;
			}
			default:{
				cout<<"Opcion No valida"<<endl;
				break;
			}
		}
		
		Pago::guardar();
		system("Pause");
		system("cls");
	}while(opc!=0);
	return 0;
}

int menu1(){
	int opc;
	cout << "**************************"<<endl;
    cout << "**   MENU PRINCIPAL     **"<<endl;
    cout << "**************************"<<endl;
    cout << "**        BLIM          **"<<endl;
    cout << "**************************"<<endl;
    cout << "1-. Peliculas" << endl;
    cout << "2.-Catalogo Series TV" << endl;
    cout << "3.-Usuarios" << endl;
    cout << "4.-Lista de Reproduccion" << endl;
    cout << "5.-Pagos" << endl;
    cout << "6.-Historial Usuarios" << endl;
    cout << "7.-Menu de Pagos(Dispersion)" << endl;
    cout << "8.-Datos de Usuario (Encriptacion)" << endl;
    cout << "9.-Series TV (Compresion)" << endl;
    cout << "0.-Salir" << endl;
    cout << endl;
    cout << "Elige una opcion: ";
	cin>>opc;
	return opc;
}

//Funciones Desarrolladas
int menu2(){
	int opc;
    cout << endl;
    cout << " Peliculas" << endl;
    cout << " [1] Agregar" << endl;
    cout << " [2] Imprimir" << endl;
    cout << " [3] Buscar" << endl;
    cout << " [4] Modificar" << endl;
    cout << " [5] Eliminar" << endl;
    cout << " [0] Salir"<< endl;
    cout << endl;
    cout << "Elige una opcion: ";
	cin>>opc;
	return opc;
}

int menu3(){
	int opc;
    cout << endl;
    cout << "Catalogo Series TV" << endl;
    cout << " [1] Agregar" << endl;
    cout << " [2] Imprimir" << endl;
    cout << " [3] Buscar" << endl;
    cout << " [4] Modificar" << endl;
    cout << " [5] Eliminar" << endl;
    cout << " [0] Salir"<< endl;
    cout << endl;
    cout << "Elige una opcion: ";
	cin>>opc;
	return opc;
}

int menu4(){
	int opc;
    cout << endl;
    cout << " Usuarios" << endl;
    cout << " [1] Agregar" << endl;
    cout << " [2] Imprimir" << endl;
    cout << " [3] Buscar" << endl;
    cout << " [4] Modificar" << endl;
    cout << " [5] Eliminar" << endl;
    cout << " [0] Salir"<< endl;
    cout << endl;
    cout << "Elige una opcion: ";
	cin>>opc;
	return opc;
}

int menu5(){
	int opc;
    cout << endl;
    cout << "Lista de Reproduccion" << endl;
    cout << " [1] Agregar" << endl;
    cout << " [2] Imprimir" << endl;
    cout << " [3] Buscar" << endl;
    cout << " [4] Modificar" << endl;
    cout << " [5] Eliminar" << endl;
    cout << " [0] Mstrar Indice"<< endl;
    cout << " [0] Salir"<<endl;
    cout << endl;
    cout << "Elige una opcion: ";
	cin>>opc;
	return opc;
}

int menu6(){
	string opcionElegida;

	cout << "    Pagos" << endl << endl;
	cout << "[1]Agregar Pago" << endl;
	cout << "[2]Mostrar todos los pagos" << endl;
	cout << "[3]Buscar pago por ID" << endl;
	cout << "[4]Buscar pagos por Nombre" << endl;
    cout << "[5]Modificar pagos" << endl;
    cout << "[6]Eliminar pago" << endl;
    cout << "[7]Salir" << endl;
    cout << "[8]Mostrar listas" << endl; 
	cin >> opcionElegida;

	return atoi(opcionElegida.c_str());
}

int menu7(){
	int opc;
    cout << endl;
    cout << "         Historial Usuarios " << endl;
    cout << " [1] Agregar" << endl;
    cout << " [2] Imprimir" << endl;
    cout << " [3] Buscar" << endl;
    cout << " [4] Modificar" << endl;
    cout << " [5] Eliminar" << endl;
    cout << " [6] Mostrar Indice" << endl;
    cout << " [0] Salir" << endl;
    cout << endl;
    cout << "Elige una opcion: ";
    cin>>opc;
    
    return opc;
}

int menu8(){
		int opc;
    cout << endl;
    cout << "       Menu de Pagos(Dispersion) " << endl;
    cout << " [1] Pagar" << endl;
    cout << " [2] Mostrar" << endl;
    cout << " [3] Buscar" << endl;
    cout << " [4] Modificar" << endl;
    cout << " [5] Eliminar" << endl;
    cout << " [6] Salir" << endl;
    cout << endl;
    cout << "Elige una opcion: ";
    cin>>opc;

    return opc;
}

int menu9(){
	int opc;
    cout << endl;
    cout << "        Datos de Usuario (Encriptados)" << endl;
    cout << " [1] Agregar" << endl;
    cout << " [2] Imprimir" << endl;
    cout << " [3] Buscar" << endl;
    cout << " [4] Modificar" << endl;
    cout << " [5] Eliminar" << endl;
    cout << " [0] Salir" << endl;
    cout << endl;
    cout << "Elige una opcion: ";
	cin>>opc;
	return opc;
}

	
