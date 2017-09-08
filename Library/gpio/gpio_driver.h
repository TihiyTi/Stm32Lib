//
// Created by Alex on 15.08.2017.
//

#ifndef STMSAMPLE_GPIO_DRIVER_H
#define STMSAMPLE_GPIO_DRIVER_H

typedef enum {LD3_ORANGE = 0, LD4_GREEN = 1, LD5_RED = 2, LD6_BLUE = 3}LDx_Color;

void initDiscLed(LDx_Color led);
void testDscLedOn();
void initGPIO(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);

#endif //STMSAMPLE_GPIO_DRIVER_H
