#include <stdio.h>
#include <stdlib.h>

int* get_scores_right(int size) {
    // 1. Allocate space on the Heap
    int* scores = malloc(size * sizeof(int));

    if (scores == NULL) return NULL;  // Safety check

    // 2. Fill the array
    scores[0] = 90;
    scores[1] = 85;
    scores[2] = 80;

    return scores;  // SAFE: The heap memory persists after the function ends
}

int main() {
    int size = 3;
    int* my_scores = get_scores_right(size);

    if (my_scores != NULL) {
        printf("Score 1: %d\n", my_scores[0]);  // Prints 90

        // 3. YOU are responsible for ending the lifetime
        free(my_scores);
    }

    return 0;
}
