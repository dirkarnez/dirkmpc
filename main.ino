/*
  Button

  Turns on and off a light emitting diode(LED) connected to digital pin 13,
  when pressing a pushbutton attached to pin 2.

  The circuit:
  - LED attached from pin 13 to ground
  - pushbutton attached to pin 2 from +5V
  - 10K resistor attached to pin 2 from ground

  - Note: on most Arduinos there is already an LED on the board
    attached to pin 13.

  created 2005
  by DojoDave <http://www.0j0.org>
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Button
*/
// - [Button: Arduino Basics - Arduino Project Hub](https://create.arduino.cc/projecthub/glowascii/button-arduino-basics-5ecffc?ref=search&ref_id=button&offset=0)
// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  Serial.begin(9600);         // Set the speed of the midi port to the same as we will be using in the Hairless Midi software
  pinMode(ledPin, OUTPUT);    // initialize the LED pin as an output:
  pinMode(buttonPin, INPUT);  // initialize the pushbutton pin as an input:
}

void loop() {
  // read the state of the pushbutton value:
  int temp = digitalRead(buttonPin);
  if (temp == buttonState) {
    return;
  }

  buttonState = temp;

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
    PlayNote();
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
    ReleaseNote();
  }
}

const int middleC =  60;      // the number of the LED pin

void PlayNote() {
  MidiMessage(144, middleC, 127);
}

void ReleaseNote() {
    MidiMessage(128, middleC, 127);
}

void MidiMessage(byte command, byte data1, byte data2) //pass values out through standard Midi Command
{
  Serial.write(command);
  Serial.write(data1);
  Serial.write(data2);
}
