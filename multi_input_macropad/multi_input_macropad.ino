#include "Keyboard.h"

// Rotary encoder pins
const int encoderPinA = 16;  
const int encoderPinB = 14;  
const int encoderButtonPin = 10;  // Push button connected to pin 10

int lastEncoderPinAState;
int encoderPosition = 0;
bool encoderButtonState = HIGH;

// Keys
const int bottomLeft = 7; 
const int topLeft = 6; 
const int bottomRight = 5; 
const int bottomCentre = 4; 
const int topRight = 3; 
const int topCentre = 2; 

int bottomLeftState = HIGH;
int topLeftState = HIGH;
int bottomRightState = HIGH;
int bottomCentreState = HIGH;
int topRightState = HIGH;
int topCentreState = HIGH;

void setup() {
  // Initialize the Serial Monitor
  Serial.begin(9600);

  Keyboard.begin();

  // Configure rotary encoder pins
  pinMode(encoderPinA, INPUT_PULLUP);
  pinMode(encoderPinB, INPUT_PULLUP);
  pinMode(encoderButtonPin, INPUT_PULLUP);

  // Read the initial state of encoder pin A
  lastEncoderPinAState = digitalRead(encoderPinA);

  // Configure the button pins as input with internal pull-up resistors
  pinMode(bottomLeft, INPUT_PULLUP);
  pinMode(topLeft, INPUT_PULLUP);
  pinMode(bottomRight, INPUT_PULLUP);
  pinMode(bottomCentre, INPUT_PULLUP);
  pinMode(topCentre, INPUT_PULLUP);
  pinMode(topRight, INPUT_PULLUP);
}

void loop() {
  // Read the state of the rotary encoder button
  encoderButtonState = digitalRead(encoderButtonPin);

  // Read the state of the keys
  bottomLeftState = digitalRead(bottomLeft);
  topLeftState = digitalRead(topLeft);
  bottomRightState = digitalRead(bottomRight);
  bottomCentreState = digitalRead(bottomCentre);
  topCentreState = digitalRead(topCentre);
  topRightState = digitalRead(topRight);

  // Check if any button is pressed
  if (topLeftState == LOW) {
    Serial.println("A");
    Keyboard.press(97);  // Simulate pressing 'a'
    delay(50);
    Keyboard.release(97);
    delay(200);
  }
  if (topCentreState == LOW) {
    Serial.println("B");
    Keyboard.press(98);  // Simulate pressing 'b'
    delay(50);
    Keyboard.release(98);
    delay(200);
  }
  if (topRightState == LOW) {
    Serial.println("C");
    Keyboard.press(99);  // Simulate pressing 'c'
    delay(50);
    Keyboard.release(99);
    delay(200);
  }
  if (bottomLeftState == LOW) {
    Serial.println("D");
    Keyboard.press(100);  // Simulate pressing 'd'
    delay(50);
    Keyboard.release(100);
    delay(200);
  }
  if (bottomCentreState == LOW) {
    Serial.println("E");
    Keyboard.press(101);  // Simulate pressing 'e'
    delay(50);
    Keyboard.release(101);
    delay(200);
  }
  if (bottomRightState == LOW) {
    Serial.println("F");
    Keyboard.press(102);  // Simulate pressing 'f'
    delay(50);
    Keyboard.release(102);
    delay(200);
  }

  // Check the rotary encoder rotation
  int currentEncoderPinAState = digitalRead(encoderPinA);
  if (currentEncoderPinAState != lastEncoderPinAState) {
    if (digitalRead(encoderPinB) != currentEncoderPinAState) {
      encoderPosition++;
      Serial.println("Rotated Right");
      Keyboard.press(KEY_RIGHT_ARROW);  // Simulate pressing the right arrow key
      delay(50);
      Keyboard.release(KEY_RIGHT_ARROW);
    } else {
      encoderPosition--;
      Serial.println("Rotated Left");
      Keyboard.press(KEY_LEFT_ARROW);  // Simulate pressing the left arrow key
      delay(50);
      Keyboard.release(KEY_LEFT_ARROW);
    }
    lastEncoderPinAState = currentEncoderPinAState;
  }

  // Check if the rotary encoder button is pressed
  if (encoderButtonState == LOW) {
    Keyboard.press('1');  // Simulate pressing '1'
    delay(50);
    Keyboard.release('1');
    delay(200);  // Debounce delay to prevent multiple readings
  }
}
