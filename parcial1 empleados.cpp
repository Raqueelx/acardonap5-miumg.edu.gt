#include <iostream>
#include <stdio.h>  
#include <string.h> 


using namespace std;
const char *archivo_empleados = "registros.dat";

struct Empleado{
	int Codigo_Empleado;
	char Nombres[50];
	char Apellidos[50];
	char Puesto[50];
	int Sueldo_base;
	int Bonificacion;
	int Sueldo_Total;
};

void Ingresar_Empleado();
void Abrir_Empleado();
void Modificar_Empleado();
void Eliminar_Empleado();
void buscar_codigo();

//declarmos el menu con los datos
int main (){
	Abrir_Empleado();
	int mn;
	cout<<"----------------HOLA BIENVENIDO-------------------------"<<endl;
	cout<<" "<<endl;
	cout<<"\n		Menu para gestionar empleados"<<endl;
	cout<<""<<endl;
	cout<<"\n1. Ingrese Empleado Nuevo"<<endl;
	cout<<"2. Modificar Empleado"<<endl;
	cout<<"3. Eliminar Empleado"<<endl;
	cout<<"4. Buscar empleado"<<endl;
	cout<<"\n\n Opcion: ";
	cin>>mn;
	switch(mn){
		
		case 1 :
			Ingresar_Empleado();
		break;
		
		case 2 :
			Modificar_Empleado();
		break;
		
		case 3 :
			Eliminar_Empleado();
		break;
		case 4 :
			buscar_codigo();
		break;
	}	
	return 0;	
}

//BUSCANDO DATOS DEL EMPLEADO
void buscar_codigo(){
	
	FILE* archivo = fopen(archivo_empleados, "rb");
	
	int indice=0,pos=0,cod=0;
	cout<<"BUSCAR EL CODIGO: ";
	cin>>cod;
	Empleado empleado;
	
	fread ( &empleado, sizeof(Empleado), 1, archivo );
		
		do{
			
			if (empleado.Codigo_Empleado == cod){
			pos = indice;
			}
	
		fread ( &empleado, sizeof(Empleado), 1, archivo );
		indice += 1;
		} while (feof( archivo ) == 0);
		
	cout<<"------------------ "<<pos<<" ------------------"<<endl;
	fseek ( archivo,pos * sizeof(Empleado), SEEK_SET );

    fread ( &empleado, sizeof( Empleado ), 1, archivo );

    	cout<<"CODIGO: "<<empleado.Codigo_Empleado<<endl;
        cout<<"NOMBRE: "<<empleado.Nombres<<endl;
        cout<<"APELLIDO: "<<empleado.Apellidos<<endl;
        cout<<"PUESTO: "<<empleado.Puesto<<endl;
        cout<<"SUELDO BASE: "<<empleado.Sueldo_base<<endl;
        cout<<"BONIFICACION: "<<empleado.Bonificacion<<endl;
        cout<<"SUELDO TOTAL: "<<empleado.Sueldo_Total<<endl;
        cout << endl;
	
	fclose(archivo);
	system("PAUSE");
}

void buscar_indice(){
	FILE* archivo = fopen(archivo_empleados, "rb");
	
	int pos=0;
	cout<<"Ingrese el codigo del empleado que desea ver: ";
	cout<<""<<endl;
	cin>>pos;
	cout<<"------------------ "<<pos<<" ------------------"<<endl;
	fseek ( archivo,pos * sizeof(Empleado), SEEK_SET );
	
	Empleado empleado;
	
    fread ( &empleado, sizeof( Empleado ), 1, archivo );

    	cout<<"Codigo: "<<empleado.Codigo_Empleado<<endl;
        cout<<"Nombre: " <<empleado.Nombres<<endl;
        cout<<"Apellido: "<<empleado.Apellidos<<endl;
        cout<<"Puesto: " <<empleado.Puesto<<endl;
        cout<<"Sueldo base: "<<empleado.Sueldo_base<<endl;
        cout<<"Bonificacion: "<<empleado.Bonificacion<<endl;
        cout<<"Sueldo Total: "<<empleado.Sueldo_Total<<endl;
        cout << endl;
	
	fclose(archivo);
}
void Abrir_Empleado(){

	system("cls");
	FILE* archivo = fopen(archivo_empleados, "rb");
	if(!archivo) {
		archivo = fopen(archivo_empleados, "w+b");
	}
	Empleado empleado;
	int registro=0;
	fread ( &empleado, sizeof(Empleado), 1, archivo );
	cout<<"							PORTAL EMPLEADOS"<<endl;
	cout<<"____________________________________________________________________________________________________________"<<endl;
	cout << "id" <<" | "<< "CODIGO" <<" | "<< "NOMBRES"<<"        "<<"APELLIDOS"<<"  |  "<<"PUESTO"<<"  | "<<"SUELDO BASE (Q)"<<" | "<<"BONIFICACION (Q)"<<" | "<<"SUELDO TOTAL (Q)"<<endl;	
		do{
		cout<<"____________________________________________________________________________________________________________"<<endl;
		cout<<registro<<" | "<<empleado.Codigo_Empleado<<" | "<<empleado.Nombres<<" "<<empleado.Apellidos<<" | "<<empleado.Puesto<<" | "<<"Q"<<empleado.Sueldo_base<<" | "<<"Q"<<empleado.Bonificacion<<" | "<<"Q"<<empleado.Sueldo_Total<<endl;
        
		fread ( &empleado, sizeof(Empleado), 1, archivo );
		registro += 1;	
		} while (feof( archivo ) == 0);
		
    cout<<endl;
    
		fclose(archivo);
	}
	
	//INGRESAMOS UN NUEVA REGISTRO
void Ingresar_Empleado(){
	
	char continuar;
	FILE* archivo = fopen(archivo_empleados, "ab"); // ab
	
		Empleado empleado;
		 string nombre,apellido,puesto;
		do{
			fflush(stdin);
			
		cout<<"Ingrese el Codigo: ";
		cin>>empleado.Codigo_Empleado;
        cin.ignore();
        
		cout<<"Ingrese el Nombre: ";
		getline(cin,nombre);
    	strcpy(empleado.Nombres, nombre.c_str()); 
			
		cout<<"Ingrese el Apellido: ";
		getline(cin,apellido);
		strcpy(empleado.Apellidos, apellido.c_str()); 
		
		cout<<"Ingrese el Puesto: ";
		getline(cin,puesto);
		strcpy(empleado.Puesto, puesto.c_str());
		
		cout<<"Ingrese el sueldo: ";
		cin>>empleado.Sueldo_base;
		cin.ignore();
		
		cout<<"Ingrese bonificaciones: ";
		cin>>empleado.Bonificacion;
		cin.ignore();
		
		empleado.Sueldo_Total = empleado.Sueldo_base + empleado.Bonificacion;
		cin.ignore();
		
		fwrite( &empleado, sizeof(Empleado), 1, archivo );
		
		cout<<"Desea Agregar otro Nombre s/n : ";
		cin>>continuar;
		} while((continuar=='s') || (continuar=='S') );
		
	
	fclose(archivo);
	Abrir_Empleado();
	//buscar_indice();
}

//MODIFICACION DE DATOS
void Modificar_Empleado(){
	
	FILE* archivo = fopen(archivo_empleados, "r+b");
	
		int id;
		string nombre,apellido, puesto;	
    	Empleado empleado;
    
		cout<<"Ingrese el ID que desea Modificar: ";
    		cin>>id;
    		fseek(archivo,id* sizeof(Empleado), SEEK_SET);  // esto es lo que permite modificar en la pocision
	
		cout<<"Codigo: ";
		cin>>empleado.Codigo_Empleado;
        cin.ignore();
        
		cout<<" Nombre: ";
		getline(cin,nombre);
    	strcpy(empleado.Nombres, nombre.c_str()); 
			
		cout<<"Apellido: ";
		getline(cin,apellido);
		strcpy(empleado.Apellidos, apellido.c_str()); 
		
		cout<<" Puesto: ";
		getline(cin,puesto);
		strcpy(empleado.Puesto, puesto.c_str());
		
		cout<<"sueldo base : ";
		cin>>empleado.Sueldo_base;
		cin.ignore();
		
		cout<<"Ingrese las bonificaciones: ";
		cin>>empleado.Bonificacion;
		cin.ignore();
		
		empleado.Sueldo_Total = empleado.Sueldo_base + empleado.Bonificacion;
		cin.ignore();
		
		fwrite( &empleado, sizeof(Empleado), 1, archivo );
		
	fclose(archivo);
	Abrir_Empleado();
		system("PAUSE");
}

//ELIMINACION DE DATOS
void Eliminar_Empleado(){
	FILE* archivo = fopen(archivo_empleados, "r+b");
	
		int id;
		char valor;
		char continuar;
		string nombre,apellido,puesto;	
    	Empleado empleado;
    
		cout << "Ingrese el ID que desea eliminar: ";
    		cin >> id;
    		fseek ( archivo, id * sizeof(Empleado), SEEK_SET );  // esto es lo que permite modificar en la pocision
		cout<<"Deseas eliminar a "<<empleado.Nombres<<" definitivamente?: ";
		
		cin>>empleado.Codigo_Empleado;
        cin.ignore();
		getline(cin,nombre);
    	strcpy(empleado.Nombres, nombre.c_str()); 
		getline(cin,apellido);
		strcpy(empleado.Apellidos, apellido.c_str());
		getline(cin,puesto);
		strcpy(empleado.Puesto, puesto.c_str());
		cin>>empleado.Sueldo_base;
		cin.ignore();
		cin>>empleado.Bonificacion;
		cin.ignore();
		cin>>empleado.Sueldo_Total;
		cin.ignore();
		
		fwrite( &empleado, sizeof(Empleado), 1, archivo );
		
		cout<<"\n\n\n ELIMINADO CON EXITO!"<<endl;
		fclose(archivo);
		Abrir_Empleado();
	
		system("PAUSE");
}
