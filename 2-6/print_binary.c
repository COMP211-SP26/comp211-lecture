#include "print_binary.h"

#include <stdint.h>
#include <stdio.h>

/* ----------------------- Private helper (not in header) ----------------- */

static void print_bits_grouped_u64(uint64_t value, unsigned width,
                                   unsigned group) {
    if (width == 0 || width > 64 || group == 0) return;

    printf("0b");

    for (int i = (int)width - 1; i >= 0; --i) {
        putchar(((value >> i) & 1ULL) ? '1' : '0');

        /* Insert a separator every `group` bits (except after the final bit).
         */
        if (i != 0 && ((unsigned)i % group) == 0) {
            putchar('_');
        }
    }
}

/* --------------------------- Public API (in header) ---------------------- */

void print_bin8(uint8_t x) { print_bits_grouped_u64((uint64_t)x, 8, 4); }

void print_bin16(uint16_t x) { print_bits_grouped_u64((uint64_t)x, 16, 4); }

void print_bin32(uint32_t x) { print_bits_grouped_u64((uint64_t)x, 32, 4); }

void print_bin64(uint64_t x) { print_bits_grouped_u64(x, 64, 4); }