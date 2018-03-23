#define ECHOPIN 7 
#define TRIGPIN 8 
#define LEDPIN 13

int maximumRange = 200; 
int minimumRange = 0; 
long duration, distance; 

int REDPIN = 11;
int GREENPIN = 10;
int BLUEPIN = 9;
int BLUELED = 4;

};

void setup() {


 Serial.begin (9600);
 pinMode(TRIGPIN, OUTPUT);
 pinMode(ECHOPIN, INPUT);
 pinMode(LEDPIN, OUTPUT); 
 
 pinMode(REDPIN, OUTPUT);
 pinMode(GREENPIN, OUTPUT);
 pinMode(BLUEPIN, OUTPUT);
 pinMode(BLUELED, OUTPUT);

}

void loop() {
   digitalWrite(TRIGPIN, LOW); 
 delayMicroseconds(2); 

 digitalWrite(TRIGPIN, HIGH);
 delayMicroseconds(10); 
 
 digitalWrite(TRIGPIN, LOW);
 duration = pulseIn(ECHOPIN, HIGH);

 //digitalWrite(BLUELED, LOW);
 
 distance = duration/58.2;


  if(distance>=70){  
 setColor(100, 0, 100 );  // fade
  delay(100);
 }
 if(distance<70 && distance>=60){  
 setColor(150, 0, 150 );  // fade
  delay(100);
 }
  if (distance<60 && distance>=50){
  setColor(200, 0, 200);  // fade
  delay(100);
  }
  if (distance<50 && distance>=40){
  setColor(255, 0, 255);  // fade
  delay(100);
  }
  if (distance<40 && distance>=30){
  setColor(0, 100, 0);  // blue fade
  delay(100);
  }
  if (distance<30 && distance>=20){
  setColor(0, 150, 0);  // blue fade
  delay(100);
  }
  if (distance<20 && distance>=10){
  setColor(0, 200, 0);  // blue
  delay(100);
  }
  if (distance<10 && distance>=0){
  setColor(0, 255, 0);  // blue
  delay(100);
  }
  if (distance<30 && distance>=0){
    digitalWrite(BLUELED, HIGH); 
    //delay (2000);
    
    } else {
      digitalWrite(BLUELED, LOW);
      }
  Serial.println(distance);
 delay(100);
}
void setColor(int red, int green, int blue)

{
analogWrite(REDPIN, red);
analogWrite(GREENPIN, green);
analogWrite(BLUEPIN, blue);



