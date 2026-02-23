#include <stdio.h>
#include <stdlib.h>

int main() {
    // Start with space for 2 integers
    int* list = malloc(2 * sizeof(int));
    list[0] = 100;
    list[1] = 200;

    // Oh no, we need room for a 3rd!
    // realloc moves the data to a bigger spot if needed
    int* temp = realloc(list, 3 * sizeof(int));

    if (temp != NULL) {
        list = temp;
        list[2] = 300;
    }

    for (int i = 0; i < 3; i++) printf("%d ", list[i]);
    printf("\n");
    free(list);  // Clean up the final version
    return 0;
}
