#include "Perso.cpp"
#include <iostream>
using namespace std;

class Empleado : Perso {
	//ATRIBUTOS
	private : string codigo;
	
	//constructor 
	public : 
	Empleado (){
	}
	
	Empleado(string nom, string ape, string pu, int suel, string cod) : Perso (nom, ape, pu, suel){
		codigo=cod;
	}
	//metodos
	//set (modificar)
	void setCodigo(string cod){	codigo = cod;}
	void setNombres(string nom){nombres = nom;}
	void setApellidos(string ape){apellidos = ape;}
	void setPuesto(string puesto){puesto = puesto;}
	void setSueldo(int suel){sueldo = suel;}
	//get (mostrar)
	string getCodigo (){return codigo;}
	string getNombres (){return nombres;}
	string getApellidos () {return apellidos;	}
	string getPuesto () {return puesto; }
	int getSueldo() {return sueldo;	}
	
	void mostrar(){
		cout <<"__________________________"<<endl;
		cout<<codigo<<","<<nombres<<","<<apellidos<<","<<puesto<<","<<sueldo<<","<<endl;
	}
};

