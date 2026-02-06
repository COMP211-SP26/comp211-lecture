#include <stdint.h>
#include <stdio.h>

int8_t get_bit(int8_t num, int8_t bit);

int main(void) {
    printf("%d\n", get_bit(8, 1));
    printf("%d\n", get_bit(8, 3));
    printf("%d\n", get_bit(16, 4));
    return 0;
}

int8_t get_bit(int8_t num, int8_t bit) {
    int8_t mask = 1 << bit;
    int8_t isolate_bit = num & mask;
    return (isolate_bit != 0);
}
