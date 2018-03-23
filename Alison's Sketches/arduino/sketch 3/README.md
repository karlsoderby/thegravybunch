#Exploring proximity with a NeoPixel ring and arduino.

This is an arduino sketch where an arduino uno board hosts a proximity sensor (HC-SR04) as means of an input device and a NeoPixel ring as an output device.

Depending on the proximity to the sensor, the NeoPixels will light up in different colours accordingly.

#Assembly

To assemble this setup, you need:
- an arduino uno
- the arduino IDE or web editor
- an HC-SR04 proximity sensor
- a NeoPixel ring (in this case with 12 pixels)
- jumper wires

# A few words about working with proximity
If the proximity sensor is located close to the edge of a table for example, make sure it is placed all the way to the edge so that the table is not obstructing its "view".

The HC-SR04 emits an ultrasonic signal which is sent into the surrounding area and upon being reflected by objects around it, the reflected signal will bounce back to the proximity sensor.
The time that takes will determine the distance to the object.

# Usage
This sketch was used to detect proximity to my prototype upon which the led ring would light up in different colours depending on the distance to the prototype, thus inviting to interact with it.
