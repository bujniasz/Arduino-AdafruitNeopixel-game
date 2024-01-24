# Arduino Adafruit NeoPixel game
The project presented here is a simple game created using the Arduino UNO microcontroller.
After starting the game, two pixels light up on the LED strip, and the player can change the colour of one of them
using a potentiometer. The player's task is to choose the colour of the pixel so that they both light up with the same color.
Once the player has confirmed their choice, the game can give the point, which is shown by turning on one of the four, green LED diode attached to the system.
It happens if the choice made by the player is within the specified range ε.
The player makes his choice four times in one game, so he can score 4 points. The game is is won when all of them have been scored.

## Device design
This components were used to build this device:
- Arduino UNO
- Adafruit Neopixel 8 LED strip
- potentiometer
- push-button (3x)
- green LED diode (4x)
- resistor 1k Ohm

![ar1](https://github.com/bujniasz/Arduino-AdafruitNeopixel-game/assets/149008651/2e1a9743-c320-4ff3-a95b-88069fcd6ec6)

## Gameplay
The button on the left is used to start the game. When it is pressed, the first two pixels on the strip turn on. Once the user has selected a colour, they confirm it with the centre button. At this point, two next pixels light up and, if a point is scored, a green LED lights up. After making four choices, we end the game with the right button, and in the serial port monitor we receive information about our score and the time of the game.
