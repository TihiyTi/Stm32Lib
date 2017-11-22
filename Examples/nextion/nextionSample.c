//
// Created by Aleksey on 12.08.2017.
//
#include "stm32f4xx.h"
#include "uart_buffer.h"
#include "nextion_core.h"

int a = 1;
uint32_t stopCount = 0;

//#define NextionHandler USART6_IRQHandler

int main(void){
    nextionInit(UART4);
    while(a){
        nextionProtocolParse();
        a++;
    }
}

//Function that need extract to nextion manager
void NextionCommand_1(){
    stopCount++;
}
