#include <iostream>
using namespace std;
class Perso{
	//ATRIBUTOS
	protected : string nombres, apellidos, puesto;
	int sueldo;
	
	//constructor
	protected :
		Perso(){
		}
		Perso (string nom, string ape, string pu, int suel ) {
			nombres = nom;
			apellidos = ape;
			puesto=pu;
			sueldo=suel; 
			
		}
	//METODO//
	void mostrar();
};
