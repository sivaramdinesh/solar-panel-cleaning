const int motorPin1  = 5;  
const int motorPin2  = 6; 

const int motorPin3  = 10; 
const int motorPin4  = 9;  
const int sensor_pin = 2;


int a_delay = 10000;

void setup() {
  pinMode(sensor_pin, INPUT);
  pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    pinMode(motorPin3, OUTPUT);
    pinMode(motorPin4, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(sensor_pin) == HIGH) 
  {
    front();
    delay(a_delay);
    back();
    
  }
void front() {
  digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, HIGH);
    digitalWrite(motorPin4, LOW);
  
}

void back() {
   digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, HIGH);
}
  void stop()
  {
    
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, LOW);
  }
