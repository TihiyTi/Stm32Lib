#include <stm32f4xx.h>
#include <queue.h>
#include "uart_buffer.h"
#include "uart_driver.h"

QueueByte* queueByteUSART1;
uint8_t * bufUSART1;

QueueByte* queueByteUSART3;
uint8_t * bufUSART3;

QueueByte* queueByteUSART4;
uint8_t * bufUSART4;

void initBuffer(USART_TypeDef* UART, uint32_t speed,
                QueueByte* queueByte, uint8_t * buf){
    initUSART(UART, speed, DMA_ENABLE, IRQ_ENABLE);
    switch ((uint32_t)UART) {
        case (uint32_t) USART1:
            queueByteUSART1 = queueByte;
            bufUSART1 = buf;
            queueByteUSART1->buf = bufUSART1;
            break;
        case (uint32_t) USART2:
            //todo не реализовано для USART2
            break;
        case (uint32_t) USART3:
            queueByteUSART3 = queueByte;
            bufUSART3 = buf;
            queueByteUSART3->buf = bufUSART3;
            break;
        case (uint32_t) UART4:
            queueByteUSART4 = queueByte;
            bufUSART4 = buf;
            queueByteUSART4->buf = bufUSART4;
        default:
            break;
    }

}

#if defined(BUFFER_UART1)
void USART1_IRQHandler(){
    if (USART_GetITStatus(USART1, USART_IT_RXNE) != RESET){
		USART_ClearITPendingBit(USART1, USART_IT_RXNE);
		uint8_t rxByte = (uint8_t) USART_ReceiveData(USART1);
        addToQueueByte(queueByteUSART1, rxByte);
	}
	if(USART_GetITStatus(USART1, USART_IT_ORE)!= RESET){
		USART_ClearITPendingBit(USART1, USART_IT_ORE);
//		error_uart1_rx ++;
	}
}
#endif

#if defined(BUFFER_UART2)
void USART2_IRQHandler(){
	if (USART_GetITStatus(USART2, USART_IT_RXNE) != RESET){
		USART_ClearITPendingBit(USART2, USART_IT_RXNE);

		rxByte = (uint8_t) USART_ReceiveData(USART2);
		addToRX1Buffer(rxByte);
	}
	if(USART_GetITStatus(USART2, USART_IT_ORE)!= RESET){
		USART_ClearITPendingBit(USART2, USART_IT_ORE);
		error_uart1_rx ++;
	}
}

#endif

#if defined(BUFFER_UART3)
void USART3_IRQHandler(){
    __disable_irq();
	if (USART_GetITStatus(USART3, USART_IT_RXNE) != RESET){
		USART_ClearITPendingBit(USART3, USART_IT_RXNE);
        uint8_t rxByte = (uint8_t) USART_ReceiveData(USART3);
        addToQueueByte(queueByteUSART3, rxByte);
	}
	if(USART_GetITStatus(USART3, USART_IT_ORE)!= RESET){
		USART_ClearITPendingBit(USART3, USART_IT_ORE);
//		error_uart1_rx ++;
	}
    __enable_irq();
}
#endif

#if defined(BUFFER_UART4)
void UART4_IRQHandler(){
    __disable_irq();
    if (USART_GetITStatus(UART4, USART_IT_RXNE) != RESET){
        USART_ClearITPendingBit(UART4, USART_IT_RXNE);
        uint8_t rxByte = (uint8_t) USART_ReceiveData(UART4);
        addToQueueByte(queueByteUSART4, rxByte);
    }
    if(USART_GetITStatus(UART4, USART_IT_ORE)!= RESET){
        USART_ClearITPendingBit(UART4, USART_IT_ORE);
    }
    __enable_irq();
}
#endif


uint8_t takeFromRX(USART_TypeDef* UART){
    uint8_t result;
    switch ((uint32_t)UART) {
        case (uint32_t) USART1:
            USART_ITConfig(USART1, USART_IT_RXNE, DISABLE);
            result = takeQueueByte(queueByteUSART1);
            USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
            break;
        case (uint32_t) USART2:
            //todo не реализовано для USART2
            result = 0;
            break;
        case (uint32_t) USART3:
            //Block add element to queue to DISABLE irq from UART
            // Safety take element from queue
            USART_ITConfig(USART3, USART_IT_RXNE, DISABLE);
            result = takeQueueByte(queueByteUSART3);
            USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);
            break;
        default:
            result = 0;
            break;
    }
    return result;
}

uint8_t isContainRX(USART_TypeDef* UART){
    if(UART == USART1){
        return queueByteUSART1 -> size;
    }else if(UART == USART2){
        //todo unsupported yet
        return 0;
    }else if(UART == USART3){
        return queueByteUSART3 -> size;
    }else{
        return 0;
    }
}