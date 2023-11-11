# Putting Your Affairs in Order

## Files:

##### `sorting.c`
Source file that implements test harness for all of the vaious<br>
sorting algorithms.

##### `shell.c`
Implements Shell Sorting algorithm.

##### `shell.h`
Header file which declares defined function in `shell.c`<br>

##### `gaps.h`
Header file used by `shell.c` which defines the gap sequence<br>
used for the Shell Sort algorithm. 

##### `quick.c`
Source file that implements Quick Sort algorithm.

##### `quick.h`
Header file for `quick.c` that declares in function.

##### `heap.c`
Source file that implements Heap Sort.

##### `heap.h`
Header file for `heap.c`. Declares its functions.

##### `batcher.c`
Source file that implements Batcher's Odd-Even Merge Sort.

##### `batcher.h`
Header file that declares `batcher.c`'s functions.

##### `set.c`
Implements a `set` type using unsigned 32 bit integers. <br>
Also defines functions altering sets in various ways.

##### `set.h`
Header file for `set.c`.

##### `stats.c`
Implements struct that holds `moves` and `comapares` <br>
used to keep track of each sorting algorithm's number <br>
of moves and compares. Also defines functions for that <br>
struct to make easier `swaps` and `move` operations.

##### `stats.h`
Header file for `stats.c`.

##### `WRITEUP.pdf`
Analyzes the results from all the functions implemented.<br>
Uses graphs generated from `gnuplot`.

##### `DESIGN.pdf`
Demonstrates the desgin behind each source file using <br>
pseudocode.

##### `README.me`
*This* file. Provides short description of the program <br>
and its dependent/associated files. Additionally describes<br>
how to compile and run the program.

## Short Description:
Tests the efficiency of various sorting algorithms.<br>

## Build:
To compile the program, run `$ make`, `$ make all`, <br>
or `$ make sorting`. <br>
This will generate a single executable in the current <br>
working directory along with several object files you can <br>
ignore.

## Clean:
To remove all the `.o` and executable files, run <br>
`$ make clean`. 

## Format:
To format all `.c` and `.h` files, execute `$ make format`.

## Running:
To run the program, `$ ./sorting [-Hasbhqn:p:r:]`. <br>
Running with no options will return a help output <br>
describing each option. For convenience, here they are too,<br>

   -H              Display program help and usage.<br>
   -a              Enable all sorts.<br>
   -s              Enable Shell Sort.<br>
   -b              Enable Batcher Sort.<br>
   -h              Enable Heap Sort.<br>
   -q              Enable Quick Sort.<br>
   -n length       Specify number of array elements (default: 100).<br>
   -p elements     Specify number of elements to print (default: 100).<br>
   -r seed         Specify random seed (default: 13371453).<br>

Invalid usage results in the help screen again.

