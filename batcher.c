#include "batcher.h"

#include "stats.h"

#include <stdint.h>

// Takes a 32 bit unsigned integer and uses
// leftshift to find number of bits USED.
// Returns unisigned 32 bit integer.
//
// a : desired unsigned int to get bitlength of
uint32_t bit_length(uint32_t a) {
    uint32_t b = 0;
    for (b = 0; a != 0; a >>= 1) {
        b++;
    }
    return b;
}

// Emulates comparator from real life
// sorting network.
//
// stats : pointer to Stats struct
// A : pointer to array
// x : index of first value
// y : index of second value
void comparator(Stats *stats, uint32_t *A, uint32_t x, uint32_t y) {
    if (cmp(stats, A[x], A[y]) == 1) {
        swap(stats, &A[x], &A[y]);
    }
}

// Batcher Sorting Network,
//
// stats : pointer to Stats struct
// A : pointer to array
// n : length of A
void batcher_sort(Stats *stats, uint32_t *A, uint32_t n) {
    reset(stats);
    if (n == 0) {
        return;
    }
    uint32_t t = bit_length(n);
    uint32_t p = 1 << (t - 1);
    uint32_t q, r, d;
    while (p > 0) {
        q = 1 << (t - 1);
        r = 0;
        d = p;
        while (d > 0) {
            for (uint32_t i = 0; i < (n - d); i++) {
                if ((i & p) == r) {
                    comparator(stats, A, i, i + d);
                }
            }
            d = q - p;
            q >>= 1;
            r = p;
        }
        p >>= 1;
    }
}
