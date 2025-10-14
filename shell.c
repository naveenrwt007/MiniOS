#include <stdio.h>
#include <string.h>
#include "fs.h"
#include "history.h"
#include "utils.h"
#include "mm.h"
#include "proc.h"

void shell() {
    char input[100], arg1[100], arg2[200];

    while (1) {
        printf("\nMiniOS> ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;

        apply_alias(input);           // Modular aliasing
        save_history(input);         // Track command history

        if (!strcmp(input, "help")) {
            printf("Commands:\n");
            printf("help\nls\nwrite\nread\ndelete\nedit\nrename\nsearch\ninfo\nhistory\nclear\nexport\nreset\nmem\nps\nexit\n");
        } else if (!strcmp(input, "ls")) {
            fs_list();
        } else if (!strcmp(input, "history")) {
            show_history();
        } else if (!strcmp(input, "clear")) {
            clear_screen();
        } else if (!strcmp(input, "exit")) {
            break;
        } else if (!strcmp(input, "mem")) {
            mm_status();
        } else if (!strcmp(input, "ps")) {
            proc_list();
        } else if (!strcmp(input, "write")) {
            printf("Filename: ");
            fgets(arg1, sizeof(arg1), stdin);
            arg1[strcspn(arg1, "\n")] = 0;

            if (strlen(arg1) == 0) {
                printf("Error: Filename cannot be empty.\n");
                continue;
            }

            printf("Content: ");
            fgets(arg2, sizeof(arg2), stdin);
            arg2[strcspn(arg2, "\n")] = 0;

            fs_write(arg1, arg2);
        } else if (!strcmp(input, "read")) {
            printf("Filename: ");
            fgets(arg1, sizeof(arg1), stdin);
            arg1[strcspn(arg1, "\n")] = 0;

            fs_read(arg1);
        } else if (!strcmp(input, "delete")) {
            printf("Filename: ");
            fgets(arg1, sizeof(arg1), stdin);
            arg1[strcspn(arg1, "\n")] = 0;

            fs_delete(arg1);
        } else if (!strcmp(input, "edit")) {
            printf("Filename: ");
            fgets(arg1, sizeof(arg1), stdin);
            arg1[strcspn(arg1, "\n")] = 0;

            fs_edit(arg1);
        } else if (!strcmp(input, "search")) {
            printf("Keyword: ");
            fgets(arg1, sizeof(arg1), stdin);
            arg1[strcspn(arg1, "\n")] = 0;

            fs_search(arg1);
        } else if (!strcmp(input, "rename")) {
            printf("Old Filename: ");
            fgets(arg1, sizeof(arg1), stdin);
            arg1[strcspn(arg1, "\n")] = 0;

            printf("New Filename: ");
            fgets(arg2, sizeof(arg2), stdin);
            arg2[strcspn(arg2, "\n")] = 0;

            fs_rename(arg1, arg2);
        } else if (!strcmp(input, "info")) {
            printf("Filename: ");
            fgets(arg1, sizeof(arg1), stdin);
            arg1[strcspn(arg1, "\n")] = 0;

            fs_info(arg1);
        } else if (!strcmp(input, "export")) {
            printf("Files are already saved to disk automatically.\n");
        } else if (!strcmp(input, "reset")) {
            fs_clear_all();
        } else {
            printf("Unknown command.\n");
        }
    }
}

// Shell as a process task
void shell_task() {
    shell();
}