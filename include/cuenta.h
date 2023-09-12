#ifndef CUENTA_H
#define CUENTA_H
#include <string>
//#include "admin.h"
/**
* @brief Account object for the Database
***************************************************************************************/
class Cuenta{


protected:

std::string username;

std::string password;

/**
* @brief 0 for admin, 1 for regular accounts
***************************************************************************************/
int type;

/**
* @brief 0 -> logged off, 1 -> logged in
* @note Always initialized at 0
***************************************************************************************/
int status;

/**
* @brief Constructor with all parameters, only available for Admin constructor
* @param usr Username
* @param psw Password
* @param t Account type
* @param s Account type
***************************************************************************************/
Cuenta(std::string usr, std::string psw, int t, int s);

public:

/**
* @brief Constructor
***************************************************************************************/
Cuenta();

/**
* @brief Constructor with parameters
* @param usr Username
* @param psw Password
* @note Account type will be set to 1
***************************************************************************************/
Cuenta(std::string usr, std::string psw);


/**
* @brief Overrides operator less than so the object can be used inside a set
***************************************************************************************/
friend bool operator< (const Cuenta &current, const Cuenta &other);

/**
* @brief Overrides assignment operator
***************************************************************************************/
Cuenta& operator= (const Cuenta &current);


/**@name Attribute access functions 
* @brief Provide access to class read only attributes
***************************************************************************************/
/**@{*/ 
std::string usr() const{
	return username;
}

std::string psw() const{
	return password;
}

int ty() const{
	return type;
}

int st() const{
	return status;
}
/**@}*/

/**@name Status management functions 
* @brief Handle status switch
***************************************************************************************/
/**@{*/ 
void login(){
	status = 1;
}

void logoff(){
	status = 0;
}
/**@}*/

/**@name Admin functions 
* @brief Admin only functions, change username and password
***************************************************************************************/
/**@{*/ 
/** 
* @brief Sets new username
* @param usr new username */
void changeName(std::string usr);
/**
* @brief Sets new password
* @param usr new password */
void changePassword(std::string psw);
/**@}*/

}; // end class Cuenta

#endif
