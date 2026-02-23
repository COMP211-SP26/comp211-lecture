#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("How many grades do you want to enter? ");
    scanf("%d", &n);

    // 1. Allocate memory on the HEAP
    // We request space for 'n' integers
    int* grades = malloc(n * sizeof(int));

    // ALWAYS check if malloc failed (if the computer is out of memory)
    if (grades == NULL) {
        return 1;
    }

    for (int i = 0; i < n; i++) {
        grades[i] = i * 10;  // Assigning some values
        printf("Grade %d: %d\n", i, grades[i]);
    }

    // 2. End the lifetime manually!
    free(grades);

    return 0;
}
