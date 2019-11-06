/*
  Example_C_style.ino - Usage of the libraries Example
  Using the MonaV2 library in C style.
  Created by Bart Garcia, November 2019.
  bart.garcia.nathan@gmail.com
  Released into the public domain.
*/
//Include the MonaV2 librarie
#include <MonaV2_lib.h>

//Variables
int IR_value;
void setup()
{
	//Initialize the MonaV2 robot
	MonaV2_init();

}

void loop(){
	//Turn on LED2
	LED2_ON();
	//Read IR1 , the one in the front of the robot
	IR_value = Read_IR(1);
	//Turn on LED3 if IR value is less than 1000
	if(IR_value < 1000){
		LED3_ON();
	}
	else{
		LED3_OFF();
	}
	//Move forward for half a second
	Motors_forward();
	delay(500);
	//Stop motors
	Motors_stop();

}