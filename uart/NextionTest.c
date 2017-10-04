#include "stm32f4xx.h"
#include "inc/uart_driver.h"
#include "nextion_manager.h"


int main(){
    nextionInit();
    testUART(UART4);
    while(1){

    }
}