#include "../header_files/common.h"
#include "../header_files/debug.h"
#include "../header_files/vm.h"
#include <stdio.h>

VM vm;

// resets the stack to a clean slate 
static void resetStack() {
	vm.stackTop = vm.stack;
}

// create virtual machine 
void initVM() {
	resetStack();
}
// free memory occupied by virtual machine 
void freeVM() {
}
// VM's Stack Functions 
void push(Value value) {
	// de-referencing then setting to value 
	*vm.stackTop = value;
	vm.stackTop++;
}
Value pop() {
	vm.stackTop--;
	return *vm.stackTop;
}

// runs the VM 
static InterpretResult run() {
// Initialize instruction pointer to point to the next instruction 
#define READ_BYTE() (*vm.ip++)
// reads the next byte from the bytecode, treats the resulting
// number as an index, and looks up the corresponding Value in the chunk’s
// constant table
#define READ_CONSTANT() (vm.chunk->constants.values[READ_BYTE()])
#define BINARY_OP(op) \
 do { \
	double b = pop(); \
	double a = pop(); \
	push(a op b); \
	} while (false)
	for (;;) {
#ifdef DEBUG_TRACE_EXECUTION 
		printf(" ");
		// print the stack trace when in debug mode 
		for (Value* slot = vm.stack; slot < vm.stackTop; slot++) {
			printf("[ ");
			printValue(*slot);
			printf(" ]");
		}
		printf("\n");
		disassembleInstruction(vm.chunk, (int)(vm.ip - vm.chunk->code));
#endif
		uint8_t instruction;
		// Determines the opcode of the instruction to be executed 
		switch (instruction = READ_BYTE()) {
		case OP_CONSTANT: {
			Value constant = READ_CONSTANT();
			// producing a value == pushing it on to the stack 
			push(constant);
			break;
		}
		case OP_ADD: BINARY_OP(+); break;
		case OP_SUBTRACT: BINARY_OP(-); break;
		case OP_MULTIPLY: BINARY_OP(*); break;
		case OP_DIVIDE: BINARY_OP(/ ); break;
		case OP_NEGATE: push(-pop()); break;  // negate most recent value 
		case OP_RETURN: {
			printValue(pop());
			printf("\n");
			return INTERPRET_OK;
		}
		}
	}
#undef READ_BYTE
#undef READ_CONSTANT
}

// An instruction is broken down into its OP Code and the instruction itself. 
// Given an opcode we have to determine which C code this refers to - and execute it! 
// The above process is called 'decoding'the instruction. 

InterpretResult interpret(Chunk* chunk) {
	vm.chunk = chunk; 
	vm.ip = vm.chunk->code;
	return run();
}