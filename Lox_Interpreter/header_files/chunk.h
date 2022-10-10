#ifndef clox_chunk_h
#define clox_chunk_h

#include "common.h"
#include "../header_files/value.h"

// defining instructions operational codes 
typedef enum {
	OP_CONSTANT,    // defines operation involving constants
	OP_RETURN,		// return from current function or loop
	OP_NEGATE,      // the minus operand
	OP_ADD,			// Binary arithmetic operators
	OP_SUBTRACT,
	OP_MULTIPLY,
	OP_DIVIDE,
} OpCode;

// dynamic array to store instructions and relevant data 
typedef struct {
	int count;
	int capacity;
	uint8_t* code;  // a type of unsigned integer of length 8 bits -- A byte
	int* lines;
	ValueArray constants; 
} Chunk;

// Chunk ctor
void initChunk(Chunk* chunk);
// memory management
void writeChunk(Chunk* chunk, uint8_t byte, int line);
int addConstant(Chunk* chunk, Value value);
void freeChunk(Chunk* chunk);

#endif
