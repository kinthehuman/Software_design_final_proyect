#include <string>
#include <iostream>
#include "cuenta.h"

Cuenta::Cuenta() : username(""), password(""), type(1), status(0){
} // constructor

Cuenta::Cuenta(std::string usr, std::string psw) : username(usr), password(psw),type(1), status(0){
} // constructor with parameters

Cuenta::Cuenta(std::string usr, std::string psw, int t, int s) : username(usr), password(psw),type(t), status(s){
} // constructor with parameters

bool operator< (const Cuenta &current, const Cuenta &other){

	return current.username < other.username;

}

Cuenta& Cuenta::operator= (const Cuenta &current){
	
	this->username = current.usr();
	this->password = current.psw();
	this->type = current.ty();
	this->status = current.st();
	
	return *this;

}
