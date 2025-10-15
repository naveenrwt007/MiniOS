#ifndef MM_H
#define MM_H

#include <stddef.h>

#define HEAP_SIZE 65536

void mm_init();
void* mm_alloc(size_t size);
void mm_free(void* ptr);
void mm_status();

#endif