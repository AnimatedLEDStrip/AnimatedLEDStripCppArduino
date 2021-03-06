# AnimatedLEDStrip Library
## An expansion on the [FastLED library](http://fastled.io/docs/3.1/index.html)

**See AnimatedLEDStrip_Library_User_Manual.pdf for complete descriptions of methods and animations along with instructions for usage.**


This Arduino library was designed to simplify the usage of animations on LED strips so that an animation can be run with only one function call rather than spending time writing and debugging the logic behind an animation. Though this library only supplies 12 animations, the range of uses of them are endless. The user can also create their own animations, which we would love to hear about and potentially include in future versions of the library.

The base of this library is the FastLED library, which gives the user control over an LED strip. The aspect in which FastLED was lacking was predefined animations. Though they gave examples of potential animations (some of which we modified and used here), the user would still be required to copy the animation code into their program’s code and then modify it to work with their setup.

Because of time limitations, this library is only configured to work with NeoPixel LEDs, though a user can modify the constructors of the LEDStrip and AnimatedLEDStrip classes to use another LED chipset.

The arduino can be controlled via serial communication when the included AnimatedLEDStrip_Serial_Arduino.ino file is loaded on the Arduino. Details on how to use this are located in the Controlling Your LED Strip with Arduino Serial Communication section. PREREQUISITE for serial communication: Messenger library.

This library was also created with FIRST Robotics Competition teams in mind. During the stressful 6 1/2 week build season, only the largest and most experienced teams have the time to think about adding LEDs to their robot before competition. This library hopes to help the smaller teams and teams with less coding experience by simplifying the coding aspect of adding LEDs to a robot. If the RoboRIO is connected to an Arduino via USB, the RoboRIO can send serial communications to the Arduino using its SerialPort class.

The FastLED library is included in this library ([Link to the FastLED documentation](http://fastled.io/docs/3.1/index.html)). If using the serial communication, the Messenger library needs to be installed in the Arduino IDE.

Contributors: Max Narvaez, Will Roberts, Katie Richter, Ziqi Wei, Chan Jin Park
