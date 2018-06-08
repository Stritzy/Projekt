#define ESC 0x1B
#include "stm32f30x_conf.h"
#include "30010_io.h"
#include "ansi.h"

void fgcolor(int foreground) {
/*  Value      foreground     Value     foreground
    ------------------------------------------------
      0        Black            8       Dark Gray
      1        Red              9       Light Red
      2        Green           10       Light Green
      3        Brown           11       Yellow
      4        Blue            12       Light Blue
      5        Purple          13       Light Purple
      6        Cyan            14       Light Cyan
      7        Light Gray      15       White
*/
  int type = 22;             // normal text
	if (foreground > 7) {
	  type = 1;                // bold text
		foreground -= 8;
	}
  printf("%c[%d;%dm", ESC, type, foreground+30);
}

void bgcolor(int background) {
/* IMPORTANT:   When you first use this function you cannot get back to true white background in HyperTerminal.
   Why is that? Because ANSI does not support true white background (ANSI white is gray to most human eyes).
                The designers of HyperTerminal, however, preferred black text on white background, which is why
                the colors are initially like that, but when the background color is first changed there is no
 	              way comming back.
   Hint:        Use resetbgcolor(); clrscr(); to force HyperTerminal into gray text on black background.

    Value      Color
    ------------------
      0        Black
      1        Red
      2        Green
      3        Brown
      4        Blue
      5        Purple
      6        Cyan
      7        Gray
*/
  printf("%c[%dm", ESC, background+40);
}

void color(int foreground, int background) {
// combination of fgcolor() and bgcolor() - uses less bandwidth
  int type = 22;             // normal text
	if (foreground > 7) {
	  type = 1;                // bold text
		foreground -= 8;
	}
  printf("%c[%d;%d;%dm", ESC, type, foreground+30, background+40);
}

void resetbgcolor() {
// gray on black text, no underline, no blink, no reverse
  printf("%c[m", ESC);
}

void clrscr(){
    printf("%c[2J",ESC);
}

void clreol(){
    printf("%c[K",ESC);
}
void gotoxy(int8_t x,int8_t y){
    printf("%c[%d;%dH",ESC,y,x);
}

void underline(int8_t on){
    if (on == 1)
    printf("%c[%dm",ESC,4);
    else printf("%c[%dm",ESC,24);
}

void blink182(int8_t on){
    if (on == 1)
    printf("%c[%dm",ESC,5);
    else printf("%c[%dm",ESC,25);
}

void inverse(int8_t on){
    if (on == 1)
    printf("%c[%dm",ESC,7);
    else printf("%c[%dm",ESC,27);
}

void windows(int x1,int x2,int y1,int y2){
    gotoxy(x1+1,y1);
    for(int i = 0; i < x2-x1; i++){
        inverse(1);
        printf(" ");
        }

    gotoxy(x1+4,y1);
        printf("Stop watch"); // HEADER TITLE
        inverse(0);

    gotoxy(x1,y2);
    for(int i = 0; i < x2-x1; i++){
        printf("%c",196);
        }
    for(int i = 0; i <= y2-y1; i++){
        gotoxy(x1,y1+i);
        printf("%c",179);
        }
    for(int i = 0; i <= y2-y1; i++){
        gotoxy(x2,y1+i);
        printf("%c",179);
        }
    gotoxy(x1,y1);
    printf("%c",218);

    gotoxy(x2,y1);
    printf("%c",191);

    gotoxy(x1,y2);
    printf("%c",192);

    gotoxy(x2,y2);
    printf("%c",217);

    gotoxy(x1+1,y1);
    printf("%c",180);

    gotoxy(x2-1,y1);
    printf("%c",195);

    gotoxy(x1+2,y1);
    for(int i=x1+2;i<x2-2;i++){
    inverse(1);}
    inverse(0);



}









