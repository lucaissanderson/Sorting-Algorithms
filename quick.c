#include "quick.h"

#include "stats.h"

#include <stdint.h>

// Splits given sub-array by some
// pivot. Returns that pivot for
// quick_sorter.
//
// stats : pointer to Stats struct
// A : pointer to array
// lo : lower limit of sub-array
// hi : higher limit of sub-array
uint32_t partition(Stats *stats, uint32_t *A, uint32_t lo, uint32_t hi) {
    uint32_t i = lo - 1;
    for (uint32_t j = lo; j < hi; j++) {
        if (cmp(stats, A[hi - 1], A[j - 1]) == 1) {
            i++;
            swap(stats, &A[i - 1], &A[j - 1]);
        }
    }
    swap(stats, &A[i], &A[hi - 1]);
    return i + 1;
}

// Helper program for recursive calls.
//
// stats : pointer to Stats struct
// A : pointer to array
// lo : lower limit of sub-array (index)
// hi : higher limit of sub-array (index)
void quick_sorter(Stats *stats, uint32_t *A, uint32_t lo, uint32_t hi) {
    if (lo < hi) {
        uint32_t p = partition(stats, A, lo, hi);
        quick_sorter(stats, A, lo, p - 1);
        quick_sorter(stats, A, p + 1, hi);
    }
}

// Main sort function to be called by
// other source files.
//
// stats : pointer to Stats struct
// A : pointer to array
// n : number of elements in A
void quick_sort(Stats *stats, uint32_t *A, uint32_t n) {
    reset(stats);
    quick_sorter(stats, A, 1, n);
}
