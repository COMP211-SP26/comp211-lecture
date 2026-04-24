#include "Scanner.h"

#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 128

void free_string_array(char** strings, int count) {
    if (!strings) {
        return;
    }

    for (int i = 0; i < count; i++) {
        free(strings[i]);
    }

    free(strings);
}

char** scan_line(char* line, int* token_count) {
    char** tokens = malloc(sizeof(char*) * (MAX_TOKENS + 1));
    if (!tokens) {
        *token_count = 0;
        return NULL;
    }

    int count = 0;
    char* token = strtok(line, " ");

    while (token) {
        if (count >= MAX_TOKENS) {
            free_string_array(tokens, count);
            *token_count = 0;
            return NULL;
        }

        tokens[count] = strdup(token);
        if (!tokens[count]) {
            free_string_array(tokens, count);
            *token_count = 0;
            return NULL;
        }

        count++;
        token = strtok(NULL, " \t");
    }

    tokens[count] = NULL;
    *token_count = count;
    return tokens;
}