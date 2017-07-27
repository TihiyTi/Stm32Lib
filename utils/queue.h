/*
 * dsp.h
 *
 *  Created on: 24 ���. 2017 �.
 *      Author: Aleksey
 */
#include "stm32f4xx.h"

#ifndef DSP_H_
#define DSP_H_

#define SIZE_DSP_BUFFER 256

typedef int32_t queueElement;
typedef struct {
	queueElement buf[SIZE_DSP_BUFFER];
	uint8_t first;
	uint8_t last;
	uint8_t size;
}QueueInt32;

void addToQueueInt32(QueueInt32 *A, queueElement el);
void initQueueInt32(QueueInt32 *A);
int32_t takeFromHeadQueueInt32(QueueInt32 *A);
uint8_t isContainsElementQueueInt32(QueueInt32 *A);
int32_t getElementQueueInt32(QueueInt32 *A, uint8_t shift);

#endif /* DSP_H_ */