#ifndef LCD_H
#define LCD_H

#define ESC 0x1B
#include "stm32f30x_conf.h"
#include "30010_io.h"




void lcd_write_string(char *str, uint8_t *buffer2, int16_t forskydning, int16_t linje);

void updatebuf(uint8_t *buffer2, uint8_t *buffer);

void lcd_update(uint8_t *buffer, uint8_t * buffer2, uint32_t *flagUpdate);

void leftbigbuf(uint8_t *buffer2);

void right(uint8_t *buffer);

void left(uint8_t *buffer);

#endif
