#include <SoftwareSerial.h>

const int Motor_E1 = 5;  // 控制馬達1轉速 digital pin 5 of Arduino (PWM) 

const int Motor_E2 = 6; // 控制馬達2轉速 digital pin 6 of Arduino (PWM)   

const int Motor_M1 = 10;     // 控制馬達1正反轉 digital pin 10 of Arduino

const int Motor_M2 = 11;    // 控制馬達2正反轉 digital pin 11 of Arduino

char val;  // 接收來自藍芽資料

 void setup() 

{

  // Start serial communication at 57600 baud rate(傳輸率)

  Serial.begin(57600);

  pinMode(Motor_M1, OUTPUT); //設定 Motor_M1為輸出腳位

  pinMode(Motor_M2, OUTPUT); //設定 Motor_M2為輸出腳位出

 }

 //////////// 主程式 ////////

void loop()

{  if(Serial.available())

  {    val = Serial.read();

     switch(val)    {

      case 'f':   // 前進

                forward(0, 255);

                break;

      case 'b':   // 後退

                backward(0, 255);

                break;

      case 'l':   // 左轉

                left(0, 255);

                break;

      case 'r':   // 右轉

                right(0, 255);

                break;

      case 's':   // 停止

                motorstop(0, 0);

                break;

    }  }

}
 void motorstop(byte flag, byte motorspeed)

{

  Serial.println("stop!");

  digitalWrite( Motor_E1, motorspeed);

  digitalWrite( Motor_E2, motorspeed);

 }

 void forward(byte flag, byte motorspeed)

{

  Serial.println("forward!");

  digitalWrite( Motor_M1, HIGH);

  digitalWrite( Motor_M2, HIGH);

  analogWrite( Motor_E1, motorspeed);

  analogWrite( Motor_E2, motorspeed);

}

 void backward(byte flag, byte motorspeed)

{

  Serial.println("backward!");

  digitalWrite( Motor_M1, LOW);

  digitalWrite( Motor_M2, LOW);

  analogWrite( Motor_E1, motorspeed);

  analogWrite( Motor_E2, motorspeed);

 }

 void right(byte flag, byte motorspeed)

{

  Serial.println("right!"); 

  digitalWrite( Motor_M1, HIGH);

  digitalWrite( Motor_M2, HIGH);

  analogWrite( Motor_E1, 0);

  analogWrite( Motor_E2, motorspeed);

}

 void left(byte flag, byte motorspeed)

{

  Serial.println("left!"); 

  digitalWrite( Motor_M1, HIGH);

  digitalWrite( Motor_M2, HIGH);

  analogWrite( Motor_E1, motorspeed);

  analogWrite( Motor_E2, 0);

 }  