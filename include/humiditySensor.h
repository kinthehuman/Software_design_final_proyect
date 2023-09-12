#ifndef HUMIDITYSENSOR_H
#define HUMIDITYSENSOR_H
#include "sensor.h"
/**
* @brief Simulated humidity Sensor
***************************************************************************************/
class humiditySensor : public Sensor {

public:
/**
* @brief Constructor
***************************************************************************************/
humiditySensor();

/**
* @brief Interprets generated data
***************************************************************************************/
void dataCheck();

/**
* @brief Print the latest generated data on the screen
***************************************************************************************/
void printData();

}; // end class humiditySensor

#endif
