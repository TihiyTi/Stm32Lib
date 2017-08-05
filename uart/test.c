#include <stdio.h>
#include <string.h>
#include <queue.h>
#include "stm32f4xx.h"
#include "uart_buffer.h"
#include "uart_driver.h"

void Delay(uint32_t delay);

int a = 1;
QueueInt32 queueInt32;
const char word1[] = "word1";
const char word2[] = "word2";

QueueByte queueByte;
uint8_t array[32];

int main() {
    initBuffer(UART4, 115200, &queueByte, array, 32);
    testUART(UART4);
    Delay(100000);
//    testUART(USART3);
    while(a) {
        if(isContainRX(UART4) > 0){
            uint8_t out = takeFromRX(UART4);
            USART_SendData(UART4, out);
            while (USART_GetFlagStatus(UART4, USART_FLAG_TC) == RESET){}
        }
    }
}

void Delay(uint32_t delay){
    while (delay > 1){
        delay--;
    }
}
