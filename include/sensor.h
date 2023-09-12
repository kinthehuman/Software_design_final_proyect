#ifndef SENSOR_H
#define SENSOR_H            // for linux 
/**
* @brief Simulated Sensor that generates data within ranges
***************************************************************************************/
class Sensor {

public:
/**
* @brief Constructor
***************************************************************************************/
Sensor();

/**
* @brief Constructor with parameters
* @param max is the maximum value your simulated sensor can generate
* @param min are the minimum value your simulated sensor can generate
***************************************************************************************/
Sensor(int max, int min); // constructor with parameters

/**
* @brief Sets/changes the ranges of your simulated sensor
* @param max is the maximum value your simulated sensor can generate
* @param min are the minimum value your simulated sensor can generate
***************************************************************************************/
void setRanges(int min, int max);

/**
* @brief Generates a random number within the ranges given
***************************************************************************************/
int generateData();


/**
* @brief Print the latest generated data on the screen
***************************************************************************************/
void printData();



protected:

float Dato; // Latest data
int max_val; // Maximum value for the data generator
int min_val; // Minimum value for the data generator
int num_datos = 10;

}; // end class Sensor

#endif
