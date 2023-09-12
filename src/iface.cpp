#include <string>
#include <iostream>
#include <unistd.h>               // for linux 
#include <fstream>
#include "iface.h"

iface::iface(){
	system("touch users.dat");
	bdd = new Database("users.dat");
}

iface::iface(Database* base){
	bdd = base;
}

int iface::Menu1(){

	int MENU1;
	std::cout << "\n\nSELECCIONE:\n\n";
	std::cout << "1. Crear cuenta\n";
	std::cout << "2. Login\n";
	std::cout << "3. Salir\n";
	std::cout << "4. Lista de usuarios\n";
	std::cout << "\n\n>";
	try{
		std::cin >> MENU1;
		if(std::cin.fail()){
			throw invalidInput();
		}
	}
	catch(invalidInput &except){
		std::cout << except.what();
		std::cin.clear();
		std::cin.ignore();
		sleep(1);
		return 0;
	}
	
	return MENU1;
	
}

int iface::Menu2(){

	int MENU2;
	std::cout << "\n\nSELECCIONE:\n\n";
	std::cout << "0. MENU\n";
	std::cout << "1. Calidad de aire\n";
	std::cout << "2. Temperatura\n";
	std::cout << "3. Humedad\n";
	std::cout << "4. Iluminacion\n";
	std::cout << "5. Cerrar sesion\n\n";
	if(Admin()){std::cout << "6. Menu de ADMIN\n";}
	std::cout << "\n\n>";
	try{
		std::cin >> MENU2;
		if(std::cin.fail()){
			throw invalidInput();
		}
	}
	catch(invalidInput &except){
		std::cout << except.what();
		std::cin.clear();
		std::cin.ignore();
		sleep(1);
		return 0;
	}
	return MENU2;
	
}

int iface::Menu3(){

	int MENU3;
	std::cout << "\n\nSELECCIONE:\n\n";
	std::cout << "1. Cambiar nombre\n";
	std::cout << "2. Cambiar contraseña\n";
	std::cout << "3. Borrar usuario\n";
	std::cout << "4. Lista de usuarios\n";
	std::cout << "5. Volver\n";
	std::cout << "\n\n>";
	try{
		std::cin >> MENU3;
		if(std::cin.fail()){
			throw invalidInput();
		}
	}
	catch(invalidInput &except){
		std::cout << except.what();
		std::cin.clear();
		std::cin.ignore();
		sleep(1);
		return 0;
	}
	return MENU3;
	
}

void iface::displayUsers(){
	system("clear");
	std::cout << "Lista de usuarios:\n\n";
	bdd->showUsers();
}

void iface::displayCurrent(){
	system("clear");
	bdd->displayStatus();
}

void iface::ifaceCreateAccount(){
	
	std::string usr;
	std::string psw1;
	std::string psw2;
	int a;
	system("clear");
	std::cout << "Introduzca nombre de usuario:\n";
	std::cin >> usr;
	
	
	while(!bdd->validname(usr)){
		std::cin >> usr;
	}
	
	system("clear");
	std::cout << "Introduzca contraseña:\n";
	std::cin >> psw1;
	while(!bdd->validpsw(psw1)){
		std::cin >> psw1;
	}
	system("clear");
	std::cout << "Confirme contraseña:\n";
	std::cin >> psw2;
		
	while(psw1 != psw2){
		
		system("clear");
		std::cout << "Las contraseñas no coinciden. Vuelva a introducir la contraseña:\n";
		std::cin >> psw1;
		while(!bdd->validpsw(psw1)){
			std::cin >> psw1;
		}
		system("clear");
		std::cout << "Confirme contraseña:\n";
		std::cin >> psw2;
	}
	
	system("clear");
	std::cout << "Usuario y contraseña correctos. Introduzca tipo de cuenta:\n\n";
	std::cout << "0. Administrador\n";
	std::cout << "1. Usuario estandar\n";
	std::cin >> a;
	
	bdd->crearCuenta(usr, psw1, a);
}


void iface::ifaceLogin(){
	try{
	
		if(bdd->isEmpty()){
			throw EmptyDatabase();
		}
		
		std::string usr;
		std::string psw;
			
		system("clear");
		std::cout << "Introduzca nombre de usuario:\n";
		std::cin >> usr;

		std::cout << "Introduzca contraseña:\n";
		std::cin >> psw;
		
		bdd->login(usr, psw);
				
	}	
	catch(EmptyDatabase &except){
		system("clear");
		std::cout << except.what();
		sleep(2);
	}
}

void iface::ifaceChUsr(){

	try{
		if(!bdd->isAdmin()){
			throw NotAdmin();
		}
		std::string psw;
		std::string newname;
		int username_err = 0;
		int password_err = 0;
		
		system("clear");
		std::cout << "Introduzca contraseña:\n";
		std::cin >> psw;
		
		while(!bdd->correctPassword(psw) && password_err < 3){
			system("clear");
			password_err++;
			std::cout << "Contraseña incorrecta, por favor introduzca la contraseña de nuevo:\n";
			std::cin >> psw;
		}
		if(password_err >= 3){
			system("clear");
			std::cout << "Credenciales incorrectos. Operacion cancelada.\n";
			sleep(1);
		}
		else{
			system("clear");
			std::cout << "Introduzca nuevo nombre de usuario:\n";
			std::cin >> newname;
			
			while(!bdd->validname(newname) && username_err < 3){
				system("clear");
				username_err++;
				std::cin >> newname;
			}
			
			if(username_err >= 3){
				system("clear");
				std::cout << "Operacion cancelada\n";
				sleep(1);
			}
			else{
				bdd->chusername(newname);
			}				
		}	
	}
	catch(NotAdmin& except){
		system("clear");
		std::cout << except.what();
		sleep(2);
	}
}

void iface::ifaceChPsw(){
	try{
		if(!bdd->isAdmin()){
			throw NotAdmin();
		}
		std::string psw;
		std::string psw1;
		std::string psw2;
		int password_err = 0;
		int newpswerr = 0;
		
		system("clear");
		std::cout << "Introduzca contraseña actual:\n";
		std::cin >> psw;
		
		while(!bdd->correctPassword(psw) && password_err < 3){
			system("clear");
			password_err++;
			std::cout << "Contraseña incorrecta, por favor introduzca la contraseña de nuevo:\n";
			std::cin >> psw;
		}
		if(password_err >= 3){
			system("clear");
			std::cout << "Credenciales incorrectos. Operacion cancelada.\n";
			sleep(1);
		}
		else{
			system("clear");
			std::cout << "Introduzca nueva contraseña:\n";
			std::cin >> psw1;
			
			while(!bdd->validpsw(psw1) && newpswerr < 3){
				newpswerr++;
				std::cin >> psw1;
			}
			if(newpswerr >= 3){
				system("clear");
				std::cout << "Operacion cancelada\n";
				sleep(1);
			}
			else{
				system("clear");
				std::cout << "Confirme contraseña:\n";
				std::cin >> psw2;
					
				while(psw1 != psw2 && newpswerr < 3){
					newpswerr++;
					system("clear");
					std::cout << "Las contraseñas no coinciden. Vuelva a introducir la contraseña:\n";
					std::cin >> psw1;
					while(!bdd->validpsw(psw1)){
						std::cin >> psw1;
					}
					system("clear");
					std::cout << "Confirme contraseña:\n";
					std::cin >> psw2;
				}
				if(newpswerr >= 3){
					system("clear");
					std::cout << "Operacion cancelada\n";
					sleep(1);
				}
				else{
					bdd->chpassword(psw1);
				}
			}
		}				
	}	
	catch(NotAdmin& except){
		system("clear");
		std::cout << except.what();
		sleep(2);
	}
}

void iface::ifaceDelUsr(){
	try{
		if(!bdd->isAdmin()){
			throw NotAdmin();
		}
		
		std::string delname;
		std::string psw;
		int password_err = 0;
		
		system("clear");
		std::cout << "Introduzca el nombre de usuario que desea eliminar:\n\n";
		bdd->showUsers();
		std::cout << "\n\n>";
		std::cin >> delname;
		
		system("clear");
		std::cout << "Introduzca contraseña:\n";
		std::cin >> psw;
		
		while(!bdd->correctPassword(psw) && password_err <= 3){
			system("clear");
			password_err++;
			std::cout << "Contraseña incorrecta, por favor introduzca la contraseña de nuevo:\n";
			std::cin >> psw;
		}
		if(password_err > 3){
			system("clear");
			std::cout << "Credenciales incorrectos. Operacion cancelada.\n";
			sleep(1);
		}
		else{	
			bdd->remove(delname);
		}			
	}	
	catch(NotAdmin& except){
		system("clear");
		std::cout << except.what();
		sleep(2);
	}

}

bool iface::Admin(){
	return bdd->isAdmin();
}

bool iface::LoggedIn(){
	return bdd->isLoggedIn();
}

void iface::ifaceLogoff(){
	bdd->logoff();
	system("clear");
}

void iface::close(){

	system("clear");
	std::cout << "SALIENDO\n\n";	
	bdd->guardarLista();
	delete bdd;

}




























