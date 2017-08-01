#include "queue.h"

// Not concurrency method
void addToQueueInt32(QueueInt32 *A, queueElement el){
	if(A->size < SIZE_DSP_BUFFER){
		A->size++;
		A->last = (uint8_t) ((A->first + A->size - 1) % SIZE_DSP_BUFFER);
		A->buf[A->last] = el;
	}else{
		//todo increment error counter
	}
}

// Not concurrency method
int32_t getElementQueueInt32(QueueInt32 *A, uint8_t shift){
	uint16_t i;
	if(shift > A->last){
		i = (uint16_t) (SIZE_DSP_BUFFER + A->last - shift);
	}else{
		i = A->last - shift;
	}
	return A->buf[i];
}

// Not concurrency method
int32_t takeFromHeadQueueInt32(QueueInt32 *A){
	int32_t result;
	result = A->buf[A->first];
	if(A->first == SIZE_DSP_BUFFER - 1){
		A->first = 0;
	}else{
		A->first ++;
	}
	A->size --;
	return result;
}

uint8_t isContainsElementQueueInt32(QueueInt32 *A){
	if(A->size > 0){
		return 1;
	}
	return 0;

}

void initQueueInt32(QueueInt32 *A){
	A->first = 0;
	A->last = 0;
	A->size = 0;
}

//Methods for byte (uint8_t) queue

void addToQueueByte(QueueByte *A, uint8_t el){
    if(A->size < SIZE_DSP_BUFFER){
        A->size++;
        A->last = (uint8_t) ((A->first + A->size - 1) % SIZE_DSP_BUFFER);
        A->buf[A->last] = el;
    }else{
        //todo increment error counter
    }
}

// Not concurrency method
uint8_t getElementQueueByte(QueueByte *A, uint8_t shift){
    uint16_t i;
    if(shift > A->last){
        i = (uint16_t) (SIZE_DSP_BUFFER + A->last - shift);
    }else{
        i = A->last - shift;
    }
    return A->buf[i];
}

// Not concurrency method
uint8_t takeQueueByte(QueueByte *A){
    uint8_t result;
    result = A->buf[A->first];
    if(A->first == SIZE_DSP_BUFFER - 1){
        A->first = 0;
    }else{
        A->first ++;
    }
    A->size --;
    return result;
}

uint8_t isContainsElementQueueByte(QueueByte *A){
    if(A->size > 0){
        return 1;
    }
    return 0;

}

void initQueueByte(QueueByte *A, uint8_t max){
    A->first = 0;
    A->last = 0;
    A->size = 0;
    A->maxsize = max;
}

