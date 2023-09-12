#ifndef DATABASE_H
#define DATABASE_H

#include <set>
#include <string>
#include <cstring>
#include <iostream>
#include <exception>
#include "cuenta.h"
#include "admin.h"
#include "EmptyDatabase.h"
#include "CurrentUser.h"
#include "NotFound.h"
#include "NotAdmin.h"
#include "WrongPsw.h"

/**
* @brief A database that handles accounts, their info, and their status. Loads from and unloads into a file.
***************************************************************************************/
class Database {


public:

/**
* @brief Constructor
* @note Generates/uses a file named database.txt on your working environment to store user data
***************************************************************************************/
Database();

/**
* @brief Constructor with file
* @param file name of the file to be used/generated
* @note Generates/uses the file on your working environment to store user data
***************************************************************************************/
Database(std::string file);

/**
* @brief Destructor
***************************************************************************************/
~Database();

/**
* @brief Generates an account with the given info
* @param usr Username
* @param psw Password
* @param a Account type (regular 1 vs admin 0)
* @note Both username and password must meet requirements
* @note The account is stored in a set data struture
***************************************************************************************/
void crearCuenta(std::string usr, std::string psw, int a);

/**
* @brief Writes the account info into the file
* @param acc the account to be written down
***************************************************************************************/
void guardarCuenta(Cuenta acc);

/**
* @brief Writes down all the accounts info into the file
* @warning Overwrites the file
***************************************************************************************/
void guardarLista();


/**
* @brief Tells if the database is empty
* @return True if the size of the users set size is zero
***************************************************************************************/
bool isEmpty();

/**
* @brief Checks if the username is in the database
* @note Iterates over the set data structure and checks for any username matching the one given
* @param usr string containing the username to be looked for
* @return True if the username is found in the database, false otherwise or if the database is empty
***************************************************************************************/
bool usrExists(std::string usr);

/**
* @brief Checks if the current user is and administrator
* @note Uses the current account, a copy of the last logged in user info, and checks the #type parameter
* @return True if the user is an administrator, false if it isn't
***************************************************************************************/
bool isAdmin();

/**
* @brief Checks if the given password matches the one of the current account
* @param psw string containing the password to be compared
* @return True if the passwords are equal, false otherewise
***************************************************************************************/
bool correctPassword(std::string psw);

/**
* @brief Checks if the current user is logged in
* @note Uses the current account, a copy of the last logged in user info, and checks the #status parameter
* @return True if the user is an logged in, false if it isn't
***************************************************************************************/
bool isLoggedIn();

/**
* @brief Checks if the given username meets necessary requirements, prints any missing requirements
* @note Requirements for usernames are:
* @note - Usernames must be unique
* @note - Usernames must not exceed character maximum (15)
* @param usr string containing username to be checked
* @return True if the username meets the requirements
***************************************************************************************/
bool validname(std::string usr);

/**
* @brief Checks if the given password meets necessary requirements, prints any missing requirements
* @note Requirements for passwords are:
* @note - Passwords must be over the character minimun (8) and under the character maximum (15)
* @note - Passwords must contain one lowercase, one uppercase and one digit
* @param psw string containing password to be checked
* @return True if the password meets the requirements
***************************************************************************************/
bool validpsw(std::string psw);


/**
* @brief Takes the user name and password and logs it in
* @note This function sets the current user to the one that just logged in
* @warning If the username doesn't exist, the password is incorrect, or the database is empty, this function won't work and will throw an exception
***************************************************************************************/
void login(std::string usr, std::string psw);

/**
* @brief Logs off the current user
* @note See Cuenta.logoff()
***************************************************************************************/
void logoff();

/**
* @brief Prints "logged in" or "logged off" depending on the current account #status
***************************************************************************************/
void displayStatus();

/**
* @brief Prints out a list of the users, if they're Admin and if they are logged in
* @note No more than one user will be logged in at any point
***************************************************************************************/
void showUsers();

/**
* @brief Looks the given username and removes it from the database
* @note Only available for Admin users
* @param usr string containing username to be deleted
* @warning Will throw an excpetion if the username doesn't exist or is currently logged in
***************************************************************************************/
void remove(std::string username);

/**
* @brief Changes current username
* @note Only available for Admin users
***************************************************************************************/
void chusername(std::string newname);

/**
* @brief Changes current password
* @note Only available for Admin users
***************************************************************************************/
void chpassword(std::string newpsw);

private:

/**
* @brief Set structure that stores user info
***************************************************************************************/
std::set<Cuenta> usuarios;

std::set<Cuenta>::iterator it;
/**
* @brief Proxy for the current account
***************************************************************************************/
Cuenta actual;

/**
* @brief Path to the file that for the creation/saving of the database
***************************************************************************************/
std::string fichero;
int minlen = 8;
int maxlen = 15;

}; // end class Database

#endif
