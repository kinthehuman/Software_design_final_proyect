#ifndef TEMPERATURESENSOR_H
#define TEMPERATURESENSOR_H
#include "sensor.h"
/**
* @brief Simulated temperature Sensor
***************************************************************************************/
class temperatureSensor : public Sensor {

public:
/**
* @brief Constructor
***************************************************************************************/
temperatureSensor();

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
