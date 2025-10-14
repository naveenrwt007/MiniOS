#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "history.h"
#include "utils.h"

#define MAX_HISTORY 100

char *history[MAX_HISTORY];
int history_count = 0;

void save_history(const char *cmd) {
    if (history_count < MAX_HISTORY) {
        history[history_count++] = safe_strdup(cmd);
    } else {
        free(history[0]);
        for (int i = 1; i < MAX_HISTORY; i++)
            history[i - 1] = history[i];
        history[MAX_HISTORY - 1] = safe_strdup(cmd);
    }
}

void show_history() {
    printf("Command History:\n");
    for (int i = 0; i < history_count; i++)
        printf("%d: %s\n", i + 1, history[i]);
}

void clear_history() {
    for (int i = 0; i < history_count; i++) {
        free(history[i]);
        history[i] = NULL;
    }
    history_count = 0;
}