// mysql_poo.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Cliente.h"
using namespace std;
int main(){

	string nit, nombres, apellidos, direccion, fecha_nacimiento;
	int telefono;
	cout << "ingrese Nit: ";
	getline(cin, nit);
	cout << "ingrese Nombres: ";
	getline(cin, nombres);
	cout << "ingrese apellidos: ";
	getline(cin, apellidos);
	cout << "ingrese direccion: ";
	getline(cin, direccion);
	cout << "ingrese telefono: ";
	cin >> telefono;
	cin.ignore();
	cout << "ingrese fecha nacimiento: ";
	cin >> fecha_nacimiento;

	
	Cliente c = Cliente (nombres, apellidos, direccion, telefono, fecha_nacimiento, nit);
	c.crear();
	c.leer();

		system("pause");
		return 0;
	}
    

