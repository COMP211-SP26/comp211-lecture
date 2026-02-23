#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* duplicate_string(char* original) {
    // Calculate length + 1 for the null terminator '\0'
    int len = strlen(original) + 1;

    // TODO: Allocate exactly enough memory on the HEAP for the new string
    char* copy = __________________________________________;

    if (copy != NULL) {
        strcpy(copy, original);
    }

    return copy;
}

int main() {
    char* name = "C Programming";

    // TODO: Call the function to get a heap-allocated copy
    char* my_copy = ____________________________;

    if (my_copy != NULL) {
        printf("Copy: %s\n", my_copy);

        // TODO: Free the copy
        ________________;
    }

    return 0;
}