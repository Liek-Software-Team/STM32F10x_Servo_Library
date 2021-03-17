/*******************
@author: Liek
@version: 2.2
@date: 17.03.2021 
*******************/

#include "stm32f10x.h"                  // Device header
#include "servo_lib.h"

uint32_t counter=0;


void systemClockEnable(void){
	SystemCoreClockUpdate();
	SysTick_Config(SystemCoreClock/1000);
}

void SysTick_Handler(void){
	if(counter>0){
		counter--;
	}
}

void Servo_Delay(uint64_t time){
		systemClockEnable();
	counter=time;
	while(counter);
}


void Servo_Config(Servo port_pin){
	if(port_pin.port == 'A' && port_pin.pin == 0){
		RCC->APB1ENR |= 0x1;
		RCC->APB2ENR |= 0x5; //GPIOA Enable. (If you use pwm, you should also enable alternate function mode. It has done in here.)
		GPIOA->CRL &= 0xFFFFFFF0;
		GPIOA->CRL |= 0xB;
		TIM2->CCER |= 0x1;
		TIM2->CR1 |= 0x80;
		TIM2->CCMR1 |= 0x68;
		TIM2->PSC = 1000;
		TIM2->ARR = 1439;
	}
	else if(port_pin.port == 'A' && port_pin.pin == 1){
		RCC->APB1ENR |= 0x1;
		RCC->APB2ENR |= 0x5; //GPIOA Enable. (If you use pwm, you should also enable alternate function mode. It has done in here.)
		GPIOA->CRL &= 0xFFFFFF0F;
		GPIOA->CRL |= (0xB<<4);
		TIM2->CCER |= 0x10;      
		TIM2->CR1 |= 0x80;       
		TIM2->CCMR1 |= 0x6800;   
		TIM2->PSC = 1000;       
		TIM2->ARR = 1439;
	}
	else if(port_pin.port == 'A' && port_pin.pin == 2){
		RCC->APB1ENR |= 0x1;
		RCC->APB2ENR |= 0x5; //GPIOA Enable. (If you use pwm, you should also enable alternate function mode. It has done in here.)
		GPIOA->CRL &= 0xFFFFF0FF;
		GPIOA->CRL |= (0xB<<8);
		TIM2->CCER |= 0x100;
		TIM2->CR1 |= 0x80;
		TIM2->CCMR2 |= 0x68;
		TIM2->PSC = 1000;
		TIM2->ARR = 1439;
	}
	else if(port_pin.port == 'A' && port_pin.pin == 3){
		RCC->APB1ENR |= 0x1;
		RCC->APB2ENR |= 0x5; //GPIOA Enable. (If you use pwm, you should also enable alternate function mode. It has done in here.)
		GPIOA->CRL &= 0xFFFF0FFF;
		GPIOA->CRL |= (0xB<<12);
		TIM2->CCER |= 0x1000;      
		TIM2->CR1 |= 0x80;       
		TIM2->CCMR2 |= 0x6800;   
		TIM2->PSC = 1000;       
		TIM2->ARR = 1439;        
	}
	else if(port_pin.port == 'A' && port_pin.pin == 6){
		RCC->APB1ENR |= (0x1<<1);
		RCC->APB2ENR |= 0x5; //GPIOA Enable. (If you use pwm, you should also enable alternate function mode. It has done in here.)
		GPIOA->CRL &= 0xF0FFFFFF;
		GPIOA->CRL |= (0xB<<24);
		TIM3->CCER |= 0x1;
		TIM3->CR1 |= 0x80;
		TIM3->CCMR1 |= 0x68;
		TIM3->PSC = 1000;
		TIM3->ARR = 1439;        
	}	
	else if(port_pin.port == 'A' && port_pin.pin == 7){
		RCC->APB1ENR |= (0x1<<1);
		RCC->APB2ENR |= 0x5; //GPIOA Enable. (If you use pwm, you should also enable alternate function mode. It has done in here.)
		GPIOA->CRL &= 0x0FFFFFFF;
		GPIOA->CRL |= (0xB<<28);
		TIM3->CCER |= 0x10;      
		TIM3->CR1 |= 0x80;       
		TIM3->CCMR1 |= 0x6800;   
		TIM3->PSC = 1000;       
		TIM3->ARR = 1439;                
	}
	else if(port_pin.port == 'A' && port_pin.pin == 8){
		RCC->APB2ENR |= (0x1<<11);
		RCC->APB2ENR |= 0x5; //GPIOA Enable. (If you use pwm, you should also enable alternate function mode. It has done in here.)
		GPIOA->CRH &= 0xFFFFFFF0;
		GPIOA->CRH |= 0xB;
		TIM1->CCER |= 0x1;
		TIM1->CR1 |= 0x80;
		TIM1->CCMR1 |= 0x68;
		TIM1->PSC = 1000;
		TIM1->ARR = 1439;             
	}	
	else if(port_pin.port == 'A' && port_pin.pin == 9){
		RCC->APB2ENR |= (0x1<<11);
		RCC->APB2ENR |= 0x5; //GPIOA Enable. (If you use pwm, you should also enable alternate function mode. It has done in here.)
		GPIOA->CRH &= 0xFFFFFF0F;
		GPIOA->CRH |= (0xB<<4);
		TIM1->CCER |= 0x10;      
		TIM1->CR1 |= 0x80;       
		TIM1->CCMR1 |= 0x6800;   
		TIM1->PSC = 1000;       
		TIM1->ARR = 1439;              
	}
	else if(port_pin.port == 'A' && port_pin.pin == 10){
		RCC->APB2ENR |= (0x1<<11);
		RCC->APB2ENR |= 0x5; //GPIOA Enable. (If you use pwm, you should also enable alternate function mode. It has done in here.)
		GPIOA->CRH &= 0xFFFFF0FF;
		GPIOA->CRH |= (0xB<<8);
		TIM1->CCER |= 0x100;
		TIM1->CR1 |= 0x80;
		TIM1->CCMR2 |= 0x68;
		TIM1->PSC = 1000;
		TIM1->ARR = 1439;              
	}
	else if(port_pin.port == 'A' && port_pin.pin == 11){
		RCC->APB2ENR |= (0x1<<11);
		RCC->APB2ENR |= 0x5; //GPIOA Enable. (If you use pwm, you should also enable alternate function mode. It has done in here.)
		GPIOA->CRH &= 0xFFFF0FFF;
		GPIOA->CRH |= (0xB<<12);
		TIM1->CCER |= 0x1000;      
		TIM1->CR1 |= 0x80;       
		TIM1->CCMR2 |= 0x6800;   
		TIM1->PSC = 1000;       
		TIM1->ARR = 1439;            
	}
	else if(port_pin.port == 'A' && port_pin.pin == 15){
		RCC->APB2ENR |= 0x5; //GPIOA Enable. (If you use pwm, you should also enable alternate function mode. It has done in here.)
		RCC->APB1ENR |= 0x1;
		GPIOA->CRH &= 0x0FFFFFFF;
		GPIOA->CRH |= (0xB<<28);
		TIM2->CCER |= 0x1;
		TIM2->CR1 |= 0x80;
		TIM2->CCMR1 |= 0x68;
		TIM2->PSC = 1000;
		TIM2->ARR = 1439;          
	}
	else if(port_pin.port == 'B' && port_pin.pin == 0){
		RCC->APB1ENR |= (0x1<<1);
		RCC->APB2ENR |= 0x9; //GPIOB Enable. (If you use pwm, you should also enable alternate function mode. It has done in here.)
		GPIOB->CRL &= 0xFFFFFFF0;
		GPIOB->CRL |= 0xB;
		TIM3->CCER |= 0x100;
		TIM3->CR1 |= 0x80;
		TIM3->CCMR2 |= 0x68;
		TIM3->PSC = 1000;
		TIM3->ARR = 1439;        
	}
	else if(port_pin.port == 'B' && port_pin.pin == 1){
		RCC->APB1ENR |= (0x1<<1);
		RCC->APB2ENR |= 0x9; //GPIOB Enable. (If you use pwm, you should also enable alternate function mode. It has done in here.)
		GPIOB->CRL &= 0xFFFFFF0F;
		GPIOB->CRL |= (0xB<<4);
		TIM3->CCER |= 0x1000;      
		TIM3->CR1 |= 0x80;       
		TIM3->CCMR2 |= 0x6800;   
		TIM3->PSC = 1000;       
		TIM3->ARR = 1439;           
	}
	else if(port_pin.port == 'B' && port_pin.pin == 3){
		RCC->APB1ENR |= 0x1;
		RCC->APB2ENR |= 0x9; //GPIOB Enable. (If you use pwm, you should also enable alternate function mode. It has done in here.)
		GPIOB->CRL &= 0xFFFF0FFF;
		GPIOB->CRL |= (0xB<<12);
		TIM2->CCER |= 0x10;      
		TIM2->CR1 |= 0x80;       
		TIM2->CCMR1 |= 0x6800;   
		TIM2->PSC = 1000;       
		TIM2->ARR = 1439;          
	}
	else if(port_pin.port == 'B' && port_pin.pin == 4){
		RCC->APB1ENR |= (0x1<<1);
		RCC->APB2ENR |= 0x9; //GPIOB Enable. (If you use pwm, you should also enable alternate function mode. It has done in here.)
		GPIOB->CRL &= 0xFFF0FFFF;
		GPIOB->CRL |= (0xB<<16);
		TIM3->CCER |= 0x1;
		TIM3->CR1 |= 0x80;
		TIM3->CCMR1 |= 0x68;
		TIM3->PSC = 1000;
		TIM3->ARR = 1439;          
	}
	else if(port_pin.port == 'B' && port_pin.pin == 5){
		RCC->APB1ENR |= (0x1<<1);
		RCC->APB2ENR |= 0x9; //GPIOB Enable. (If you use pwm, you should also enable alternate function mode. It has done in here.)
		GPIOB->CRL &= 0xFF0FFFFF;
		GPIOB->CRL |= (0xB<<20);
		TIM3->CCER |= 0x10;      
		TIM3->CR1 |= 0x80;       
		TIM3->CCMR1 |= 0x6800;   
		TIM3->PSC = 1000;       
		TIM3->ARR = 1439;      
	}
	else if(port_pin.port == 'B' && port_pin.pin == 10){
		RCC->APB1ENR |= 0x1;
		RCC->APB2ENR |= 0x9; //GPIOB Enable. (If you use pwm, you should also enable alternate function mode. It has done in here.)
		GPIOB->CRH &= 0xFFFFF0FF;
		GPIOB->CRH |= (0xB<<8);
		TIM2->CCER |= 0x100;
		TIM2->CR1 |= 0x80;
		TIM2->CCMR2 |= 0x68;
		TIM2->PSC = 1000;
		TIM2->ARR = 1439;      
	}
	else if(port_pin.port == 'B'&& port_pin.pin == 11){
		RCC->APB1ENR |= 0x1;
		RCC->APB2ENR |= 0x9; //GPIOB Enable. (If you use pwm, you should also enable alternate function mode. It has done in here.)
		GPIOB->CRH &= 0xFFFF0FFF;
		GPIOB->CRH |= (0xB<<12);
		TIM2->CCER |= 0x1000;      
		TIM2->CR1 |= 0x80;       
		TIM2->CCMR2 |= 0x6800;   
		TIM2->PSC = 1000;       
		TIM2->ARR = 1439;   
	}
}


void Servo_Degree(Servo port_pin, uint16_t degree){
	
	if(port_pin.port == 'A' && port_pin.pin == 0){
		TIM2->CCR1 = ((((degree) *8)/10) + 36);    
		TIM2->EGR |= 0x1;
		TIM2->CR1 |= 0x1;
	}
	else if(port_pin.port == 'A' && port_pin.pin == 1){
		TIM2->CCR2 = ((((degree) *8)/10) + 36);      
		TIM2->EGR |= 0x1;        
		TIM2->CR1 |= 0x1;
	}
	else if(port_pin.port == 'A' && port_pin.pin == 2){
		TIM2->CCR3 = ((((degree) *8)/10) + 36);   
		TIM2->EGR |= 0x1;
		TIM2->CR1 |= 0x1;
	}
	else if(port_pin.port == 'A' && port_pin.pin == 3){
		TIM2->CCR4 = ((((degree) *8)/10) + 36);     
		TIM2->EGR |= 0x1;        
		TIM2->CR1 |= 0x1;
	}
	else if(port_pin.port == 'A' && port_pin.pin == 6){
		TIM3->CCR1 = ((((degree) *8)/10) + 36); 
		TIM3->EGR |= 0x1;
		TIM3->CR1 |= 0x1;
	}
	else if(port_pin.port == 'A' && port_pin.pin == 7){
		TIM3->CCR2 = ((((degree) *8)/10) + 36);
		TIM3->EGR |= 0x1;        
		TIM3->CR1 |= 0x1;
	}
	else if(port_pin.port == 'A' && port_pin.pin == 8){
		TIM1->CCR1 = ((((degree) *8)/10) + 36);    
		TIM1->EGR |= 0x1;
		TIM1->CR1 |= 0x1;
	}
	else if(port_pin.port == 'A' && port_pin.pin == 9){
		TIM1->CCR2 = ((((degree) *8)/10) + 36);   
		TIM1->EGR |= 0x1;        
		TIM1->CR1 |= 0x1;
	}
	else if(port_pin.port == 'A' && port_pin.pin == 10){
		TIM1->CCR3 = ((((degree) *8)/10) + 36);    
		TIM1->EGR |= 0x1;
		TIM1->CR1 |= 0x1;
	}
	else if(port_pin.port == 'A' && port_pin.pin == 11){
		TIM1->CCR4 = ((((degree) *8)/10) + 36);     
		TIM1->EGR |= 0x1;        
		TIM1->CR1 |= 0x1;
	}
	else if(port_pin.port == 'A' && port_pin.pin == 15){
		TIM2->CCR1 = ((((degree) *8)/10) + 36);    
		TIM2->EGR |= 0x1;
		TIM2->CR1 |= 0x1;
	}
	else if(port_pin.port == 'B' && port_pin.pin == 0){
		TIM3->CCR3 = ((((degree) *8)/10) + 36);    
		TIM3->EGR |= 0x1;
		TIM3->CR1 |= 0x1;
	}
	else if(port_pin.port == 'B' && port_pin.pin == 1){
		TIM3->CCR4 = ((((degree) *8)/10) + 36);    
		TIM3->EGR |= 0x1;        
		TIM3->CR1 |= 0x1;
	}
	else if(port_pin.port == 'B' && port_pin.pin == 3){
		TIM2->CCR2 = ((((degree) *8)/10) + 36);     
		TIM2->EGR |= 0x1;        
		TIM2->CR1 |= 0x1;
	}
	else if(port_pin.port == 'B' && port_pin.pin == 4){
		TIM3->CCR1 = ((((degree) *8)/10) + 36);  
		TIM3->EGR |= 0x1;
		TIM3->CR1 |= 0x1;
	}
	else if(port_pin.port == 'B' && port_pin.pin == 5){
		TIM3->CCR2 = ((((degree) *8)/10) + 36);    
		TIM3->EGR |= 0x1;        
		TIM3->CR1 |= 0x1;
	}
	else if(port_pin.port == 'B' && port_pin.pin == 10){
		TIM2->CCR3 = ((((degree) *8)/10) + 36);  
		TIM2->EGR |= 0x1;
		TIM2->CR1 |= 0x1;
	}
	else if(port_pin.port == 'B' && port_pin.pin == 10){
		TIM2->CCR4 = ((((degree) *8)/10) + 36);  
		TIM2->EGR |= 0x1;        
		TIM2->CR1 |= 0x1;
	}
}

void Servo_Detach(Servo port_pin){
	
	if(port_pin.port == 'A' && port_pin.pin==0){																		//If the PIN = A0;
		GPIOA->CRL &= ~(0xF);
	}
	else if(port_pin.port == 'A' && port_pin.pin==1){																//If the PIN = A1;
		GPIOA->CRL &= ~(0xF<<4);	
	}
	else if(port_pin.port == 'A' && port_pin.pin==2){																//If the PIN = A2;
		GPIOA->CRL &= ~(0xF<<8);
	}
	else if(port_pin.port == 'A' && port_pin.pin==3){																//If the PIN = A3;
		GPIOA->CRL &= ~(0xF<<12);	
	}
	else if(port_pin.port == 'A' && port_pin.pin==6){																//If the PIN = A6;
		GPIOA->CRL &= ~(0xF<<24);	
	}
	else if(port_pin.port == 'A' && port_pin.pin==7){																//If the PIN = A7;
		GPIOA->CRL &= ~(0xF<<28);	
	}
	else if(port_pin.port == 'A' && port_pin.pin==8){																//If the PIN = A8;
		GPIOA->CRH &= ~(0xF);
	}
	else if(port_pin.port == 'A' && port_pin.pin==9){																//If the PIN = A9;
		GPIOA->CRH &= ~(0xF<<4);
	}
	else if(port_pin.port == 'A' && port_pin.pin==10){															//If the PIN = A10;
		GPIOA->CRH &= ~(0xF<<8);
	}
	else if(port_pin.port == 'A' && port_pin.pin==11){															//If the PIN = A11;
		GPIOA->CRH &= ~(0xF<<12);	
	}
	else if(port_pin.port == 'A' && port_pin.pin==15){															//If the PIN = A15;
		GPIOA->CRH &= ~(0xF<<28);
	}
	else if(port_pin.port == 'B' && port_pin.pin==0){																//If the PIN = B0;
		GPIOB->CRL &= ~(0xF);
	}
	else if(port_pin.port == 'B' && port_pin.pin==1){																//If the PIN = B1;
		GPIOB->CRL &= ~(0xF<<4);
	}
	else if(port_pin.port == 'B' && port_pin.pin==3){																//If the PIN = B3;
		GPIOB->CRL &= ~(0xF<<12);
	}
	else if(port_pin.port == 'B' && port_pin.pin==4){																//If the PIN = B4;
		GPIOB->CRL &= ~(0xF<<16);	
	}
	else if(port_pin.port == 'B' && port_pin.pin==5){																//If the PIN = B5;
		GPIOB->CRL &= ~(0xF<<20);	
	}
	else if(port_pin.port == 'B' && port_pin.pin==10){															//If the PIN = B10;
		GPIOB->CRH &= ~(0xF<<8);
	}
	else if(port_pin.port == 'B' && port_pin.pin==11){															//If the PIN = B11;
		GPIOB->CRH &= ~(0xF<<12);
	}
	else if(port_pin.port == 'B' && port_pin.pin==13){															//If the PIN = B13;
		GPIOB->CRH &= ~(0xF<<20);
	}
	else if(port_pin.port == 'B' && port_pin.pin==14){															//If the PIN = B14;
		GPIOB->CRH &= ~(0xF<<24);
	}
	else if(port_pin.port == 'B' && port_pin.pin==15){															//If the PIN = B15;
		GPIOB->CRH &= ~(0xF<<28);
	}
}
