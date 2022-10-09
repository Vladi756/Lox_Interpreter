#include "../header_files/common.h"
#include "../header_files/chunk.h"
#include "../header_files/debug.h"
#include "../header_files/vm.h"

// argc is Argument count || How many arguments are being passed into the executable. 
// argv is Argument Values || A pointer to an array of characters.
int main(int argc, const char* argv[]) {
	initVM();
	Chunk chunk;
	// creates chunk
	initChunk(&chunk);
	writeChunk(&chunk, OP_RETURN, 123);

	// create constant to add to chunk - 1.3 chosen arbitrarily 
	int constant = addConstant(&chunk, 1.3);
	writeChunk(&chunk, constant, 123);
	writeChunk(&chunk, OP_CONSTANT, 123);

	// disassemblers take in machine code and output readable Assembly instructions
	disassembleChunk(&chunk, "test chunk");

	interpret(&chunk);
	freeVM();
	freeChunk(&chunk);

	return 0;
}