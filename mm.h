#include <stddef.h>
#ifndef MM_H
#define MM_H

#define HEAP_SIZE (1024 * 64)  // 64 KB

void mm_init();
void* mm_alloc(size_t size);
void mm_free(void* ptr);
void mm_status();

#endif