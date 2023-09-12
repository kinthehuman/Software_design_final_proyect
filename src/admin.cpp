#include <string>
#include <iostream>
#include "admin.h"

Admin::Admin() : Cuenta ("", "", 0, 0){
} // constructor

Admin::Admin(std::string usr, std::string psw) : Cuenta (usr, psw, 0, 0){
} // constructor with parameters

void Cuenta::changeName(std::string usr){
	username = usr;
}

void Cuenta::changePassword(std::string psw){
	password = psw;
}

