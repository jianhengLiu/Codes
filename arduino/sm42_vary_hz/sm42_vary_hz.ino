#define DIR1  A1//乘电机方向
#define STP1  11//步进
#define EN1  A0//使能

void setup()
{
  pinMode(DIR1, OUTPUT);
  pinMode(STP1, OUTPUT);
  pinMode(EN1, OUTPUT);
  Serial.begin(9600);

//TCCR2B = TCCR2B & 0xF8 | 3;

/*
   ?  Prescaler   Frequency
   1         1       31372.549 Hz
   2         8         3921.569
   3            32          980.392
   4        64         490.196   <--DEFAULT
   5      128         245.098
   6      256         122.549
   7    1024           30.637 Hz
*/
}

void loop()
{
  //
  digitalWrite(EN1, HIGH); //处于能转动状态
  digitalWrite(DIR1, LOW); //乘电机上升
  analogWrite(STP1, 200);
  delay(2000);//持续2*楼层秒数
  digitalWrite(EN1, HIGH); //处于能转动状态
  digitalWrite(DIR1, LOW); //乘电机上升
  analogWrite(STP1, 200);
  delay(2000);//持续2*楼层秒数

  /*//pwm频率调节，例1
    digitalWrite(EN1, HIGH); //处于能转动状态
    digitalWrite(DIR1, LOW);

    digitalWrite(STP1, HIGH);
    delayMicroseconds(100); // Approximately 10% duty cycle @ 1KHz
    digitalWrite(STP1, LOW);
    delayMicroseconds(1000 - 100); //修改这里的1000可以调整频率
  */
  /*pwm频率调节，例2
    digitalWrite(DIR1, LOW);
    unsigned int number = 1000; unsigned int time = 100; //numbe为脉冲个数，time为脉冲宽度。

    while (number > 0)
    {
      digitalWrite(PUL_1, HIGH);
      delayMicroseconds(time);
      digitalWrite(PUL_1, LOW);
      delayMicroseconds(time);
    }
    number--;
  */
}
