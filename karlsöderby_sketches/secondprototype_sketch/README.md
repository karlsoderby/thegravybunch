# Turning LED's on/off and update live server with Arduino



##### This package uses different photo resistors to both turn leds on/off and sends streams of data to a live server through a websocket.

# You will need
  - An arduino unit (this example uses an Arduino Genuino/Micro)
  - Arduino software installed
  - Jumper cables
  - 3 LED's of different colours
  - 2 photo-resistors
  - Node.js installed

# Setup
### Arduino Software
  - Install Arduino's latest software [here](https://www.arduino.cc/en/Main/Software)
  - Plug in your Arduino to your computer
  - In the editor, upload the sketch included in the 'Arduino' folder (arduino.ino)
  - Done!

### Arduino Wiring

Please refer to image 'arduino_wiring_schematic.png' in the arduino folder for wiring information.

### Command Line

 Open your command prompt as administrator
```sh  
$ cd (where you saved your map)
$ npm install
$ npm --add-python-to-path install --global --production windows-build-tools
$ npm install -g node-gyp
```

To find out what port your Arduino is connected to.
```sh  
$ node app
```
Copy the port from the command line. Should be something like dev/tty.usbmodem2221 on Mac, for windows it should be COM followed by a number. Run the following command
```sh  
$ node app COM(number here) or dev/tty.usbmodem(number here) for macs
```

That should establish connection to your Arduino, and you can start hacking.

# Usage

This sketch is based on sending streams of data to manipulate the appearance of a live-server. By sending streams of data, it can be altered in the public/script.js file to trigger when data is recieved from the Arduino. In this example, the data received from the Arduino comes in the form of either a "0" or a "1" which can be edited in the arduino.ino file. The basic concept is to have a photo resistor detect if you want to turn a green led on, or a yellow led off. Depending on which you turn on or off, the screen will change at localhost:4000. In addition to the green LED turning on, a blue LED will also trigger as this project required. 

By doing so, you have a cross-device connection, and you can interact with a webpage by using a photo-resistor.

# Dependencies

This package uses a sample code provided by Clint Heyer, which can be downloaded at https://github.com/ClintH/interactivity


