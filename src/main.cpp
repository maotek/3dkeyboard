#include <Arduino.h>
#include "Keyboard.h"
#include "keymap.h"

const int buttonPin = PA0;          // input pin for pushbutton

int previousButtonState = HIGH;   // for checking the state of a pushButton

void setup() {
  // make the pushButton pin an input:
  pinMode(buttonPin, INPUT_PULLUP);
  // initialize control over the keyboard:
  Keyboard.begin();
}

void loop() {
  // read the pushbutton:
  int buttonState = digitalRead(buttonPin);
  // if the button state has changed,
  if ((buttonState != previousButtonState)
      // and it's currently pressed:
      && (buttonState == LOW)) {
        Keyboard.press('\n');

  }
  if ((buttonState != previousButtonState)
      // and it's currently pressed:
      && (buttonState == HIGH)) {
        Keyboard.release('\n');

  }
  // save the current button state for comparison next time:
  previousButtonState = buttonState;
}