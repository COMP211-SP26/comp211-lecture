#include <stdint.h>
#include <stdio.h>

int8_t update_bit(int8_t num, int8_t i, int8_t x);

int main(void) {
    int8_t ex1 = update_bit(0b0101, 2, 0);
    printf("%d\n", ex1);
    int8_t ex2 = update_bit(0b0101, 1, 1);
    printf("%d\n", ex2);
    return 0;
}
