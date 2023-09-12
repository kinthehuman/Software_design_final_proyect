#ifndef LIGHTSENSOR_H
#define LIGHTSENSOR_H
#include "sensor.h"
/**
* @brief Simulated ilumination Sensor
***************************************************************************************/
class lightSensor : public Sensor {

public:
/**
* @brief Constructor
***************************************************************************************/
lightSensor();

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
