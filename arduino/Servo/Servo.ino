#include <Servo.h>
//#define PIN_SERVOFLJ A5//前左肩

#define PIN_SERVO 11

//Servo myservoFLJ;
Servo myservo;

void setup()
{
  Serial.begin(9600);
  //myservoFLJ.attach(PIN_SERVOFLJ);
  myservo.attach(PIN_SERVO);
}

void loop()
{
  int angleL =180;
  //myservoFLJ.write(angleL);
  myservo.write(angleL);
  delay(1000);
//  angleL =90;
//  //myservoFLJ.write(angleL);
// myservo.write(angleL);
//  delay(1000);
}
