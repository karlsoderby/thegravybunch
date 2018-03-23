#Lucas README

ARDUINO FOLDER: In the Arduino folder you'll find the pure arduino code and it's the first thing i wrote for this assignment which is why i will call it my first sketch for my first prototype. 

You'll find the fritzing scheme in the fritzing folder and it shows the set up for the breadboard and the various components. Not very complicated, which i consider to be a good thing.

once set up, the code can be uploaded to the Arduino, i used the "uno"-board och for the Range Finder i used to HCSR-04.

once it's all set up and upload is complete the RGB led will be set to orange to convey that the device is in "standby mode" and once you approach the rangefinder it the shade of orange will change until it turn to blue, at this moment another blue led will also turn on (in the demo folder there's a video of this). Which is supposed to light up the play buttons on the "device". 

CROSSDEVICE (WEBSOCKETS) FOLDER: in this folder you have the slightly updated arduino code combined with the arduino code from the serial-bridge folder from Clints GitHub Repository. 

when combined you can use the Terminal as the monitor for the Rangefinder and the local host server as a means to display things depending on the distance from the Range finder.

i added code to the Index.html and the Script.js files in order to make a play button appear when the "device" is approached. you can also press the play button in order to play music.

DEMO/PICTURES FOLDER: Contains videos and pictures of prototypes.

FRITZING FOLDER: contains Fritzing scheme