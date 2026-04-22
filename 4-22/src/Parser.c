#include "Parser.h"

#include "Node.h"
#include "Scanner.h"

Node* parse_line(char* line) {
    int argc = 0;
    char** argv = scan_line(line, &argc);
    return create_node(argc, argv);
}