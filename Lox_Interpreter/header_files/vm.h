#ifndef clox_vm_h
#define clox_vm_h

#include "../header_files/chunk.h"
#include "../header_files/value.h"

// Max stack size 
#define STACK_MAX 256

// Virtual Machine to read and execute chunks of bytecode 
typedef struct {
	Chunk* chunk;
	// byte pointer - acts as instruction pointer or program counter IP or PC 
	uint8_t* ip;
	// the VMs stack 
	Value stack[STACK_MAX];
	// pointer to top of stack 
	Value* stackTop;
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