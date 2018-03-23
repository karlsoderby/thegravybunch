README

# A NeoPixel ring reacting to proximity and pressure
This sketch is a part of the gravy bunch's final project within the courses Programming II and Physical Prototyping.
In order to start up the serial communication, I made us of Clint Heyer's serial bridge example (https://github.com/ClintH/interactivity/tree/master/websockets/serial-bridge).

# Assembly
To assemble this setup, you will need:
- an Arduino (in this case I used an Uno)
- Arduino IDE or web editor (https://www.arduino.cc/en/Main/Software)
- a NeoPixel ring (I used one with 12 led     pixels)
- a HC-SR04 proximity sensor
- a force sensitive resistor
- jumper wires
- 220 Ohm resistors
- and the jpg file called "proximity_neopixel_serialcommunication_bb.jpg" with assembly instructions.

# Instructions
If not already installed, download the Arduino IDE.

Upload the arduino sketch "serial_proximity_neopixel.ino" to your Arduino board.

Next, open your command line tool and navigate to the folder you are working from:

$ cd (the folder you are working from)
$ npm install
$ npm install -g node-gyp

 Then, make sure your arduino board is connected to a USB port.

 After that, find out what that port is called by writing the following in your command line tool:
 $ node app

 The command line will then show all the available ports on your computer.
 Copy the one that is called something similar to this (/dev/tty.usbmodem411 or COM on windows).

 Give the command to connect to that port:
 $ node app (the port your arduino is on)

 Then, you should start seeing a serial stream of data in the command line tool.

 Now you can open the index.html file that is located in the public folder and see how the site will change background colour according to colour changes on your NeoPixel ring.
