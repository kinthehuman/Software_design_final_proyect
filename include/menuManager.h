#ifndef MENUMANAGER_H
#define MENUMANAGER_H

#include <cstdlib>
#include <time.h>
#include <iostream>
#include <unistd.h>               // for linux 
#include "sensor.h"
#include "cuenta.h"
#include "database.h"
#include "iface.h"
#include "airSensor.h"
#include "temperatureSensor.h"
#include "lightSensor.h"
#include "humiditySensor.h"

/**
* @brief Logical implementation of the menu navigation
***************************************************************************************/
class menuManager {

public:

/**
* @brief Constructor
***************************************************************************************/
menuManager();

/**
* @brief Constructor
* @param a initial MENU1 status
* @param b initial MENU2 status
* @param c initial MENU3 status
***************************************************************************************/
menuManager(int a, int b, int c);

/**
* @brief main function of the program
***************************************************************************************/
void run();

private:

	airSensor calidadAire = airSensor();
	temperatureSensor temperatura = temperatureSensor();
	humiditySensor humedad = humiditySensor();
	lightSensor iluminacion = lightSensor();
	
	int MENU1;
	int MENU2;
	int MENU3;

	
	bool exit = false;
	
	iface interfaz = iface();
	
}; // end class menu_manager

#endif
