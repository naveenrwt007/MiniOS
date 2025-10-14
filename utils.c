#include <stdio.h>
#include <string.h>
#include "utils.h"
#include <stdlib.h>
#include "mm.h"  // Include your memory manager

char* safe_strdup(const char* s) {
    size_t len = strlen(s) + 1;
    char* copy = (char*) mm_alloc(len);
    if (copy) strcpy(copy, s);
    return copy;
}
void clear_screen() {
    printf("\033[2J\033[H");
}

void apply_alias(char *input) {
    if (!strcmp(input, "rm")) strcpy(input, "delete");
    else if (!strcmp(input, "cat")) strcpy(input, "read");
    else if (!strcmp(input, "vi")) strcpy(input, "edit");
}