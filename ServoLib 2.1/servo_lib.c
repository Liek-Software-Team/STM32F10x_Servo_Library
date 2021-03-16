/***************************
@author: Liek
@version: 2.1
@date: 16.03.2021

***************************/

#include "stm32f10x.h"  						                   
#include "servo_lib.h"

GPIO_InitTypeDef ServoGPIOInitStructure;
TIM_TimeBaseInitTypeDef TIMERInitStructure;
TIM_OCInitTypeDef TIMER_OCInitStructure;	

uint32_t counter=0;

void systemClockEnable(){
	SystemCoreClockUpdate();
	SysTick_Config(SystemCoreClock/1000);
}

void SysTick_Handler(){
	if(counter>0){
		counter--;
	}
}

void Servo_Delay(uint32_t time){
	systemClockEnable();
	counter=time;
	while(counter);
}

void timer_configure(uint16_t TIM){                                    //Timer config function created
	
		if( TIM == 1 ){                             //Condition for tim1
			
		RCC_APB1PeriphClockCmd(RCC_APB2Periph_TIM1,ENABLE);       //Apb1 Tim1 channel  opened	
		TIMERInitStructure.TIM_ClockDivision=TIM_CKD_DIV1;        //Clock deviation mode
    TIMERInitStructure.TIM_CounterMode=TIM_CounterMode_Up;    //Counting mode set	
    TIMERInitStructure.TIM_Period=1439;                       //Timer period selected	
    TIMERInitStructure.TIM_Prescaler=1000;                    //Timer Prescaler selected	
    TIMERInitStructure.TIM_RepetitionCounter=0;               //
    TIM_TimeBaseInit(TIM1,&TIMERInitStructure);               //Timer settings is set	 
    TIM_Cmd(TIM1,ENABLE);                                     //Timer is set
	}
		
		else if (TIM == 2 ){                       //Condition for tim2
			
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);       //Apb1 Tim2 channel opened		
		TIMERInitStructure.TIM_ClockDivision=TIM_CKD_DIV1;        //Clock deviation mode	
    TIMERInitStructure.TIM_CounterMode=TIM_CounterMode_Up;    //Counting mode set	
    TIMERInitStructure.TIM_Period=1439;                       //Timer period selected	
    TIMERInitStructure.TIM_Prescaler=1000;                    //Timer Prescaler selected	
    TIMERInitStructure.TIM_RepetitionCounter=0;								//
    TIM_TimeBaseInit(TIM2,&TIMERInitStructure);               //Timer settings is set	
    TIM_Cmd(TIM2,ENABLE);                                     //Timer is set
	}
		
		else if(TIM == 3 ){                        //Condition for tim3
			
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);       //Apb1 Tim3 channel  opened			
		TIMERInitStructure.TIM_ClockDivision=TIM_CKD_DIV1;        //Clock deviation mode
    TIMERInitStructure.TIM_CounterMode=TIM_CounterMode_Up;    //Counting mode set	
    TIMERInitStructure.TIM_Period=1439;                       //Timer period selected	
    TIMERInitStructure.TIM_Prescaler=1000;                    //Timer Prescaler selected	
    TIMERInitStructure.TIM_RepetitionCounter=0;								//
    TIM_TimeBaseInit(TIM3,&TIMERInitStructure);               //Timer settings is set	
    TIM_Cmd(TIM3,ENABLE);
	}
				
		else if(TIM == 4 ){                        //Condition for tim4
			
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

void Servo_Conf(Servo Port_Pin){

	  if( Port_Pin.port == GPIOA){														
																
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);			
		}
	
		else if( Port_Pin.port == GPIOB){														
																
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);			
		}
		
		else if( Port_Pin.port == GPIOC){														
																
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);			
		}
		else if( Port_Pin.port == GPIOD){													
																
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD,ENABLE);			
		}
		else if( Port_Pin.port == GPIOE){														 
																
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);		
		}
		else if( Port_Pin.port == GPIOF){												
																
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOF,ENABLE);			
		}
		else if( Port_Pin.port == GPIOG){														
																
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOG,ENABLE);			
		}

		
	
	
		ServoGPIOInitStructure.GPIO_Pin= Port_Pin.pin;
		ServoGPIOInitStructure.GPIO_Mode= GPIO_Mode_AF_PP;
		ServoGPIOInitStructure.GPIO_Speed= GPIO_Speed_50MHz;
		
		GPIO_Init(Port_Pin.port,&ServoGPIOInitStructure);		
		
	   	 if(Port_Pin.port == GPIOA && Port_Pin.pin == GPIO_Pin_0) {timer_configure(2);}		// Timer configurations for A0 pin
	else if(Port_Pin.port == GPIOA && Port_Pin.pin == GPIO_Pin_1) {timer_configure(2);}		// Timer configurations for A1 pin				
	else if(Port_Pin.port == GPIOA && Port_Pin.pin == GPIO_Pin_2) {timer_configure(2);}		// Timer configurations for A2 pin			
	else if(Port_Pin.port == GPIOA && Port_Pin.pin == GPIO_Pin_3) {timer_configure(2);}		// Timer configurations for A3 pin	
	else if(Port_Pin.port == GPIOA && Port_Pin.pin == GPIO_Pin_6) {timer_configure(3);}		// Timer configurations for A6 pin
	else if(Port_Pin.port == GPIOA && Port_Pin.pin == GPIO_Pin_7) {timer_configure(3);}			// Timer configurations for A7 pin
	else if(Port_Pin.port == GPIOA && Port_Pin.pin == GPIO_Pin_8) {timer_configure(1);}		// Timer configurations for A8 pin		
	else if(Port_Pin.port == GPIOA && Port_Pin.pin == GPIO_Pin_9) {timer_configure(1);}			// Timer configurations for A9 pin
	else if(Port_Pin.port == GPIOA && Port_Pin.pin == GPIO_Pin_10){timer_configure(1);}			// Timer configurations for A10 pin
	else if(Port_Pin.port == GPIOA && Port_Pin.pin == GPIO_Pin_11){timer_configure(1);}			// Timer configurations for A11 pin
	else if(Port_Pin.port == GPIOA && Port_Pin.pin == GPIO_Pin_15){timer_configure(2);}		// Timer configurations for A15 pin
	else if(Port_Pin.port == GPIOB && Port_Pin.pin == GPIO_Pin_0) {timer_configure(3);}			// Timer configurations for B0 pin
	else if(Port_Pin.port == GPIOB && Port_Pin.pin == GPIO_Pin_1) {timer_configure(2);}		// Timer configurations for B1 pin
	else if(Port_Pin.port == GPIOB && Port_Pin.pin == GPIO_Pin_3) {timer_configure(2);}		// Timer configurations for B3 pin
	else if(Port_Pin.port == GPIOB && Port_Pin.pin == GPIO_Pin_4) {timer_configure(3);}			// Timer configurations for B4 pin
	else if(Port_Pin.port == GPIOB && Port_Pin.pin == GPIO_Pin_5) {timer_configure(3);}		// Timer configurations for B5 pin
	else if(Port_Pin.port == GPIOB && Port_Pin.pin == GPIO_Pin_10){timer_configure(2);}		// Timer configurations for B10 pin
	else if(Port_Pin.port == GPIOB && Port_Pin.pin == GPIO_Pin_11){timer_configure(2);}	// Timer configurations for B11 pin
	else if(Port_Pin.port == GPIOB && Port_Pin.pin == GPIO_Pin_13){timer_configure(1);}			// Timer configurations for B13 pin
	else if(Port_Pin.port == GPIOB && Port_Pin.pin == GPIO_Pin_14){timer_configure(1);}			// Timer configurations for B14 pin
	else if(Port_Pin.port == GPIOB && Port_Pin.pin == GPIO_Pin_15){timer_configure(1);}			// Timer configurations for B15 pin
	
		TIMER_OCInitStructure.TIM_OCMode=TIM_OCMode_PWM1;								// Specifies the TIM mode
    TIMER_OCInitStructure.TIM_OutputState=TIM_OutputState_Enable;		// Enabling output state
    TIMER_OCInitStructure.TIM_OCPolarity=TIM_OCPolarity_High;				// Specifies the output polarity
}


void Servo_Degree(Servo Port_Pin, uint16_t Degree){															//Function that assigns the given pwm unit to the servo
	
		uint16_t timPulse = ((((Degree) *8)/10) + 36);
    TIMER_OCInitStructure.TIM_Pulse=timPulse;												//Initializes the TIM_Pulse in the TIM_OCInitStruct.

	if( Port_Pin.port == GPIOA && Port_Pin.pin==GPIO_Pin_0){																		//If the PIN = A0;
			TIM_OC1Init(TIM2,&TIMER_OCInitStructure);											  //Initializes the TIMx Channel1 according to the specified parameters in the TIM_OCInitStruct
			TIM_OC1PreloadConfig(TIM2,TIM_OCPreload_Enable);								//Activates and configs the TIM2 Channell's preload
	}
	else if(Port_Pin.port == GPIOA && Port_Pin.pin==GPIO_Pin_1){																//If the PIN = A1;
			TIM_OC2Init(TIM2,&TIMER_OCInitStructure);												//Initializes the TIMx Channel1 according to the specified parameters in the TIM_OCInitStruct
			TIM_OC2PreloadConfig(TIM2,TIM_OCPreload_Enable);								//Activates and configs the TIM2 Channell's preload
	}
	else if(Port_Pin.port == GPIOA && Port_Pin.pin==GPIO_Pin_2){																//If the PIN = A2;
			TIM_OC3Init(TIM2,&TIMER_OCInitStructure);												//Initializes the TIMx Channel1 according to the specified parameters in the TIM_OCInitStruct
			TIM_OC3PreloadConfig(TIM2,TIM_OCPreload_Enable);								//Activates and configs the TIM2 Channell's preload
	}
	else if(Port_Pin.port == GPIOA && Port_Pin.pin==GPIO_Pin_3){																//If the PIN = A3;
			TIM_OC4Init(TIM2,&TIMER_OCInitStructure);												//Initializes the TIMx Channel1 according to the specified parameters in the TIM_OCInitStruct
			TIM_OC4PreloadConfig(TIM2,TIM_OCPreload_Enable);								//Activates and configs the TIM2 Channell's preload
	}
	else if(Port_Pin.port == GPIOA && Port_Pin.pin==GPIO_Pin_6){																//If the PIN = A6;
			TIM_OC1Init(TIM3,&TIMER_OCInitStructure);												//Initializes the TIMx Channel1 according to the specified parameters in the TIM_OCInitStruct
			TIM_OC1PreloadConfig(TIM2,TIM_OCPreload_Enable);								//Activates and configs the TIM2 Channell's preload
	}
	else if(Port_Pin.port == GPIOA && Port_Pin.pin==GPIO_Pin_7){																//If the PIN = A7;
			TIM_OC2Init(TIM3,&TIMER_OCInitStructure);												//Initializes the TIMx Channel1 according to the specified parameters in the TIM_OCInitStruct
			TIM_OC2PreloadConfig(TIM3,TIM_OCPreload_Enable);								//Activates and configs the TIM3 Channell's preload
	}
	else if(Port_Pin.port == GPIOA && Port_Pin.pin==GPIO_Pin_8){																//If the PIN = A8;
			TIM_OC1Init(TIM1,&TIMER_OCInitStructure);												//Initializes the TIMx Channel1 according to the specified parameters in the TIM_OCInitStruct
			TIM_OC1PreloadConfig(TIM1,TIM_OCPreload_Enable);								//Activates and configs the TIM1 Channell's preload
		
	}
	else if(Port_Pin.port == GPIOA && Port_Pin.pin==GPIO_Pin_9){																//If the PIN = A9;
			TIM_OC2Init(TIM1,&TIMER_OCInitStructure);												//Initializes the TIMx Channel1 according to the specified parameters in the TIM_OCInitStruct.
			TIM_OC2PreloadConfig(TIM1,TIM_OCPreload_Enable);								//Activates and configs the TIM1 Channell's preload
	}
	else if(Port_Pin.port == GPIOA && Port_Pin.pin==GPIO_Pin_10){															//If the PIN = A10;
			TIM_OC3Init(TIM1,&TIMER_OCInitStructure);												//Initializes the TIMx Channel1 according to the specified parameters in the TIM_OCInitStruct.
			TIM_OC3PreloadConfig(TIM1,TIM_OCPreload_Enable);								//Activates and configs the TIM1 Channell's preload
	}
	else if(Port_Pin.port == GPIOA && Port_Pin.pin==GPIO_Pin_11){															//If the PIN = A11;
			TIM_OC4Init(TIM1,&TIMER_OCInitStructure);												//Initializes the TIMx Channel1 according to the specified parameters in the TIM_OCInitStruct.
			TIM_OC4PreloadConfig(TIM1,TIM_OCPreload_Enable);								//Activates and configs the TIM1 Channell's preload
	}
	else if(Port_Pin.port == GPIOA && Port_Pin.pin==GPIO_Pin_15){															//If the PIN = A15;
			TIM_OC1Init(TIM2,&TIMER_OCInitStructure);												//Initializes the TIMx Channel1 according to the specified parameters in the TIM_OCInitStruct.
			TIM_OC1PreloadConfig(TIM2,TIM_OCPreload_Enable);								//Activates and configs the TIM2 Channell's preload
	}
	else if(Port_Pin.port == GPIOB && Port_Pin.pin==GPIO_Pin_0){																//If the PIN = B0;
			TIM_OC3Init(TIM3,&TIMER_OCInitStructure);												//Initializes the TIMx Channel1 according to the specified parameters in the TIM_OCInitStruct.
			TIM_OC3PreloadConfig(TIM3,TIM_OCPreload_Enable);								//Activates and configs the TIM3 Channell's preload
	}
	else if(Port_Pin.port == GPIOB && Port_Pin.pin==GPIO_Pin_1){																//If the PIN = B1;
			TIM_OC4Init(TIM3,&TIMER_OCInitStructure);												//Initializes the TIMx Channel1 according to the specified parameters in the TIM_OCInitStruct.
			TIM_OC4PreloadConfig(TIM3,TIM_OCPreload_Enable);								//Activates and configs the TIM3 Channell's preload
	}
	else if(Port_Pin.port == GPIOB && Port_Pin.pin==GPIO_Pin_3){																//If the PIN = B3;
			TIM_OC2Init(TIM2,&TIMER_OCInitStructure);												//Initializes the TIMx Channel1 according to the specified parameters in the TIM_OCInitStruct.
			TIM_OC2PreloadConfig(TIM2,TIM_OCPreload_Enable);								//Activates and configs the TIM2 Channell's preload
	}
	else if(Port_Pin.port == GPIOB && Port_Pin.pin==GPIO_Pin_4){																//If the PIN = B4;
			TIM_OC1Init(TIM3,&TIMER_OCInitStructure);												//Initializes the TIMx Channel1 according to the specified parameters in the TIM_OCInitStruct.
			TIM_OC1PreloadConfig(TIM3,TIM_OCPreload_Enable);								//Activates and configs the TIM3 Channell's preload
	}
	else if(Port_Pin.port == GPIOB && Port_Pin.pin==GPIO_Pin_5){																//If the PIN = B5;
			TIM_OC2Init(TIM3,&TIMER_OCInitStructure);												//Initializes the TIMx Channel1 according to the specified parameters in the TIM_OCInitStruct.
			TIM_OC2PreloadConfig(TIM3,TIM_OCPreload_Enable);								//Activates and configs the TIM3 Channell's preload
	}
	else if(Port_Pin.port == GPIOB && Port_Pin.pin==GPIO_Pin_10){															//If the PIN = B10;
			TIM_OC3Init(TIM2,&TIMER_OCInitStructure);												//Initializes the TIMx Channel1 according to the specified parameters in the TIM_OCInitStruct.
			TIM_OC3PreloadConfig(TIM2,TIM_OCPreload_Enable);								//Activates and configs the TIM2 Channell's preload
	}
	else if(Port_Pin.port == GPIOB && Port_Pin.pin==GPIO_Pin_11){															//If the PIN = B11;
			TIM_OC4Init(TIM2,&TIMER_OCInitStructure);												//Initializes the TIMx Channel1 according to the specified parameters in the TIM_OCInitStruct.
			TIM_OC4PreloadConfig(TIM2,TIM_OCPreload_Enable);								//Activates and configs the TIM2 Channell's preload
	}
	else if(Port_Pin.port == GPIOB && Port_Pin.pin==GPIO_Pin_13){															//If the PIN = B13;
			TIM_OC1Init(TIM1,&TIMER_OCInitStructure);												//Initializes the TIMx Channel1 according to the specified parameters in the TIM_OCInitStruct.
			TIM_OC1PreloadConfig(TIM1,TIM_OCPreload_Enable);								//Activates and configs the TIM1 Channell's preload
	}
	else if(Port_Pin.port == GPIOB && Port_Pin.pin==GPIO_Pin_14){															//If the PIN = B14;
			TIM_OC2Init(TIM1,&TIMER_OCInitStructure);												//Initializes the TIMx Channel1 according to the specified parameters in the TIM_OCInitStruct.
			TIM_OC2PreloadConfig(TIM1,TIM_OCPreload_Enable);								//Activates and configs the TIM1 Channell's preload
	}
	else if(Port_Pin.port == GPIOB && Port_Pin.pin==GPIO_Pin_15){															//If the PIN = B15;
			TIM_OC3Init(TIM1,&TIMER_OCInitStructure);												//Initializes the TIMx Channel1 according to the specified parameters in the TIM_OCInitStruct.
			TIM_OC3PreloadConfig(TIM1,TIM_OCPreload_Enable);								//Activates and configs the TIM3 Channell's preload
	}
}

void Servo_DegreetoDegree(Servo Port_Pin,uint16_t Degree1, uint16_t Degree2){  //Servo DegreetoDegree Function is created

	Servo_Degree(Port_Pin,Degree1); 																			  // First value sent to servo
	Servo_Delay(20000000);																			  // The time required for servo movement has been written
	Servo_Degree(Port_Pin,Degree2);		//  Second value sent to servo
}

void Servo_Detach(Servo Port_Pin){
	
	if( Port_Pin.port == GPIOA && Port_Pin.pin==GPIO_Pin_0){																		//If the PIN = A0;
		GPIOA->CRL &= ~(0xF);
	}
	
	else if(Port_Pin.port == GPIOA && Port_Pin.pin==GPIO_Pin_1){																//If the PIN = A1;
		GPIOA->CRL &= ~(0xF<<4);	
	}
	
	else if(Port_Pin.port == GPIOA && Port_Pin.pin==GPIO_Pin_2){																//If the PIN = A2;
		GPIOA->CRL &= ~(0xF<<8);
	}
	
	else if(Port_Pin.port == GPIOA && Port_Pin.pin==GPIO_Pin_3){																//If the PIN = A3;
		GPIOA->CRL &= ~(0xF<<12);	
	}
	
	else if(Port_Pin.port == GPIOA && Port_Pin.pin==GPIO_Pin_6){																//If the PIN = A6;
		GPIOA->CRL &= ~(0xF<<24);	
	}
	
	else if(Port_Pin.port == GPIOA && Port_Pin.pin==GPIO_Pin_7){																//If the PIN = A7;
		GPIOA->CRL &= ~(0xF<<28);	
	}
	
	else if(Port_Pin.port == GPIOA && Port_Pin.pin==GPIO_Pin_8){																//If the PIN = A8;
		GPIOA->CRH &= ~(0xF);
	}
	
	else if(Port_Pin.port == GPIOA && Port_Pin.pin==GPIO_Pin_9){																//If the PIN = A9;
		GPIOA->CRH &= ~(0xF<<4);
	}
	
	else if(Port_Pin.port == GPIOA && Port_Pin.pin==GPIO_Pin_10){															//If the PIN = A10;
		GPIOA->CRH &= ~(0xF<<8);
	}
	
	else if(Port_Pin.port == GPIOA && Port_Pin.pin==GPIO_Pin_11){															//If the PIN = A11;
		GPIOA->CRH &= ~(0xF<<12);	
	}
	
	else if(Port_Pin.port == GPIOA && Port_Pin.pin==GPIO_Pin_15){															//If the PIN = A15;
		GPIOA->CRH &= ~(0xF<<28);
	}
	
	else if(Port_Pin.port == GPIOB && Port_Pin.pin==GPIO_Pin_0){																//If the PIN = B0;
		GPIOB->CRL &= ~(0xF);
	}
	
	else if(Port_Pin.port == GPIOB && Port_Pin.pin==GPIO_Pin_1){																//If the PIN = B1;
		GPIOB->CRL &= ~(0xF<<4);
	}
	
	else if(Port_Pin.port == GPIOB && Port_Pin.pin==GPIO_Pin_3){																//If the PIN = B3;
		GPIOB->CRL &= ~(0xF<<12);
	}
	
	else if(Port_Pin.port == GPIOB && Port_Pin.pin==GPIO_Pin_4){																//If the PIN = B4;
		GPIOB->CRL &= ~(0xF<<16);	
	}
	
	else if(Port_Pin.port == GPIOB && Port_Pin.pin==GPIO_Pin_5){																//If the PIN = B5;
		GPIOB->CRL &= ~(0xF<<20);	
	}
	
	else if(Port_Pin.port == GPIOB && Port_Pin.pin==GPIO_Pin_10){															//If the PIN = B10;
		GPIOB->CRH &= ~(0xF<<8);
	}
	
	else if(Port_Pin.port == GPIOB && Port_Pin.pin==GPIO_Pin_11){															//If the PIN = B11;
		GPIOB->CRH &= ~(0xF<<12);
	}
	
	else if(Port_Pin.port == GPIOB && Port_Pin.pin==GPIO_Pin_13){															//If the PIN = B13;
		GPIOB->CRH &= ~(0xF<<20);
	}
	
	else if(Port_Pin.port == GPIOB && Port_Pin.pin==GPIO_Pin_14){															//If the PIN = B14;
		GPIOB->CRH &= ~(0xF<<24);
	}
	
	else if(Port_Pin.port == GPIOB && Port_Pin.pin==GPIO_Pin_15){															//If the PIN = B15;
		GPIOB->CRH &= ~(0xF<<28);
	}
}


/*
GPIO_InitTypeDef GPIOInitStructure;
char message[20];
char dataBuffer[20] = "Hello";

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
*/

/*		
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
*/
