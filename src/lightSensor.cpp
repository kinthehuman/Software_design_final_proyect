#include <iostream>
#include <unistd.h>   
#include "lightSensor.h"

lightSensor::lightSensor() : Sensor(50,750){
	num_datos = 2;
}


void lightSensor::dataCheck(){

	float min_light = (max_val/2)*0.5;
	float max_light = (max_val/2)*1.5;
	
	if (Dato < min_light){
		std::cout << "WARNING: Iluminacion baja";
	}else if (min_light <= Dato <= max_light){
		std::cout << "Luz optima";
	}else if (Dato > max_light){
		std::cout << "WARNING: Iluminacion alta";
	}
}

void lightSensor::printData(){

	system("clear");
	std::cout << "Iluminacion: " << Dato << " lux\n";
	dataCheck();
	std::cout << "\n\n";

}
