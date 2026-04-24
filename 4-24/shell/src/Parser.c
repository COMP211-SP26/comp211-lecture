#include "Parser.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Scanner.h"

static Node* parse_command(char** tokens, int start, int end) {
    int argc = end - start;
    if (argc <= 0) {
        return NULL;
    }

    char** argv = malloc(sizeof(char*) * (argc + 1));
    if (!argv) {
        return NULL;
    }

    for (int i = 0; i < argc; i++) {
        argv[i] = strdup(tokens[start + i]);
        if (!argv[i]) {
            free_string_array(argv, i);
            return NULL;
        }
    }

    argv[argc] = NULL;
    return create_command_node(argv, argc);
}

Node* parse_line(char* line) {
    int token_count = 0;
    char** tokens = scan_line(line, &token_count);
    if (!tokens || token_count == 0) {
        free(tokens);
        return NULL;
    }

    Node* tree = NULL;
    int cmd_start = 0;

    for (int i = 0; i <= token_count; i++) {
        int at_end = (i == token_count);
        int at_pipe = (!at_end && strcmp(tokens[i], "|") == 0);

        if (!at_end && !at_pipe) {
            continue;
        }

        if (i == cmd_start) {
            fprintf(stderr, "parse error: invalid pipeline\n");
            free_string_array(tokens, token_count);
            free_node(tree);
            return NULL;
        }

        Node* command = parse_command(tokens, cmd_start, i);
        if (!command) {
            free_string_array(tokens, token_count);
            free_node(tree);
            return NULL;
        }

        if (!tree) {
            tree = command;
        } else {
            Node* pipe_node = create_pipe_node(tree, command);
            if (!pipe_node) {
                free_node(command);
                free_string_array(tokens, token_count);
                free_node(tree);
                return NULL;
            }
            tree = pipe_node;
        }

        cmd_start = i + 1;
    }

    free_string_array(tokens, token_count);
    return tree;
}