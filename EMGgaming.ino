////////////////////////////////////////////////////////////////////////////
//            OpenBCI_GUI to Arduino via Serial: EMG                      //
//                                                                        //
//   Tested 3/9/2020 using Yoga 920, Arduino UNO R3, OpenBCI_GUI 4.1.7    //
////////////////////////////////////////////////////////////////////////////

#define NUM_CHAN 4 // setup number of channels (4 for Ganglion board)
#define BAUD_RATE 57600 

#define THRESHOLD 0.25 // voltage threshold may need to be adjusted for individual user

const byte BufferSize = 96;
char Buffer[BufferSize + 1];
boolean newData = false;
float emgData[NUM_CHAN];
int pins[] = {2, 3, 4, 5}; //setting up analog output pins on arduino

unsigned long loopLimit = 100;
unsigned long loopTime = 0;

void setup() {
  Serial.begin(BAUD_RATE);
  pinMode(LED_BUILTIN, OUTPUT);

  //set all controller pins to be able to write HIGH/LOW and default to HIGH
  //HIGH = off (button not pressed), LOW = on (button pressed)
  for (int i = 0; i < 5; i++) {
    pinMode(pins[i], OUTPUT);
    digitalWrite(pins[i], HIGH);
  }
}

void loop() {
  // Data Format 4CH
  // 0.999,0.001,0.002,0.003\n

  receiveMoreThan64Chars();
  if (newData) {
    parseData(",", Buffer);
    newData = false;
  }

/* Buttons on wiimote pin assignment 
   1 = pins[0]
   UP = pins[1]
   LEFT = pins[2]
   RIGHT = pins[3]
*/

    //if 1 is above threshold, then button press for 1 
    if (emgData[0] >= THRESHOLD) {    
        digitalWrite(pins[0], LOW); //activate button
    }
    else {
      digitalWrite(pins[0], HIGH); // deactivate button
    }

    // if UP above threshold, then button is pressed for UP
    if (emgData[1] >= THRESHOLD ) {    
        digitalWrite(pins[1], LOW); // activate forward
    } 
    else {
          digitalWrite(pins[1], HIGH); // deactivate forward
    }

    //if LEFT or RIGHT are above threshold, deactivate the lower of the two, and activate the higher ... otherwise, deactivate both
    if (emgData[2] >= THRESHOLD || emgData[3] >= THRESHOLD) {
        if (emgData[2] >= emgData[3]) { // if LEFT is greater than RIGHT (giving priority to left in case of a tie)
          digitalWrite(pins[3], HIGH); // deactivate RIGHT
          digitalWrite(pins[2], LOW); // activate LEFT
          }
        else {
          digitalWrite(pins[2], HIGH); // deactivate LEFT
          digitalWrite(pins[3], LOW); // activate RIGHT
        }
      } 
    else { //if neither are above threshold
        digitalWrite(pins[2], HIGH); // deactivate LEFT
        digitalWrite(pins[3], HIGH); // deactivate RIGHT
    }
  
  } //end of checking thresholds

void receiveMoreThan64Chars() {
  if (Serial.available() > 0) {

    // Clear Buffer content
    memset(Buffer, 0, BufferSize + 1);

    while (Serial.available() > 0) {
      // "readBytes" terminates if the determined length has been read, or it
      // times out. It fills "Buffer" with 1 to 96 bytes of data. To change the
      // timeout use: Serial.setTimeout() in setup(). Default timeout is 1000ms.
      Serial.readBytes(Buffer, BufferSize);
    }

    // Print out buffer contents
    //Serial.println(Buffer);

    // You can use Serial.peek() to check if more than 96 chars
    // were in the serial buffer and if Buffer has truncated data.
    // This should never happen because you know what the max length of
    // the incoming data is and you have adequately sized your input buffer.
    if (Serial.peek() != -1) {
      Serial.println("96 byte Buffer Overflowed. ");
    }
    Buffer[BufferSize] = '\0'; //overwrite the \n char with \0 to terminate the string
    newData = true;
  }
}

void parseData(char* delimiter, char* str) { //parsing through data from openBCI networking widget
  char* pch;
  pch = strtok (str, delimiter);
  int i = 0;
  while (pch != NULL) {
    emgData[i] = atof(pch);
    pch = strtok (NULL, ",");
    i++;
  }
}
