#include "../header_files/common.h"
#include "../header_files/debug.h"
#include "../header_files/vm.h"
#include <stdio.h>

VM vm;
// create virtual machine 
void initVM() {
}
// free memory occupied by virtual machine 
void freeVM() {
}
// runs the VM 
static InterpretResult run() {
// Initialize instruction pointer to point to the next instruction 
#define READ_BYTE() (*vm.ip++)
// reads the next byte from the bytecode, treats the resulting
// number as an index, and looks up the corresponding Value in the chunk’s
// constant table
#define READ_CONSTANT() (vm.chunk->constants.values[READ_BYTE()])
	for (;;) {
#ifdef DEBUG_TRACE_EXECUTION 
		disassembleInstruction(vm.chunk, (int)(vm.ip - vm.chunk->code));
#endif
		uint8_t instruction;
		// Determines the opcode of the instruction to be executed 
		switch (instruction = READ_BYTE()) {
		case OP_CONSTANT: {
			Value constant = READ_CONSTANT();
			printValue(constant);
			printf("\n");
			break;
		}
		case OP_RETURN: {
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