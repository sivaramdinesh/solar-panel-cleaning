#include<Servo.h>
int echopin = 5;
int trigpin = 4;
int LeftMotorForward = 10; // Pin 10 has Left Motor connected on Arduino boards.
int LeftMotorReverse = 9; // Pin 9 has Left Motor connected on Arduino boards.
int RightMotorForward = 12; // Pin 12 has Right Motor connected on Arduino boards.
int RightMotorReverse = 13; // Pin 13 has Right Motor connected on Arduino boards.
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LeftMotorForward, OUTPUT);  // initialize the  pin as an output.
  pinMode(RightMotorForward, OUTPUT);  // initialize the  pin as an output.
  pinMode(LeftMotorReverse, OUTPUT);  // initialize the  pin as an output.
  pinMode(RightMotorReverse, OUTPUT);  // initialize the  pin as an output.
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
}
void straight()
{
  digitalWrite(RightMotorForward, HIGH);
  analogWrite(RightMotorReverse, 0);
  digitalWrite(LeftMotorForward, HIGH);
  analogWrite(LeftMotorReverse, 0);
}


void reverse()
{
  digitalWrite(buzzer, HIGH);
  analogWrite(RightMotorForward, 0);
  analogWrite(RightMotorReverse, 150);
  analogWrite(LeftMotorForward, 0);
  digitalWrite(LeftMotorReverse, HIGH);
  delay(2000);
  analogWrite(RightMotorForward, 0);
  analogWrite(RightMotorReverse, 0);
  analogWrite(LeftMotorForward, 0);
  digitalWrite(LeftMotorReverse, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  int distance1 =  0,distance2 = 0;
  if (distance1 >= 10)
  {
    //Serial.println(distance1);
    straight();}
  else
  {
    reverse();
    delay(500);
    distance1 = observe();
    //Serial.println("right dis\t\t");
    //Serial.println(distance1);
    delay(1000);
    servo.write(90);
    delay(1000);
    servo.write(160);
    delay(500);
    distance2  = observe();
    //Serial.println("left dis\t\t");
    //Serial.println(distance2);
    delay(1000);
    servo.write(90);
    if(distance1 > distance2)
          {right();
          delay(1000);}
    else
          {left();
           delay(1000);}
    straight();
  }
}
