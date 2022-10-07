#ifndef clox_chunk_h
#define clox_chunk_h

#include "common.h"

// defining instructions operational codes 
typedef enum {
	OP_RETURN,		// return from current function
} OpCode;

// dynamic array to store instructions and relevant data 
typedef struct {
	int count;
	int capacity;
	uint8_t* code;  // a type of unsigned integer of length 8 bits -- A byte
} Chunk;

// Chunk ctor
void initChunk(Chunk* chunk);
// memory management
void writeChunk(Chunk* chunk, uint8_t byte);
void freeChunk(Chunk* chunk);

#endif
