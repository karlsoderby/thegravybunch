# Measuring distance with LEDs and a photo-resistor



##### A simple sketch of using LED's as feedback for how close you are to the object

# You will need
  - An arduino unit (this example uses an Arduino Genuino/Micro)
  - Arduino software installed
  - Jumper cables
  - 5 LEDs, one being of a different colour, the rest of same colour
  - Photo-resistor
  - Node.js installed

# Setup
### Arduino Software
  - Install Arduino's latest software [here](https://www.arduino.cc/en/Main/Software)
  - Plug in your Arduino to your computer
  - In the editor, navigate to 'examples' in the toolbar and choose to upload 'StandardFirmata'.
  - Done!

### Arduino Hardware

![alt text](http://url/to/img.png) Add fritzing here

### Command Line

 Open your command prompt as administrator
```sh  
$ cd (where you saved your map)
$ npm install
$ npm --add-python-to-path install --global --production windows-build-tools
$ npm install -g node-gyp
```

And finally to run the code on your Arduino:
```sh  
$ node led.js
```

# Usage

This basic sketch will allow you to 'move' LED's with your hand in a basic way. By approaching the photoresistor with your hand, one LED after another will trigger. Since photoresistors are quite unreliable, it is recommended to use something more reliable, but for the sake of demonstration, this works just fine.

The code itself is very self explanitory and consists of less than 70 lines of code including a lot of blank spaces. Some ideas of usage could be either volume control or simple on/off functions for certain components.
