//
// Created by Aleksey on 12.08.2017.
//
#include "stm32f4xx.h"
#include "stm32f4xx_dac.h"
#include "nextion_manager.h"
#include <uart_buffer.h>

uint16_t form0[40] = {0, 312, 616, 904, 1176, 1416, 1616, 1784, 1904, 1976,
                                       2000, 2000,	2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
                                       2000, 1000, 200, 0, 0, 0, 0, 0, 0, 0,
                                       0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int a = 1;

//#define USART4_addToBuffer() UART4_IRQHandler
//void USART4_addToBuffer() __attribute__((used));

int main(void){
    nextionInit();
    while(a){
        nextionProtocolParse();
        a++;
    }
}

void  USART4_addToBuffer() __attribute__ ((weak));
