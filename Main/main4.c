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
#include "30010_io.h" // Input/output libreay for this course
#include "LUT.h"
#include "trig.h"
#include "ansi.h"

int32_t x2; int32_t y2;

int main(void)
{
    init_usb_uart( 9600 );
    clrscr();
    gotoxy(0,0);

    int x1 = 0;
    int x2 = 84;
    int y1 = 0;
    int y2 = 22;
    int counter = 0;
    windows(x1,x2,y1,y2); //Dimension af ydre vindue
    windows((x2/3),(2*x2/3),(y2/2)-1,(y2/2)+1); //Dimension af inderste vindue


    blink182(1);
     //For counteren
    blink182(0);
    struct ball_t b;
    ballVector(&b);
    gotoxy(x2/3+1,y2/2);
    printf("Counter:");

/*
    printFix(expand(v.x));
    printf(" ");
    printFix(expand(v.y));
*/
  while(1){
    gotoxy(x2/3+9,y2/2);
    printf("%d",counter);
    gotoxy(b.pos.x >> 14,b.pos.y >> 14);
    printf(" ");
    ballUpdate(&b);



            if(b.pos.x >> 14  >  x2-2){
                b.vel.x = -b.vel.x;
                counter = counter +1;
                }

            if(b.pos.y >> 14 > y2-2){
                b.vel.y = -b.vel.y;
                counter = counter + 1;
                }

           if(b.pos.x >> 14 < x1+3){
                b.vel.x = -b.vel.x;
                counter = counter +1;
                }

            if(b.pos.y >> 14 < y1+3){
                b.vel.y = -b.vel.y;
                counter= counter +1;
                }


                     if(  (b.pos.x >> 14  >= (x2/3+1) && b.pos.x >> 14  <= (2*x2/3 +1)) && (b.pos.y >> 14 >= (y2/2-1) && b.pos.y >> 14 <= (y2/2+1))  ){
                        windows((x2/3),(2*x2/3),(y2/2)-1,(y2/2)+1);
                        gotoxy(x2/3+1,y2/2);
                        printf("Counter:");
                        }

}
}
