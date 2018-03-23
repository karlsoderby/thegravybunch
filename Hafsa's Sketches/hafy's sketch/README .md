# Dimming and Brightening of leds in relation to distance with the help of a Range finder to indicate availabilty.



##### A simple sketch of using LED's as feedback for how close you are to the object

# You will need
  - An arduino unit (this example uses an Arduino Genuino/Micro)
  - Arduino software installed
  - Jumper cables
  - 2 LEDS
  - Range finder
  - Node.js installed

# Setup
### Arduino Software
  - Install Arduino's latest software [here](https://www.arduino.cc/en/Main/Software)
  - Plug in your Arduino to your computer
  - In the editor, navigate to 'examples' in the toolbar and choose to upload '
  - Done!

### Arduino Hardware

![alt text](http://url/to/img.png) Add fritzing here

### Command Line

 Open your command prompt as administrator
```sh  
$ cd (where you saved your map)
$ npm install


```

And finally to run the code on your Arduino:
```sh  
$ node app
```

# Usage

This basic sketch will allow you to 'move' LED's with your hand in a basic way. By approaching the range finder  with your hand, the led turns on  dim  then fro there the closer you get the intensity and brightens of the  LEDS increase where as the further you go from it the brightness decreases cause it to dim till it turns off as soon as youare of the distance range..

