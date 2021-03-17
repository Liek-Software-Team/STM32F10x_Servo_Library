/*********************
@author: Liek
@version: 2.2
@date: 17.03.2021 

Fixed parts:
*Servo_Config and Servo_Degree functions have arranged to work based on register.

Problems:
*Some pins still aren't working. [PA(8,9,10,11,15), PB(3,4,5,10,11)]
*********************/

#include "stm32f10x.h"                  // Device header

typedef struct servoStruct{
	
	uint8_t port;
	uint8_t pin;
	
}Servo;

void Servo_Config(Servo port_pin);
void Servo_Degree(Servo port_pin, uint16_t degree);
void Servo_Detach(Servo port_pin);
void systemClockEnable(void);
void SysTick_Handler(void);
void Servo_Delay(uint64_t time);
