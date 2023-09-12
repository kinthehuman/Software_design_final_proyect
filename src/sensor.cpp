#include <cstdlib>
#include <time.h>
#include <exception>
#include <iostream>
#include "sensor.h"
#include "DivisionByZero.h"

Sensor::Sensor() : Dato(0.0), max_val(0), min_val(0) {}

Sensor::Sensor(int max, int min){
	setRanges(max, min);
	Dato = 0.0;
}

void Sensor::setRanges(int min, int max){

	max_val = max;
	min_val = min;
	
}

int Sensor::generateData(){

	float avg = 0;

	for (int i = 0; i < num_datos; i++){
	
		avg = avg + (rand() % max_val) + min_val;
		
	}
	try{
		if (num_datos == 0){
			throw DivisionByZero();
		}
		Dato = avg/num_datos;
		return Dato;
	}
	catch(DivisionByZero &except){
		system("clear");
		std::cout << except.what();
	}
	return 0;
}

void Sensor::printData(){
	
	std::cout << "Data: " << Dato;
	
}



