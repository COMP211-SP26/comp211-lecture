#include "Scanner.h"

#include <stdlib.h>
#include <string.h>

#define MAX_ARGS 64

char** scan_line(char* line, int* argc) {
    char** args = malloc(sizeof(char*) * MAX_ARGS);
    *argc = 0;

    // strtok splits a string into tokens based on delimeters
    char* token = strtok(line, " ");
    while (token && *argc < MAX_ARGS - 1) {
        // strdup allocates new memory and copies a string into it
        args[*argc] = strdup(token);
        (*argc)++;
        token = strtok(NULL, " ");
    }

    args[*argc] = NULL;
    return args;
}