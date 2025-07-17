
#include <PPMReader.h>
//Global Pins Assignment for motor pins, and motor enable pins
//IN1-IN4 pins can be connected to both digital and analog pins
//EN1-EN2 pins to be connected to D3, D5, D6, D9, D10, or D11

//Motor Pin Constants
const int L_FwdPin_1 = 12;
const int L_BwdPin_2 = 12;
const int L_FwdPin_3 = 9;
const int L_BwdPin_4 = 8;

const int R_FwdPin_1 = 12;
const int R_BwdPin_2 = 12;
const int R_FwdPin_3 = 10;
const int R_BwdPin_4 = 11;

const int L_EN = 6;
const int R_EN = 5;

//Encoder Pin Constants
const int ENC_Left_A = 4;
const int ENC_Left_B = 4;

const int ENC_Right_A = 4;
const int ENC_Right_B = 4;

int enc_time_delay = 20; //in milliseconds

int counter = 0;
int oldCounter = 0;

int aState;
int aLastState;
int aStepSpeed = 0;

int counter_RIGHT = 0;

int aState_RIGHT;
int aLastState_RIGHT;
int aStepSpeed_RIGHT = 0;


//Controller settings, do not change
byte interruptPin = 3;
byte channelAmount = 8;
PPMReader ppm(interruptPin, channelAmount);


void setup() {
  //Motor Pin Setup
  pinMode(L_FwdPin_1, OUTPUT);
  pinMode(L_BwdPin_2, OUTPUT);
  pinMode(L_FwdPin_3, OUTPUT);
  pinMode(L_BwdPin_4, OUTPUT);
  
  pinMode(R_FwdPin_1, OUTPUT);
  pinMode(R_BwdPin_2, OUTPUT);
  pinMode(R_FwdPin_3, OUTPUT);
  pinMode(R_BwdPin_4, OUTPUT);
  
  pinMode(L_EN, OUTPUT);
  pinMode(R_EN, OUTPUT);

  //Encoder Pin Setup

  pinMode(ENC_Left_A, INPUT);
  pinMode(ENC_Left_B, INPUT);

  pinMode(ENC_Right_A, INPUT);
  pinMode(ENC_Right_B, INPUT);

  Serial.begin(9600);

  aLastState = digitalRead(ENC_Left_A);
  
  aLastState_RIGHT = digitalRead(ENC_Right_A);
}

int readEncoderLeft(){
  aState = digitalRead(ENC_Left_A);
  if(aState != aLastState){
    if(digitalRead(ENC_Left_B) != aState) {
      counter++;
    } else {
      counter--;
    }
//    Serial.print("Position_Left: ");
//    Serial.println(counter);
  }
  aLastState = aState;
  
  return counter;
}

int readEncoderRight(){
  aState_RIGHT = digitalRead(ENC_Right_A);
  if(aState_RIGHT != aLastState_RIGHT){
    if(digitalRead(ENC_Right_B) != aState_RIGHT) {
      counter_RIGHT++;
    } else {
      counter_RIGHT--;
    }
//    Serial.print("Position_RIGHT: ");
//    Serial.println(counter_RIGHT);
  }
  aLastState_RIGHT = aState_RIGHT;
  return counter_RIGHT;
}


//int test = 0;
//int loops = 3;

int readChannel(int channelNumber) {
  unsigned value = ppm.latestValidChannelValue(channelNumber, 0);
  //Serial.print(value);
  //Serial.print(", ");
  return value;
}

int speed_Value = 1;
void loop() {


    int c1 = readChannel(5);
    int c2 = readChannel(6);
    
    int c3 = readChannel(7);
    int c4 = readChannel(8);

    int swA = readChannel(9);
  
    delay(10);

    
    
    if(c2 > 1700){
        move_Forward();
        speed_Value = 2;
    } 

    else if(c2 < 1300){
        move_Backward();
        speed_Value = 2;
        
    } else if(c1 > 1700){
        rotate_Clockwise();
        speed_Value = 3;
    } 
    else if (c1 < 1300){
        rotate_CounterClockwise();
        speed_Value = 3;
    } else{
        stop_Move();
    }
      
    analogWrite(L_EN,300/speed_Value);
    analogWrite(R_EN,280/speed_Value);  

    Serial.println(swA);
//    stop_Move();
//    int yes = 0;
//    if
//    yes = readEncoderRight();  
//    aStepSpeed = (oldCounter - yes)/(enc_time_delay*loops);
//    delay(enc_time_delay);
//    if(test >= loops){
//      oldCounter = yes;
//      test = 0;
//    } else{
//      test++;
//    }

}
