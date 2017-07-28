#include <stdio.h>
#include <string.h>
#include <queue.h>
#include <uart_logger.h>
#include "stm32f4xx.h"
#include "uart_logger.h"

int a = 1;

QueueInt32 queueInt32;

void Delay(uint32_t delay);

const char word1[] = "word1";
const char word2[] = "word2";

int main() {

    initLogger();

    addToLoggerQueue((char *)word1, 5);
    addToLoggerQueue((char *)word1, 5);
    addToLoggerQueue((char *)word1, 5);
    addToLoggerQueue((char *)word1, sizeof(word1)/sizeof(char));
    addToLoggerQueue((char *)word1, 5);

    Pair pair;
    takeFromLoggerQueue(&pair);
    sendStringByDMAAfterWait(pair.pointer, pair.size);
    takeFromLoggerQueue(&pair);
    sendStringByDMAAfterWait(pair.pointer, pair.size);
    takeFromLoggerQueue(&pair);
    sendStringByDMAAfterWait(pair.pointer, pair.size);
    takeFromLoggerQueue(&pair);
    sendStringByDMAAfterWait(pair.pointer, pair.size);
    takeFromLoggerQueue(&pair);
    sendStringByDMAAfterWait(pair.pointer, pair.size);


    sendStringByDMAAfterWait(word2, (uint8_t) 12);

    for (int j = 0; j < 4; ++j) {
        char str[3] = {0,0,0};
        int size;
        if(isContainsElementQueueInt32(&queueInt32)){
            size = sprintf(str, "%d", (int) takeFromHeadQueueInt32(&queueInt32));
        }
        sendStringByDMAAfterWait(str, (uint8_t) size);
    }

    while(a){
        for (int i = 0; i < 10; ++i) {
            sendStringByDMAandWait("Hello", 5);
            char str_data[10];
            sprintf(str_data, "%s %d %s", "World! ", i, "\n");
            sendStringByDMAandWait(str_data, 10);
        }
        Delay(2000000);
    }
}

void Delay(uint32_t delay){
    while (delay > 1){
        delay--;
    }
}