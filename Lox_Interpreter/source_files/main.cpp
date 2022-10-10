#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../header_files/common.h"
#include "../header_files/chunk.h"
#include "../header_files/debug.h"
#include "../header_files/vm.h"

// create a REPL
static void repl() {
	char line[1024];
	for (;;) {
		printf("> ");
		if (!fgets(line, sizeof(line), stdin)) {
			printf("\n");
			break;
		}
		interpret(line);
	}
}

// reading file 
static char* readFile(const char* path) {
	// file poiner to file
	FILE* file = fopen(path, "rb");
	// error handling 
	if (file == NULL) {
		fprintf(stderr, "Could not open file \"%s\".\n", path);
		exit(74);
	}
	fseek(file, 0L, SEEK_END);
	size_t fileSize = ftell(file);
	rewind(file);
	// casting to char pointer 
	char* buffer = (char*)malloc(fileSize + 1);
	// error handling 
	if (buffer == NULL) {
		fprintf(stderr, "Not enough memory to read \"%s\".\n", path);
		exit(74);
	}
	// reading file
	size_t bytesRead = fread(buffer, sizeof(char), fileSize, file);
	// error handling 
	if (bytesRead < fileSize) {
		fprintf(stderr, "Could not read file \"%s\".\n", path);
		exit(74);
	}
	buffer[bytesRead] = '\0';
	// closing when EOF found
	fclose(file);
	// return pointer to file 
	return buffer;
}

// run given file
static void runFile(const char* path) {
	// path to executable
	char* source = readFile(path);
	InterpretResult result = interpret(source);
	free(source);

	// handling compilation errors 
	if (result == INTERPRET_COMPILE_ERROR) exit(65);
	if (result == INTERPRET_RUNTIME_ERROR) exit(70);
}



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