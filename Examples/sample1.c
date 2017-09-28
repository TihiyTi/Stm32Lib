//Work with 407 and 429 dev board
#include "stm32f4xx.h"
#include "rcc_driver.h"
#include "gpio_driver.h"

int main(){
    int a = 1;
    initDiscLed(LD3_ORANGE);
    initDiscLed(LD4_GREEN);
    initDiscLed(LD5_RED);
    initDiscLed(LD6_BLUE);
    testDscLedOn();

    while(a){
        for (int i = 0; i < 1000000; ++i) {}
        GPIO_ToggleBits(LED_PORT, LD_ORANGE_Pin);
        GPIO_ToggleBits(LED_PORT, LD_BLUE_Pin);
        GPIO_ToggleBits(LED_PORT, LD_GREEN_Pin);
        GPIO_ToggleBits(LED_PORT, LD_RED_Pin);
        a++;
    }
}
