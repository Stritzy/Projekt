#define ESC 0x1B
#include "stm32f30x_conf.h"
#include "30010_io.h"
#include "joystick.h"


void initJoystick(){

    //Clock initializing
        RCC -> AHBENR  |=  RCC_AHBPeriph_GPIOA; // Enable clock for GPIO Port GPIOx
        RCC -> AHBENR  |=  RCC_AHBPeriph_GPIOB;
        RCC -> AHBENR  |=  RCC_AHBPeriph_GPIOC;
        RCC -> AHBENR  |=  RCC_AHBPeriph_GPIOD;

    // Set pin PC0 to input
        GPIOC -> MODER  &=  ~(0x00000003 << (0*2)); //Clear mode register
        GPIOC -> MODER  |=   (0x00000000 << (0*2)); //Set mode register
                            //(0x00 - input, 0x01 - Outpunt,
                            // 0x02 - alternate function, 0x03 - analog in/out)
        GPIOC -> PUPDR  &=  ~(0x00000003 << (0*2)); //Clear Push/Pull register
        GPIOC -> PUPDR  |=   (0x00000002 << (0*2)); //Set push/pull register
                            //(0x00 - no pull, 0x01 - pullup, 0x02 - pulldown)

    // Set pin PA4 to input
        GPIOA -> MODER  &=  ~(0x00000003 << (4*2)); //Clear mode register
        GPIOA -> MODER  |=   (0x00000000 << (4*2)); //Set mode register
                            //(0x00 - input, 0x01 - Outpunt,
                            // 0x02 - alternate function, 0x03 - analog in/out)
        GPIOA -> PUPDR  &=  ~(0x00000003 << (4*2)); //Clear Push/Pull register
        GPIOA -> PUPDR  |=   (0x00000002 << (4*2)); //Set push/pull register
                            //(0x00 - no pull, 0x01 - pullup, 0x02 - pulldown)

    // Set pin PB5 to input
        GPIOB -> MODER  &=  ~(0x00000003 << (5*2)); //Clear mode register
        GPIOB -> MODER  |=   (0x00000000 << (5*2)); //Set mode register
                            //(0x00 - input, 0x01 - Outpunt,
                            // 0x02 - alternate function, 0x03 - analog in/out)
        GPIOB -> PUPDR  &=  ~(0x00000003 << (5*2)); //Clear Push/Pull register
        GPIOB -> PUPDR  |=   (0x00000002 << (5*2)); //Set push/pull register
                            //(0x00 - no pull, 0x01 - pullup, 0x02 - pulldown)

    // Set pin PC1 to input
        GPIOC -> MODER  &=  ~(0x00000003 << (1*2)); //Clear mode register
        GPIOC -> MODER  |=   (0x00000000 << (1*2)); //Set mode register
                            //(0x00 - input, 0x01 - Outpunt,
                            // 0x02 - alternate function, 0x03 - analog in/out)
        GPIOC -> PUPDR  &=  ~(0x00000003 << (1*2)); //Clear Push/Pull register
        GPIOC -> PUPDR  |=   (0x00000002 << (1*2)); //Set push/pull register
                            //(0x00 - no pull, 0x01 - pullup, 0x02 - pulldown)

    // Set pin PB0 to input
        GPIOB -> MODER  &=  ~(0x00000003 << (0*2)); //Clear mode register
        GPIOB -> MODER  |=   (0x00000000 << (0*2)); //Set mode register
                            //(0x00 - input, 0x01 - Outpunt,
                            // 0x02 - alternate function, 0x03 - analog in/out)
        GPIOB -> PUPDR  &=  ~(0x00000003 << (0*2)); //Clear Push/Pull register
        GPIOB -> PUPDR  |=   (0x00000002 << (0*2)); //Set push/pull register
                            //(0x00 - no pull, 0x01 - pullup, 0x02 - pulldown)
}

void initLED(){

    //Clock initializing
        RCC -> AHBENR  |=  RCC_AHBPeriph_GPIOA; // Enable clock for GPIO Port GPIOx
        RCC -> AHBENR  |=  RCC_AHBPeriph_GPIOB;
        RCC -> AHBENR  |=  RCC_AHBPeriph_GPIOC;

    // Set pin PB4 to output
        GPIOB -> MODER  &=  ~(0x00000003 << (4*2)); //Clear mode register
        GPIOB -> MODER  |=   (0x00000001 << (4*2)); //Set mode register
                            //(0x00 - input, 0x01 - Outpunt,
                            // 0x02 - alternate function, 0x03 - analog in/out)
        GPIOB -> OSPEEDR  &=  ~(0x00000003 << (4*2)); //Clear Push/Pull register
        GPIOB -> OSPEEDR  |=   (0x00000002 << (4*2)); //Set push/pull register
                            //(0x00 - no pull, 0x01 - pullup, 0x02 - pulldown)
        GPIOB -> OTYPER  &=  ~(0x0001 << (4)); // Clear output type register
        GPIOB -> OTYPER  |=   (0x0000 << (4)); // Set output type register
                            //(0x00 - push pull, 0x01 - open drain)


    // Set pin PC7 to output
        GPIOC -> MODER  &=  ~(0x00000003 << (7*2)); //Clear mode register
        GPIOC -> MODER  |=   (0x00000001 << (7*2)); //Set mode register
                            //(0x00 - input, 0x01 - Outpunt,
                            // 0x02 - alternate function, 0x03 - analog in/out)
        GPIOC -> OSPEEDR  &=  ~(0x00000003 << (7*2)); //Clear Push/Pull register
        GPIOC -> OSPEEDR  |=   (0x00000002 << (7*2)); //Set push/pull register
                            //(0x00 - no pull, 0x01 - pullup, 0x02 - pulldown)
        GPIOC -> OTYPER  &=  ~(0x0001 << (7)); // Clear output type register
        GPIOC -> OTYPER  |=   (0x0000 << (7)); // Set output type register
                            //(0x00 - push pull, 0x01 - open drain)

    // Set pin PA9 to output
        GPIOA -> MODER  &=  ~(0x00000003 << (9*2)); //Clear mode register
        GPIOA -> MODER  |=   (0x00000001 << (9*2)); //Set mode register
                            //(0x00 - input, 0x01 - Outpunt,
                            // 0x02 - alternate function, 0x03 - analog in/out)
        GPIOA -> OSPEEDR  &=  ~(0x00000003 << (9*2)); //Clear Push/Pull register
        GPIOA -> OSPEEDR  |=   (0x00000002 << (9*2)); //Set push/pull register

        GPIOA -> OTYPER  &=  ~(0x0001 << (9)); // Clear output type register
        GPIOA -> OTYPER  |=   (0x0000 << (9)); // Set output type register



}

uint8_t readJoystick(){

    //C0 (Right)
    uint16_t val3 = (GPIOC  ->  IDR  &  (0x0001 << 0)) >> 0;

    //A4 (Up)
    uint16_t val0 = (GPIOA  ->  IDR  &  (0x0001 << 4)) >> 4;

    //B5 (Center)
    uint16_t val4 = (GPIOB  ->  IDR  &  (0x0001 << 5)) >> 5;

    //C1 (Left)
    uint16_t val2 = (GPIOC  ->  IDR  &  (0x0001 << 1)) >> 1;

    //B0 (Down)
    uint16_t val1 = (GPIOB  ->  IDR  &  (0x0001 << 0)) >> 0;



    uint8_t returnVal = val0 | val1 << 1 | val2 << 2 | val3 << 3 | val4 << 4;

        return returnVal;
}

void setLED(int returnVal){

    if(returnVal == 0x01){
            GPIOA  ->  ODR  |=  (0x0001 << 9);}
    else if(returnVal == 0x02){
            GPIOB  ->  ODR  |=  (0x0001 << 4);}

}

