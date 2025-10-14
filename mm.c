#include "mm.h"
#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

typedef struct Block {
    size_t size;
    int free;
    struct Block* next;
} Block;

#define ALIGN4(x) (((((x)-1) >> 2) << 2) + 4)

static uint8_t heap[HEAP_SIZE];
static Block* free_list = NULL;

void mm_init() {
    free_list = (Block*)heap;
    free_list->size = HEAP_SIZE - sizeof(Block);
    free_list->free = 1;
    free_list->next = NULL;
}

void* mm_alloc(size_t size) {
    size = ALIGN4(size);
    Block* curr = free_list;

    while (curr) {
        if (curr->free && curr->size >= size) {
            if (curr->size > size + sizeof(Block)) {
                Block* new_block = (Block*)((uint8_t*)curr + sizeof(Block) + size);
                new_block->size = curr->size - size - sizeof(Block);
                new_block->free = 1;
                new_block->next = curr->next;

                curr->size = size;
                curr->next = new_block;
            }
            curr->free = 0;
            return (void*)((uint8_t*)curr + sizeof(Block));
        }
        curr = curr->next;
    }

    return NULL; // No suitable block found
}

void mm_free(void* ptr) {
    if (!ptr) return;

    Block* block = (Block*)((uint8_t*)ptr - sizeof(Block));
    block->free = 1;

    // Coalesce adjacent free blocks
    Block* curr = free_list;
    while (curr && curr->next) {
        if (curr->free && curr->next->free) {
            curr->size += sizeof(Block) + curr->next->size;
            curr->next = curr->next->next;
        } else {
            curr = curr->next;
        }
    }
}

void mm_status() {
    Block* curr = free_list;
    size_t used = 0, free = 0;

    while (curr) {
        if (curr->free)
            free += curr->size;
        else
            used += curr->size;
        curr = curr->next;
    }

    printf("Memory Status:\n");
    printf("Used: %zu bytes\n", used);
    printf("Free: %zu bytes\n", free);
    printf("Total: %zu bytes\n", (size_t)HEAP_SIZE);
}