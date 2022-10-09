#ifndef clox_vm_h
#define clox_vm_h

#include "chunk.h"

// Virtual Machine to read and execute chunks of bytecode 
typedef struct {
	Chunk* chunk;
	// byte pointer - acts as instruction pointer or program counter IP or PC 
	uint8_t ip;
} VM;

// Return code from VM after interpreting chunk 
typedef enum {
	INTERPRET_OK,
	INTERPRET_COMPILE_ERROR,
	INTERPRET_RUNTIME_ERROR
} InterpretResult;


// Virtual Machine functions 
void initVM();
void freeVM();

InterpretResult interpetC(Chunk* chunk);

#endif