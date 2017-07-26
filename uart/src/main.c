#include "stm32f4xx.h"
#include "uart_driver.h"

volatile uint8_t a = 1;
volatile uint8_t b = 2;
volatile uint8_t c = 0;

void Delay(uint32_t delay);

int main() {
//    initUART(USART3, 115200);
    initLogger();

    logByteUnsafe(0x21);
    c = b + a;
    c = (uint8_t) (10 * c);
    while(a){
//        USART_SendData(USART3, 0x21);
//        logByteUnsafe(0x21);
        Delay(2000000);
        sendStringByDMA();
    }
}

void Delay(uint32_t delay){
    while (delay > 1){
        delay--;
    }
}