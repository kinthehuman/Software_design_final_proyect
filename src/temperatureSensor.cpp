#include <iostream>
#include <unistd.h>   
#include "temperatureSensor.h"

temperatureSensor::temperatureSensor() : Sensor(0,40){}


void temperatureSensor::dataCheck(){

	float min_temperature = (max_val/2)*0.9;
	float max_temperature = (max_val/2)*1.1;
	
	if (Dato < min_temperature){
		std::cout << "WARNING: Temperatura baja";
	}else if (min_temperature <= Dato <= max_temperature){
		std::cout << "Temperatura optima";
	}else if (Dato > max_temperature){
		std::cout << "WARNING: Temperatura alta";
	}
}

void temperatureSensor::printData(){

	system("clear");
	std::cout << "Temperatura: " << Dato << "ºC\n";
	dataCheck();
	std::cout << "\n\n";

}
