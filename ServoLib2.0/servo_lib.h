/***************************
@author: Liek
@version: 2.0
@date: 9.03.2021


*artilar
çoklu servo kullanimi için kodlar struct kullanilarak gelistirildi
fazlalik bazi kodlar düzeltildi, kod optimizasyonu yapildi
string kütüphanesine artik gerek yok 

*eksikler
detach fonksiyonu
bazi çalismayan pinler
uart kismi
kod açiklamalari düzenlenecek

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


/*
void uartConfig();  																								 // Uart config function
void uartTransmit(char *string); 																	   // Uart transmit function
void uartReceive();	 																								 // Uart receive function
*/
