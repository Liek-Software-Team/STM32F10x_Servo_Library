/*
@author: Liek Software Team
@version: 1.7.1
@date: 01.03.2021

*/

#include "stm32f10x.h"    																		// Library definitions         
#include "servo_lib.h"
#include "string.h"

uint32_t Gpio_Port;																						// Global definitions
char Mode_PWM; 			 	
uint16_t Num_PWM;		 
char message[20];
char dataBuffer[20] = "Hello";

TIM_OCInitTypeDef TIMER_OCInitStructure;											// Global definitions	
GPIO_InitTypeDef GPIOInitStructure;
TIM_TimeBaseInitTypeDef TIMERInitStructure;

uint32_t i;
   
void uartConfig(){																					
	
	 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);	
	
	 //TX
	 GPIOInitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
	 GPIOInitStructure.GPIO_Pin=GPIO_Pin_6;
	 GPIOInitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	 GPIO_Init(GPIOB,&GPIOInitStructure);
		 
 	 //RX
	 GPIOInitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;
	 GPIOInitStructure.GPIO_Pin=GPIO_Pin_7;
   GPIO_Init(GPIOB,&GPIOInitStructure);
	
   USART_InitTypeDef UARTInitStructure;
   
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
   
   UARTInitStructure.USART_BaudRate=9600;
   UARTInitStructure.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
   UARTInitStructure.USART_Mode=USART_Mode_Tx | USART_Mode_Rx;
   UARTInitStructure.USART_Parity=USART_Parity_No;
   UARTInitStructure.USART_StopBits=USART_StopBits_1;
   UARTInitStructure.USART_WordLength=USART_WordLength_8b;
   
   USART_Init(USART1,&UARTInitStructure);
   USART_Cmd(USART1,ENABLE);
}

void Servo_Delay(uint32_t time){															// Delay function

		while(time--);
}

void Servo_Config(char *Gpio, uint16_t Gpio_Pin){							// Servo attach function
	
	  Num_PWM=Gpio_Pin;																					 
    
		if(strcmp(Gpio,"GPIOA") == 0 ){														// APB channel configurations 
		Mode_PWM='A';																							
		Gpio_Port = (uint32_t)GPIOA;															
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);			// GPIOA port enable
		}
	
		else if(strcmp(Gpio,"GPIOB") == 0){												// APB channel configurations
		Mode_PWM='B';
		Gpio_Port = (uint32_t)GPIOB;
				RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);	// GPIOA port enable
		}
		
		else if(strcmp(Gpio,"GPIOC") == 0){												// APB channel configurations
		Mode_PWM='C';
		Gpio_Port = (uint32_t)GPIOC;
				RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);	// GPIOA port enable
		}
		
		else if(strcmp(Gpio,"GPIOD") == 0){												// APB channel configurations
		Mode_PWM='D';
		Gpio_Port = (uint32_t)GPIOD;
				RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD,ENABLE);	// GPIOA port enable
		}
		
		else if(strcmp(Gpio,"GPIOE") == 0){												// APB channel configurations
		Mode_PWM='E';
		Gpio_Port = (uint32_t)GPIOE;
				RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);	// GPIOA port enable
		}
		
		else if(strcmp(Gpio,"GPIOF") == 0){												// APB channel configurations
		Mode_PWM='F';
		Gpio_Port = (uint32_t)GPIOF;
				RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOF,ENABLE);	// GPIOA port enable
		}
		
		else if(strcmp(Gpio,"GPIOG") == 0){												// APB channel configurations
			
		Mode_PWM='G';
		Gpio_Port = (uint32_t)GPIOG;
				RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOG,ENABLE);	// GPIOA port enable
		}
		
	
		GPIOInitStructure.GPIO_Mode=GPIO_Mode_AF_PP;							// GPIO Mode PushPull
		
		switch(Gpio_Pin){																					// Port configurations
			case 0: GPIOInitStructure.GPIO_Pin=GPIO_Pin_0; break;		
			case 1: GPIOInitStructure.GPIO_Pin=GPIO_Pin_1; break;
			case 2: GPIOInitStructure.GPIO_Pin=GPIO_Pin_2; break;
			case 3: GPIOInitStructure.GPIO_Pin=GPIO_Pin_3; break;
			case 4: GPIOInitStructure.GPIO_Pin=GPIO_Pin_4; break;
			case 5: GPIOInitStructure.GPIO_Pin=GPIO_Pin_5; break;
			case 6: GPIOInitStructure.GPIO_Pin=GPIO_Pin_6; break;
			case 7: GPIOInitStructure.GPIO_Pin=GPIO_Pin_7; break;
			case 8: GPIOInitStructure.GPIO_Pin=GPIO_Pin_8; break;
			case 9: GPIOInitStructure.GPIO_Pin=GPIO_Pin_9; break;
			case 10: GPIOInitStructure.GPIO_Pin=GPIO_Pin_10; break;
			case 11: GPIOInitStructure.GPIO_Pin=GPIO_Pin_11; break;
			case 12: GPIOInitStructure.GPIO_Pin=GPIO_Pin_12; break;
			case 13: GPIOInitStructure.GPIO_Pin=GPIO_Pin_13; break;
			case 14: GPIOInitStructure.GPIO_Pin=GPIO_Pin_14; break;
			case 15: GPIOInitStructure.GPIO_Pin=GPIO_Pin_15; break;
			default: break;
		}
		
		GPIOInitStructure.GPIO_Speed=GPIO_Speed_50MHz;						// Clock speed configuration
		GPIO_Init((GPIO_TypeDef*)Gpio_Port,&GPIOInitStructure);		// Initializing pwm pin
		
	if(Mode_PWM=='A' && Num_PWM==0)      {timerayar("TIM2");}		// Timer configurations for A0 pin
	else if(Mode_PWM=='A' && Num_PWM==1) {timerayar("TIM2");}		// Timer configurations for A1 pin				
	else if(Mode_PWM=='A' && Num_PWM==2) {timerayar("TIM2");}		// Timer configurations for A2 pin			
	else if(Mode_PWM=='A' && Num_PWM==3) {timerayar("TIM2");}		// Timer configurations for A3 pin	
	else if(Mode_PWM=='A' && Num_PWM==6) {timerayar("TIM3");}		// Timer configurations for A6 pin
	else if(Mode_PWM=='A' && Num_PWM==7) {timerayar("TIM3");}		// Timer configurations for A7 pin
	else if(Mode_PWM=='A' && Num_PWM==8) {timerayar("TIM1");}		// Timer configurations for A8 pin		
	else if(Mode_PWM=='A' && Num_PWM==9) {timerayar("TIM1");}		// Timer configurations for A9 pin
	else if(Mode_PWM=='A' && Num_PWM==10){timerayar("TIM1");}		// Timer configurations for A10 pin
	else if(Mode_PWM=='A' && Num_PWM==11){timerayar("TIM1");}		// Timer configurations for A11 pin
	else if(Mode_PWM=='A' && Num_PWM==15){timerayar("TIM2");}		// Timer configurations for A15 pin
	else if(Mode_PWM=='B' && Num_PWM==0) {timerayar("TIM3");}		// Timer configurations for B0 pin
	else if(Mode_PWM=='B' && Num_PWM==1) {timerayar("TIM2");}		// Timer configurations for B1 pin
	else if(Mode_PWM=='B' && Num_PWM==3) {timerayar("TIM2");}		// Timer configurations for B3 pin
	else if(Mode_PWM=='B' && Num_PWM==4) {timerayar("TIM3");}		// Timer configurations for B4 pin
	else if(Mode_PWM=='B' && Num_PWM==5) {timerayar("TIM3");}		// Timer configurations for B5 pin
	else if(Mode_PWM=='B' && Num_PWM==10){timerayar("TIM2");}		// Timer configurations for B10 pin
	else if(Mode_PWM=='B' && Num_PWM==11){timerayar("TIM2");}		// Timer configurations for B11 pin
	else if(Mode_PWM=='B' && Num_PWM==13){timerayar("TIM1");}		// Timer configurations for B13 pin
	else if(Mode_PWM=='B' && Num_PWM==14){timerayar("TIM1");}		// Timer configurations for B14 pin
	else if(Mode_PWM=='B' && Num_PWM==15){timerayar("TIM1");}		// Timer configurations for B15 pin

	  TIMER_OCInitStructure.TIM_OCMode=TIM_OCMode_PWM1;								// Specifies the TIM mode
    TIMER_OCInitStructure.TIM_OutputState=TIM_OutputState_Enable;		// Enabling output state
    TIMER_OCInitStructure.TIM_OCPolarity=TIM_OCPolarity_High;				// Specifies the output polarity		

}

void timerayar(char *TIM){                                    //Timer config function created
	
		if(strcmp(TIM,"TIM1") == 0 ){                             //Condition for tim1
			
		RCC_APB1PeriphClockCmd(RCC_APB2Periph_TIM1,ENABLE);       //Apb1 Tim1 channel  opened	
		TIMERInitStructure.TIM_ClockDivision=TIM_CKD_DIV1;        //Clock deviation mode
    TIMERInitStructure.TIM_CounterMode=TIM_CounterMode_Up;    //Counting mode set	
    TIMERInitStructure.TIM_Period=1439;                       //Timer period selected	
    TIMERInitStructure.TIM_Prescaler=1000;                    //Timer Prescaler selected	
    TIMERInitStructure.TIM_RepetitionCounter=0;               //
    TIM_TimeBaseInit(TIM1,&TIMERInitStructure);               //Timer settings is set	 
    TIM_Cmd(TIM1,ENABLE);                                     //Timer is set
	}
		
		else if (strcmp(TIM,"TIM2") == 0 ){                       //Condition for tim2
			
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);       //Apb1 Tim2 channel opened		
		TIMERInitStructure.TIM_ClockDivision=TIM_CKD_DIV1;        //Clock deviation mode	
    TIMERInitStructure.TIM_CounterMode=TIM_CounterMode_Up;    //Counting mode set	
    TIMERInitStructure.TIM_Period=1439;                       //Timer period selected	
    TIMERInitStructure.TIM_Prescaler=1000;                    //Timer Prescaler selected	
    TIMERInitStructure.TIM_RepetitionCounter=0;								//
    TIM_TimeBaseInit(TIM2,&TIMERInitStructure);               //Timer settings is set	
    TIM_Cmd(TIM2,ENABLE);                                     //Timer is set
	}
		
		else if(strcmp(TIM,"TIM3") == 0 ){                        //Condition for tim3
			
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);       //Apb1 Tim3 channel  opened			
		TIMERInitStructure.TIM_ClockDivision=TIM_CKD_DIV1;        //Clock deviation mode
    TIMERInitStructure.TIM_CounterMode=TIM_CounterMode_Up;    //Counting mode set	
    TIMERInitStructure.TIM_Period=1439;                       //Timer period selected	
    TIMERInitStructure.TIM_Prescaler=1000;                    //Timer Prescaler selected	
    TIMERInitStructure.TIM_RepetitionCounter=0;								//
    TIM_TimeBaseInit(TIM3,&TIMERInitStructure);               //Timer settings is set	
    TIM_Cmd(TIM3,ENABLE);
	}
				
		else if(strcmp(TIM,"TIM4") == 0 ){                        //Condition for tim4
			
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4,ENABLE);       //Apb1 Tim4 channel  opened			
		TIMERInitStructure.TIM_ClockDivision=TIM_CKD_DIV1;        //Clock deviation mode
    TIMERInitStructure.TIM_CounterMode=TIM_CounterMode_Up;    //Counting mode set	
    TIMERInitStructure.TIM_Period=1439;                       //Timer period selected	
    TIMERInitStructure.TIM_Prescaler=1000;                    //Timer Prescaler selected	
    TIMERInitStructure.TIM_RepetitionCounter=0;								//
    TIM_TimeBaseInit(TIM4,&TIMERInitStructure);               //Timer settings is set	
    TIM_Cmd(TIM4,ENABLE);                                     //Timer is set
	}

}

void pwmconfigrest(uint16_t timPulse){															//Function that assigns the given pwm unit to the servo
	
    TIMER_OCInitStructure.TIM_Pulse=timPulse;												//Initializes the TIM_Pulse in the TIM_OCInitStruct.

	if(Mode_PWM=='A' && Num_PWM==0){																		//If the PIN = A0;
			TIM_OC1Init(TIM2,&TIMER_OCInitStructure);											  //Initializes the TIMx Channel1 according to the specified parameters in the TIM_OCInitStruct
			TIM_OC1PreloadConfig(TIM2,TIM_OCPreload_Enable);								//Activates and configs the TIM2 Channell's preload
	}
	else if(Mode_PWM=='A' && Num_PWM==1){																//If the PIN = A1;
			TIM_OC2Init(TIM2,&TIMER_OCInitStructure);												//Initializes the TIMx Channel1 according to the specified parameters in the TIM_OCInitStruct
			TIM_OC2PreloadConfig(TIM2,TIM_OCPreload_Enable);								//Activates and configs the TIM2 Channell's preload
	}
	else if(Mode_PWM=='A' && Num_PWM==2){																//If the PIN = A2;
			TIM_OC3Init(TIM2,&TIMER_OCInitStructure);												//Initializes the TIMx Channel1 according to the specified parameters in the TIM_OCInitStruct
			TIM_OC3PreloadConfig(TIM2,TIM_OCPreload_Enable);								//Activates and configs the TIM2 Channell's preload
	}
	else if(Mode_PWM=='A' && Num_PWM==3){																//If the PIN = A3;
			TIM_OC4Init(TIM2,&TIMER_OCInitStructure);												//Initializes the TIMx Channel1 according to the specified parameters in the TIM_OCInitStruct
			TIM_OC4PreloadConfig(TIM2,TIM_OCPreload_Enable);								//Activates and configs the TIM2 Channell's preload
	}
	else if(Mode_PWM=='A' && Num_PWM==6){																//If the PIN = A6;
			TIM_OC1Init(TIM3,&TIMER_OCInitStructure);												//Initializes the TIMx Channel1 according to the specified parameters in the TIM_OCInitStruct
			TIM_OC1PreloadConfig(TIM2,TIM_OCPreload_Enable);								//Activates and configs the TIM2 Channell's preload
	}
	else if(Mode_PWM=='A' && Num_PWM==7){																//If the PIN = A7;
			TIM_OC2Init(TIM3,&TIMER_OCInitStructure);												//Initializes the TIMx Channel1 according to the specified parameters in the TIM_OCInitStruct
			TIM_OC2PreloadConfig(TIM3,TIM_OCPreload_Enable);								//Activates and configs the TIM3 Channell's preload
	}
	else if(Mode_PWM=='A' && Num_PWM==8){																//If the PIN = A8;
			TIM_OC1Init(TIM1,&TIMER_OCInitStructure);												//Initializes the TIMx Channel1 according to the specified parameters in the TIM_OCInitStruct
			TIM_OC1PreloadConfig(TIM1,TIM_OCPreload_Enable);								//Activates and configs the TIM1 Channell's preload
	}
	else if(Mode_PWM=='A' && Num_PWM==9){																//If the PIN = A9;
			TIM_OC2Init(TIM1,&TIMER_OCInitStructure);												//Initializes the TIMx Channel1 according to the specified parameters in the TIM_OCInitStruct.
			TIM_OC2PreloadConfig(TIM1,TIM_OCPreload_Enable);								//Activates and configs the TIM1 Channell's preload
	}
	else if(Mode_PWM=='A' && Num_PWM==10){															//If the PIN = A10;
			TIM_OC3Init(TIM1,&TIMER_OCInitStructure);												//Initializes the TIMx Channel1 according to the specified parameters in the TIM_OCInitStruct.
			TIM_OC3PreloadConfig(TIM1,TIM_OCPreload_Enable);								//Activates and configs the TIM1 Channell's preload
	}
	else if(Mode_PWM=='A' && Num_PWM==11){															//If the PIN = A11;
			TIM_OC4Init(TIM1,&TIMER_OCInitStructure);												//Initializes the TIMx Channel1 according to the specified parameters in the TIM_OCInitStruct.
			TIM_OC4PreloadConfig(TIM1,TIM_OCPreload_Enable);								//Activates and configs the TIM1 Channell's preload
	}
	else if(Mode_PWM=='A' && Num_PWM==15){															//If the PIN = A15;
			TIM_OC1Init(TIM2,&TIMER_OCInitStructure);												//Initializes the TIMx Channel1 according to the specified parameters in the TIM_OCInitStruct.
			TIM_OC1PreloadConfig(TIM2,TIM_OCPreload_Enable);								//Activates and configs the TIM2 Channell's preload
	}
	else if(Mode_PWM=='B' && Num_PWM==0){																//If the PIN = B0;
			TIM_OC3Init(TIM3,&TIMER_OCInitStructure);												//Initializes the TIMx Channel1 according to the specified parameters in the TIM_OCInitStruct.
			TIM_OC3PreloadConfig(TIM3,TIM_OCPreload_Enable);								//Activates and configs the TIM3 Channell's preload
	}
	else if(Mode_PWM=='B' && Num_PWM==1){																//If the PIN = B1;
			TIM_OC4Init(TIM3,&TIMER_OCInitStructure);												//Initializes the TIMx Channel1 according to the specified parameters in the TIM_OCInitStruct.
			TIM_OC4PreloadConfig(TIM3,TIM_OCPreload_Enable);								//Activates and configs the TIM3 Channell's preload
	}
	else if(Mode_PWM=='B' && Num_PWM==3){																//If the PIN = B3;
			TIM_OC2Init(TIM2,&TIMER_OCInitStructure);												//Initializes the TIMx Channel1 according to the specified parameters in the TIM_OCInitStruct.
			TIM_OC2PreloadConfig(TIM2,TIM_OCPreload_Enable);								//Activates and configs the TIM2 Channell's preload
	}
	else if(Mode_PWM=='B' && Num_PWM==4){																//If the PIN = B4;
			TIM_OC1Init(TIM3,&TIMER_OCInitStructure);												//Initializes the TIMx Channel1 according to the specified parameters in the TIM_OCInitStruct.
			TIM_OC1PreloadConfig(TIM3,TIM_OCPreload_Enable);								//Activates and configs the TIM3 Channell's preload
	}
	else if(Mode_PWM=='B' && Num_PWM==5){																//If the PIN = B5;
			TIM_OC2Init(TIM3,&TIMER_OCInitStructure);												//Initializes the TIMx Channel1 according to the specified parameters in the TIM_OCInitStruct.
			TIM_OC2PreloadConfig(TIM3,TIM_OCPreload_Enable);								//Activates and configs the TIM3 Channell's preload
	}
	else if(Mode_PWM=='B' && Num_PWM==10){															//If the PIN = B10;
			TIM_OC3Init(TIM2,&TIMER_OCInitStructure);												//Initializes the TIMx Channel1 according to the specified parameters in the TIM_OCInitStruct.
			TIM_OC3PreloadConfig(TIM2,TIM_OCPreload_Enable);								//Activates and configs the TIM2 Channell's preload
	}
	else if(Mode_PWM=='B' && Num_PWM==11){															//If the PIN = B11;
			TIM_OC4Init(TIM2,&TIMER_OCInitStructure);												//Initializes the TIMx Channel1 according to the specified parameters in the TIM_OCInitStruct.
			TIM_OC4PreloadConfig(TIM2,TIM_OCPreload_Enable);								//Activates and configs the TIM2 Channell's preload
	}
	else if(Mode_PWM=='B' && Num_PWM==13){															//If the PIN = B13;
			TIM_OC1Init(TIM1,&TIMER_OCInitStructure);												//Initializes the TIMx Channel1 according to the specified parameters in the TIM_OCInitStruct.
			TIM_OC1PreloadConfig(TIM1,TIM_OCPreload_Enable);								//Activates and configs the TIM1 Channell's preload
	}
	else if(Mode_PWM=='B' && Num_PWM==14){															//If the PIN = B14;
			TIM_OC2Init(TIM1,&TIMER_OCInitStructure);												//Initializes the TIMx Channel1 according to the specified parameters in the TIM_OCInitStruct.
			TIM_OC2PreloadConfig(TIM1,TIM_OCPreload_Enable);								//Activates and configs the TIM1 Channell's preload
	}
	else if(Mode_PWM=='B' && Num_PWM==15){															//If the PIN = B15;
			TIM_OC3Init(TIM1,&TIMER_OCInitStructure);												//Initializes the TIMx Channel1 according to the specified parameters in the TIM_OCInitStruct.
			TIM_OC3PreloadConfig(TIM1,TIM_OCPreload_Enable);								//Activates and configs the TIM3 Channell's preload
	}
}

void Servo_Detach(){                     
	
		if(Mode_PWM=='A' && Num_PWM==0){                	   //Ao pin is disconnected 
				TIM_DeInit(TIM2);
		}
		else if( Mode_PWM=='A' & Num_PWM==1){                //A1 pin is disconnected 
					TIM_DeInit(TIM2);}
			
		else if(Mode_PWM=='A' && Num_PWM==2){                //A2 pin is disconnected 
				TIM_DeInit(TIM2);
		}
		else if(Mode_PWM=='A' && Num_PWM==3){                //A3 pin is disconnected 
				TIM_DeInit(TIM2);
		}
		else if(Mode_PWM=='A' && Num_PWM==6){                //A6 pin is disconnected 
				TIM_DeInit(TIM3);
		}
		else if(Mode_PWM=='A' && Num_PWM==7){                //A7 pin is disconnected 
				TIM_DeInit(TIM3);
		}
		else if(Mode_PWM=='A' && Num_PWM==8){                //A8 pin is disconnected 
				TIM_DeInit(TIM1);
		}
		else if(Mode_PWM=='A' && Num_PWM==9){                //A9 pin is disconnected  
				TIM_DeInit(TIM1);
		}
		else if(Mode_PWM=='A' && Num_PWM==10){               //A10 pin is disconnected 
				TIM_DeInit(TIM1);
		}
		else if(Mode_PWM=='A' && Num_PWM==11){               //A11 pin is disconnected 
				TIM_DeInit(TIM1);
		}
		else if(Mode_PWM=='A' && Num_PWM==15){               //A15 pin is disconnected 
				TIM_DeInit(TIM2);
		}
		else if(Mode_PWM=='B' && Num_PWM==0){                //B0 pin is disconnected 
				TIM_DeInit(TIM3);
		}
		else if(Mode_PWM=='B' && Num_PWM==1){                //B1 pin is disconnected 
				TIM_DeInit(TIM3);
		}
		else if(Mode_PWM=='B' && Num_PWM==3){                //B3 pin is disconnected 
				TIM_DeInit(TIM2);
		}
		else if(Mode_PWM=='B' && Num_PWM==4){                //B4 pin is disconnected 
				TIM_DeInit(TIM3); 
		}
		else if(Mode_PWM=='B' && Num_PWM==5){                //B5 pin is disconnected 
				TIM_DeInit(TIM3);
		}
		else if(Mode_PWM=='B' && Num_PWM==10){               //B10 pin is disconnected 
				 TIM_DeInit(TIM2);
		}
		else if(Mode_PWM=='B' && Num_PWM==11){               //B11 pin is disconnected 
				 TIM_DeInit(TIM2);
		}
		else if(Mode_PWM=='B' && Num_PWM==13){///            //B13 pin is disconnected 
				 TIM_DeInit(TIM1);
		}
		else if(Mode_PWM=='B' && Num_PWM==14){               //B14 pin is disconnected 
				TIM_DeInit(TIM1);
		}
		else if(Mode_PWM=='B' && Num_PWM==15){               //B15 pin is disconnected 
				TIM_DeInit(TIM1);
		}
}
			
void Servo_Degree(uint32_t Degree){													    //Servo_Degree Function is created
	
	pwmconfigrest( ((((Degree) *8)/10) + 36) );                   //Pwm numbers were placed between 0-180 degrees.
}

void Servo_DegreetoDegree(uint32_t Degree1, uint32_t Degree2){  //Servo DegreetoDegree Function is created

	Servo_Degree(Degree1); 																			  // First value sent to servo
	Servo_Delay(20000000);																			  // The time required for servo movement has been written
	Servo_Degree(Degree2);																		 	  //  Second value sent to servo
}

void Servo_GPIO_Speed(uint16_t Gpio_Speed){ 

		if(Gpio_Speed==2){																					//For condition created 2 MHz
			
				GPIOInitStructure.GPIO_Speed=GPIO_Speed_2MHz;           //Servo gpio speed changed
		}	
		else if(Gpio_Speed==50){																		//For condition created 50 MHz
			
				GPIOInitStructure.GPIO_Speed=GPIO_Speed_50MHz;          //Servo gpio speed changed
		}
 		else if(Gpio_Speed==10){																		//For condition created 10 MHz
	
				GPIOInitStructure.GPIO_Speed=GPIO_Speed_10MHz;          //Servo gpio speed changed
		}
}

void uartTransmit(char *string){
	
   while(*string){
      while(!(USART1->SR & 0x00000040));
      USART_SendData(USART1,*string);
      *string++;
   }
}

void uartReceive(){
	while(USART1->SR & 32){
		dataBuffer[i] = USART_ReceiveData(USART1);
		if(dataBuffer[i] == '*'){
			for(i=0;i<20;i++){
				dataBuffer[i] = ' ';
			}
			i=0;
		}
		i++;
	}
}
