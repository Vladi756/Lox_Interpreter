#ifndef clox_memory_h
#define clos_memory_h

#include "common.h"


// macro to calculate a new capacity given the current capacity 
#define GROW_CAPACITY(capacity) \
	((capacity) < 8 ? 8 : capacity * 2)

// takes care of getting the size of the array’s element type
// and casting the resulting void* back to a pointer of the right type
#define GROW_ARRAY(type, pointer, oldCount, newCount) \
 (type*)reallocate(pointer, sizeof(type) * (oldCount), \
 sizeof(type) * (newCount))

// freeing chunk array by taking current size and reallocating to 0 size
#define FREE_ARRAY(type, pointer, oldCount) \
	(type*)reallocate(pointer, sizeof(type) * oldCount, 0)

// The above are wrappers for 'reallocate'
void* reallocate(void* pointer, size_t oldSize, size_t newSize);

#endif