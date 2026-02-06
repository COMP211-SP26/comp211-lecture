#include <stdint.h>
#include <stdio.h>

int8_t set_bit_2(int8_t num);

int main(void) {
    printf("%d\n", set_bit_2(10));
    printf("%d\n", set_bit_2(8));
    printf("%d\n", set_bit_2(12));
    return 0;
}

int8_t set_bit_2(int8_t num) {
    int8_t mask = 0b00000100;
    return (mask | num);
}
