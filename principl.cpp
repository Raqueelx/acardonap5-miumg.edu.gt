#include "Empleado.cpp"
#include<iostream>
using namespace std;

main (){
	string codigo, nombres, apellidos, puesto;
	int sueldo;
	
	cout<<"---------BIENVENIDO-----------"<<endl;
	cout<<""<<endl;
	cout<<"INGRESAR CODIGO: ";
	cin>>codigo;
	cout<<"INGRESAR NOMBRES: ";
	cin>>nombres;
	cout<<"INGRESAR APELLIDOS: ";
	cin>>apellidos;
	cout<<"INGRESAR PUESTO: ";
	cin>>puesto;
	cout<<"INGRESAR SUELDO: ";
	cin>>sueldo;
	
	//instancia de un objeto
	Empleado obj = Empleado (nombres, apellidos, puesto, sueldo, codigo);
	cout<<"DATOS INGRESADOS DEL EMPLEADO" <<endl;
	obj.getCodigo();
	obj.getNombres();
	obj.getApellidos();
	obj.getPuesto();
	obj.getSueldo();
	obj.mostrar();
	}
