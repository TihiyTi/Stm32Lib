#include "stm32f4xx.h"

#include "gpio_driver.h"
#include "tim_driver.h"
int a = 1;

#define timerInterrupt TIM2_IRQHandler

int main(){
    initTimerWithIRQ(TIM2, 1000);
    startTimer(TIM2);
    initGPIO(GPIOD, GPIO_Pin_15);

    while(a){
        a++;
    }
}

void timerInterrupt(){
    if(TIM_GetITStatus(TIM2, TIM_IT_Update) == SET){
        TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
        GPIO_ToggleBits(GPIOD, GPIO_Pin_15);
    }
}