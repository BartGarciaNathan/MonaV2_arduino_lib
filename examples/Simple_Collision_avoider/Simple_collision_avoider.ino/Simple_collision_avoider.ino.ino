/*
  Simple_collision_avoider.ino - Usage of the libraries Example
  Using the MonaV2 library in C style.
  Created by Bart Garcia, December 2019.
  bart.garcia.nathan@gmail.com
  Released into the public domain.
*/
//Include the MonaV2 librarie
#include <MonaV2_lib.h>

//Variables
int IR_value;
int IR_values[5] = {0, 0, 0, 0, 0};
//State Machine Variable
// 0 -move forward , 1 - forward obstacle , 2 - right proximity , 3 - left proximity
int state, old_state;
///The value of 3000 of the IR is a distance of around 2-3 cm, larger number is a bigger distance.
int distance_threshold = 3000;
void setup()
{
	//Initialize the MonaV2 robot
	MonaV2_init();
  //Serial.begin(115200);//Setting up serial for communication
  //Enable the IR sensors
  Enable_IR();
  //Initialize variables
  state=0;
  old_state=0;

}

void loop(){
  //--------------Motors------------------------
  //Set motors movement based on the state machine value. 
  //Use the LEDs as indicators of motors movement.
  if(state == 0){
    // Start moving Forward
    Motors_forward(200);
    LED3_OFF();
    LED2_OFF();
  }
  if(state == 1){
    //Spin to the left
    Motors_spin_left(100);
    //Turn on LED2
    LED2_ON();
    LED3_OFF();
  }
    if(state == 2){
    //Spin to the left
    Motors_spin_left(100);
    //Turn on LED2
    LED2_ON();
    LED3_OFF();
  }
    if(state == 3){
    //Spin to the right
    Motors_spin_right(100);
    //Turn on LED2
    LED3_ON();
    LED2_OFF();
  }
  //--------------IR sensors------------------------
  //Decide future state:
	//Read IR values to determine maze walls
	IR_value = Read_IR(1);
  IR_values[0] = Read_IR(4);
  IR_values[1] = Read_IR(2);
  IR_values[2] = Read_IR(1);
  IR_values[3] = Read_IR(3);
  IR_values[4] = Read_IR(5);

  //Transform to discrete wall or not wall
  if(IR_values[0]<= distance_threshold){
    IR_values[0] = 1;
  }else {
    IR_values[0] = 0;
  }
  if(IR_values[1]<= distance_threshold){
    IR_values[1] = 1;
  }else {
    IR_values[1] = 0;
  }
  if(IR_values[2]<= distance_threshold){
    IR_values[2] = 1;
  }else {
    IR_values[2] = 0;
  }
  if(IR_values[3]<= distance_threshold){
    IR_values[3] = 1;
  }else {
    IR_values[3] = 0;
  }
  if(IR_values[4]<= distance_threshold){
    IR_values[4] = 1;
  }else {
    IR_values[4] = 0;
  }
  //--------------State Machine------------------------
  //Use the retrieved IR values to set state
  //Check for frontal wall, which has priority
  if(IR_values[1]==1 or IR_values[2]==1 or IR_values[3]==1){
    state=1;
  }
  else if(IR_values[0]==1){ //Check for left proximity
    state=3;
  }
  else if(IR_values[4]==1){// Check for right proximity
    state=2;
  }
  else{ //If there are no proximities, move forward
    state=0;
  }

  delay(50);

}
