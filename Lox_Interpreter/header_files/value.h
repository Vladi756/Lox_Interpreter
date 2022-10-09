#ifndef clox_value_h 
#define clox_value_h

#include "../header_files/common.h"

// abstraction of how doubles are represented in Lox 
typedef double Value; 

typedef struct {
	int capacity;
	int count; 
	Value* values;
} ValueArray;

// Function declarations for Value Array 
void initValueArray(ValueArray* a);
void writeValueArray(ValueArray* a, Value v);
void freeValueArray(ValueArray* a);
void printValue(Value value);

#endif
