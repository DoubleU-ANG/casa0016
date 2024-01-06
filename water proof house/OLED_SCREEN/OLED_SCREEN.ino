#include <U8g2lib.h>

#define POWER_PIN  8
#define SIGNAL_PIN A1
#define SENSOR_MIN 0
#define SENSOR_MAX 521

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/U8X8_PIN_NONE, /* clock=*/SCL, /* data=*/SDA);

int rain;
int value = 0; // variable to store the sensor value
int level = 0; // variable to store the water level


void setup() {
  Serial.begin(9600);
  pinMode(A0,INPUT);
  pinMode(2,OUTPUT);
  pinMode(POWER_PIN, OUTPUT);   // configure D  pin as an OUTPUT
  digitalWrite(POWER_PIN, LOW); // turn the sensor OFF
  u8g2.begin();
  u8g2.enableUTF8Print(); // enable UTF8 support for the Arduino print() function
}

void loop() {

  rain = map(analogRead(A0), 0, 1023, 235, 0);

  digitalWrite(POWER_PIN, HIGH);  // turn the sensor ON
  delay(10);                      // wait 10 milliseconds
  value = analogRead(SIGNAL_PIN); // read the analog value from sensor
  digitalWrite(POWER_PIN, LOW);   // turn the sensor OFF

  level = map(value, SENSOR_MIN, SENSOR_MAX, 0, 4); // 4 levels

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
