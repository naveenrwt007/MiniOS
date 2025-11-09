
#include <stdio.h>
#include "fs.h"
#include "shell.h"
#include "proc.h"
#include "mm.h"

void shell_task() {
    shell();
}

int main() {
    printf("Welcome to MiniOS Shell! Type 'help' for available commands\n");

    // Initialize subsystems
    mm_init();       // Memory manager
    proc_init();     // Process manager
    fs_init();       // File system

    // Create shell as a process
    proc_create("shell", shell_task);

    // Run all processes
    proc_run();

    printf("System Halted.\n");
    return 0;
}