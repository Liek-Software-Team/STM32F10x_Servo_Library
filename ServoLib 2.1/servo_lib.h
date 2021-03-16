/***************************
@author: Liek
@version: 2.1
@date: 16.03.2021

-Servo_Detach function is added.
-Delay function is enhanced for real time delay. ( Servo_Delay(1000)= 1 second )

***************************/

#include "stm32f10x.h"									// Library definitions   

typedef struct ServoStruct{
	
	GPIO_TypeDef * port;
	uint16_t pin;

}Servo;

void Servo_Conf(Servo Port_Pin); 														
void Servo_Delay(uint32_t time);																									 // delay function
void Servo_Degree(Servo Port_Pin, uint16_t Degree); 															 //  pwm function  (This function is inside of Servo_Degree() )
void Servo_DegreetoDegree(Servo Port_Pin, uint16_t Degree1, uint16_t Degree2); 			 // It is used to reach degree to degree
void Servo_Detach(Servo Port_Pin);

/*
void uartConfig();  																								 // Uart config function
void uartTransmit(char *string); 																	   // Uart transmit function
void uartReceive();	 																								 // Uart receive function
*/
