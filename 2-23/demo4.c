#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 3
int main() {
    int16_t stack_arr[ARRAY_SIZE];
    int16_t* heap_arr = malloc(ARRAY_SIZE * sizeof(int16_t));

    if (heap_arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int32_t i = 0; i < ARRAY_SIZE; i++) {
        stack_arr[i] = i;
        heap_arr[i] = i * 2;
    }

    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("heap arr[%d] = %d\n", i, heap_arr[i]);
    }

    int32_t* inc_arr = (int32_t*)heap_arr;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("inc arr[%d] = %d\n", i, inc_arr[i]);
    }

    free(heap_arr);

    return 0;
}
