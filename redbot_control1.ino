#include <SoftwareSerial.h>

const int FORWARD_PIN = 6;
const int REVERSE_PIN = 5;
const int TURN_PIN = 7;

int iForwardValue;
int iReverseValue;
int iTurnValue;

byte byMessage;

SoftwareSerial XBee(2, 3); // Arduino RX, TX (XBee Dout, Din)

void setup() {

  pinMode(FORWARD_PIN, INPUT_PULLUP);
  pinMode(REVERSE_PIN, INPUT_PULLUP);
  pinMode(TURN_PIN, INPUT_PULLUP);

  XBee.begin(9600); 
  //Serial.begin(38400);

}

void loop() {

  byMessage = B0;

  iForwardValue = digitalRead(FORWARD_PIN);
  iReverseValue = digitalRead(REVERSE_PIN);
  iTurnValue = digitalRead(TURN_PIN);

  if (iReverseValue == LOW) {
    byMessage = B1100;
  }
  else {

    if (iTurnValue == LOW) {
      byMessage = B1001;
    }
    else {
  
      if (iForwardValue == LOW) {
        byMessage = B0011;
      }
    }
  }

  //Serial.println(byMessage, BIN);

  XBee.write(byMessage);

  delay(500);

}
