#include <stdint.h>
#include <stdio.h>

int8_t is_bit3_on(int8_t number);

int main(void) {
    printf("%d\n", is_bit3_on(8));
    printf("%d\n", is_bit3_on(9));
    printf("%d\n", is_bit3_on(4));
    return 0;
}

int8_t is_bit3_on(int8_t number) {
    int8_t mask = 0b01000;
    if (number & mask) {
        return 1;
    } else {
        return 0;
    }
}