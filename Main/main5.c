/*
**
**                           Main.c
**
**
**********************************************************************/
/*
   Last committed:     $Revision: 00 $
   Last changed by:    $Author: $
   Last changed date:  $Date:  $
   ID:                 $Id:  $

**********************************************************************/
#define ESC 0x1B
#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" // Input/output liberary for this course
#include "LUT.h"
#include "trig.h"
#include "ansi.h"
#include "timer.h"
#include "joystick.h"


int main(void)
{
    init_usb_uart( 9600 );
    clrscr();
    printf("%c[?25l",ESC); // Fjerner curseren
    gotoxy(0,0);

    windows(25,75,25,50);

    initTimer();

    while(1)
    {
        gotoxy(25+3,25+4);
        printf("%02d:%02d:%02d:%02d",t.h,t.m,t.s,t.cs);

    }
}
