#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>
#include "fs.h"

#define MAX_FILES 100
#define MAX_CONTENT 2000

char *files[MAX_FILES];
char *file_data[MAX_FILES];

void fs_init() {
    for (int i = 0; i < MAX_FILES; i++) {
        files[i] = NULL;
        file_data[i] = NULL;
    }

    DIR *dir = opendir(".");
    struct dirent *entry;
    int count = 0;

    while ((entry = readdir(dir)) && count < MAX_FILES) {
        struct stat st;
        if (stat(entry->d_name, &st) == 0 && S_ISREG(st.st_mode)) {
            FILE *fp = fopen(entry->d_name, "r");
            if (fp) {
                char buffer[MAX_CONTENT];
                size_t bytes = fread(buffer, 1, sizeof(buffer) - 1, fp);
                buffer[bytes] = '\0';
                fclose(fp);

                files[count] = strdup(entry->d_name);
                file_data[count] = strdup(buffer);
                count++;
            }
        }
    }
    closedir(dir);
}

int fs_find(const char *name) {
    for (int i = 0; i < MAX_FILES; i++)
        if (files[i] && strcmp(files[i], name) == 0)
            return i;
    return -1;
}

void fs_write(const char *name, const char *data) {
    int idx = fs_find(name);
    FILE *fp = fopen(name, "w"); // Save to disk
    if (fp) {
        fputs(data, fp);
        fclose(fp);
    }

    if (idx >= 0) {
        free(file_data[idx]);
        file_data[idx] = strdup(data);
        printf("File updated.\n");
        return;
    }
    for (int i = 0; i < MAX_FILES; i++) {
        if (!files[i]) {
            files[i] = strdup(name);
            file_data[i] = strdup(data);
            printf("File created.\n");
            return;
        }
    }
    printf("File system full.\n");
}

void fs_read(const char *name) {
    int idx = fs_find(name);
    if (idx >= 0)
        printf("Content: %s\n", file_data[idx]);
    else
        printf("File not found.\n");
}

void fs_list() {
    printf("Files:\n");
    int found = 0;
    for (int i = 0; i < MAX_FILES; i++) {
        if (files[i]) {
            printf("- %s\n", files[i]);
            found = 1;
        }
    }
    if (!found) printf("No files found.\n");
}

void fs_delete(const char *name) {
    int idx = fs_find(name);
    if (idx >= 0) {
        remove(name); // Delete from disk
        free(files[idx]);
        free(file_data[idx]);
        files[idx] = NULL;
        file_data[idx] = NULL;
        printf("File deleted.\n");
    } else {
        printf("File not found.\n");
    }
}

void fs_info(const char *name) {
    struct stat st;
    if (stat(name, &st) == 0) {
        printf("File: %s\n", name);
        printf("Size: %ld bytes\n", st.st_size);
        printf("Last modified: %s", ctime(&st.st_mtime));
    } else {
        printf("File not found.\n");
    }
}

void fs_edit(const char *name) {
    int idx = fs_find(name);
    if (idx >= 0) {
        printf("Old Content: %s\n", file_data[idx]);
        printf("New Content: ");
        char temp[MAX_CONTENT];
        fgets(temp, sizeof(temp), stdin);
        temp[strcspn(temp, "\n")] = 0;
        free(file_data[idx]);
        file_data[idx] = strdup(temp);
        printf("File updated.\n");
    } else
        printf("File not found.\n");
}

void fs_search(const char *keyword) {
    printf("Searching for '%s'...\n", keyword);
    int found = 0;
    for (int i = 0; i < MAX_FILES; i++) {
        if (files[i] && strstr(file_data[i], keyword)) {
            printf("- Found in '%s'\n", files[i]);
            found = 1;
        }
    }
    if (!found) printf("No matches found.\n");
}

void fs_rename(const char *old_name, const char *new_name) {
    int idx = fs_find(old_name);
    if (idx >= 0) {
        // Rename on disk
        if (rename(old_name, new_name) == 0) {
            free(files[idx]);
            files[idx] = strdup(new_name);
            printf("File renamed.\n");
        } else {
            printf("Rename failed.\n");
        }
    } else {
        printf("File not found.\n");
    }
}

void fs_export_all() {
    for (int i = 0; i < MAX_FILES; i++) {
        if (files[i]) {
            FILE *fp = fopen(files[i], "w");
            if (fp) {
                fputs(file_data[i], fp);
                fclose(fp);
            }
        }
    }
    printf("All files exported to disk.\n");
}

void fs_clear_all() {
    for (int i = 0; i < MAX_FILES; i++) {
        if (files[i]) {
            remove(files[i]); // delete from disk
            free(files[i]);
        }
        if (file_data[i]) free(file_data[i]);
        files[i] = NULL;
        file_data[i] = NULL;
    }
    printf("All files cleared from memory and disk.\n");
}