# Liek-Servo-Library  
Liek Servo Library is a library that makes it easy for you to drive servo motors with STM32F10x series cards.
The library is still ongoing and is released with its notes as updates become available.

# Update notes
Version 2.2
Servo_Config and Servo_Degree functions have arranged to work based on register.

Version 2.1
Servo_Detach function is added and delay function is enhanced for real time delay. ( Servo_Delay(1000)= 1 second )

Version 2.0.0
Servo motor adjustments are configured as struct. In this way, more than one servo definition is allowed. Due to some problems with the functions used for UART communication, it has been made a comment line. It is planned to be fixed in version 2.1.0. 

Version 1.7.1
Suitable for SG90 model servo motors. Functions that provide servo control with UART have been added and their configurations will be added later.
