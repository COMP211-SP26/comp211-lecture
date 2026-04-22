#ifndef NODE_H
#define NODE_H

typedef struct {
    int argc;
    char** argv;
} Node;

Node* create_node(int argc, char** argv);
void free_node(Node* node);

#endif