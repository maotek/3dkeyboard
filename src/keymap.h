#include "Keyboard.h"

#define KEY_FN 255
#define KEY_PRTSCRN 0x46 + 136
#define ROWS 5
#define COLUMNS 16

int rowPins[5] = {PB5, PB6, PB7, PB8, PB9};
int columnPins[16] = {PB14, PB15, PA8, PA9, PB10, PB2, PB1, PB0, PA7, PA6, PA5, PA4, PA3, PA2, PA1, PA0};

char layer1[5][16] = {
    {KEY_ESC, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', KEY_BACKSPACE, KEY_INSERT, KEY_HOME},
    {KEY_TAB, 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\\', KEY_DELETE, KEY_END},
    {KEY_CAPS_LOCK, 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', 0, '\n', KEY_PRTSCRN, KEY_PAGE_UP},
    {KEY_LEFT_SHIFT, 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', 0, 0, KEY_RIGHT_SHIFT, KEY_UP_ARROW, KEY_PAGE_DOWN},
    {KEY_LEFT_CTRL, KEY_LEFT_GUI, KEY_LEFT_ALT, 0, 0, ' ', 0, 0, KEY_RIGHT_ALT, KEY_FN, KEY_RIGHT_CTRL, 0, 0, KEY_LEFT_ARROW, KEY_DOWN_ARROW, KEY_RIGHT_ARROW}};

char layer2[5][16] = {
    {'`', KEY_F1, KEY_F2, KEY_F3, KEY_F4, KEY_F5, KEY_F6, KEY_F7, KEY_F8, KEY_F9, KEY_F10, KEY_F11, KEY_F12},
    {},
    {},
    {},
    {}};