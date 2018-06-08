#ifndef TRIG_H
#define TRIG_H

#define ESC 0x1B
#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" // Input/output libreay for this course
#include "LUT.h"

#define FIX14_SHIFT 14
#define FIX14_MULT(a,b) ( (a) * (b) >> FIX14_SHIFT )
#define FIX14_DIV(a, b) ( (a) << FIX14_SHIFT) / b )

int32_t zinus(int theta);

int32_t kozinusus(int theta);

void printFix(int32_t i);

int32_t expand(int32_t i);

struct vector_t{
        int32_t x, y;
};

void initVector(struct vector_t *v, int32_t x, int32_t y);

void rotateVec(struct vector_t *v, int32_t theta);

struct ball_t{
        struct vector_t pos;
        struct vector_t vel;
};

void ballVector(struct ball_t *b);

void ballUpdate(struct ball_t *b);

#endif
