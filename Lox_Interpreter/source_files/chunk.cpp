#include <stdlib.h>
#include "../header_files/chunk.h"
#include "../header_files/memory.h"

// Implementation of chunk ctor 
void initChunk(Chunk* chunk) {
	chunk->count = 0;
	chunk->capacity = 0;
	chunk->code = NULL;
}

// Writing chunks
void writeChunk(Chunk* chunk, uint8_t byte) {
	if (chunk->capacity < chunk->count + 1) {
		int oldCapacity = chunk->capacity; 
		chunk->capacity = GROW_CAPACITY(oldCapacity);
		chunk->code = GROW_ARRAY(uint8_t, chunk->code,
			oldCapacity, chunk->capacity);
	}
	chunk->code[chunk->count] = byte;
	chunk->count++;
}

// Manually freeing Memory when needed 
void freeChunk(Chunk* chunk) {
	FREE_ARRAY(uint8_t, chunk->code, chunk->capacity);
	initChunk(chunk);
}