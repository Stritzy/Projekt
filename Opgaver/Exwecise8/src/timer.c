#define ESC 0x1B
#include "stm32f30x_conf.h"
#include "30010_io.h"
#include "timer.h"


void initTimer()
{

    RCC->APB1ENR |= RCC_APB1Periph_TIM2; //Enable clock line to timer 2
    TIM2->CR1 = 0; //Configure timer 2
    TIM2->ARR = 639999;//Set reload value
    TIM2->PSC = 0; //Set prescale value

    TIM2->DIER |= 0x0001; //enable timer 2 interrupts

    NVIC_SetPriority(TIM2_IRQn, 0); // Set interrupt priority
    NVIC_EnableIRQ(TIM2_IRQn); // Enable interrupt

    TIM2->CR1 |= 0x01;
}

void TIM2_IRQHandler(void)
{
    flag = 1;
    t.cs++;

    if(t.cs >= 100)
    {
        t.s++;
        t.cs=0;
    }
    else if(t.s >= 60)
    {
        t.m++;
        t.s=0;
    }
    else if(t.m >= 60)
    {
        t.h++;
        t.m=0;
    }


    TIM2->SR &= ~0x0001; // CLear interrupt bit
}

int henttaster()
{
    char str[21] = { 0 };
    for (int i=0 ; i < 20 ; i++){
        str[i] = uart_getc();
        if (str[i] == 0x0D) {
            str[i] = 0x00;
            break;
        }
    }

    if (strcmp(str, "start") == 0){
        return 1;}
    else if (strcmp(str, "stop") == 0){
        return 2;}
    else if (strcmp(str, "split1") == 0){
        return 3;}
    else if (strcmp(str, "split2") == 0){
        return 4;}
    else if (strcmp(str, "reset") == 0){
        return 5;}
    else if (strcmp(str, "help") == 0){
        return 6;}
    else if (strcmp(str, " ") != 0){
        return 7;}
    else{
        return 7;
    }
}

void urctrl(){
    int32_t var2 = henttaster();

    if (var2 == 1){
        TIM2->CR1 |= 0x01;
    }
    if (var2 == 2){
        TIM2->CR1 &= 0x00;
    }
    if (var2 == 3){
        gotoxy(5+3,5+6);
        printf("Split time 1: %02d:%02d:%02d:%02d",t.h,t.m,t.s,t.cs);
    }
    if (var2 == 4){
        gotoxy(5+3,5+8);
        printf("Split time 2: %02d:%02d:%02d:%02d",t.h,t.m,t.s,t.cs);
    }
    if (var2 == 5){
        TIM2->CR1 &= 0x00;
        t.cs=0, t.s=0, t.m=0, t.h=0;
    }
    if (var2 == 6){
        gotoxy(5+3,5+12);
        printf("Hvis du ikke kan det her, er du dum!!!!!");
    }
    if (var2 == 7){
        gotoxy(5+3,5+14);
        printf("You are a fool motherfucker");
    }

}


