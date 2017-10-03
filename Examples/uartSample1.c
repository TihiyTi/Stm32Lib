#include <stdio.h>
#include <string.h>
#include <queue.h>
#include "stm32f4xx.h"
#include "../Library/uart/uart_driver.h"
#include "../Library/uart/uart_buffer.h"

void Delay(uint32_t delay);

int a = 1;
QueueInt32 queueInt32;
const char word1[] = "word1";
const char word2[] = "word2";

QueueByte rxQueue;
uint8_t array[32];

int main() {
    initBuffer(USART3, 115200, &rxQueue, array, 32);
    testUART(USART3);
    Delay(100000);
    while(a) {
        if(isContainRX(USART3) > 0){
            uint8_t out = takeFromRX(USART3);
            USART_SendData(USART3, out);
            while (USART_GetFlagStatus(USART3, USART_FLAG_TC) == RESET){}
        }
    }
}

void Delay(uint32_t delay){
    while (delay > 1){
        delay--;
    }
}
