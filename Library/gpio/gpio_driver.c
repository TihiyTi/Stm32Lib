//
// Created by Alex on 15.08.2017.
//

#include <stm32f4xx.h>
#include "gpio_driver.h"
/*
 * LD3 -  PD13
 * LD4 -  PD12
 * LD5 -  PD14
 * LD6 -  PD15
 */
void initDiscLed(LDx_Color led){
    switch (led){
        case LD3_ORANGE:
            initGPIO(GPIOD, GPIO_Pin_13);
            break;
        case LD4_GREEN:
            initGPIO(GPIOD, GPIO_Pin_12);
            break;
        case LD5_RED:
            initGPIO(GPIOD, GPIO_Pin_14);
            break;
        case LD6_BLUE:
            initGPIO(GPIOD, GPIO_Pin_15);
            break;
        default:
            break;
    }
}
void testDscLedOn(){
    GPIO_SetBits(GPIOD, GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
}
void initGPIO(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin){
    switch ((uint32_t)GPIOx){
        case (uint32_t)GPIOA:
            RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
            break;
        case (uint32_t)GPIOB:
            RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
            break;
        case (uint32_t)GPIOC:
            RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
            break;
        case (uint32_t)GPIOD:
            RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
            break;
        case (uint32_t)GPIOE:
            RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
            break;
        default:
            break;
    }
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin;
    GPIO_Init(GPIOx, &GPIO_InitStructure);
};
