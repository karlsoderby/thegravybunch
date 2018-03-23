#define trigPin 12
#define echoPin 11

#define led 10
#define led2 9

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  long duration, distance,distance2,fadeValue;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(20);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(20); 
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  if (distance < 40) { 
     distance2 =  30- distance;  
     fadeValue = map(distance2 , 0, 30, 0, 254);

     analogWrite(led, fadeValue);
      delay(3);
      digitalWrite(led2,LOW);
      Serial.println(distance);
}
  else {
    digitalWrite(led,LOW);
    digitalWrite(led2,(HIGH));
    delay(3);
  }
}
