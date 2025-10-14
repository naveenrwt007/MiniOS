#include <stdio.h>
#include "fs.h"
#include "shell.h"
#include "mm.h"
#include "proc.h"

int main() {
    printf("Welcome to MiniOS Shell! Type 'help' for available commands\n");

    mm_init();
    proc_init();
    fs_init();

    proc_create("shell", shell_task);
    proc_run();

    printf("System Halted.\n");
    return 0;
}