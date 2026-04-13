#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "CharItr.h"

bool read_next_line(char* buffer, size_t max_length);

int main(void) {
    char buffer[256];

    printf("Enter a line: ");

    // Read a line from input
    if (!read_next_line(buffer, sizeof(buffer))) {
        fprintf(stderr, "Failed to read input\n");
        return EXIT_FAILURE;
    }

    // Get length of the string
    size_t len = strlen(buffer);

    // Create iterator
    CharItr it = CharItr_value(buffer, len);

    // Iterate through characters
    printf("Characters:\n");
    // TODO: your code here

    return EXIT_SUCCESS;
}

bool read_next_line(char* buffer, size_t max_length) {
    return fgets(buffer, max_length, stdin) != NULL;
}