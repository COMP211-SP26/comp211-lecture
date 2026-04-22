#include "Node.h"

#include <stdlib.h>

Node* create_node(int argc, char** argv) {
    Node* node = malloc(sizeof(Node));
    node->argc = argc;
    node->argv = argv;
    return node;
}

void free_node(Node* node) {
    for (int i = 0; i < node->argc; i++) {
        free(node->argv[i]);
    }
    free(node->argv);
    free(node);
}