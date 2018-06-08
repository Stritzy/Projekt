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
#include "lcd.h"
#include <string.h>


int main(void)
{
    init_usb_uart( 9600 );
    clrscr();
    printf("%c[?25l",ESC); // Fjerner curseren
    gotoxy(0,0);

    init_spi_lcd();
    initTimer();
    uint8_t buffer[512];
    uint8_t buffer2[512];
    uint32_t flagUpdate = 0;
    uint8_t forskydning = 0;

    memset(buffer,0x00,512); // Sets each element of the buffer to 0xAA
    memset(buffer2,0x00,512);

    lcd_write_string("Fucking 8 bit og 32 bit styrer for vildt", buffer2, forskydning, 0);

    while(1)
    {
        updatebuf(buffer2,buffer);
        lcd_update(buffer, buffer2, &flagUpdate);


    }
}
