//
// Created by Aleksey on 12.08.2017.
//
#include "stm32f4xx.h"
#include "stm32f4xx_dac.h"
//#include "dac_driver.h"
#include "../../Library/dac/dac_driver.h"

//#define NUM_OF_SIGNAL_POINT 40
uint16_t form0[40] = {0, 312, 616, 904, 1176, 1416, 1616, 1784, 1904, 1976,
                                       2000, 2000,	2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
                                       2000, 1000, 200, 0, 0, 0, 0, 0, 0, 0,
                                       0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int a = 1;

//Test complete TIM2, TIM4, TIM5,
int main(){

    initDACwithDMA(DAC_Channel_2, TIM5, form0, 40);
    timerConfigForDAC_DMA(TIM5, 0xFFFF, 9, 0);

    DMA_Cmd(DMA1_Stream6, ENABLE);

    TIM_TypeDef *timer =  TIM2;
    initDACwithDMA(DAC_Channel_1, timer, form0, 40);
    timerConfigForDAC_DMA(timer, 0xFFFF, 9, 0);

    DMA_Cmd(DMA1_Stream5, ENABLE);
    while(a){
        a++;
    }
}