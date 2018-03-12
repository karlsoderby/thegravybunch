#include <Adafruit_NeoPixel.h>

//#ifdef __AVR__
  //#include <avr/power.h>
//#endif

#define PIN 6

Adafruit_NeoPixel strip = Adafruit_NeoPixel(12, PIN, NEO_GRB + NEO_KHZ800);

uint8_t mode = 0;
uint8_t offset = 0;
uint32_t color = 0xffae00;
uint32_t prevTime;

//distance sensor
const int trigPin = 9;
const int echoPin = 10;

//defines variables
long duration;
int distance;


void setup() {
  // put your setup code here, to run once:
//distance pin modes
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  strip.begin();
  strip.setBrightness(80);
  prevTime = millis();
  
  Serial.begin(9600);
  
//strip.begin();
//strip.show(); //initialise all pixels to off
}

void loop() {
  // put your main code here, to run repeatedly:
  
  //clear trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  //set trigPin HIGH for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  //read echoPin, return sound wave travel time in ms
  duration = pulseIn(echoPin, HIGH);

  //calculating distance
  distance = duration*0.034/2;
  //print distance in serial monitor
  Serial.print("Distance: ");
  Serial.println(distance);

  uint8_t i;
  uint32_t t;
  
  //case 0
  /*i = random(12);
  color = random(16777215);
  strip.setPixelColor(i, color);
  strip.show();
  delay(20);
  strip.setPixelColor(i, 0);*/
  /*for (i=0; i<16; i++ && distance <= 20) {
    uint32_t c= 0;
    if(((offset + i) & 16) >2) c = color;
    strip.setPixelColor(i, c);*/

  if (distance <= 20) for (i=0; i<16; i++) {
      uint32_t c = 0;
      if(((offset + i) & 16) < 2) c = color; // 4 pixels on...
      strip.setPixelColor(   i, c); // First eye
      strip.setPixelColor(31-i, c); // Second eye (flipped)
    }
    strip.show();
    offset++;
    delay(50); 
  }
  
  

 /* for(i=0; i<16; i++) {
      uint32_t c = 0;
      if(((offset + i) & 16) < 2) c = color; // 4 pixels on...
      strip.setPixelColor(   i, c); // First eye
      strip.setPixelColor(31-i, c); // Second eye (flipped)
    }
    strip.show();
    offset++;
    delay(50);
    //break;
  }
  */


  /*if (distance <= 20) {
    strip.setPixelColor(0, 0, 0, 255), 50; // White RGBW
    strip.show();
    delay(20);
    
  } */
  



    
    //strip.setPixelColor(10, 0, 0, 0);
    //strip.show();

