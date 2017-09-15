#include "stm32f4xx.h"
#include "rcc_driver.h"
#include "gpio_driver.h"

int main(){
    int a = 1;
    initDiscLed(LD3_ORANGE);
    initDiscLed(LD4_GREEN);
    initDiscLed(LD5_RED);
    initGPIO(GPIOD, GPIO_Pin_15);
    testDscLedOn();
    GPIO_ToggleBits(GPIOD, GPIO_Pin_15);

    while(a){
        for (int i = 0; i < 100000; ++i) {}
        GPIO_ToggleBits(GPIOD, GPIO_Pin_15);
        a++;
    }
}
