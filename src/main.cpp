#include <Arduino.h>
#include "Keyboard.h"
#include "keymap.h"

int keyPressed[5][16];

void setup()
{
  Keyboard.begin();
  pinMode(PC13, OUTPUT);

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
        digitalWrite(PC13, HIGH);

        if (j == 4 && i == 10)
          continue;

        if (keyPressed[4][10] && j == 0 && i <= 12) // fnKey
        {
          Keyboard.press(layer2[j][i]);
        }
        else
        {
          Keyboard.press(layer1[j][i]);
        }
      }
    }

    for (int j = 0; j < ROWS; j++)
    {
      if (rowValues[j] == 0 && keyPressed[j][i])
      {
        keyPressed[j][i] = false;
        digitalWrite(PC13, LOW);

        if (j == 4 && i == 10)
          continue;

        if (keyPressed[4][10] && j == 0 && i <= 12) // fnKey
        {
          Keyboard.release(layer2[j][i]);
        }
        else
        {
          Keyboard.release(layer1[j][i]);
        }
      }
    }

    digitalWrite(columnPins[i], LOW);
  }
}