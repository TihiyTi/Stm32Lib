//
// Created by Alex on 27.07.2017.
//

#ifndef STMSAMPLE_UART_BUFFER_H
#define STMSAMPLE_UART_BUFFER_H

void initBuffer(USART_TypeDef* UART, uint32_t speed,
                QueueByte* queueByte, uint8_t * buf,uint8_t size);
uint8_t takeFromRX(USART_TypeDef* UART);
uint8_t isContainRX(USART_TypeDef* UART);

#endif //STMSAMPLE_UART_BUFFER_H
