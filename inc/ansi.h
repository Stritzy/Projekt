#ifndef ANSI_H
#define ANSI_H

#define ESC 0x1B
#include "stm32f30x_conf.h"
#include "30010_io.h"

void fgcolor(int foreground);

void bgcolor(int background);

void color(int foreground, int background);

void resetbgcolor();

void clrscr();

void clreol();

void gotoxy(int8_t x,int8_t y);

void underline(int8_t on);

void blink182(int8_t on);

void inverse(int8_t on);

void windows(int x1,int x2,int y1,int y2);

#endif







