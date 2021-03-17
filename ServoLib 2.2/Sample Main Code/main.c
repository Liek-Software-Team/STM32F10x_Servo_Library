/*******************
@author: Liek
@version: 2.2
@date: 17.03.2021 
*******************/

#include "servo_lib.h"

Servo myServo;
Servo myServo2;

int main(){
	
	myServo.port='A';
	myServo.pin=2;
	myServo2.port='A';
	myServo2.pin=3;
	
	Servo_Config(myServo);
	Servo_Config(myServo2);
	
	while(1){
		
		Servo_Degree(myServo,0);
		Servo_Degree(myServo2,0);
		Servo_Delay(2000);
		
		Servo_Degree(myServo,80);
		Servo_Degree(myServo2,80);
		Servo_Delay(2000);
		
		Servo_Degree(myServo,150);
		Servo_Degree(myServo2,150);
		Servo_Delay(2000);
		
		Servo_Detach(myServo2);
		
		
	}
}
