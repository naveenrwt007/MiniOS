#include <stdio.h>
#include "fs.h"
#include "shell.h"

int main() {
    printf("Welcome to MiniOS Shell! Type 'help' for available commands\n");
    fs_init();
    shell();
    printf("System Halted.\n");
    return 0;
}