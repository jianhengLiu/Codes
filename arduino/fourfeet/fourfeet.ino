//所用舵机可转向角度为270，但Servo.h封装默认为180封顶，因此180即为pwm占空比为满的情况，因此实际输入的1°是为270/180=1.5°
//小腿垂直  20
//大腿垂直  30
//摆幅  70
//小抬  30

#include <Servo.h>
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
    //3.0跨绳
    control_pose(110, 70, 30, 70, 10, 90, 10, 170);//左上右下抬大往前，左下右上往后
    delay(500);
    control_pose(110, 140, 30, 70, 10, 160, 10, 170);//左上右下放
    delay(500);
    control_pose(10, 140, 100, 170, 100, 160, 80, 70);//左上右下后，左下右上抬大往前
    delay(500);
    control_pose(10, 140, 30, 170, 100, 160, 10, 70);//左下右上放
    delay(500);
  }
}

void move_forward(int i)
{
  for (int n = 0; n < i; n++)
  {
    //2.0
    //    control_pose(10, 140, 100, 170, 10, 160, 20, 170);//右上抬大
    //    delay(300);
    //    control_pose(10, 140, 100, 170, 10, 160, 80, 70);//左下抬大往前
    //    delay(300);
    //    control_pose(10, 140, 30, 170, 10, 160, 20, 70);//左下右上放腿
    //    delay(300);
    //    control_pose(10, 140, 30, 170, 10, 90, 20, 70);//左上抬小//大
    //    delay(300);
    //    control_pose(10, 140, 30, 70, 10, 100, 20, 170);//左下右上往后
    //    delay(300);
    //    control_pose(110, 70, 30, 70, 10, 100, 20, 170); //右下抬大往前           ，左上抬大
    //    delay(300);
    //        control_pose(110, 140, 30, 70, 10, 160, 20, 170);//左上右下放腿                ，右上抬大，左下抬小
    //        delay(300);
    //    control_pose(110, 140, 100, 170, 10, 160, 40, 170);//右上抬大，左下抬小
    //    delay(300);
    //    control_pose(10, 140, 60, 170, 100, 160, 40, 170);//左上右下后
    //    delay(300);
    //    control_pose(10, 140, 30, 170, 100, 160, 20, 170);//左下右上放腿
    //    delay(300);
    //    control_pose(10, 140, 30, 170, 10, 90, 20, 170);//左上抬大前
    //    delay(300);
    //    control_pose(10, 140, 30, 170, 10, 160, 20, 170);//左上放
    //    delay(300);

    //4.0直走（垂直），延迟700ms
    control_pose(110, 130, 20, 70, 30, 130, 20, 150);//左上右下抬小往前，左下右上往后
    delay(700);
    control_pose(110, 160, 20, 70, 30, 160, 20, 150);//左上右下放
    delay(700);
    control_pose(30, 160, 50, 150, 110, 160, 50, 70);//左上右下后，左下右上抬大往前
    delay(700);
    control_pose(30, 160, 20, 150, 110, 160, 20, 70);//左下右上放
    delay(700);

    //4.0直走（非垂直）(小摆幅）//摆幅60->40，延迟500ms
    control_pose(110, 130, 20, 70, 70, 130, 20, 110);//左上.5.右下.1.抬小往前，左下.8右上.4往后
    delay(500);
    control_pose(110, 160, 20, 70, 70, 160, 20, 110);//左上右下放
    delay(500);
    control_pose(70, 160, 50, 110, 110, 160, 50, 70);//左上.5.右下.1.后，左下.8.右上.4.抬大往前
    delay(500);
    control_pose(70, 160, 20, 110, 110, 160, 20, 70);//左下右上放
    delay(500);

    //4.0直走（非垂直）(大摆幅）//摆幅120->80，延迟700ms
    control_pose(110, 130, 20, 70, 50, 130, 20, 130);//左上.5.右下.1.抬小往前，左下.8右上.4往后
    delay(700);
    control_pose(110, 160, 20, 70, 50, 160, 20, 130);//左上右下放
    delay(700);
    control_pose(50, 160, 50, 130, 110, 160, 50, 70);//左上.5.右下.1.后，左下.8.右上.4.抬大往前
    delay(700);
    control_pose(50, 160, 20, 130, 110, 160, 20, 70);//左下右上放
    delay(700);

    //1.0普通前进
    //    control_pose(10, 160, 50, 170, 20, 160, 30, 70);//右上左下抬,左下前//
    //    delay(1000);//
    //    control_pose(10, 160, 20, 170, 20, 160, 0, 70);//右上左下放//
    //    delay(300);//
    //    control_pose(10, 130, 20, 170, 20, 130, 0, 70);//右下左上抬腿//
    //    delay(300);
    //    control_pose(110, 130, 20, 70, 20, 130, 0, 170);//右上左下后,右下前//
    //    delay(300);
    //    control_pose(110, 160, 20, 70, 20, 160, 0, 170);//右下左上放//
    //    delay(300);
    //    control_pose(110, 160, 50, 170, 20, 160, 30, 170);//左下右上抬,右上前//
    //    delay(300);
    //    control_pose(10, 160, 50, 170, 110, 160, 30, 170); //右下左上后//
    //    delay(300);
    //    control_pose(10, 160, 20, 170, 110, 160, 10, 170); //右上左下放腿//
    //    delay(300);
    //    control_pose(10, 160, 20, 170, 110, 130, 10, 170);//左上抬
    //    delay(300);
    //    control_pose(10, 160, 20, 170, 10, 160, 10, 170);//左上前,放
    //    delay(300);
  }
}

void turn_rightFortiFIVE(int i)//半面向右转
{
  for (int n = 0;  n <= i  ;  n++)
  {
    control_pose(45, 160, 0, 135, 45, 160, 0, 135);//初始姿态
    delay(300);
    control_pose(45, 160, 50, 90, 45, 160, 30, 90);//左下右上抬腿，右转45°
    delay(1000);
    control_pose(0, 130, 20, 90, 0, 130, 0, 90);//右上左下放,同时右下左上上抬
    delay(1000);
    control_pose(0, 130, 50, 90, 0, 130, 30, 90);//左上右下抬腿，右转45°
    delay(300);
    control_pose(0, 160, 20, 90, 0, 160, 0, 90); //右下左上放
    delay(1000);
    control_pose(0, 160, 50, 135, 0, 160, 30, 135); //右上左下收，但脚不抬起来
    delay(1000);
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

void setup()
{
  Serial.begin(9600);
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
//    control_pose(60, 160, 20, 120, 60, 160, 20, 120);//初始姿态
//    delay(1000);
//    control_pose(60, 180, 0, 120, 60, 180, 0, 120);//蹲
//    delay(1000);
  //  turn_rightFortiFIVE(1);//半面向右转
  //  delay(1000);
  //leap_over(1);
  move_forward(1);
  //delay(1500);
}
