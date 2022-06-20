#include "Usuarios.h"

Usuarios::Usuarios()
{
}

void Usuarios::Agregar()
{
    string SubUsuarios[3];
    cout << endl;
    cin.ignore();
	cout<<"Nombre: "<<endl;
	getline(cin, nombre);
	string Nombre = nombre.substr(0,35);

    cout << endl;
	cout<<"Edad: "<<endl;
	cin>>edad[0];

	cout << endl;
	cin.ignore();
	cout<<"Contrasena: "<<endl;
	getline(cin, contrasena);
	string Contrasena = contrasena.substr(0,35);

	int sub = 0;
    cout << endl;
	cout<<"Defina la cantidad de Sub Usuarios -. Limite 3: ";
	cin>>sub;

	if(sub > 0){
            if(sub > 3){
                sub = 3;
            }

            int cont = 0;
        do{
            cout << endl;
            cin.ignore();
            cout<<"Nombre sub Usuario "<< cont + 1<< ":"<<endl;
            getline(cin, subUsuarios[cont]);
            SubUsuarios[cont] = subUsuarios[cont].substr(0,35);

            cout << endl;
            cout<<"Edad sub Usuario "<< cont + 1 <<":"<<endl;
            cin>>edad[cont+1];

            cont++;
        }while(cont < sub);
	}
	else{
        cout<<"0 Sub-usuarios Creados"<<endl;
	}

	int cont = 0;

	cout << endl;
	string Archivo = "Usuario.txt";
	ofstream  Usuario;

    Usuario.open(Archivo.c_str(), fstream::app);
    Usuario <<Nombre<<endl<<"-"<<endl;
    Usuario <<Contrasena<<endl<<"-"<<endl;
    Usuario <<edad[0]<<endl<<"-"<<endl;

	do{
        if(cont < sub){
            Usuario <<subUsuarios[cont]<<endl<<"-"<<endl;
            Usuario <<edad[cont + 1]<<endl<<"-"<<endl;
        }
        else{
            string vacio = "Empty";
             Usuario <<vacio<<endl<<"-"<<endl;
             Usuario <<0<<endl<<"-"<<endl;
        }
        cont++;
	}while(cont < 3);

	Usuario <<"_"<<endl;
	Usuario.close();
}

void Usuarios::Imprimir()
{
	string cadena;
	fstream datos("Usuario.txt");

	if(datos.fail()){
		cout<<"Texto entrada Usuario.txt no existe"<<endl;
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

void Usuarios::Buscar()
{
	string cadena,titulo,temporal;
	bool find = false;
	int contador = 0;
	cout << endl;
	cout<<"Coloca El Usuario a Buscar:"<<endl;
	cin.ignore();
	getline(cin,titulo);
	fstream datos("Usuario.txt");

	if(datos.fail()){
		cout<<"Texto entrada Usuarios.txt no existe"<<endl;
	}
	else{
		while(!datos.eof()){
			getline(datos,cadena);

			if(cadena != "-" && cadena != "_" && find == false){
				temporal=temporal+cadena;
			}
			if(temporal == titulo && find == false && (contador%19==0 || contador == 0)){
				cout<<endl<<"Usuario Encontrado!"<<endl<<endl;
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
		cout<<endl<<"Usuario No Encontrado!"<<endl<<endl;
	}
}

void Usuarios::Modificar()
{
	string cadena,titulo,temporal, nuevo;
	bool find = false;
	int cont = 0, opc, contador = 0;
	cout<<endl<<"Coloca El Nombre del Usuario:"<<endl;
	cin.ignore();
	getline(cin,titulo);
	fstream datos("Usuario.txt");

	if(datos.fail()){
		cout<<"Texto entrada Usuario.txt no existe"<<endl;
	}
	else{
		while(!datos.eof()){
			getline(datos,cadena);

			if(cadena != "-" && cadena != "_" && find == false){
				temporal=temporal+cadena;
			}
			if(temporal == titulo && find == false && (contador%19==0 || contador == 0)){
				cout<<endl<<"Usuario Encontrado!"<<endl<<endl;
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
		ifstream datos("Usuario.txt");
		ofstream Cache("Cache.txt");
		cout << endl;
		cout<<"+--------------------------------+"<<endl;
		cout<<"|      Que desea Modificar?      |"<<endl;
		cout<<"|                                |"<<endl;
		cout<<"|   [1] Nombre                   |"<<endl;
		cout<<"|   [2] Edad  de Usuario         |"<<endl;
		cout<<"|   [3] Contrasena               |"<<endl;
		cout<<"|   [4] Nombre de subUsuario1    |"<<endl;
		cout<<"|   [5] Edad  de subUsuario1     |"<<endl;
		cout<<"|   [6] Nombre de subUsuario2    |"<<endl;
		cout<<"|   [7] Edad  de subUsuario2     |"<<endl;
		cout<<"|   [8] Nombre de subUsuario3    |"<<endl;
		cout<<"|   [9] Edad  de subUsuario3     |"<<endl;
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
					if(temporal == titulo && find == false && (contador%19==0 || contador == 0)){
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
				remove("Usuario.txt");
				rename("Cache.txt", "Usuario.txt");

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
					if(temporal == titulo && find == false && (contador%19 == 0 || contador == 0)){
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
				remove("Usuario.txt");
				rename("Cache.txt", "Usuario.txt");

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
					if(temporal == titulo && find == false && (contador%19 == 0 || contador == 0)){
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
				remove("Usuario.txt");
				rename("Cache.txt", "Usuario.txt");

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
					if(temporal == titulo && find == false && (contador%19 == 0 || contador == 0)){
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
				remove("Usuario.txt");
				rename("Cache.txt", "Usuario.txt");

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
					if(temporal == titulo && find == false && (contador%19 == 0 || contador == 0)){
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
				remove("Usuario.txt");
				rename("Cache.txt", "Usuario.txt");

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
					if(temporal == titulo && find == false && (contador%19 == 0 || contador == 0)){
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
				remove("Usuario.txt");
				rename("Cache.txt", "Usuario.txt");

				cout<<"Reescritura Exitosa!"<<endl<<endl;
				break;
			}
			case 7:{
				find = false;
				while(!datos.eof()){
					getline(datos,cadena);
					if(cadena != "-" && cadena != "_" && find == false){
						temporal=temporal+cadena;
					}
					if(temporal == titulo && find == false && (contador%19 == 0 || contador == 0)){
						cout<<endl<<"Dato Renombrado Con Exito!"<<endl;
						find = true;
					}
					else{
						temporal = "";
					}
					if(find == true){
						cont++;
						if(cont == 13){
							Cache<<nuevo<<endl;
						}
					}
					if(cont != 13){
						Cache<<cadena<<endl;
					}
					contador++;
				}

				datos.close();
				Cache.close();
				remove("Usuario.txt");
				rename("Cache.txt", "Usuario.txt");

				cout<<"Reescritura Exitosa!"<<endl<<endl;
				break;
			}
			case 8:{
				find = false;
				while(!datos.eof()){
					getline(datos,cadena);
					if(cadena != "-" && cadena != "_" && find == false){
						temporal=temporal+cadena;
					}
					if(temporal == titulo && find == false && (contador%19 == 0 || contador == 0)){
						cout<<endl<<"Dato Renombrado Con Exito!"<<endl;
						find = true;
					}
					else{
						temporal = "";
					}
					if(find == true){
						cont++;
						if(cont == 15){
							Cache<<nuevo<<endl;
						}
					}
					if(cont != 15){
						Cache<<cadena<<endl;
					}
					contador++;
				}

				datos.close();
				Cache.close();
				remove("Usuario.txt");
				rename("Cache.txt", "Usuario.txt");

				cout<<"Reescritura Exitosa!"<<endl<<endl;
				break;
			}
			case 9:{
				find = false;
				while(!datos.eof()){
					getline(datos,cadena);
					if(cadena != "-" && cadena != "_" && find == false){
						temporal=temporal+cadena;
					}
					if(temporal == titulo && find == false && (contador%19 == 0 || contador == 0)){
						cout<<endl<<"Dato Renombrado Con Exito!"<<endl;
						find = true;
					}
					else{
						temporal = "";
					}
					if(find == true){
						cont++;
						if(cont == 17){
							Cache<<nuevo<<endl;
						}
					}
					if(cont != 17){
						Cache<<cadena<<endl;
					}
					contador++;
				}

				datos.close();
				Cache.close();
				remove("Usuario.txt");
				rename("Cache.txt", "Usuario.txt");

				cout<<"Reescritura Exitosa!"<<endl<<endl;
				break;
			}
        }
    }
	else{
		cout<<endl<<"Usuario No Encontrado!"<<endl<<endl;
	}
}

void Usuarios::Eliminar()
{
	string nuevo, cadena, temporal, titulo;
	bool find = false, pass = false;
	int contador = 0,cont = 0;
	ifstream datos("Usuario.txt");
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
		if(temporal == titulo && find == false && (contador%19==0 || contador == 0)){
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
			if(cont == 19){
				pass = false;
			}
		}
		contador++;
	}
	if(find == true){
		datos.close();
		Cache.close();
		remove("Usuario.txt");
		rename("Cache.txt", "Usuario.txt");

		cout<<"Reescritura Exitosa!"<<endl<<endl;
	}
	else{
		cout<<endl<<"Usuario No Encontrado!"<<endl<<endl;
	}
}
