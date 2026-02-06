#include <stdint.h>
#include <stdio.h>

#define NUM_TESTS 3

int8_t clear_bit(int8_t num, int8_t i);

int main() {
    int tests[NUM_TESTS] = {14, 12, 8};
    for (int i = 0; i < NUM_TESTS; i++) {
        printf("Original: %d, Modified: %d\n", tests[i],
               clear_bit(tests[i], i + 2));
    }
    return 0;
}
