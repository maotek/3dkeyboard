#include <Arduino.h>
#include "Keyboard.h"
#include "keymap.h"

int keyPressed[5][16];

void setup()
{
  Keyboard.begin();

  for (int i = 0; i < ROWS; i++)
  {
    pinMode(rowPins[i], INPUT_PULLDOWN);
  }
  for (int i = 0; i < COLUMNS; i++)
  {
    pinMode(columnPins[i], OUTPUT);
    digitalWrite(columnPins[i], LOW);
  }
}

void loop()
{
  for (int i = 0; i < COLUMNS; i++)
  {

    digitalWrite(columnPins[i], HIGH);

    int rowValues[ROWS];
    for (int j = 0; j < ROWS; j++)
    {
      rowValues[j] = digitalRead(rowPins[j]);
    }

    for (int j = 0; j < ROWS; j++)
    {
      if (rowValues[j] == 1 && !keyPressed[j][i])
      {
        keyPressed[j][i] = true;
        Keyboard.press(layer1[j][i]);
        // TODO: handle FN key layer 2
      }
    }

    for (int j = 0; j < ROWS; j++)
    {
      if (rowValues[j] == 0 && keyPressed[j][i])
      {
        keyPressed[j][i] = false;
        Keyboard.release(layer1[j][i]);
        // TODO: handle FN key layer 2
      }
    }

    digitalWrite(columnPins[i], LOW);
  }
}