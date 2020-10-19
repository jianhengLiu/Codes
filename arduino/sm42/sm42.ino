#define DIR1  9//乘电机方向
#define STP1  6//步进
#define EN1  8//使能

void setup()
{
//TCCR2B = TCCR2B & 0xF8 | 5;


  pinMode(DIR1, OUTPUT);

  pinMode(STP1, OUTPUT);

  pinMode(EN1, OUTPUT);

  Serial.begin(9600);
}

void loop()
{
digitalWrite(EN1, HIGH); //处于能转动状态
digitalWrite(DIR1, HIGH); //乘电机上升
analogWrite(STP1, 200);
delay(2000);//持续2*楼层秒数
//digitalWrite(EN1, HIGH); //处于能转动状态
//digitalWrite(DIR1, HIGH); //乘电机上升
//analogWrite(STP1, 200);
//delay(2000);//持续2*楼层秒数
}
