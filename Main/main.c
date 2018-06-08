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
#include "stm32f30x_conf.h"
#define ESC 0x1B
#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" // Input/output libreay for this course
#include "LUT.h"
#include "ansi.h"
#include "trig.h"
#include "menu.h"

int main(void)
{
    windows(0,20,0,20);
    initJoystick();
    int16_t var = readJoystick();
    int8_t x=5;
    int8_t y=10;
    gotoxy(x,y);
    printf("%c/n%c/n%c/n%c/n","Menu","Play","Levels","Highscore");
    while(1)
    {
        switch (var)
        {
        case 0x01 //Up
                gotoxy(x,y-1);
            y-=1;
            break;
        case 0x02 //Down
                gotoxy(x,y+1);
            y+=1
               break;
        case 0x04 // Left
                break;
        case 0x08 // Right

                break;
        case 0x10 // center
                if(y==11)
                {
                    //Play game, skift til nyt vindue
                }
                else if (y==12)
                {
                    // Nyt vindue med levels
                }
                else if(y==13)
                {
                    // Nyt Vindue highscore.
                }

            break;




        }

    }
}
