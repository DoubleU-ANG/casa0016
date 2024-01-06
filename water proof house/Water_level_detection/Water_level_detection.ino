#include <Servo.h>  
#include <U8g2lib.h>
#include <Adafruit_NeoPixel.h>

#define PIN 6
#define RED 13
#define NUMPIXELS 6
#define DELAYVAL 50
#define POWER_PIN  8
#define SIGNAL_PIN A1
#define SENSOR_MIN 0
#define SENSOR_MAX 521
#define WATER_PUMP 10
Adafruit_NeoPixel pixels(NUMPIXELS, PIN);
int value = 0; // variable to store the sensor value
int level = 0; // variable to store the water level

void ledstrip(int n, int r, int g, int b)
{
    pixels.clear();
  for(int i=0; i<n; i++) {
    pixels.setPixelColor(i, r, g, b);
    pixels.show();
    delay(DELAYVAL);
  }

  delay(100);
}

void setup() {
  Serial.begin(9600);
  pixels.begin();
  pinMode(2,OUTPUT);
  pinMode(POWER_PIN, OUTPUT);   // configure D  pin as an OUTPUT
  pinMode(WATER_PUMP,OUTPUT);
  pinMode(YELLOW,OUTPUT);
  pinMode(RED,OUTPUT);
  digitalWrite(POWER_PIN, LOW); // turn the sensor OFF
  digitalWrite(WATER_PUMP, LOW);
  digitalWrite(RED, LOW); 
}

void loop() {

  digitalWrite(POWER_PIN, HIGH);  // turn the sensor ON
  delay(10);                      // wait 10 milliseconds
  value = analogRead(SIGNAL_PIN); // read the analog value from sensor
  digitalWrite(POWER_PIN, LOW);   // turn the sensor OFF

  level = map(value, SENSOR_MIN, SENSOR_MAX, 0, 4); // 4 levels
  Serial.print("Water level: ");
  Serial.println(level);
  if(level>4)
  {
  digitalWrite(WATER_PUMP, HIGH); 
  digitalWrite(RED, HIGH);
  ledstrip(level,150,0,0);
  }
  else
  {
  digitalWrite(WATER_PUMP, LOW); 
  digitalWrite(RED, LOW); 
  ledstrip(level,0,150,0);
  }
  if(level==0)
  {
    pixels.clear();
    pixels.show();  
  }

}
