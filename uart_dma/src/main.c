#include "stm32f4xx.h"

volatile uint8_t a = 1;
volatile uint8_t b = 2;
volatile uint8_t c = 0;

int main() {
    c = b + a;
    c = (uint8_t) (2 * c);
}