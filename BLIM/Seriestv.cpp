#include "Seriestv.h"

void Seriestv::Agregar()
{
    cout << endl;
    cin.ignore();
	cout<<"Nombre: ";
	getline(cin, nombre);
	string Nombre = nombre.substr(0,35);

	cout << endl;
	cout<<"Categoria: ";
	getline(cin, categoria);
	string Categoria = categoria.substr(0,35);

	cout << endl;
	cout<<"Duracion en minutos(Ej. 40 min): ";
	getline(cin, duracion);
	string Duracion = duracion.substr(0,15);

	cout << endl;
	cout<<"Temporadas: ";
    cin >> Temporadas;

	cout << endl;
	cout<<"Episodios: ";
    cin >> Episodios;

	cout << endl;
	cout<<"Anio de estreno: ";
	cin.ignore();
	getline(cin, anio);
	string Anio = anio.substr(0,5);

	cout << endl;
	string Archivo = "Series.txt";
	ofstream Series;

	Series.open(Archivo.c_str(), fstream::app);
	Series <<Nombre<<endl<<"-"<<endl;
	Series <<Categoria<<endl<<"-"<<endl;
	Series <<Duracion<<endl<<"-"<<endl;
	Series <<Temporadas<<endl<<"-"<<endl;
	Series <<Episodios<<endl<<"-"<<endl;
	Series <<Anio<<endl<<"-"<<endl;
	Series <<"_"<<endl;
	Series.close();
}

void Seriestv::Imprimir()
{
	string cadena;
	fstream datos("Series.txt");

	if(datos.fail()){
		cout<<"Texto entrada Series.txt no existe"<<endl;
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

void Seriestv::Buscar()
{
	string cadena,titulo,temporal;
	bool find = false;
	int contador = 0;
	cout << endl;
	cout<<"Coloca El titulo de la Serie:"<<endl;
	cin.ignore();
	getline(cin,titulo);
	fstream datos("Series.txt");

	if(datos.fail()){
		cout<<"Texto entrada Series.txt no existe"<<endl;
	}
	else{
		while(!datos.eof()){
			getline(datos,cadena);

			if(cadena != "-" && cadena != "_" && find == false){
				temporal=temporal+cadena;
			}
			if(temporal == titulo && find == false && (contador%13==0 || contador == 0)){
				cout<<endl<<"Serie Encontrada!"<<endl<<endl;
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
		cout<<endl<<"Serie No Encontrada!"<<endl<<endl;
	}
}

void Seriestv::Modificar()
{
	string cadena,titulo,temporal, nuevo;
	bool find = false;
	int cont = 0, opc, contador = 0;
	cout<<endl<<"Coloca El titulo de la Serie:"<<endl;
	cin.ignore();
	getline(cin,titulo);
	fstream datos("Series.txt");

	if(datos.fail()){
		cout<<"Texto entrada Series.txt no existe"<<endl;
	}
	else{
		while(!datos.eof()){
			getline(datos,cadena);

			if(cadena != "-" && cadena != "_" && find == false){
				temporal=temporal+cadena;
			}
			if(temporal == titulo && find == false && (contador%13==0 || contador == 0)){
				cout<<endl<<"Serie Encontrada!"<<endl<<endl;
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
	if(find == true)
    {
		contador = 0, cont  = 0;
		ifstream datos("Series.txt");
		ofstream Cache("Cache.txt");
		cout << endl;
		cout<<"+--------------------------------+"<<endl;
		cout<<"|      Que desea Modificar?      |"<<endl;
		cout<<"|                                |"<<endl;
		cout<<"|   [1] Nombre                   |"<<endl;
		cout<<"|   [2] Categoria                |"<<endl;
		cout<<"|   [3] Duracion                 |"<<endl;
		cout<<"|   [4] Temporadas               |"<<endl;
		cout<<"|   [5] Episodios                |"<<endl;
		cout<<"|   [6] Anio                     |"<<endl;
		cout<<"|                                |"<<endl;
		cout<<"+--------------------------------+"<<endl<<endl;
		cin>>opc;
		cout<<endl<<"Introduzca el Nuevo Dato:"<<endl;
		cin.ignore();
		getline(cin, nuevo);
		switch(opc)
		{
			case 1:{
				find = false;
				while(!datos.eof()){
					getline(datos,cadena);
					if(cadena != "-" && cadena != "_" && find == false){
						temporal=temporal+cadena;
					}
					if(temporal == titulo && find == false && (contador%13==0 || contador == 0)){
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
				remove("Series.txt");
				rename("Cache.txt", "Series.txt");

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
					if(temporal == titulo && find == false && (contador%13 == 0 || contador == 0)){
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
				remove("Series.txt");
				rename("Cache.txt", "Series.txt");

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
					if(temporal == titulo && find == false && (contador%13 == 0 || contador == 0)){
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
				remove("Series.txt");
				rename("Cache.txt", "Series.txt");

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
					if(temporal == titulo && find == false && (contador%13 == 0 || contador == 0)){
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
				remove("Series.txt");
				rename("Cache.txt", "Series.txt");

				cout<<"Reescritura Exitosa!"<<endl<<endl;
				break;
			}
			case 5:{
				find = false;
				while(!datos.eof()){
					getline(datos,cadena);
					if(cadena != "-" && cadena != "_" && find == false){
						temporal=temporal+cadena;
					}
					if(temporal == titulo && find == false && (contador%13 == 0 || contador == 0)){
						cout<<endl<<"Dato Renombrado Con Exito!"<<endl;
						find = true;
					}
					else{
						temporal = "";
					}
					if(find == true){
						cont++;
						if(cont == 9){
							Cache<<nuevo<<endl;
						}
					}
					if(cont != 9){
						Cache<<cadena<<endl;
					}
					contador++;
				}

				datos.close();
				Cache.close();
				remove("Series.txt");
				rename("Cache.txt", "Series.txt");

				cout<<"Reescritura Exitosa!"<<endl<<endl;
				break;
			}
			case 6:{
				find = false;
				while(!datos.eof()){
					getline(datos,cadena);
					if(cadena != "-" && cadena != "_" && find == false){
						temporal=temporal+cadena;
					}
					if(temporal == titulo && find == false && (contador%13 == 0 || contador == 0)){
						cout<<endl<<"Dato Renombrado Con Exito!"<<endl;
						find = true;
					}
					else{
						temporal = "";
					}
					if(find == true){
						cont++;
						if(cont == 11){
							Cache<<nuevo<<endl;
						}
					}
					if(cont != 11){
						Cache<<cadena<<endl;
					}
					contador++;
				}

				datos.close();
				Cache.close();
				remove("Series.txt");
				rename("Cache.txt", "Series.txt");

				cout<<"Reescritura Exitosa!"<<endl<<endl;
				break;
			}
        }
    }
	else{
		cout<<endl<<"Pelicula No Encontrada!"<<endl<<endl;
	}
}

void Seriestv::Eliminar()
{
	string nuevo, cadena, temporal, titulo;
	bool find = false, pass = false;
	int contador = 0,cont = 0;
	ifstream datos("Series.txt");
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
		if(temporal == titulo && find == false && (contador%13==0 || contador == 0)){
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
			if(cont == 13){
				pass = false;
			}
		}
		contador++;
	}
	if(find == true){
		datos.close();
		Cache.close();
		remove("Series.txt");
		rename("Cache.txt", "Series.txt");

		cout<<"Reescritura Exitosa!"<<endl<<endl;
	}
	else{
		cout<<endl<<"Titulo No Encontrado!"<<endl<<endl;
	}
}
