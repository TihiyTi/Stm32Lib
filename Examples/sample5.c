//Work with 407 and 429 dev board
#include "stm32f4xx.h"

#include <stdio.h>
#include "SEGGER_SYSVIEW.h"
#include "SEGGER_RTT.h"

#include "gpio_driver.h"
#include "tim_driver.h"

#define timerInterrupt TIM2_IRQHandler

#define SEGGER_SYSVIEW_GET_TIMESTAMP() (*(U32 *)(0xE0001004))
#define SEGGER_SYSVIEW_TIMESTAMP_BITS (32)

void seggerTest();

volatile int _Cnt;
volatile int a = 1;

int main(){

    SEGGER_SYSVIEW_Conf();
    SEGGER_RTT_ConfigUpBuffer(0, NULL, NULL, 0, SEGGER_RTT_MODE_BLOCK_IF_FIFO_FULL);

    SEGGER_RTT_printf(0, "SystemView from SEGGER with printf load", 0);

    initTimerWithIRQ(TIM2, 1000);
    startTimer(TIM2);
    initDiscLed(LD3_ORANGE);
//    initGPIO(GPIOD, GPIO_Pin_15);

    while(a){
        a++;
    }
}

void timerInterrupt(){
    SEGGER_SYSVIEW_RecordEnterISR();
    if(TIM_GetITStatus(TIM2, TIM_IT_Update) == SET){
        TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
        GPIO_ToggleBits(LED_PORT, LD_ORANGE_Pin);
        SEGGER_RTT_printf(0, "Togle LED, a : %p.\r\n", a);
    }
    SEGGER_SYSVIEW_RecordExitISR();
}