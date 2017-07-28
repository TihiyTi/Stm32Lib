# StmSample
Проект примеров работы с периферией STM32f4 и набор библиотечных файлов для работы с этой периферией

## Модуль usart

### Логгер
'usart_driver.c' - логгер для STM32 работающий через USART. Настройка производится путем установки define-ов:
* LOG_SPEED = 115200 - скорость порта
* LOG_USARTx (x = 1,2,3)
        Note: пока полноценная реализация для USART3
* LOG_DMA - включение использования DMA для передачи данных по usart
* LOG_BUF - установка размера буфера

Использование:
Потокозащищенные
`sendStringByDMAandWait(char *str, uint8_t size)` - отправка строки и о
`sendStringByDMAAfterWait(char *str, uint8_t size)`