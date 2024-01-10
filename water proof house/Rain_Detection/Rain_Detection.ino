#include <Servo.h>  
#define YELLOW 12

Servo myservo;        // create a servo object 
int rain = 0;

void setup() {
  Serial.begin(9600);
  pinMode(A0,INPUT);
  pinMode(YELLOW,OUTPUT);
  digitalWrite(YELLOW, LOW);
  myservo.attach(9);
}

void loop() {

  rain = map(analogRead(A0), 0, 1023, 235, 0);
  Serial.print("rain = ");
  Serial.println(rain);
  
  if(rain<70&&rain>10)
  {
   digitalWrite(YELLOW, HIGH); 
   myservo.write(rain);
  }
  else if(rain>=70)
  {
   digitalWrite(YELLOW, HIGH); 
   myservo.write(70); 
  }
  else if(rain<=10)
  {
  digitalWrite(YELLOW, LOW);
  myservo.write(0);   
  }
  
}
