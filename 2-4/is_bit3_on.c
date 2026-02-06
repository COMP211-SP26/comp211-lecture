#include <stdint.h>
#include <stdio.h>

int8_t is_bit3_on(int8_t number);

int main(void) {
    printf("%d\n", is_bit3_on(8));
    printf("%d\n", is_bit3_on(9));
    printf("%d\n", is_bit3_on(4));
    return 0;
}
