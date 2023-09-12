#include <iostream>
#include <unistd.h>   
#include "humiditySensor.h"

humiditySensor::humiditySensor() : Sensor(1,100){}


void humiditySensor::dataCheck(){

	float min_humidity = (max_val/2)*0.9;
	float max_humidity = (max_val/2)*1.1;
	
	if (Dato < min_humidity){
		std::cout << "WARNING: Humedad baja";
	}else if (min_humidity <= Dato <= max_humidity){
		std::cout << "Humedad optima";
	}else if (Dato > max_humidity){
		std::cout << "WARNING: Humedad alta";
	}
}

void humiditySensor::printData(){

	system("clear");
	std::cout << "Humedad: " << Dato << "%\n";
	dataCheck();
	std::cout << "\n\n";

}
