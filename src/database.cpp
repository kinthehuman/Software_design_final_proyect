#include <string>
#include <iostream>
#include <unistd.h>               // for linux 
#include <fstream>
#include "database.h"

const int LOGGED_IN = 1;
const int ADMIN = 0;


Database::Database() : fichero("users.dat"){
	system("touch users.dat");
}

Database::Database(std::string file) :  fichero(file){

	std::string usr;
	std::string psw;
	int a;
	
	std::ifstream infile(file);
	while (infile >> usr >> psw >> a){
		crearCuenta(usr, psw, a);
		//usuarios.insert(new_acc);
	}
}

Database::~Database(){
	usuarios.clear();
}

void Database::guardarCuenta(Cuenta acc){

	std::ofstream wfile;
	wfile.open(fichero, std::ios::app);
	wfile << "\n" << acc.usr() << " " << acc.psw() << " " << acc.ty();
	wfile.close();
}

void Database::guardarLista(){
	if(usuarios.size() > 0){
		
		Cuenta acc;
		std::ofstream ofs;
		ofs.open(fichero, std::ofstream::out | std::ofstream::trunc);
		
		for (it = usuarios.begin(); it != usuarios.end(); it++){
			acc = *it;
			ofs << "\n" << acc.usr() << " " << acc.psw() << " " << acc.ty();
		}
		
		ofs.close();
	}
}

bool Database::validname(std::string usr){
	int n = usr.length();
	if(usrExists(usr)){
		system("clear");
		std::cout << "El usuario " << usr << " ya existe, por favor introduzca otro nombre de usuario:\n";
		return false;
	}
	else if(n > maxlen){
		system("clear");
		std::cout << "El nombre de usuario introducido excede el máximo de caracteres permitidos(" << maxlen << "), por favor introduzca otro nombre de usuario:\n";
		return false;
	}
	else return true;

}

bool Database::validpsw(std::string psw){
	int n = psw.length();
	if(minlen > n || n > maxlen){
		system("clear");
		std::cout << "La contraseña debe contener entre " << minlen << " y " << maxlen << " caracteres, por favor introduzca otra contraseña:\n";
		return false;
	}
	
 	bool lower = false;
	bool upper = false;
	bool digit = false;

 	for (int i = 0; i < n; i++) {
      		if (islower(psw[i])){lower = true;}
    		if (isupper(psw[i])){upper = true;}
      		if (isdigit(psw[i])){digit = true;}
	}
	if(!lower || !upper || !digit){
		system("clear");
		std::cout << "La contraseña debe contener al menos una letra minuscula, una letra mayuscula y un numero, por favor introduzca otra contraseña:\n";
		return false;
	}
	else return true;
}

void Database::crearCuenta(std::string usr, std::string psw, int a){
	if (a == 0){
		Admin new_acc(usr, psw);
		usuarios.insert(new_acc);
	}
	else{
		Cuenta new_acc(usr, psw);
		usuarios.insert(new_acc);
	}
}


bool Database::isEmpty(){
	return (usuarios.size() == 0);
}

bool Database::usrExists(std::string usr){
	Cuenta temp_acc(usr, "");
	
	if (it = usuarios.find(temp_acc); it != usuarios.end()){
		return true;
		}
    	else{
		return false;
		}
}

bool Database::isAdmin(){
	try{
		if(usuarios.size() == 0){
			throw EmptyDatabase();
		}
		return(actual.ty() == ADMIN);
	}
	catch(EmptyDatabase &except){
		return false;
	}
	
}

bool Database::correctPassword(std::string psw){
	try{
		if(usuarios.size() == 0){
			throw EmptyDatabase();
		}
		return(actual.psw() == psw);//1 = logged in
	}
	catch(EmptyDatabase &except){
		return false;
	}
}

bool Database::isLoggedIn(){
	try{
		if(usuarios.size() == 0){
			throw EmptyDatabase();
		}
		return(actual.st() == LOGGED_IN);
	}
	catch(EmptyDatabase &except){
		return false;
	}
}

void Database::login(std::string usr, std::string psw){
	try{
		if(!usrExists(usr)){
			throw NotFound();
		}
		actual = *it;
				
		if(!correctPassword(psw)){
			throw WrongPsw();
		}
		else{
			actual.login();
			it = usuarios.find(actual);
			usuarios.erase(*it);
			usuarios.insert(actual);
		}
		
	}
	catch(WrongPsw &except){
		system("clear");
		std::cout << except.what();
		sleep(2);
	}
	catch(NotFound &except){
		system("clear");
		std::cout << except.what();
		sleep(2);
	}
}

void Database::logoff(){
	actual.logoff();
	it = usuarios.find(actual);
	usuarios.erase(*it);
	usuarios.insert(actual);
}

void Database::displayStatus(){

	if(isLoggedIn()){
		std::cout << "Logged in as " << actual.usr();
		if(isAdmin()){
			std::cout << " ADMIN";
		}
		std::cout << "\n";
	}
	else{
		std::cout << "Logged off\n";
	}
}

void Database::chusername(std::string newname){

	it = usuarios.find(actual);
	actual.changeName(newname);
	usuarios.erase(*it);
	usuarios.insert(actual);

}

void Database::chpassword(std::string newpsw){

	it = usuarios.find(actual);
	actual.changePassword(newpsw);
	usuarios.erase(*it);
	usuarios.insert(actual);

}

void Database::remove(std::string delname){
	try{

		if(delname == actual.usr()){
			throw CurrentUser();
		}
			
		if(!usrExists(delname)){
			throw NotFound();	
		}
				
		usuarios.erase(*it);
			
	}
	
	catch(CurrentUser& except){
		system("clear");
		std::cout << except.what();
		sleep(2);
	}
	
	catch(NotFound& except){
		system("clear");
		std::cout << except.what();
		sleep(2);
	}
}

void Database::showUsers(){
	try{
		if(usuarios.size() == 0){
			throw EmptyDatabase();
		}
		for (it = usuarios.begin(); it != usuarios.end(); it++){
			std::cout << it->usr();
			if(it->ty() == 0){std::cout << "	ADMIN";}
			if(it->st() == 1){std::cout << "	logged in";}
			std::cout << "\n";
		}
	}
	catch(EmptyDatabase& except){
		std::cout << except.what();

	}
	
}




























