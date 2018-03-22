// Serial I/O based on example http://forum.arduino.cc/index.php?topic=396450


int greenLedPin = 10;
int yellowLedPin = 9;
int redLedPin = 8;

int lightSensorPin = A0;
int analogValue = 0;
int lightSensorPin2 = A1;
int analogValue2 = 0;

// Serial communication
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


void setup()  {
  
  Serial.begin(115200);
  pinMode(greenLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
 
  

  

  report(MsgAcknowledge, "Ready");
}

void loop() {


  
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
    report(MsgPosition, (random(0, 100)));
    lastFakeReport = millis();
  }*/

  // put your main code here, to run repeatedly:
 // Serial.println(analogRead(lightSensorPin));
  analogValue = analogRead(lightSensorPin);

 // Serial.println(analogRead(lightSensorPin2));
  analogValue2 = analogRead(lightSensorPin2);
  
  if (analogValue < 120) {
    digitalWrite(redLedPin, HIGH);
    digitalWrite(greenLedPin, HIGH);
    digitalWrite(yellowLedPin, LOW);
    Serial.println (1);
  }/*
  else if(analogValue >= 80 && analogValue <= 120) {
    digitalWrite(yellowLedPin, HIGH);
    delay(10);
    digitalWrite(yellowLedPin, LOW);
  } 
  else if(analogValue > 50 && analogValue <= 80){
    digitalWrite(greenLedPin, HIGH);
    delay(10);
    digitalWrite(greenLedPin, LOW);
  }
  else {
    digitalWrite(greenLedPin && yellowLedPin && redLedPin, LOW);
  }*/


  if (analogValue2 < 120) {
    digitalWrite(redLedPin, LOW);
    digitalWrite(greenLedPin, LOW);
    digitalWrite(yellowLedPin, HIGH);
    Serial.println (0);
    
    
    
  }
  delay(10);
}

// ---- Serial communication
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

  strtokIndx = strtok(tempChars, ",");     // get the first part - the string
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

