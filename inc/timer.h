#ifndef TIMER_H
#define TIMER_H

#define ESC 0x1B
#include "stm32f30x_conf.h"
#include "30010_io.h"
#include "ansi.h"
#include <string.h>

struct timer{
    uint16_t h, m, s,cs;
};

volatile struct timer t;
volatile uint8_t flag;

void initTimer();

void TIM2_IRQHandler(void);

int henttaster();

void urctrl();


#endif
