#include <stdio.h>
#include "../header_files/debug.h"


void disassembleChunk(Chunk* chunk, const char* name) {
	// print chunk being dissasembled
	printf("== %s ==\n", name);

	// dissasemble each instruction of chunk 
	for (int offset = 0; offset < chunk->count;) {
		offset = disassembleInstruction(chunk, offset);
	}
}

static int simpleInstruction(const char* name, int offset) {
	printf("%s\n", name);
	return offset + 1;
}

int disassembleInstruction(Chunk* chunk, int offset) {
	printf("%04d ", offset);
	uint8_t instruction = chunk->code[offset];
	switch (instruction) {
	case OP_RETURN:
		return simpleInstruction("OP_RETURN", offset);
	default:
		printf("Unknown opcode %d\n", instruction);
		return offset + 1;
	}
}