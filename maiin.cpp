#include "Client.cpp"
#include<iostream>
using namespace std;

main (){
	string nit, nombres, apellidos, direccion;
	int telefono;
	
	cout<<"INGRESAR NIT: ";
	cin>>nit;
	cout<<"INGRESAR NOMBRES: ";
	cin>>nombres;
	cout<<"INGRESAR apellidos";
	cin>>apellidos;
	cout<<"INGRESAR DIRECCION: ";
	cin>>direccion;
	cout<<"INGRESAR Telefono: ";
	cin>>telefono;
	
	//instancia de un objeto
	Client obj = Client(nombres, apellidos, direccion, telefono, nit);
	cout<<"DATOS DL CLIENTE" <<endl;
	obj.getNit();
	obj.getNombres();
	obj.getApellidos();
	obj.getDireccion();
	obj.getTelefono();
	obj.mostrar();
	
	/*Client obj = Client();
	obj.setNit(nit);
	obj.setNombres(nombres);
	obj.setApellidos(apellidos);
	obj.setDireccion(direccion);
	obj.setTelefono(telefono);
	obj.mostrar();*/
} 


