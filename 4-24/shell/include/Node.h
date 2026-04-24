#ifndef NODE_H
#define NODE_H

typedef enum NodeType { NODE_COMMAND, NODE_PIPE } NodeType;

typedef struct Node {
    NodeType type;
    int argc;
    char** argv;
    struct Node* left;
    struct Node* right;
} Node;

Node* create_command_node(char** argv, int argc);
Node* create_pipe_node(Node* left, Node* right);
void free_node(Node* node);

#endif