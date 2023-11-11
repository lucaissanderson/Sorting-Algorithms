#include "shell.h"

#include "gaps.h"
#include "stats.h"

#include <stdint.h>

// Shell sorting function using
// gap sequence from gaps.h (Pratt).
//
// stats : pointer to Stats struct
// arr : pointer to array
// length : number of elements in arr
void shell_sort(Stats *stats, uint32_t *arr, uint32_t length) {
    reset(stats);
    uint32_t j = 0;
    uint32_t temp = 0;
    for (uint32_t k = 0; k < GAPS; k++) {
        for (uint32_t i = gaps[k]; i < length; i++) {
            j = i;
            temp = move(stats, arr[i]);
            while ((j >= gaps[k]) && (cmp(stats, arr[j - gaps[k]], temp) == 1)) {
                arr[j] = move(stats, arr[j - gaps[k]]);
                j -= gaps[k];
            }
            arr[j] = move(stats, temp);
        }
    }
}
