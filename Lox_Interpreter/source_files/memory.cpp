#include "../header_files/memory.h"
#include <stdlib.h>

void* reallocate(void* pointer, size_t oldSize, size_t newSize) {
	// de-allocating memory
	if (newSize == 0) {
		free(pointer);
		return NULL;
	}
	// handles all other cases (is newSize == 0, then realloc = malloc basically)
	void* result = realloc(pointer, newSize);

	return result;
}