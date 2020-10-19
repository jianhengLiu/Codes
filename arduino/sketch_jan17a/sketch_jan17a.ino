const int pul_pin_x = 2;//X轴脉冲驱动口
const int pul_pin_y = 3;//脉冲驱动口
const int dir_pin = 4;//方向控制
const int ena_pin = 5;//释放电机
const int key_pin_stop = 6;//紧急停止按钮
const int key_pin_auto = 7;//手动-自动切换开关

//开关方向摇杆，4方向。模拟摇杆使用时，可以不用此4个开关
const int key_pin_x1 = 8;//x轴方向正向
const int key_pin_x2 = 9;//x轴方向反向
const int key_pin_y1 = 10;//y轴方向正向
const int key_pin_y2 = 11;//y轴方向反向

const int buzzer = 12;//蜂鸣器
const int led_pin = 13;//执行状态

int hz = -1;//脉冲频率
int sp = 0;//转速调整的数值
float f = 0;//每秒进给量
boolean output = LOW; //脉冲方波状态
boolean dir = LOW;//方向状态
boolean ena = HIGH;//释放电机锁死状态
boolean auto_old = LOW ;//手自动状态
boolean stop_old = LOW;//急停状态
boolean xx = LOW;//摇杆x轴停止状态
boolean yy = LOW;//摇杆y轴停滞状态
boolean x1, x2, y1, y2 = LOW;
long unsigned beep = 0;//蜂鸣器
int az = 0;//摇杆输出频率

LiquidCrystal_I2C lcd(0x27, 16, 2); //定义1602LCD，地址为0x27

/*---------=============函数定义==============----------*/

void wave_x()  //摇杆x轴脉冲输出程序
{
  if (( xx == LOW) || (stop_old == HIGH))
  {
    Timer1.detachInterrupt();
    Timer1.stop();
    stop_old = HIGH;
    output = LOW;
    digitalWrite(pul_pin_x, output);     //**********  test code  ***********
    digitalWrite(led_pin, output);
  }
  else
  {
    output = !output;
    digitalWrite(pul_pin_x, output);       //***********  test code ************
    digitalWrite(led_pin, output);
  }
}

void wave_y()  //摇杆y轴脉冲输出程序
{
  if (( yy == LOW) || (stop_old == HIGH))
  {
    Timer1.detachInterrupt();
    Timer1.stop();
    stop_old = HIGH;
    output = LOW;
    digitalWrite(pul_pin_y, output);
  }
  else
  {
    output = !output;
    digitalWrite(pul_pin_y, output);
  }
}

void wave_x1() //驱动 x1 x2 轴的脉冲发生函数
{
  if (digitalRead(key_pin_auto) == HIGH)
  {
    if (stop_old == HIGH)
    {
      wave_stop();
    }
    else
    {
      output = !output;
      digitalWrite(pul_pin_x, output);
      digitalWrite(led_pin, output);          //***********  test code  **************
    }
  }
  else
  {
    if ((x1 == LOW) && (x2 == LOW))
    {
      wave_stop();
    }
    else
    {
      output = !output;
      digitalWrite(pul_pin_x, output);
      digitalWrite(led_pin, output);          //***********  test code  **************
    }
  }
}

void wave_y1()  //驱动y1轴的脉冲发生函数
{
  if (digitalRead(key_pin_auto) == HIGH)
  {
    if (stop_old == HIGH)
    {
      wave_stop();
    }
    else
    {
      output = !output;
      digitalWrite(pul_pin_y, output);
      digitalWrite(led_pin, output);          //***********  test code  **************
    }
  }
  else
  {
    if ((y1 == LOW) && (y2 == LOW))
    {
      wave_stop();
    }
    else
    {
      output = !output;
      digitalWrite(pul_pin_y, output);
      digitalWrite(led_pin, output);          //***********  test code  **************
    }
  }
}

void wave_stop() //脉冲停止程序
{
  Timer1.stop();
  output = LOW;
  digitalWrite(pul_pin_x, output);
  digitalWrite(pul_pin_y, output);
  digitalWrite(led_pin, output);
  stop_show();
  stop_old = HIGH;
}



void lcd_show()  //1602刷新显示函数
{
  //显示每秒进给量，单位是mm，精度是0.01mm
  f = (hz / 10 ) * 0.01;
  lcd.clear();
  lcd.print("f=");
  lcd.print(f); //显示输出 每秒进给速度
  lcd.setCursor(10, 0);
  //测试手自动按钮状态，高电平显示“自动”，低电平显示“手动”
  if (digitalRead(key_pin_auto) == HIGH)
  {
    lcd.print("AUTO");
  }
  else
  {
    lcd.print("MANUAL");
  }
  delay(10);
}

void stop_show() //当停止按钮被按下，显示函数用来在屏幕显示停止警示同事发出蜂鸣器的声音报警信号
{
  lcd.setCursor(4, 1); //设置在第二行显示
  lcd.print("STOP!!");
  for (int k = 0; k < 2; k++)
  {
    for (int j = 0; j < 2; j++)
    {
      for (int i = 0; i < 60; i++)
      {
        digitalWrite(buzzer, HIGH);
        delay(1);
        digitalWrite(buzzer, LOW);
        delay(1);
      }
      delay(20);
    }
    delay(90);
  }
  lcd_show();
}


/*-----------============参数设置=============-------------*/

void setup()
{
  /*输出端口配置*/
  pinMode(pul_pin_x, OUTPUT);
  pinMode(pul_pin_y, OUTPUT);
  pinMode(dir_pin, OUTPUT);
  pinMode(ena_pin, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(led_pin, OUTPUT);

  /*输入端口配置 */
  pinMode(key_pin_stop, INPUT);
  pinMode(key_pin_auto, INPUT);
  pinMode(key_pin_x1, INPUT);
  pinMode(key_pin_x2, INPUT);
  pinMode(key_pin_y1, INPUT);
  pinMode(key_pin_y2, INPUT);

  /*端口初始化 */
  digitalWrite(pul_pin_x, LOW);
  digitalWrite(pul_pin_y, LOW);
  digitalWrite(dir_pin, LOW);
  digitalWrite(ena_pin, HIGH);
  digitalWrite(buzzer, LOW);
  digitalWrite(led_pin, LOW);

  lcd.init();//1602液晶屏初始化
  lcd.backlight();//打开背光灯

  Timer1.stop();
}

/*-----------=============主函数循环体=============-----------*/

void loop()
{
  if (digitalRead(key_pin_stop) == HIGH) //急停按钮处理
  {
    wave_stop();
  }
  sp = 10;
  //sp = analogRead(A2);
  //sp = map(sp,0,1024,0,20000);   //从电位器获取参数后，生成频率
  if (((hz > (sp + 45)) || (hz < (sp - 45))) || (digitalRead(key_pin_auto) != auto_old)) //抖动不造成显示变化，自动走刀状态改变也出发显示变化
  {
    hz = sp;
    auto_old = digitalRead(key_pin_auto);
    lcd_show();
  }
  //判断4个方向的按键那个被按下

  x1 = digitalRead(key_pin_x1);
  x2 = digitalRead(key_pin_x2);
  y1 = digitalRead(key_pin_y1);
  y2 = digitalRead(key_pin_y2);



  if (x1 == HIGH)  //x轴正方向：当方向按钮被按下的时候首先解除停止锁定，然后打开定时器，开始执行中断程序
  {
    stop_old = LOW;
    digitalWrite(dir_pin, HIGH);
    Timer1.initialize(1000000 / 10);
    Timer1.attachInterrupt(wave_x1);
  }
  if (x2 == HIGH)  //x轴负方向：当方向按钮被按下的时候首先解除停止锁定，然后打开定时器，开始执行中断程序
  {
    stop_old = LOW;
    digitalWrite(dir_pin, LOW);
    Timer1.initialize(1000000 / 10);
    Timer1.attachInterrupt(wave_x1);
  }
  if (y1 == HIGH) //y轴正方向：当方向按钮被按下的时候首先解除停止锁定，然后打开定时器，开始执行中断程序
  {
    stop_old = LOW;
    digitalWrite(dir_pin, HIGH);
    Timer1.initialize(1000000 / 20);
    Timer1.attachInterrupt(wave_y1);
  }
  if ( y2 == HIGH) //y轴负方向：当方向按钮被按下的时候首先解除停止锁定，然后打开定时器，开始执行中断程序
  {
    stop_old = LOW;
    digitalWrite(dir_pin, LOW);
    Timer1.initialize(1000000 / 20);
    Timer1.attachInterrupt(wave_y1);
  }
  //**************  微动摇杆控制程序  ****************
  /*     if (analogRead(0) > 524)  //x轴判断程序  0~1023取值之间，分为0-500,500-524,252-1023
        {                              //525 - 1023为x正取向
          xx = HIGH;
          stop_old = LOW;
          digitalWrite(dir_pin,HIGH);
          az = analogRead(A0);
          az = map(az,525,1023,0,100);
          Timer1.initialize(1000000/az);
          Timer1.attachInterrupt(wave_x);
        }
        else if(analogRead(0) < 500)    //0 - 499 为x负取向
        {
          xx = HIGH;
          stop_old = LOW;
          digitalWrite(dir_pin,LOW);
          az = analogRead(A0);
          az = map(az,0,499,100,0);
          Timer1.initialize(1000000/az);
          Timer1.attachInterrupt(wave_x);
        }
        else                            //500 - 524 为停止
        {
          xx = LOW;
        }

         if (analogRead(1) > 524)  //y轴判断程序  0~1023取值之间，分为0-500,500-524,252-1023
        {                               //525 - 1023为y正取向
          yy = HIGH;
          stop_old = LOW;
          digitalWrite(dir_pin,HIGH);
          az = analogRead(A0);
          az = map(az,525,1023,0,100);
          Timer1.initialize(1000000/az);
          Timer1.attachInterrupt(wave_y);
        }
        else if(analogRead(0) < 500)    //0 - 499 为y负取向
        {
          yy = HIGH;
          stop_old = LOW;
          digitalWrite(dir_pin,LOW);
          az = analogRead(A0);
          az = map(az,0,499,100,0);
          Timer1.initialize(1000000/az);
          Timer1.attachInterrupt(wave_y);
        }
        else                            //500 - 524 为停止
        {
          yy = LOW;
        }
  */
}
