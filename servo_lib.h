/*
@author: Liek Software Team
@version: 1.7.1
@date: 01.03.2021

*/

#include "stm32f10x.h"                  														 // Library definitions  
#include "string.h"
    																						
void Servo_Config(char *Gpio, uint16_t Gpio_Pin);  									 // Servo attach function
void timerayar(char *TIM);   																				 //  Timer function (This function is inside of Servo_Config() )
void pwmconfigrest(uint16_t timPulse); 															 //  pwm function  (This function is inside of Servo_Degree() )

void Servo_Detach();   																							 // Servo detach function
void Servo_Degree(uint32_t Degree); 																 // Servo degree control function
void Servo_DegreetoDegree(uint32_t Degree1, uint32_t Degree2); 			 // It is used to reach degree to degree
void Servo_GPIO_Speed(uint16_t Gpio_Speed); 												 // Clock speed function
void Servo_Delay();																									 // delay function

void uartConfig();  																								 // Uart config function
void uartTransmit(char *string); 																	   // Uart transmit function
void uartReceive();	 																								 // Uart receive function
