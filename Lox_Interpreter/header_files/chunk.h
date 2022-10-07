#ifndef clox_chunk_h
#define clox_chunk_h

#include "common.h"

// defining instructions operational codes 
typename enum {
	OP_RETURN,		// return from current function
} OpCode;

// dynamic array to store instructions and relevant data 
typedef struct {
	int count;
	int capacity;
	uint8_t* code;  // a type of unsigned integer of length 8 bits -- A byte
} Chunk;

// Chunk functions
void initChunk(Chunk* chunk);
void writeChunk(Chunk* chunk, uint8_t byte);

#endif
