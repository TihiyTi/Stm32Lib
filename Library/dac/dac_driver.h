//
// Created by Aleksey on 12.08.2017.
//

#ifndef STMSAMPLE_DAC_DRIVER_H
#define STMSAMPLE_DAC_DRIVER_H

#define DAC_DHR12R2_ADDRESS    0x40007414

typedef enum {DMA_DISABLE = 0, DMA_ENABLE = 1}DMA_DAC_State;

void initDAC(uint32_t dac_channel);
void initDACwithDMA(uint32_t dac_channel, TIM_TypeDef * timer);

#endif //STMSAMPLE_DAC_DRIVER_H
