#include "stm32f4xx.h"
#include <queue.h>
#include "uart_driver.h"
#include "uart_buffer.h"

#include <stdio.h>
#include "SEGGER_RTT.h"

//#define USART3_addToBuffer USART3_IRQHandler

int a = 1;

QueueByte queueByte;
uint8_t array[32];
BufferDoubleByte txQueue;
uint8_t arrayTX1[16];
uint8_t arrayTX2[16];

int main() {
    SEGGER_RTT_ConfigUpBuffer(0, NULL, NULL, 0, SEGGER_RTT_MODE_BLOCK_IF_FIFO_FULL);

    initBuffer(USART3, 115200, &queueByte, array, 32);
    initBufferTX(USART3, &txQueue, arrayTX1, arrayTX2, 16);
//    testUART(USART3);
//    for (int i = 0; i < 32; ++i) {
//        addToTXBuffer(USART3, i);
//    }

    while(a) {
        if(isContainRX(USART3) > 0){
            uint8_t out = takeFromRX(USART3);
            addToTXBuffer(USART3, out);
        }
//        if(a%1000000 == 0){
//            SEGGER_RTT_printf(0, "Array : \r\n");
//            for (int i = 0; i < 15; ++i) {
//                SEGGER_RTT_printf(0, "element: %p.\r\n", arrayTX1[i]);
//            }
//        }
        a++;
    }
}

