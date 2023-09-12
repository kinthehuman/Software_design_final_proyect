#ifndef IFACE_H
#define IFACE_H

#include <set>
#include <string>
#include <cstring>
#include <iostream>
#include <exception>
#include "cuenta.h"
#include "database.h"
#include "invalidInput.h"
/**
* @brief An interface that provides the user access to the Database. Takes input and displays menus and other communication messages for the user.
***************************************************************************************/
class iface{

public:

/**
* @brief Constructor
***************************************************************************************/
iface();

/**
* @brief Constructor with parameters
* @param base Database you want the interface to interact with.
***************************************************************************************/
iface(Database* base);

/**
* @brief Displays Login menu, returns input command from user.
* @note Login menu allows the user to create accounts, login, see the user list and exit the program.
***************************************************************************************/
int Menu1();

/**
* @brief Displays Sensor menu, returns input command from user.
* @note Sensor menu allows the user to display sensor info, logoff, and Admin accounts can access the Admin menu.
***************************************************************************************/
int Menu2();

/**
* @brief Displays Admin menu, returns input command from user.
* @note Admin menu allows the user to change username and password, delete accounts, and display the user list.
***************************************************************************************/
int Menu3();

/**
* @brief Shows user list from database
* @note see Database.showUsers()
***************************************************************************************/
void displayUsers();

/**
* @brief Shows current account status from database
* @note see Database.displayStatus()
***************************************************************************************/
void displayCurrent();


/**
* @brief Asks user to introduce username and password, generates an account with them, then adds it to the database.
***************************************************************************************/
void ifaceCreateAccount();

/**
* @brief Asks user to introduce username and password, and if they are correct, logs in the user.
***************************************************************************************/
void ifaceLogin();

/**
* @brief Allows the user to change its username.
* @note Only available for Admin users
* @note Requires password input
***************************************************************************************/
void ifaceChUsr();

/**
* @brief Allows the user to change its password.
* @note Only available for Admin users
* @note Requires password input
***************************************************************************************/
void ifaceChPsw();

/**
* @brief Displays the user list, and deletes the account that matches the input
* @note Only available for Admin users
* @note Requires password input
***************************************************************************************/
void ifaceDelUsr();

/**@name Database boolean functions
***************************************************************************************/
/**@{*/ 
/**
* @note see Database.isAdmin()*/
bool Admin();
/**
* @note see Database.isLoggedIn()*/
bool LoggedIn();
/**@}*/

/**
* @note see Database.logoff()
***************************************************************************************/
void ifaceLogoff();

/**
* @brief Displays exit message and saves the changes in the users.dat file
***************************************************************************************/
void close();

private:

Database* bdd;

};// end class iface

#endif
