#include "heap.h"

#include "stats.h"

#include <stdbool.h>
#include <stdint.h>

// Takes in a given node and returns
// which of its children is greater. (unsigned 32b int)
//
// stats : pointer to Stats struct
// A : pointer to array
// first : index of first child
// last : index of second child
uint32_t max_child(Stats *stats, uint32_t *A, uint32_t first, uint32_t last) {
    uint32_t left = 2 * first;
    uint32_t right = left + 1;
    if (right <= last && (cmp(stats, A[right - 1], A[left - 1]) == 1)) {
        return right;
    }
    return left;
}

// Corrects heap after making a change to it.
//
// stats : pointer to Stats struct
// A : pointer to array
// first : index of first element in array to
//         fix
// last : last element in array to fix.
void fix_heap(Stats *stats, uint32_t *A, uint32_t first, uint32_t last) {
    bool found = false;
    uint32_t mother = first;
    uint32_t great = max_child(stats, A, mother, last);
    while ((mother <= last / 2) && !(found)) {
        if (cmp(stats, A[great - 1], A[mother - 1]) == 1) {
            swap(stats, &A[mother - 1], &A[great - 1]);
            mother = great;
            great = max_child(stats, A, mother, last);
        } else {
            found = true;
        }
    }
}

// Initial construction of heap tree.
//
// stats : pointer to Stats struct
// A : pointer to array
// first : index of first element (in A)
// last : index of last element (in A)
void build_heap(Stats *stats, uint32_t *A, uint32_t first, uint32_t last) {
    for (uint32_t father = last / 2; father > first - 1; father--) {
        fix_heap(stats, A, father, last);
    }
}

// Main sort function to be called by
// other source files. Iterates until
// array A is sorted.
//
// stats : pointer to Stats struct
// A : pointer to array
// n : number of elements in A
void heap_sort(Stats *stats, uint32_t *A, uint32_t n) {
    reset(stats);
    uint32_t first = 1;
    uint32_t last = n;
    build_heap(stats, A, first, last);
    for (uint32_t leaf = last; leaf > first; leaf--) {
        swap(stats, &A[first - 1], &A[leaf - 1]);
        fix_heap(stats, A, first, leaf - 1);
    }
}
