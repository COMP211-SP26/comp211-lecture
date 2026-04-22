#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "Exec.h"
#include "Node.h"
#include "Parser.h"

#define MAX_LINE 1024

static int read_line(char* buffer, size_t size);

int main() {
    char line[MAX_LINE];

    while (1) {
        int status = read_line(line, sizeof(line));
        if (status == 0) break;
        if (status == 1) continue;

        Node* cmd = parse_line(line);
        if (cmd->argc == 0) {
            free_node(cmd);
            continue;
        }
        exec(cmd);
        free_node(cmd);
    }

    return 0;
}

static int read_line(char* buffer, size_t size) {
    printf("myshell> ");
    fflush(stdout);

    if (!fgets(buffer, size, stdin)) {
        printf("\n");
        return 0;  // signal EOF / exit
    }

    // remove newline
    buffer[strcspn(buffer, "\n")] = '\0';

    // skip empty lines
    if (strlen(buffer) == 0) {
        return 1;
    }

    return 2;  // valid command
}
