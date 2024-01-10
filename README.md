# casa0016
Building a smart waterproof house using Arduino UNO

<img width="368" alt="image" src="https://github.com/DoubleU-ANG/casa0016/assets/100694831/66fd52fe-62aa-4058-9f4d-53e8efcf4439">

# Overview
<img width="396" alt="image" src="https://github.com/DoubleU-ANG/casa0016/assets/100694831/f1e469b5-2619-4c2d-b034-b94a2b800ba4">

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

<img width="348" alt="image" src="https://github.com/DoubleU-ANG/casa0016/assets/100694831/06934a1e-4414-4e55-921f-2381b0e28aac">

Rain detection circuit

<img width="349" alt="image" src="https://github.com/DoubleU-ANG/casa0016/assets/100694831/e112a6fa-3f79-493a-85dc-b7a85a480b41">

Water level detection circuit

<img width="289" alt="image" src="https://github.com/DoubleU-ANG/casa0016/assets/100694831/5080b04b-9375-42b4-9bf0-3159fb524d9e">

OLED screen circuit
# Code
## Libraries
| Name     | Description |
| :---        |    :----:   |
| Servo.h      | Library for controlling servo       |
| U8g2lib.h      | Library for setting up OLED screen       |
| Adafruit_NeoPixel.h      | Library for controlling neopixel strip       |

## Rain detection
At the beginning of the code,
In setup(),
In loop(),
## Water level detection
At the beginning of the code,
In setup(),
In loop(),
## Data Visualization
At the beginning of the code,
In setup(),
In loop(),

# Enclosure
<img width="353" alt="image" src="https://github.com/DoubleU-ANG/casa0016/assets/100694831/09958fa6-9aa8-426a-bbbf-9b39d8ba6229">

The enclosure was designed in Fusion 360 and was cut by laser cutter using 6mm pine board.

# Test
## Function one
When using a wet tissue to touch the rain drop sensor, the yellow LED is turned on and servo start to rotate to close the window, the wetter the tissue, the larger the angle that servo rotate until the window is completely closed.
## Function two
When filling the container of water level sensor with water, the LED strips starts to light up, and the number of lights indicates the current water level. When the water level is not in the danger range, all the light on LED strips are green. As I gradually increase the water in the container to the danger range, the light on LED strips turns red and the pump starts to pump out water until the water level drops to the safe range.

# Reflection
**·Try to split a complicated project into several parts, and finish them one by one and finally combine them together.

**·Use external power supply when using high energy-demand devices

**·Consider the direction and length of wire before assembling all the devices and enclosure

# Future development
In this project, I built a smart waterproof house to tackle the problem of raining in London. As a house, being waterproof is not enough to provide a comfort environment. Therefore in the future, I will enrich the smart house based on certain existing environment problems including strong wind, dry indoor air and so on, and build more room which makes it looks more like a real house.

