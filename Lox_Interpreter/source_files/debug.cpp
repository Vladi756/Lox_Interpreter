#include <stdio.h>
#include "../header_files/debug.h"
#include "../header_files/value.h"

void disassembleChunk(Chunk* chunk, const char* name) {
	// print chunk being dissasembled
	printf("== %s ==\n", name);

	// dissasemble each instruction of chunk 
	for (int offset = 0; offset < chunk->count;) {
		offset = disassembleInstruction(chunk, offset);
	}
}
// Function to disassemble OP_RETURN opcpde 
static int simpleInstruction(const char* name, int offset) {
	printf("%s\n", name);
	return offset + 1;
}

// Function to disassemble OP_CONSTANT opcode
static int constantInstruction(const char* name, Chunk* chunk,
	int offset) {
	uint8_t constant = chunk->code[offset + 1];
	printf("%-16s %4d '", name, constant);
	printValue(chunk->constants.values[constant]);
	printf("'\n");
	// the beginning of the next instruction offset + 2 
	// 1 for the opcode, and 1 more for the constant so 2 bytes + the offset 
	return offset + 2;
}

int disassembleInstruction(Chunk* chunk, int offset) {
	printf("%04d ", offset);
	uint8_t instruction = chunk->code[offset];
	switch (instruction) {
	case OP_CONSTANT:
		return constantInstruction("OP_CONSTANT", chunk, offset);
	case OP_RETURN:
		return simpleInstruction("OP_RETURN", offset);
	default:
		printf("Unknown opcode %d\n", instruction);
		return offset + 1;
	}
}