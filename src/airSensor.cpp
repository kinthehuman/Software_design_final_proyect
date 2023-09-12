#include <iostream>
#include <unistd.h>   
#include "airSensor.h"

airSensor::airSensor() : Sensor(1,100){}


void airSensor::dataCheck(){

	float min_quality = (max_val/2)*0.9;
	
	if (Dato < min_quality){
		std::cout << "WARNING: Calidad de aire baja";
	}else if (min_quality <= Dato){
		std::cout << "Calidad de aire optima";
	}
}

void airSensor::printData(){

	system("clear");
	std::cout << "Calidad de aire: AQI = " << Dato << "\n";
	dataCheck();
	std::cout << "\n\n";

}
