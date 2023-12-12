#include <Servo.h>  
#include <U8g2lib.h>
#include <Adafruit_NeoPixel.h>

#define PIN 6
#define YELLOW 12
#define RED 13
#define NUMPIXELS 6
#define DELAYVAL 50
#define POWER_PIN  8
#define SIGNAL_PIN A1
#define SENSOR_MIN 0
#define SENSOR_MAX 521

Adafruit_NeoPixel pixels(NUMPIXELS, PIN);
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/U8X8_PIN_NONE, /* clock=*/SCL, /* data=*/SDA);
Servo myservo;        // create a servo object 
int pos = 0;          // define pos for storing the degree that servo rotates
int rain;
int value = 0; // variable to store the sensor value
int level = 0; // variable to store the water level

void servo_move(int n)
{
     for(pos = 0; pos < n; pos += 1){         
      myservo.write(pos);           // make servo rotate from 0 degree to 180 degree  
      delay(1);                    
   }
    for(pos = n; pos>=1; pos-=1) {                                  
       myservo.write(pos);        // make servo rotate from 180 degree to 0 degree    
       delay(5);                 
    } 
}

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
  pinMode(A0,INPUT);
  pinMode(2,OUTPUT);
  pinMode(POWER_PIN, OUTPUT);   // configure D  pin as an OUTPUT
  pinMode(10,OUTPUT);
  pinMode(YELLOW,OUTPUT);
  pinMode(RED,OUTPUT);
  digitalWrite(POWER_PIN, LOW); // turn the sensor OFF
  digitalWrite(10, LOW);
  digitalWrite(YELLOW, LOW);
  digitalWrite(RED, LOW); 
  myservo.attach(9);
  u8g2.begin();
  u8g2.enableUTF8Print(); // enable UTF8 support for the Arduino print() function
}

void loop() {
  analogWrite(2,(map(analogRead(A0), 0, 1023, 235, 0)));
  rain = map(analogRead(A0), 0, 1023, 235, 0);
  Serial.print("rain = ");
  Serial.println(rain);
  
  if(rain<50&&rain>10)
  {
   digitalWrite(YELLOW, HIGH); 
   myservo.write(rain);
  }
  else if(rain>=50)
  {
   digitalWrite(YELLOW, HIGH); 
   myservo.write(70); 
  }
  else if(rain<=10)
  {
  digitalWrite(YELLOW, LOW);
  myservo.write(0);   
  }
  digitalWrite(POWER_PIN, HIGH);  // turn the sensor ON
  delay(10);                      // wait 10 milliseconds
  value = analogRead(SIGNAL_PIN); // read the analog value from sensor
  digitalWrite(POWER_PIN, LOW);   // turn the sensor OFF

  level = map(value, SENSOR_MIN, SENSOR_MAX, 0, 4); // 4 levels
  Serial.print("Water level: ");
  Serial.println(level);
  if(level>4)
  {
  digitalWrite(10, HIGH); 
  digitalWrite(RED, HIGH);
  ledstrip(level,150,0,0);
  }
  else
  {
  digitalWrite(10, LOW); 
  digitalWrite(RED, LOW); 
  ledstrip(level,0,150,0);
  }
  if(level==0)
  {
    pixels.clear();
    pixels.show();  
  }
  u8g2.setFont(u8g2_font_unifont_t_chinese2); // use chinese2
  u8g2.firstPage();
  do
  {
    u8g2.setCursor(3, 15);
    u8g2.print("rain: ");
    u8g2.setCursor(3, 30);
    u8g2.print(rain); 
    u8g2.setCursor(3, 45);
    u8g2.print("Water level:");  
    u8g2.setCursor(3, 60);
    u8g2.print(level);    
  } while (u8g2.nextPage());
  delay(500);
  
}
