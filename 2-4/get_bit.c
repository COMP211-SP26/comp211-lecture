#include <stdint.h>
#include <stdio.h>

int8_t get_bit(int8_t num, int8_t bit);

int main(void) {
    printf("%d\n", get_bit(8, 1));
    printf("%d\n", get_bit(8, 3));
    printf("%d\n", get_bit(16, 4));
    return 0;
}
