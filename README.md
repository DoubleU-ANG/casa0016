# casa0016
Building a smart waterproof house using Arduino UNO

<img width="368" alt="image" src="https://github.com/DoubleU-ANG/casa0016/assets/100694831/66fd52fe-62aa-4058-9f4d-53e8efcf4439">

# Overview
<img width="396" alt="image" src="https://github.com/DoubleU-ANG/casa0016/assets/100694831/f1e469b5-2619-4c2d-b034-b94a2b800ba4">

This project is inspired by the weather of London, which is often raining. This house has two main  functions: it keeps monitoring the environment, if it starts raining, the windows will be closed;  if rainfall is substantial and water level rises too high, water pump will be activated to pump out the water.

# Hardware list
| type     | Name | Note     |
| :---        |    :----:   |  :---: |
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


