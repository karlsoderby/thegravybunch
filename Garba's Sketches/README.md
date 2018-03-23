TURNING LIGHT OFF AND ON using a sensor .

This will  show  how the HC-SR05 Ultrasonic Sensor works and how to use it with  a buzzer and one LED to turn on and off light .

The Hardwares used for this project/ prototype.

 Arduino Board - the arduino uno or the micro
 One Ultrasonic Sensor HC-SR04 
 One micro Buzzer
 1 LED
 1 220ohm Resistor
 Wires
 1 board

 How it was connected :
 

The HC-SR04 and how it was connected 

The HC-SR04 Ultrasonic Module has 4 pins. these pins are  Ground, VCC, Trig and Echo. The Ground and the VCC pins of the module needs to be connected to the Ground and the 5 volts pins on the Arduino Board respectively and the trig and echo pins to any Digital I/O pin on the Arduino Board.

The HC-SR04 sensor attach to the board
The Sensor VCC connect to the Arduino Board +5V
The Sensor GND connect to the Arduino Board GND
The Sensor Trig connect to the Arduino Board Digital I/O 9
The Sensor Echo connect to the Arduino Board Digital I/O 10
 
 
Buzzer and LED

 The Buzzer  was attach to the board
 The Buzzer long leg (+) connects to the Arduino Board Digital 11
 The Buzzer short leg (-) connect to the Arduino Board GND
 The LED attach to the board
 The Resistor connect to the LED long leg (+)
 The Resistor other leg (from LED's long leg) connect to the Arduino Board Digital 13
 The LED short leg (-) connect to the Arduino Board GND 

Setup and code description.

in the set up , i defined the trigPin as an output and the echo Pin as an input and also start the serial communication
for showing the result on my screen after uploading the codes for the setup.
if the object is 10 cm away from the sensor, and the speed of the sound is 340m/s the sound wave will need to travel for about 
294u seconds and what you will get with the echo pin will be double that number because the sound waves needs to travel
forward abd bounce backwards.


This smple  Arduino setup is uses an ultrasonic sensor to  turn  an LED light on/off with a buzzer attached 
and this in return sends series of  data to a live server through a websocket .

Command Line through my terminal 
Open your command prompt as administrator

$ cd (https://github.com/ClintH/interactivity)
$ npm install
$ npm --add-python-to-path install --global --production windows-build-tools
$ npm install -g node-gyp
To find out what port your Arduino is connected to.

$ node app
Copy the port from the command line. Should be something like dev/tty.usbmodem2221 on Mac, for windows it should be COM followed by a number. Run the following command

$ node app COM(number here) or dev/tty.usbmodem(number here) for macs

Dependencies
Sample code provided by Clint Heyer, which can be downloaded at https://github.com/ClintH/interactivity
Sample code provided by ardrino editor  https://create.arduino.cc/editor/garba/112c528f-6f8d-43ff-b8c6-17cc9ce2a794
