#ifndef JOYSTICK_H
#define JOYSTICK_H

#define ESC 0x1B
#include "stm32f30x_conf.h"
#include "30010_io.h"

void initJoystick();

uint8_t readJoystick();

void initLED();

void setLED(int returnVal);














#endif
