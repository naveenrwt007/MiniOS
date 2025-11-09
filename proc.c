#include "proc.h"
#include <stdio.h>
#include <string.h>

static process procs[MAX_PROCS];
static int proc_count = 0;
static int next_pid = 1;

void proc_init() {
    proc_count = 0;
}

process* proc_get_all() {
    return procs;
}

int proc_get_count() {
    return proc_count;
}

void run_simulated_process(const char* name) {
    for (int i = 0; i < MAX_PROCS; i++) {
        if (strcmp(procs[i].name, name) == 0 && procs[i].state == READY) {
            procs[i].state = RUNNING;
            printf("Running process %s (PID %d)\n", procs[i].name, procs[i].pid);
            if (procs[i].entry_point)
                procs[i].entry_point();
            procs[i].state = TERMINATED;
            return;
        }
    }
    printf("No READY process named '%s' found.\n", name);
}

int proc_create(const char* name, void (*entry)()) {
    if (proc_count >= MAX_PROCS) return -1;
    process* p = &procs[proc_count++];
    p->pid = next_pid++;
    strcpy(p->name, name);
    p->state = READY;
    p->entry_point = entry; // may be NULL for real processes
    return p->pid;
}

void proc_run() {
    for (int i = 0; i < proc_count; i++) {
        if (procs[i].state == READY) {
            procs[i].state = RUNNING;
            printf("Running process %s (PID %d)\n", procs[i].name, procs[i].pid);
            if (procs[i].entry_point) {
                procs[i].entry_point();
            } else {
                printf("No entry point for process '%s'. Skipping execution.\n", procs[i].name);
            }
            procs[i].state = TERMINATED;
        }
    }
}

void proc_list() {
    printf("Process Table:\n");
    for (int i = 0; i < proc_count; i++) {
        printf("PID %d: %s [%s]\n", procs[i].pid, procs[i].name,
            procs[i].state == READY ? "READY" :
            procs[i].state == RUNNING ? "RUNNING" :
            procs[i].state == WAITING ? "WAITING" : "TERMINATED");
    }
}