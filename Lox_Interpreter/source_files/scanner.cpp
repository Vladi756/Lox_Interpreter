#include <stdio.h>
#include <string.h>

#include "../header_files/common.h"
#include "../header_files/scanner.h"

// Scanner struct 
typedef struct {
	const char* start;
	const char* current;
	int line;
} Scanner;

// initializing a new scanner 
Scanner scanner;

// scanner ctor
void initScanner(const char* source) {
	scanner.start = source;
	scanner.current = source;
	scanner.line = 1;
}