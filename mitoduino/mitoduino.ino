#include <SoftwareSerial.h>
//SoftwareSerial BTSerial(2, 3); // 接收腳, 傳送腳
/* Input for motorA:
   IN1      IN2      Action
   LOW      LOW      Motor Stop
   HIGH     LOW      Motor moves forward  
   LOW      HIGH     Motor moves backward
   HIGH     HIGH     Motor Stop
*/   
const int motorIn1 = 6;//前輪
const int motorIn2 = 9;
const int motorIn3 = 10;//後輪      
const int motorIn4 = 11;  

int state = 0;
int value;

void setup()
{
  Serial.begin(9600);
  pinMode( motorIn1,OUTPUT);
  pinMode( motorIn2,OUTPUT);
  pinMode( motorIn3,OUTPUT);
  pinMode( motorIn4,OUTPUT);
  
}