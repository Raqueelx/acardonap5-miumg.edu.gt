// mysql_tarea.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include<mysql.h>
#include <iostream>
using namespace std;
int q_estado;
int resultado, fila;
int main()
{
	MYSQL* conectar;
	conectar = mysql_init(0);
	conectar = mysql_real_connect(conectar, "localhost", "usr_empre", "empres@123", "db_empre", 3306, NULL, 0);

	if (conectar) {
		string puestoss;
		cout << "ingrese puesto: ";
		cin >> puestoss;
		string insert = "insert into puestoss(puesto) values ('" + puestoss + "')";
		const char* i = insert.c_str();
		q_estado = mysql_query (conectar, i);
		if (!q_estado) {
			cout << "ingreso exitoso" << endl;
		
	}
	else {
		cout << "xxx error en la conexion xxx" << endl;
	}
		string consulta = " seleccionar * de puesto ";
		const  char* c = consulta.c_str();
		q_estado = mysql_query(conectar, c);
		if (!q_estado) {
			resultado = mysql_store_result(conectar);
			while (fila = mysql_fetch_row(resultado)) {
				cout << fila[0] << " , " << fila[1] << endl;

			}

		}
		else {
			cout << " Error de Ingreso ... " << endl;
		}
	system("pause");
	return 0;
}
}

