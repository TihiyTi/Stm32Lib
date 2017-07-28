//
// Created by Alex on 28.07.2017.
//

#include <stm32f4xx.h>
#include "uart_driver.h"

void initUSART(USART_TypeDef* UART, uint32_t speed, DMA_Trancieve_State dma_state, IRQ_Recieve_State irq_state){
    GPIO_InitTypeDef  GPIO;
    USART_InitTypeDef USART;

    GPIO_StructInit(&GPIO);

    GPIO.GPIO_OType = GPIO_OType_PP;
    GPIO.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO.GPIO_Mode = GPIO_Mode_AF;
    GPIO.GPIO_Speed = GPIO_Speed_50MHz;

    USART.USART_BaudRate = speed;
    USART.USART_WordLength = USART_WordLength_8b;
    USART.USART_StopBits = USART_StopBits_1;
    USART.USART_Parity = USART_Parity_No;
    USART.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;

    switch ((uint32_t)UART){
        case (uint32_t)USART1:
            RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
            RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
            GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_USART1);
            GPIO_PinAFConfig(GPIOA, GPIO_PinSource9, GPIO_AF_USART1);
            GPIO.GPIO_Pin = GPIO_Pin_9|GPIO_Pin_10;
            GPIO_Init(GPIOA, &GPIO);
            break;
        case (uint32_t)USART2:
            RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
            RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
            GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_USART2);
            GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_USART2);
            GPIO.GPIO_Pin = GPIO_Pin_2|GPIO_Pin_3;
            GPIO_Init(GPIOA, &GPIO);
            break;
        case (uint32_t)USART3:
            RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
            RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);
            GPIO_PinAFConfig(GPIOB, GPIO_PinSource10, GPIO_AF_USART3);
            GPIO_PinAFConfig(GPIOB, GPIO_PinSource11, GPIO_AF_USART3);
            GPIO.GPIO_Pin = GPIO_Pin_10|GPIO_Pin_11;
            GPIO_Init(GPIOB, &GPIO);
            break;
        case (uint32_t)UART4:
            RCC_AHB1PeriphClockCmd(RCC_APB1Periph_UART4, ENABLE);
            //todo unsupported yet
        default:break;
    }

    USART_Init(UART, &USART);
    USART_Cmd(UART, ENABLE);


}