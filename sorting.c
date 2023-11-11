#include "batcher.h"
#include "heap.h"
#include "quick.h"
#include "set.h"
#include "shell.h"

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define OPTIONS "ahbsqr:n:p:H"

// Made static because they're used
// across many functions.
static int seed = 13371453;
static uint32_t num_print = 100;
static uint32_t arr_size = 100;

char help_msg[] = "\
SYNOPSIS\n\
   A collection of comparison-based sorting algorithms.\n\
\n\
USAGE\n\
   ./sorting [-Hasbhqn:p:r:] [-n length] [-p elements] [-r seed]\n\
\n\
OPTIONS\n\
   -H              Display program help and usage.\n\
   -a              Enable all sorts.\n\
   -s              Enable Shell Sort.\n\
   -b              Enable Batcher Sort.\n\
   -h              Enable Heap Sort.\n\
   -q              Enable Quick Sort.\n\
   -n length       Specify number of array elements (default: 100).\n\
   -p elements     Specify number of elements to print (default: 100).\n\
   -r seed         Specify random seed (default: 13371453).\n\
";

// Dynamically allocates array and fills
// with peudorandom numbers. Passes to
// shell sort then prints stats.
//
// No parameters. (void)
void print_shell(void) {
    srandom(seed);
    Stats stats;
    if (num_print > arr_size) {
        num_print = arr_size;
    }
    // Create array.
    uint32_t *arr = (uint32_t *) malloc(sizeof(uint32_t) * arr_size);
    for (uint32_t i = 0; i < arr_size; i++) {
        // Fill array with random bit-masked (30bits)
        // unsigned integers.
        *(arr + i) = random() & 1073741823;
    }
    shell_sort(&stats, arr, arr_size);
    printf("Shell Sort, %u"
           " elements, %lu"
           " moves, %lu"
           " compares",
        arr_size, stats.moves, stats.compares);
    for (uint32_t i = 0; i < num_print; i++) {
        if ((i % 5) == 0) {
            printf("\n");
        }
        printf("%13" PRIu32, arr[i]);
    }
    printf("\n");
    free(arr);
}

// Dynamically allocates array and fills
// with peudorandom numbers. Passes to
// batcher sort then prints stats.
//
// No parameters. (void)
void print_batcher(void) {
    srandom(seed);
    Stats stats;
    if (num_print > arr_size) {
        num_print = arr_size;
    }
    // Create array.
    uint32_t *arr = (uint32_t *) malloc(sizeof(uint32_t) * arr_size);
    for (uint32_t i = 0; i < arr_size; i++) {
        // Fill array with random bit-masked (30bits)
        // unsigned integers.
        *(arr + i) = random() & 1073741823;
    }
    batcher_sort(&stats, arr, arr_size);
    printf("Batcher Sort, %u"
           " elements, %lu"
           " moves, %lu"
           " compares",
        arr_size, stats.moves, stats.compares);
    for (uint32_t i = 0; i < num_print; i++) {
        if ((i % 5) == 0) {
            printf("\n");
        }
        printf("%13" PRIu32, arr[i]);
    }
    printf("\n");
    free(arr);
}

// Dynamically allocates array and fills
// with peudorandom numbers. Passes to
// heap sort then prints stats.
//
// No parameters. (void)
void print_heap(void) {
    srandom(seed);
    Stats stats;
    if (num_print > arr_size) {
        num_print = arr_size;
    }
    // Create array.
    uint32_t *arr = (uint32_t *) malloc(sizeof(uint32_t) * arr_size);
    for (uint32_t i = 0; i < arr_size; i++) {
        // Fill array with random bit-masked (30bits)
        // unsigned integers.
        *(arr + i) = random() & 1073741823;
    }
    heap_sort(&stats, arr, arr_size);
    printf("Heap Sort, %u"
           " elements, %lu"
           " moves, %lu"
           " compares",
        arr_size, stats.moves, stats.compares);
    for (uint32_t i = 0; i < num_print; i++) {
        if ((i % 5) == 0) {
            printf("\n");
        }
        printf("%13" PRIu32, arr[i]);
    }
    printf("\n");
    free(arr);
}

// Dynamically allocates array and fills
// with peudorandom numbers. Passes to
// quick sort then prints stats.
//
// No parameters. (void)
void print_quick(void) {
    srandom(seed);
    Stats stats;
    if (num_print > arr_size) {
        num_print = arr_size;
    }
    // Create array.
    uint32_t *arr = (uint32_t *) malloc(sizeof(uint32_t) * arr_size);
    for (uint32_t i = 0; i < arr_size; i++) {
        // Fill array with random bit-masked (30bits)
        // unsigned integers.
        *(arr + i) = random() & 1073741823;
    }
    quick_sort(&stats, arr, arr_size);
    printf("Quick Sort, %u"
           " elements, %lu"
           " moves, %lu"
           " compares",
        arr_size, stats.moves, stats.compares);
    for (uint32_t i = 0; i < num_print; i++) {
        if ((i % 5) == 0) {
            printf("\n");
        }
        printf("%13" PRIu32, arr[i]);
    }
    printf("\n");
    free(arr);
}

int main(int argc, char **argv) {
    // Make option set.
    Set opset = set_empty();
    int opt;
    while ((opt = getopt(argc, argv, OPTIONS)) != -1) {
        switch (opt) {
        case 'a': opset = set_insert(opset, 0); break;
        case 'h': opset = set_insert(opset, 1); break;
        case 'b': opset = set_insert(opset, 2); break;
        case 's': opset = set_insert(opset, 3); break;
        case 'q': opset = set_insert(opset, 4); break;
        case 'r':
            opset = set_insert(opset, 5);
            seed = atoi(optarg);
            break;
        case 'n':
            opset = set_insert(opset, 6);
            arr_size = atoi(optarg);
            break;
        case 'p':
            opset = set_insert(opset, 7);
            num_print = atoi(optarg);
            break;
        case 'H': opset = set_insert(opset, 8); break;
        default: printf("Select at least one sort to perform.\n"); break;
        }
    }
    // I decided to use a do-while loop
    // over goto. I needed to check help option
    // and no option before any sort conditionals.
    // So I made use of the break statements to act
    // as goto since I wasn't sure goto was necessary.
    // That's why the loop will only ever go through
    // once because I only need it to check help or
    // all before checking any other sorts conditionals.
    do {
        // Help option or no option.
        if (set_member(opset, 8) || !(opset | 0)) {
            printf("%s", help_msg);
            break;
        }
        // Print all.
        if (set_member(opset, 0)) {
            print_shell();
            print_batcher();
            print_heap();
            print_quick();
            break;
        }
        // Call and print shell sort.
        if (set_member(opset, 3)) {
            print_shell();
            opset = set_remove(opset, 3);
        }
        // Call and print batcher sort.
        if (set_member(opset, 2)) {
            print_batcher();
            opset = set_remove(opset, 2);
        }
        // Call and print heap sort.
        if (set_member(opset, 1)) {
            print_heap();
            opset = set_remove(opset, 1);
        }
        // Call and print quick sort.
        if (set_member(opset, 4)) {
            print_quick();
            opset = set_remove(opset, 4);
        }
        opset = set_empty();
    } while (opset);
    return 0;
}
