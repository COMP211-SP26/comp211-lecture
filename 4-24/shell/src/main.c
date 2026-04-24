#include <stdio.h>
#include <string.h>

#include "Exec.h"
#include "Node.h"
#include "Parser.h"

static int read_line(char* buffer, size_t size) {
    printf("myshell> ");
    fflush(stdout);

    if (!fgets(buffer, size, stdin)) {
        printf("\n");
        return 0;  // EOF / exit
    }

    // remove newline
    buffer[strcspn(buffer, "\n")] = '\0';

    // skip empty lines
    if (strlen(buffer) == 0) {
        return 1;
    }

    return 2;  // valid command
}

int main(void) {
    char line[1024];

    while (1) {
        int status = read_line(line, sizeof(line));

        if (status == 0) {
            break;  // EOF (Ctrl+D)
        } else if (status == 1) {
            continue;  // empty line
        }

        Node* tree = parse_line(line);
        if (!tree) {
            continue;
        }

        exec_tree(tree);
        free_node(tree);
    }

    return 0;
}