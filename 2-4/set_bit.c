#include <stdint.h>
#include <stdio.h>

int8_t set_bit(int8_t num, int8_t i);

int main(void) {
    printf("%d\n", set_bit(10, 1));
    printf("%d\n", set_bit(8, 0));
    printf("%d\n", set_bit(12, 4));
    return 0;
}
