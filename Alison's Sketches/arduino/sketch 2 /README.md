# Dimming a neopixel ring according to proximity

This sketch will dim the colours of a NeoPixel ring in accordance with proximity to it.

# Parts list:
- an arduino uno
- the arduino IDE or web editor
- a NeoPixel ring (this one has 12 pixels)
- an HC-SR04 proximity sensor
- jumper wires

When the setup is running, the neopixel ring will darken colours while the distance to the sensor is under the value of 30 and brighten colours while the distance value is more than 30.

The darken(); and brighten(); commands can easily be switched and the values can be adjusted to experiment with different light effects happening upon proximity.
