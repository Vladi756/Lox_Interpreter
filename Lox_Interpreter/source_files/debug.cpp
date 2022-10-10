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
	if (offset > 0 &&
		chunk->lines[offset] == chunk->lines[offset - 1]) {
		printf("   |");
	}
	else {
		printf("%4d", chunk->lines[offset]); 
	}


	uint8_t instruction = chunk->code[offset];
	switch (instruction) {
	case OP_CONSTANT:
		return constantInstruction("OP_CONSTANT", chunk, offset);
	case OP_ADD:
		return simpleInstruction("OP_ADD", offset);
	case OP_SUBTRACT:
		return simpleInstruction("OP_SUBTRACT", offset);
	case OP_MULTIPLY:
		return simpleInstruction("OP_MULTIPLY", offset);
	case OP_DIVIDE:
		return simpleInstruction("OP_DIVIDE", offset);
	case OP_RETURN:
		return simpleInstruction("OP_RETURN", offset);	
	case OP_NEGATE: 
		return simpleInstruction("OP_NEGATE", offset);
	default:
		printf("Unknown opcode %d\n", instruction);
		return offset + 1;
	}
}