#ifndef ADMIN_H
#define ADMIN_H
#include <string>
#include "cuenta.h"

/**
* @brief Admin object for the Database
***************************************************************************************/
class Admin : public Cuenta {

public:

/**
* @brief Constructor
* @note type will be set to 0
***************************************************************************************/
Admin();

/**
* @brief Constructor with parameters
* @param usr Username
* @param psw Password
* @note type will be set to 0
***************************************************************************************/
Admin(std::string usr, std::string psw);


}; // end class Admin

#endif
