//所用舵机可转向角度为270，但Servo.h封装默认为180封顶，因此180即为pwm占空比为满的情况，因此实际输入的1°是为270/180=1.5°
//小腿垂直  20
//大腿垂直  30
//摆幅  70
//小抬  30

#include <Servo.h>
#include <SoftwareSerial.h>
#define PIN_SERVO_BRJ 2 //后右肩
#define PIN_SERVO_BRF 3 //后右脚
#define PIN_SERVO_FRF 4 //前右脚
#define PIN_SERVO_FRJ 5 //前右肩
#define PIN_SERVO_FLJ 6 //前左肩
#define PIN_SERVO_FLF 7 //前左脚
#define PIN_SERVO_BLF 8 //后左脚
#define PIN_SERVO_BLJ 9 //后左肩

Servo myservoFLJ;
Servo myservoFRF;
Servo myservoFLF;
Servo myservoFRJ;
Servo myservoBLJ;
Servo myservoBRF;
Servo myservoBLF;
Servo myservoBRJ;

void leap_over(int i)
{
  for (int n = 0; n < i; n++)
  {
    //5.0跨绳
    control_pose(30, 160, 20, 110, 70, 160, 20, 150);//初始姿态
    delay(900);
    control_pose(30, 160, 20, 110, 70, 160, 80, 150);//左下抬
    delay(900);
    control_pose(30, 160, 20, 110, 70, 160, 80, 110);//左下前
    delay(900);
    control_pose(30, 160, 20, 110, 70, 160, 20, 110);//左下放
    delay(900);
    control_pose(30, 160, 20, 110, 70, 100, 20, 110);//左上抬
    delay(900);
    control_pose(30, 160, 20, 110, 40, 100, 20, 110);//左上前
    delay(900);
    control_pose(30, 160, 20, 110, 40, 160, 20, 110);//左上放
    delay(900);
    control_pose(30, 100, 20, 110, 40, 160, 20, 110);//右下抬
    delay(900);
    control_pose(70, 100, 20, 110, 40, 160, 20, 110);//右下前
    delay(900);
    control_pose(70, 160, 20, 110, 40, 160, 20, 110); //右下放
    delay(900);
    control_pose(70, 160, 80, 110, 40, 160, 20, 110);//右上抬
    delay(900);
    control_pose(70, 160, 80, 140, 40, 160, 20, 110);//右上前
    delay(900);
    control_pose(70, 160, 20, 140, 40, 160, 20, 110);//右上放
    delay(900);

    //    //4.0跨绳
    //    control_pose(40, 170, 0, 90, 40, 100, 20, 100);//左上抬大往前
    //    delay(900);
    //    control_pose(40, 180, 20, 90, 40, 160, 0, 100);//左上站,右下左下蹲,右上站
    //    delay(900);
    //    control_pose(40, 180, 80, 140, 40, 160, 0, 90);//右上抬大往前
    //    delay(900);
    //    control_pose(40, 160, 20, 140, 40, 160, 20, 90);//全体起立
    //    delay(900);
    //    control_pose(80, 100, 20, 80, 90, 160, 20, 140);//右下抬大往前，前进三
    //    delay(900);
    //    control_pose(80, 160, 20, 80, 90, 170, 10, 140);//右下站,左上左下蹲
    //    delay(900);
    //    control_pose(80, 160, 80, 140, 90, 180, 0, 140);//右上抬大往前
    //    delay(900);
    //    control_pose(80, 170, 20, 140, 90, 160, 10, 140);//右上站,右下左下蹲,左上站
    //    delay(900);
    //    control_pose(80, 170, 20, 140, 40, 100, 10, 140);//左上抬大往前
    //    delay(900);
    //    control_pose(80, 160, 20, 140, 40, 160, 20, 140);//全体起立
    //    delay(900);
    //    control_pose(40, 160, 20, 90, 80, 160, 80, 100);//左下抬大往前,前进三
    //    delay(900);
    //    control_pose(40, 170, 10, 90, 80, 160, 20, 100);//左下站,右上右下蹲
    //    delay(900);

    //3.0跨绳
    //    control_pose(90, 110, 20, 80, 40, 110, 20, 140);//左上右下抬大往前，左下右上往后
    //    delay(700);
    //    control_pose(90, 160, 20, 80, 40, 160, 20, 140);//左上右下放
    //    delay(700);
    //    control_pose(40, 160, 70, 140, 90, 160, 70, 90);//左上右下后，左下右上抬大往前
    //    delay(700);
    //    control_pose(40, 160, 20, 140, 90, 160, 20, 90);//左下右上放
    //    delay(700);
  }
}

void move_forward(int i)
{
  for (int n = 0; n < i; n++)
  {
    //    //4.0直走（垂直），延迟700ms
    //    control_pose(110, 130, 20, 70, 30, 130, 20, 150);//左上右下抬小往前，左下右上往后
    //    delay(700);
    //    control_pose(110, 160, 20, 70, 30, 160, 20, 150);//左上右下放
    //    delay(700);
    //    control_pose(30, 160, 50, 150, 110, 160, 50, 70);//左上右下后，左下右上抬小往前
    //    delay(700);
    //    control_pose(30, 160, 20, 150, 110, 160, 20, 70);//左下右上放
    //    delay(700);

    //4.0直走（非垂直）(小摆幅）//摆幅60->40，延迟500ms
    control_pose(90, 140, 20, 70, 70, 140, 20, 130);//左上.5.右下.1.抬小往前，左下.8右上.4往后
    delay(300);
    control_pose(90, 160, 20, 70, 70, 160, 20, 130);//左上右下放
    delay(200);
    control_pose(50, 160, 40, 110, 110, 160, 40, 90);//左上.5.右下.1.后，左下.8.右上.4.抬小往前
    delay(300);
    control_pose(50, 160, 20, 110, 110, 160, 20, 90);//左下右上放
    delay(200);

    //    //4.0直走（非垂直）(大摆幅）//摆幅120->80，延迟700ms
    //    control_pose(110, 130, 20, 70, 50, 130, 20, 130);//左上.5.右下.1.抬小往前，左下.8右上.4往后
    //    delay(700);
    //    control_pose(110, 160, 20, 70, 50, 160, 20, 130);//左上右下放
    //    delay(700);
    //    control_pose(50, 160, 50, 130, 110, 160, 50, 70);//左上.5.右下.1.后，左下.8.右上.4.抬小往前
    //    delay(700);
    //    control_pose(50, 160, 20, 130, 110, 160, 20, 70);//左下右上放
    //    delay(700);
  }
}

float P = 1;

int stpR = 0;

void PIDturn(int stpL)
{
  control_pose(45+stpL, 140, 20, 135-stpL, 45+stpL, 140, 20, 135-stpL);//左上.5.右下.1.抬小逆转45，左下.8右上.4顺转45
  delay(700);
  control_pose(45+stpL, 160, 20, 135-stpL, 45+stpL, 160, 20, 135-stpL);//左上右下放
  delay(700);
  control_pose(45, 160, 40, 135, 45, 160, 40, 135);//左上.5.右下.1.顺转45，左下.8.右上.4.抬小逆转45
  delay(700);
  control_pose(45, 160, 20, 135, 45, 160, 20, 135);//左下右上放
  delay(700);
}

void turn_leftFortiFIVE(int i)//半面向左转//摆幅45->30，延迟700ms
{
  for (int n = 0;  n <= i  ;  n++)
  {
    control_pose(75, 140, 20, 105, 75, 140, 20, 105);//左上.5.右下.1.抬小逆转45，左下.8右上.4顺转45
    delay(700);
    control_pose(75, 160, 20, 105, 75, 160, 20, 105);//左上右下放
    delay(700);
    control_pose(45, 160, 40, 135, 45, 160, 40, 135);//左上.5.右下.1.顺转45，左下.8.右上.4.抬小逆转45
    delay(700);
    control_pose(45, 160, 20, 135, 45, 160, 20, 135);//左下右上放
    delay(700);
  }
}

void turn_rightFortiFIVE(int i)//半面向右转
{
  for (int n = 0;  n <= i  ;  n++)
  {
    control_pose(45, 140, 20, 135, 45, 140, 20, 135);//左上.5.右下.1.抬小顺转45，左下.8右上.4逆转45
    delay(700);
    control_pose(45, 160, 20, 135, 45, 160, 20, 135);//左上右下放
    delay(700);
    control_pose(75, 160, 40, 105, 75, 160, 40, 105);//左上.5.右下.1.逆转45，左下.8.右上.4.抬小顺转45
    delay(700);
    control_pose(75, 160, 20, 105, 75, 160, 20, 105);//左下右上放
    delay(700);
  }
}

void control_pose(int angle1, int angle2, int angle3, int angle4, int angle5, int angle6, int angle7, int angle8)
{
  myservoBRJ.write(angle1);
  myservoBRF.write(angle2);
  myservoFRF.write(angle3);
  myservoFRJ.write(angle4);
  myservoFLJ.write(angle5);
  myservoFLF.write(angle6);
  myservoBLF.write(angle7);
  myservoBLJ.write(angle8);
}

SoftwareSerial mySerial(0, 1);

void setup()
{
  mySerial.begin(115200);
  myservoFLJ.attach(PIN_SERVO_FLJ);
  myservoFRF.attach(PIN_SERVO_FRF);
  myservoFLF.attach(PIN_SERVO_FLF);
  myservoFRJ.attach(PIN_SERVO_FRJ);
  myservoBLJ.attach(PIN_SERVO_BLJ);
  myservoBLF.attach(PIN_SERVO_BLF);
  myservoBRJ.attach(PIN_SERVO_BRJ);
  myservoBRF.attach(PIN_SERVO_BRF);
}

void loop()
{
  PIDturn(30);
  delay(10000);
  //  int act;
  //  act = (int)mySerial.read();
  //        switch (act)
  //  {
  //    case 0:
//        move_forward(5);
  //      break;
  //    case 1:
  //      turn_leftFortiFIVE(1);
  //      break;
  //    case 2:
//        turn_rightFortiFIVE(2);
  //      break;
  //    case 3:
  //      leap_over(1);
  //      break;
  //  }
//  move_forward(3);
//  turn_leftFortiFIVE(2);
  //    control_pose(60, 160, 20, 120, 60, 160, 20, 120);//初始姿态
  //    control_pose(60, 180, 0, 120, 60, 180, 0, 120);//蹲
}
