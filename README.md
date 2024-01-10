# casa0016 
Building a smart waterproof house using Arduino UNO

<img width="500" alt="image" src="https://github.com/DoubleU-ANG/casa0016/assets/100694831/66fd52fe-62aa-4058-9f4d-53e8efcf4439">

# Overview
<img width="800" alt="image" src="https://github.com/DoubleU-ANG/casa0016/assets/100694831/f1e469b5-2619-4c2d-b034-b94a2b800ba4">

This project is inspired by the weather of London, which is often raining. This house has two main  functions: it keeps monitoring the environment, if it starts raining, the windows will be closed;  if rainfall is substantial and water level rises too high, water pump will be activated to pump out the water.

The whole project can be divided into three main sections: Rain detection, Water level detectioin and Data visualization.

# Hardware list
| type     | Name | Note     |
| :---        |    :----:   |  :--- |
| Board      | Arduino Uno       | A micro-controller   |
| Sensor   | Rain drop sensor        | A sensor for sensing rain drop      |
| Sensor   | Water level sensor        | A sensor for sensing water level      |
| Misc   | Servo motor        | An actuator for closing the window      |
| Misc   | LEDs        | 1* Yellow, 1* Red      |
| Misc   | OLED screen        | A small screen that can display some text      |
| Misc   | LED strips        | A strip of individually addressable, RGB(Red, Green, Blue) LEDs      |
| Misc   | Relay        | An electronically controlled switch      |
| Misc   | Water pump        | An actuator that can pump out water      |
| Misc   | Adafruit solar LiPo charger board        | An external power source for water pump      |

# Schematics

<img width="600" alt="image" src="https://github.com/DoubleU-ANG/casa0016/assets/100694831/06934a1e-4414-4e55-921f-2381b0e28aac">

Rain detection circuit

<img width="600" alt="image" src="https://github.com/DoubleU-ANG/casa0016/assets/100694831/e112a6fa-3f79-493a-85dc-b7a85a480b41">

Water level detection circuit

<img width="400" alt="image" src="https://github.com/DoubleU-ANG/casa0016/assets/100694831/5080b04b-9375-42b4-9bf0-3159fb524d9e">

OLED screen circuit
# Code
## Libraries
| Name     | Description |
| :---        |    :----:   |
| Servo.h      | Library for controlling servo       |
| U8g2lib.h      | Library for setting up OLED screen       |
| Adafruit_NeoPixel.h      | Library for controlling neopixel strip       |

## Rain detection
At the beginning of the code, import the library for servo, define the pin for yellow LED, create a object for servo and a variable for storing value of rain
```
#include <Servo.h>  
#define YELLOW 12

Servo myservo;        // create a servo object 
int rain = 0;
```
In setup(), initialize the pin for sensor, led and servo, set up serial
```
  Serial.begin(9600);
  pinMode(A0,INPUT);
  pinMode(YELLOW,OUTPUT);
  digitalWrite(YELLOW, LOW);
  myservo.attach(9);
```
In loop(), read the value of rain sensor and use 'if' statement to determine how servo and yellow led react to the value of rain
```
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
```
## Water level detection
At the beginning of the code, import library for LED strips, define the pin for LED strip, Red LED, water level sensor and water pump, create variable for store the value of water level. Apart from that, I also create a function for change the number and color of LED strip.
``` 
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
```
In setup(), initialize all the pin used, led strip and serial
```
  Serial.begin(9600);
  pixels.begin();
  pinMode(2,OUTPUT);
  pinMode(POWER_PIN, OUTPUT);  
  pinMode(WATER_PUMP,OUTPUT);
  pinMode(YELLOW,OUTPUT);
  pinMode(RED,OUTPUT);
  digitalWrite(POWER_PIN, LOW); // turn the sensor OFF
  digitalWrite(WATER_PUMP, LOW);
  digitalWrite(RED, LOW); 
```
In loop(), read the data from water level sensor and determine how the led strip, water pump react to the value of water level
```
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
```
## Data Visualization
At the beginning of the code, import the library for the fuction used later and initialize the OLED screen
```
#include <U8g2lib.h>
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/U8X8_PIN_NONE, /* clock=*/SCL, /* data=*/SDA);
```
In setup(), activate the OLED screen
```
  u8g2.begin();
  u8g2.enableUTF8Print(); // enable UTF8 support for the Arduino print() function
```
In loop(), set the position of cursor first and then print the text 
```
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
```
# Enclosure
<img width="500" alt="image" src="https://github.com/DoubleU-ANG/casa0016/assets/100694831/09958fa6-9aa8-426a-bbbf-9b39d8ba6229">

The enclosure was designed in Fusion 360 and was cut by laser cutter using 6mm pine board.

# Test
## Function one
When using a wet tissue to touch the rain drop sensor, the yellow LED is turned on and servo start to rotate to close the window, the wetter the tissue, the larger the angle that servo rotate until the window is completely closed.
## Function two
When filling the container of water level sensor with water, the LED strips starts to light up, and the number of lights indicates the current water level. When the water level is not in the danger range, all the light on LED strips are green. As I gradually increase the water in the container to the danger range, the light on LED strips turns red and the pump starts to pump out water until the water level drops to the safe range.

# Reflection
***·Try to split a complicated project into several parts, and finish them one by one and finally combine them together.***

***·Use external power supply when using high energy-demand devices***

***·Consider the direction and length of wire before assembling all the devices and enclosure***

# Future development
In this project, I built a smart waterproof house to tackle the problem of raining in London. As a house, being waterproof is not enough to provide a comfort environment. Therefore in the future, I will enrich the smart house based on certain existing environment problems including strong wind, dry indoor air and so on, and build more room which makes it looks more like a real house.
# Reference
Tido technology (No date) Raindrop detection sensor detect Rain, rain. Available at: https://www.tido.tech/index.php/product/raindrop-detection-sensor/ (Accessed: 6 December 2023)
Arduino (No date) Servo motor. Available at:https://arduinogetstarted.com/tutorials/arduino-servo-motor?utm_content=cmp-true (Accessed: 6 December 2023) 
Arduino (No date) Water level sensor. Available at: https://arduinogetstarted.com/tutorials/arduino-water-sensor (Accessed: 6 December 2023) 
