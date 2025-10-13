#include <stdio.h>
#include <string.h>
#include "utils.h"

void clear_screen() {
    printf("\033[2J\033[H");
}

void apply_alias(char *input) {
    if (!strcmp(input, "rm")) strcpy(input, "delete");
    else if (!strcmp(input, "cat")) strcpy(input, "read");
    else if (!strcmp(input, "vi")) strcpy(input, "edit");
}