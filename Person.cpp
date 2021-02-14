#include <iostream>
using namespace std;
class Person{
	//ATRIBUTOS
	protected : string nombres, apellidos, direccion;
	int telefono;
	
	//constructor
	protected :
		Person(){
		}
		Person (string nom, string ape, string dir, int tel ) {
			nombres = nom;
			apellidos = ape;
			direccion=dir;
			telefono=tel;
			
		}
	//METODO//
	void mostrar();
};
