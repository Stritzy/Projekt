#define ESC 0x1B
#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" // Input/output libreay for this course
#include "LUT.h"
#include "ansi.h"
#include "trig.h"

int32_t zinus(int theta){
    if( theta<0){
            return (int32_t)(SIN[512+theta]);
    //return -(int32_t)SIN[theta];
    }
   else{
        return (int32_t)SIN[theta];
    }
}

int32_t kozinusus(int theta){
    return (int32_t)(zinus(theta + 128));
}

void printFix(int32_t i)

{
// Prints a signed 16.16 fixed point number
    if ((i & 0x80000000) != 0)   // Handle negative numbers
    {
        printf("-");
        i = ~i + 1;
    }
    printf("%ld.%04ld", i >> 16, 10000 * (uint32_t)(i & 0xFFFF) >> 16);
// Print a maximum of 4 decimal digits to avoid overflow
}

int32_t expand(int32_t i)
{
// Converts an 18.14 fixed point number to 16.16
    return i << 2;
}

void initVector(struct vector_t *v, int32_t x, int32_t y){
        (*v).x = x << FIX14_SHIFT;
        (*v).y = y << FIX14_SHIFT;
}

void rotateVec(struct vector_t *v, int32_t theta){
        int32_t X = FIX14_MULT((*v).x, kozinusus(theta)) - FIX14_MULT((*v).y, zinus(theta));
        int32_t Y = FIX14_MULT((*v).x, zinus(theta)) + FIX14_MULT((*v).y, kozinusus(theta));

        (*v).x = X;
        (*v).y = Y;

}

void ballVector(struct ball_t *b){
        initVector(&(*b).pos,7,14);
        initVector(&(*b).vel,1,1);
}


void ballUpdate(struct ball_t *b){
        int32_t X = (*b).pos.x + FIX14_MULT((*b).vel.x,10000);
        int32_t Y = (*b).pos.y + FIX14_MULT((*b).vel.y,10000);
        (*b).pos.x = X;
        (*b).pos.y = Y;
        gotoxy((*b).pos.x >> 14,(*b).pos.y >> 14);
        printf("%c", 111);

}

/*void ball(int x.y, int v.y){
        gotoxy(expand(v.x),expand(v.y));
        printf("%c",233);
*/




