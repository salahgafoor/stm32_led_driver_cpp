/*
 * main.cpp
 *
 *  Created on: Apr 1, 2024
 *      Author: salahgafoor
 */


#include "led.h"


int main(void){

	Led led1(ON);

	while(1){
		led1.setState(ON);
		delay(1000);
		led1.setState(OFF);
		delay(1000);

	}
}

