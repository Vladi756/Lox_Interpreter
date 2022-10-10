#include "../header_files/common.h"
#include "../header_files/vm.h"

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
	for (;;) {
		uint8_t instruction;
		switch (instruction = READ_BYTE()) {
		case OP_RETURN: {
			return INTERPRET_OK;
		}
		}
	}
#undef READ_BYTE
}

InterpretResult interpret(Chunk* chunk) {
	vm.chunk = chunk; 
	vm.ip = vm.chunk->count;
	return run();
}