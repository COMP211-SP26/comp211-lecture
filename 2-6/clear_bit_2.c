#include <stdint.h>
#include <stdio.h>

#define NUM_TESTS 3

int8_t clear_bit2(int8_t number);

int main() {
    int8_t tests[NUM_TESTS] = {14, 12, 8};
    for (int i = 0; i < NUM_TESTS; i++) {
        int8_t modified = clear_bit2(tests[i]);
        printf("Original: %d, Modified : %d\n", tests[i], modified);
    }
    return 0;
}
