//
// Created by Alex on 25.07.2017.
//

#ifndef UART_DRIVER_H
#define UART_DRIVER_H

void initLogger();
void sendStringByDMA();
void initUART(USART_TypeDef* UART, uint32_t speed);
void logByteUnsafe(char ch);

#if !defined(LOG_USART1) && !defined(LOG_USART2) && !defined(LOG_USART3)
    #error "Don't choose usart for logger"
#endif


#endif //UART_DRIVER_H
