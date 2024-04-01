/*
 * led.h
 *
 *  Created on: Apr 1, 2024
 *      Author: optimus
 */

#ifndef LED_H_
#define LED_H_


#include "stm32g474xx.h"
//CMSIS driver files are downloaded from https://github.com/STMicroelectronics/STM32CubeG4
// Clone the repo. and copy Device, Include directories from CMSIS folder


#define LED_PIN 5

typedef enum{
	OFF = 0,
	ON
}LedState_Type;

class Led{
	private:
		LedState_Type state;
	public:
		Led(LedState_Type state);
};


#endif /* LED_H_ */
