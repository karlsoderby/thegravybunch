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

const byte numChars = 32;
char receivedChars[numChars];
char tempChars[numChars];
char messageFromPC[numChars] = {0};
int integerFromPC = 0;
float floatFromPC = 0.0;
boolean newData = false;

long lastFakeReport = 0;

enum {
  MsgAcknowledge, // 0
  MsgError,       // 1
  MsgMove,        // 2
  MsgMoveResult,  // 3
  MsgPosition,    // 4
};

void setup() {

  Serial.begin(115200);
 //Serial.begin (9600);
 pinMode(TRIGPIN, OUTPUT);
 pinMode(ECHOPIN, INPUT);
 pinMode(LEDPIN, OUTPUT); 
 
 pinMode(REDPIN, OUTPUT);
 pinMode(GREENPIN, OUTPUT);
 pinMode(BLUEPIN, OUTPUT);
 pinMode(BLUELED, OUTPUT);

 //Serial.begin(115200);
  
 report(MsgAcknowledge, "Ready");
    
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

// Process serial communucation
  recvWithStartEndMarkers();

  // If we received a command, process it
  if (newData == true) {
    strcpy(tempChars, receivedChars);
    parseData();
    switch (integerFromPC) {
      case MsgPosition:
        // Report fake result
        report(MsgPosition, 10);
        break;
      case MsgMove:
        // Pretend to do something
        report(MsgMoveResult, 10);
        break;
      }
      
      // Debug: print parsed command to serial
      // showParsedData();
      newData = false;
    }

  // Every so often report a fake position
  /*if (millis() - lastFakeReport > 2000) {
    report(MsgPosition, (random(0,100)));
    lastFakeReport = millis();    
  }*/
}

void report(int code, const char *message) {
  Serial.print("<");
  Serial.print("ws-bridge,");
  Serial.write(code);
  Serial.write(",");
  Serial.write(message);
  Serial.print(">\r\n");
  Serial.flush();
}

void report(int code, int message) {
  Serial.print("<");
  Serial.print("ws-bridge,");
  Serial.print(code);
  Serial.print(",");
  Serial.print(message);
  Serial.print(">\r\n");
  Serial.flush();
}

void recvWithStartEndMarkers() {
    static boolean recvInProgress = false;
    static byte ndx = 0;
    char startMarker = '<';
    char endMarker = '>';
    char rc;

    while (Serial.available() > 0 && newData == false) {
        rc = Serial.read();

        if (recvInProgress == true) {
            if (rc != endMarker) {
                receivedChars[ndx] = rc;
                ndx++;
                if (ndx >= numChars) {
                    ndx = numChars - 1;
                }
            }
            else {
                receivedChars[ndx] = '\0'; // terminate the string
                recvInProgress = false;
                ndx = 0;
                newData = true;
            }
        }

        else if (rc == startMarker) {
            recvInProgress = true;
        }
    }
}

void parseData() {      // split the data into its parts
    char * strtokIndx; // this is used by strtok() as an index

    strtokIndx = strtok(tempChars,",");      // get the first part - the string
    strcpy(messageFromPC, strtokIndx); // copy it to messageFromPC
 
    strtokIndx = strtok(NULL, ","); // this continues where the previous call left off
    integerFromPC = atoi(strtokIndx);     // convert this part to an integer

    strtokIndx = strtok(NULL, ",");
    floatFromPC = atof(strtokIndx);     // convert this part to a float
}

void showParsedData() {
    Serial.print("Message ");
    Serial.println(messageFromPC);
    Serial.print("Integer ");
    Serial.println(integerFromPC);
    Serial.print("Float ");
    Serial.println(floatFromPC);
}




