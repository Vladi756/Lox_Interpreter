#ifndef clox_memory_h
#define clos_memory_h

#include "common.h"


// this macro calculates a new capacity given the current capacity 
#define GROW_CAPACITY(capacity) \
	((capacity) < 8 ? 8 : capacity * 2)

// takes care of getting the size of the array’s element type
// and casting the resulting void* back to a pointer of the right type
#define GROW_ARRAY(type, pointer, oldCount, newCount) \
 (type*)reallocate(pointer, sizeof(type) * (oldCount), \
 sizeof(type) * (newCount))

void* reallocate(void* pointer, size_t oldSize, size_t newSize);


#endif