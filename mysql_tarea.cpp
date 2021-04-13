// mysql_tarea.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <mysql.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int main() {
	int empresa;
	struct db_empres {
		char marcas[70];
		char productos[70];
	};

	void INGRESAR();
	void ABRIR();
	void MODIFICAR();
	void ELIMINAR();
	void BUSCAR();

	ABRIR();
	int mn;
	cout << "\n						Menu para gestionar " << endl;
	cout << "\n1. Ingresar  Nuevo" << endl;
	cout << "2. Modificar " << endl;
	cout << "3. Eliminar " << endl;
	cout << "4. Buscar " << endl;
	cout << "\n\n Opcion: ";
	cin >> mn;
	switch (mn) {
	case 1:
		INGRESAR();
		break;

	case 2:
		MODIFICAR();
		break;

	case 3:
		ELIMINAR();
		break;
	case 4:
		BUSCAR();
		break;
	}
	return 0;
	void INGRESAR() {

		char continuar;
		FILE* archivo = fopen(db_empres, "ab"); // ab

		string idmarca, marca;
		do {
			fflush(stdin);

			cout << "Ingrese el Codigo: ";
			cin >> idmarca.db_empres;
			cin.ignore();

			cout << "Ingrese la marca: ";
			getline(cin, marca);
			strcpy(empresa.marca, marca.c_str());



		}
		void BUSCAR() {
			FILE* archivo = fopen(db_empres, "rb");

			string idmarca, marca;
			int pos = 0;
			cout << "Ingrese el codigo que desa ver:  ";
			cin >> pos;
			cout << "------------------ " << pos << " ------------------" << endl;
			fseek(empres, pos * sizeof(empresa), SEEK_SET);

			db_empres;

			fread(&empresa, sizeof(empresa), 1, archivo);

			cout << "id marca: " << idmarca << endl;
			cout << "marca: " << marca << endl;
			cout << endl;

			fclose(archivo);
		}

		MYSQL* conectar;
		conectar = mysql_init(0);
		conectar = mysql_real_connect(conectar, "localhost", "root", "habacuc316", "db_empres", 3306, NULL, 0);


		system("PAUSE");

	}
}
