/*
 * led.cpp
 *
 *  Created on: Apr 1, 2024
 *      Author: salahgafoor
 */

#include "led.h"

Led::Led(LedState_Type _state)
{
	this->state = _state;

	// Hardware Init
	// Led is connected at PA5
	// GPIOA is connected to AHB2

	//1.enable clock access to GPIOA
	RCC->AHB2ENR  |=  RCC_AHB2ENR_GPIOAEN;

	//3.Enable PA5 in output mode
	GPIOA->MODER  &= ~(0x3 << (LED_PIN*2)); // refer ref manual for more details
	GPIOA->MODER  |=  (0x1 << (LED_PIN*2));
	GPIOA->OTYPER &= ~(1 << LED_PIN);

	if(this->state  == ON){
		GPIOA->ODR |= (0x01 << 5);
	}
	else{
		GPIOA->ODR &= ~(0x01 << 5);
	}
}

void Led::setState(LedState_Type _state){
	this->state = _state;

	if(this->state  == ON){
		GPIOA->ODR |= (0x01 << 5);
	}
	else{
		GPIOA->ODR &= ~(0x01 << 5);
	}
}

LedState_Type Led::getState(void){
	return this->state;
}

void delay (int delay)
{
	int i;
	for(;delay>0; delay --){
		for (i=0; i<1000;i++);
	}
  return;
}
