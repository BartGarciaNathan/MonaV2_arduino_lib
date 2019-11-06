/*
  MonaV2_lib.h - Library of definitions and header file for the MonaV2 robot
  Created by Bart Garcia, November 2019.
  bart.garcia.nathan@gmail.com
  Released into the public domain.
*/

#ifndef MonaV2_lib_h
#define MonaV2_lib_h
#include "Arduino.h"

/* ----Pin Definitions for MonaV2----*/

//Motor Control 
//To move a motor the selected direction has to be set HIGH and the
//contrary direction low. Example: For right motor forward set:
// Mot_right_forward=HIGH and Mot_right_backward=LOW
#define Mot_right_forward  15
#define Mot_right_backward 4
#define Mot_left_forward   19
#define Mot_left_backward  18

//Motor Feedback
#define Mot_right_feedback	27 //Pulses read from right motor encoder
#define Mot_left_feedback	13 //Pulses read from left motor encoder

//IR Sensors
#define IR_enable			26	//Enable the IR sensors by setting to HIGH
#define IR1_sensor			34	//Front IR sensor
#define IR2_sensor			35	//Left 35 degree IR sensor
#define IR3_sensor			39	//Right 35 degree IR sensor
#define IR4_sensor			32	//Right 70 degree sensor
#define IR5_sensor			36	//Left  70 degree sensor

//On board LEDs
#define LED_D2				25
#define LED_D3				23

//Battery Voltage
#define Batt_Vol_pin			33 //Analog read of the Battery Voltage

/* ----Library functions definitions for MonaV2 in C style----*/
//Mona Init function - setup pinModes
void MonaV2_init(void);
//Right Motor
void Right_mot_forward(void);
void Right_mot_backward(void);
void Right_mot_stop(void);
//Left Motor
void Left_mot_forward(void);
void Left_mot_backward(void);
void Left_mot_stop(void);
//Both motors
void Motors_forward(void);
void Motors_backward(void);
void Motors_stop(void);
//IR sensors
void Enable_IR(void);
void Disable_IR(void);
int Read_IR(int IR_number);
//Battery Voltage
int Batt_Vol(void);
//LEDS control
void LED2_ON(void);
void LED2_OFF(void);
void LED3_ON(void);
void LED3_OFF(void);


/* ----Library interface definition for MonaV2 in Arduino Library style----*/
class MonaV2
{
  // user-accessible  interface
  public:
  //Mona constructor function - setup pinModes
  	MonaV2(void);
  //Right Motor
    void Right_mot_forward(void);
    void Right_mot_backward(void);
	void Right_mot_stop(void);
  //Left Motor
    void Left_mot_forward(void);
    void Left_mot_backward(void);
	void Left_mot_stop(void);
  //Both motors
    void Motors_forward(void);
    void Motors_backward(void);
	void Motors_stop(void);
  //IR sensors
  	void Enable_IR(void);
  	void Disable_IR(void);
  	int Read_IR(int IR_number);
  //Battery Voltage
  	int Batt_Vol(void);
  //LEDS control
  	void LED2_ON(void);
  	void LED2_OFF(void);
  	void LED3_ON(void);
  	void LED3_OFF(void);
   
  // library-accessible  interface
  private:
    int value;
};


#endif