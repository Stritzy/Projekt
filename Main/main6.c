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

    windows(5,55,5,30); //Vinduet

    initTimer();
    initJoystick();
    int16_t var = readJoystick();
    int16_t oldvar = 0;

    while(1)
    {
        gotoxy(5+3,5+4); //Placering af uret
        printf("Time starts: %02d:%02d:%02d:%02d",t.h,t.m,t.s,t.cs); // Vores stopur

        gotoxy(5+3,5+10);
        int henttaster();
        urctrl();

        var = readJoystick();

        if(var != oldvar && var != 0){

        if(var==0x04){
            gotoxy(5+3,5+6);
            printf("Split time 1: %02d:%02d:%02d:%02d",t.h,t.m,t.s,t.cs);
        }

        if(var==0x08){
            gotoxy(5+3,5+8);
            printf("Split time 2: %02d:%02d:%02d:%02d",t.h,t.m,t.s,t.cs);
        }

        if(var==0x10){
            TIM2->CR1 ^= 0x01;
        }

        if(var==0x02){
            TIM2->CR1 &= 0x00;
            t.cs=0, t.s=0, t.m=0, t.h=0;
        }


            oldvar = var;
        }
        if(var==0x00){
            oldvar = 0;
        }
    }
}

