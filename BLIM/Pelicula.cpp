#include "Pelicula.h"

Pelicula::Pelicula()
{
}

void Pelicula::Agregar(){
    cout << endl;
	cout<<"Nombre: ";
	cin.ignore();
	getline(cin, Nombre);
	cout << endl;
	cout<<"Categoria: ";
	getline(cin, Categoria);
	cout << endl;
	cout<<"Duracion en minutos(Ej. 125): ";
	getline(cin, Duracion);
	cout << endl;
	cout<<"Anio de estreno: ";
	getline(cin, Anio);
	cout << endl;

	string Archivo = "Peliculas.txt";
	ofstream Peliculas;

	Peliculas.open(Archivo.c_str(), fstream::app);
	Peliculas <<Nombre<<endl<<"-"<<endl;
	Peliculas <<Categoria<<endl<<"-"<<endl;
	Peliculas <<Duracion<<endl<<"-"<<endl;
	Peliculas <<Anio<<endl<<"-"<<endl;
	Peliculas <<"_"<<endl;
	Peliculas.close();
}

void Pelicula::Imprimir(){
	string cadena;
	fstream datos("Peliculas.txt");

	if(datos.fail()){
		cout<<"Texto entrada Peliculas.txt no existe"<<endl;
	}
	else{
		while(!datos.eof()){
			getline(datos,cadena);
			if(cadena == "-"){
				cout<<endl;
			}
			else if(cadena == "_"){
				cout<<"___________________"<<endl;
			}
			else{
				cout<<cadena;
			}
		}
	}
}

void Pelicula::Buscar(){
	string cadena,titulo,temporal;
	bool find = false;
	int cont = 0, contador = 0;
	cout << endl;
	cout<<"Coloca El titulo de la Pelicula:"<<endl;
	cin.ignore();
	getline(cin,titulo);
	fstream datos("Peliculas.txt");

	if(datos.fail()){
		cout<<"Texto entrada Peliculas.txt no existe"<<endl;
	}
	else{
		while(!datos.eof()){
			getline(datos,cadena);

			if(cadena != "-" && cadena != "_" && find == false){
				temporal=temporal+cadena;
			}
			if(temporal == titulo && find == false && (contador%9==0 || contador == 0)){
				cout<<endl<<"Pelicula Encontrada!"<<endl<<endl;
				find = true;
			}
			else{
				temporal = "";
			}
			if(find == true){
				if(cadena == "-"){
					cout<<endl;
				}
				else if(cadena != "_"){
					cout<<cadena;
				}
				else{
					break;
				}
			}
			contador++;
		}
		cout << endl;
		datos.close();
	}
	if(find == false){
		cout<<endl<<"Pelicula No Encontrada!"<<endl<<endl;
	}
}

void Pelicula::Modificar(){
	string cadena,titulo,temporal, nuevo;
	bool find = false;
	int cont = 0, opc, contador = 0;
	cout<<endl<<"Coloca El titulo de la Pelicula:"<<endl;
	cin.ignore();
	getline(cin,titulo);
	fstream datos("Peliculas.txt");

	if(datos.fail()){
		cout<<"Texto entrada Peliculas.txt no existe"<<endl;
	}
	else{
		while(!datos.eof()){
			getline(datos,cadena);

			if(cadena != "-" && cadena != "_" && find == false){
				temporal=temporal+cadena;
			}
			if(temporal == titulo && find == false && (contador%9==0 || contador == 0)){
				cout<<endl<<"Pelicula Encontrada!"<<endl<<endl;
				find = true;
			}
			else{
				temporal = "";
			}
			if(find == true){
				if(cadena == "-"){
					cout<<endl;
				}
				else if(cadena != "_"){
					cout<<cadena;
				}
				else{
					break;
				}
			}
			contador++;
		}
		datos.close();
	}
	if(find == true){
		contador = 0, cont  = 0;
		ifstream datos("Peliculas.txt");
		ofstream Cache("Cache.txt");
		cout << endl;
		cout<<"Que desea Modificar?"<<endl;
		cout<<"1. Nombre"<<endl;
		cout<<"2. Categoria"<<endl;
		cout<<"3. Duracion"<<endl;
		cout<<"4. Anio"<<endl<<endl;
		cin>>opc;
		cout<<endl<<"Introduzca el Nuevo Dato:"<<endl;
		cin.ignore();
		getline(cin, nuevo);
		switch(opc){
			case 1:{
				find = false;
				while(!datos.eof()){
					getline(datos,cadena);
					if(cadena != "-" && cadena != "_" && find == false){
						temporal=temporal+cadena;
					}
					if(temporal == titulo && find == false && (contador%9==0 || contador == 0)){
						Cache<<nuevo<<endl;
						cout<<endl<<"Dato Renombrado Con Exito!"<<endl;
						find = true;
					}
					else{
						temporal = "";
					}
					if(temporal != titulo){
						Cache<<cadena<<endl;
					}
					contador++;
				}

				datos.close();
				Cache.close();
				remove("Peliculas.txt");
				rename("Cache.txt", "Peliculas.txt");

				cout<<"Reescritura Exitosa!"<<endl<<endl;
				break;
			}
			case 2:{
				find = false;
				while(!datos.eof()){
					getline(datos,cadena);
					if(cadena != "-" && cadena != "_" && find == false){
						temporal=temporal+cadena;
					}
					if(temporal == titulo && find == false && (contador%9 == 0 || contador == 0)){
						cout<<endl<<"Dato Renombrado Con Exito!"<<endl;
						find = true;
					}
					else{
						temporal = "";
					}
					if(find == true){
						cont++;
						if(cont == 3){
							Cache<<nuevo<<endl;
						}
					}
					if(cont != 3){
						Cache<<cadena<<endl;
					}
					contador++;
				}

				datos.close();
				Cache.close();
				remove("Peliculas.txt");
				rename("Cache.txt", "Peliculas.txt");

				cout<<"Reescritura Exitosa!"<<endl<<endl;
				break;
			}
			case 3:{
				find = false;
				while(!datos.eof()){
					getline(datos,cadena);
					if(cadena != "-" && cadena != "_" && find == false){
						temporal=temporal+cadena;
					}
					if(temporal == titulo && find == false && (contador%9 == 0 || contador == 0)){
						cout<<endl<<"Dato Renombrado Con Exito!"<<endl;
						find = true;
					}
					else{
						temporal = "";
					}
					if(find == true){
						cont++;
						if(cont == 5){
							Cache<<nuevo<<endl;
						}
					}
					if(cont != 5){
						Cache<<cadena<<endl;
					}
					contador++;
				}

				datos.close();
				Cache.close();
				remove("Peliculas.txt");
				rename("Cache.txt", "Peliculas.txt");

				cout<<"Reescritura Exitosa!"<<endl<<endl;
				break;
			}
			case 4:{
				find = false;
				while(!datos.eof()){
					getline(datos,cadena);
					if(cadena != "-" && cadena != "_" && find == false){
						temporal=temporal+cadena;
					}
					if(temporal == titulo && find == false && (contador%9 == 0 || contador == 0)){
						cout<<endl<<"Dato Renombrado Con Exito!"<<endl;
						find = true;
					}
					else{
						temporal = "";
					}
					if(find == true){
						cont++;
						if(cont == 7){
							Cache<<nuevo<<endl;
						}
					}
					if(cont != 7){
						Cache<<cadena<<endl;
					}
					contador++;
				}

				datos.close();
				Cache.close();
				remove("Peliculas.txt");
				rename("Cache.txt", "Peliculas.txt");

				cout<<"Reescritura Exitosa!"<<endl<<endl;
				break;
			}
	}
}
	else{
		cout<<endl<<"Pelicula No Encontrada!"<<endl<<endl;
	}
}

void Pelicula::Eliminar(){
	string nuevo, cadena, temporal, titulo;
	bool find = false, pass = false;
	int contador = 0,cont = 0;
	ifstream datos("Peliculas.txt");
	ofstream Cache("Cache.txt");

	cout<<endl<<"Introduzca el Titulo a Eliminar:"<<endl;
	cin.ignore();
	getline(cin, titulo);
	find = false;
	while(!datos.eof())
        {
		getline(datos,cadena);
		if(cadena != "-" && cadena != "_" && find == false){
			temporal=temporal+cadena;
		}
		if(temporal == titulo && find == false && (contador%9==0 || contador == 0)){
			cout<<endl<<"Dato Eliminado Con Exito!"<<endl;
			find = true;
			pass = true;
		}
		else{
			temporal = "";
		}
		if(temporal != titulo && pass == false && cadena != ""){
			Cache<<cadena<<endl;
		}
		if(pass == true){
			cont++;
			if(cont == 9){
				pass = false;
			}
		}
		contador++;
	}
	if(find == true){
		datos.close();
		Cache.close();
		remove("Peliculas.txt");
		rename("Cache.txt", "Peliculas.txt");

		cout<<"Reescritura Exitosa!"<<endl<<endl;
	}
	else{
		cout<<endl<<"Titulo No Encontrado!"<<endl<<endl;
	}
}
