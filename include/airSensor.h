#ifndef AIRSENSOR_H
#define AIRSENSOR_H
#include "sensor.h"
/**
* @brief Simulated air quality Sensor
***************************************************************************************/
class airSensor : public Sensor {

public:
/**
* @brief Constructor
***************************************************************************************/
airSensor();

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
