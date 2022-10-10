#include "../header_files/common.h"
#include "../header_files/chunk.h"
#include "../header_files/debug.h"
#include "../header_files/vm.h"

// argc is Argument count || How many arguments are being passed into the executable. 
// argv is Argument Values || A pointer to an array of characters.
int main(int argc, const char* argv[]) {
	initVM();
	// if you pass no arguments you are dropped into a REPL
	if (argc == 1) {
		repl();
	}
	// 1 argument is understood as a path to a file to be run
	else if (argc == 2) {
		runFile(argv[1]);
	}
	else {
		fprintf(stderr, "Usage: clox [path]\n");
		exit(64);
	}
	freeVM();
	return 0;
}