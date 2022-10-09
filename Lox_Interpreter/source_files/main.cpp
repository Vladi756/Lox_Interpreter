#include "../header_files/common.h"
#include "../header_files/chunk.h"
#include "../header_files/debug.h"

// argc is Argument count || How many arguments are being passed into the executable. 
// argv is Argument Values || A pointer to an array of characters.
int main(int argc, const char* argv[]) {
	Chunk chunk;
	// reates chunk
	initChunk(&chunk);
	writeChunk(&chunk, OP_RETURN);
	// create constant to add to chunk - 1.3 chosen arbitrarily 
	int constant = addConstant(&chunk, 1.3);
	writeChunk(&chunk, OP_CONSTANT);

	// disassemblers take in machine code and output readable Assembly instructions
	disassembleChunk(&chunk, "test chunk");
	freeChunk(&chunk);

	return 0;
}