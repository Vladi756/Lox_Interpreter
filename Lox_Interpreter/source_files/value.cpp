#include <stdio.h>

#include "../header_files/memory.h"
#include "../header_files/value.h"

//Value array ctor 
void initValueArray(ValueArray* v) {
	v->capacity = 0;
	v->count = 0;
	v->values = NULL;
}
// writing values 
void writeValueArray(ValueArray* a, Value v) {
	if (a->capacity < a->count + 1) {
		int oldCapacity = a->capacity; 
		a->capacity = GROW_CAPACITY(oldCapacity);
		a->values = GROW_ARRAY(Value, a->values,
			oldCapacity, a->capacity);
	}

	a->values[a->count] = v;
	a->count++;
}
// Freeing memory 
void freeValueArray(ValueArray* a) {
	FREE_ARRAY(Value, a->values, a->capacity);
	initValueArray(a);
}