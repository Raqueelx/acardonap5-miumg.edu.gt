#pragma once
#include <mysql.h> 
#include <iostream>
#include <string>
#include "ConexionBD.h"
#include "Persona.h"

using namespace std;
class Cliente : Persona{
	//atributos
private: string nit;

	   //constructor
public:
	Cliente() {

	}
	Cliente(string nom, string ape, string dir, int tel, string fn, string n) : Persona(nom, ape, dir, tel, fn) {
		nit = n;
	}
	//metodos 
	//set (modificar)
	void setNit(string n) { nit = n; }
	void setNombres(string nom) { nombres = nom; }
	void setApellidos(string ape) { apellidos = ape; }
	void setDireccion(string dir) { direccion = dir; }
	void setTelefono(int tel) { telefono = tel; }
	//get (mostrar)
	string getNit() { return nit; }
	string getNombres() { return nombres; }
	string getApellidos() { return apellidos; }
	string getDireccion() { return direccion; }
	int getTelefono() { return telefono; }

	// metodo
	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string t = to_string(telefono);
			string insert = "INSERT INTO clientes(nit, nombres, apellidos, direcion, telefono, fecha_nacimientoo)VALUES('"+nit+"','" + nombres + "','" + apellidos + "','" + direccion + "'," + t + ",'" + fecha_nacimiento + "');";
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "ingreso exitoso" << endl;

			}
			else {
				cout << "xxx error en la conexion xxx" << endl;
			}
		} else {
			cout << " Error de Ingreso ... " << endl;
		}
		cn.cerrar_conexion();
	}
	void buscar() {

	}
	void eliminar() {

	}
	void leer () {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = " select * from Cliente ";
			const  char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());

				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5] << "," << fila[6] << endl;

				}

			}
			else {
				cout << "----ERROR AL INGRESAR LA INFORMACION----" << endl;
			}
		}
		else {
			cout << " Error de Ingreso ... " << endl;
		}
		cn.cerrar_conexion();
	}
};

