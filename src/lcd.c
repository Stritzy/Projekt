#include "charset.h"
#include "lcd.h"
#include "timer.h"



void lcd_write_string(char *str, uint8_t *buffer2, int16_t forskydning, int16_t linje){
    int k = 0;

    while (str[k] != 0x00){
        for (int i = 0 ; i < 5 ; i++){
           buffer2[forskydning + linje * 128 + i + k * 5] = character_data[str[k] - 0x20][i];
        }

        k++;
    }
}
void updatebuf(uint8_t *buffer2, uint8_t *buffer){
for(int i=0;i<128;i++){
    buffer[i]=buffer2[i];
}
}

void lcd_update(uint8_t *buffer, uint8_t *buffer2, uint32_t *flagUpdate){
    if(flag){
            *flagUpdate = *flagUpdate + 1;
        if(*flagUpdate >= 200){

            //left(buffer);
            leftbigbuf(buffer2);
            flag = 0;
            lcd_push_buffer(buffer);
            *flagUpdate = 0;
        }
    }
}

void right(uint8_t *buffer){
        int i = 127;
        uint32_t temp = buffer[0];
        while(i > 0){
            int k = i + 1;
            k &= 0x7F;
            buffer[k] = buffer[i];
            i = i - 1;
            }

        buffer[1] = temp;
}

void left(uint8_t *buffer){
    int i = 0;
        uint8_t temp = buffer[127];
        while(i < 127){
            int k = i - 1;
            k &= 0x7F;
            buffer[k] = buffer[i];
            i = i + 1;
            }

        buffer[126] = temp;
}

void leftbigbuf(uint8_t *buffer2){
    int i = 0;
        uint8_t temp = buffer2[511];
        while(i < 511){
            uint16_t k = i - 1;
            k &= 0x1FF;
            buffer2[k] = buffer2[i];
            i = i + 1;
        }

        buffer2[510] = temp;
}


