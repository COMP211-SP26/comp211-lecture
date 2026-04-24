#include "Node.h"

#include <stdlib.h>

Node* create_command_node(char** argv, int argc) {
    Node* node = malloc(sizeof(Node));
    if (!node) {
        return NULL;
    }

    node->type = NODE_COMMAND;
    node->argc = argc;
    node->argv = argv;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* create_pipe_node(Node* left, Node* right) {
    Node* node = malloc(sizeof(Node));
    if (!node) {
        return NULL;
    }

    node->type = NODE_PIPE;
    node->argc = 0;
    node->argv = NULL;
    node->left = left;
    node->right = right;
    return node;
}

void free_node(Node* node) {
    if (!node) {
        return;
    }

    free_node(node->left);
    free_node(node->right);

    if (node->type == NODE_COMMAND) {
        if (node->argv) {
            for (int i = 0; i < node->argc; i++) {
                free(node->argv[i]);
            }
            free(node->argv);
        }
    }

    free(node);
}