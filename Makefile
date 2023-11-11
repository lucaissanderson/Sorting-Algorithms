SHELL := /bin/sh
CC = clang
CFLAGS = -Wall -Wpedantic -Werror -Wextra
EXEC = sorting
OBJS = sorting.o shell.o batcher.o heap.o quick.o stats.o set.o

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) -o $(EXEC) $(OBJS)

sorting.o: sorting.c
	$(CC) $(CFLAGS) -c sorting.c

shell.o: shell.c
	$(CC) $(CFLAGS) -c shell.c

batcher.o: batcher.c
	$(CC) $(CFLAGS) -c batcher.c

heap.o: heap.c
	$(CC) $(CFLAGS) -c heap.c

quick.o: quick.c
	$(CC) $(CFLAGS) -c quick.c

stats.o: stats.c
	$(CC) $(CFLAGS) -c stats.c

set.o: set.c
	$(CC) $(CFLAGS) -c set.c

clean:
	rm -f $(OBJS) $(EXEC)

format:
	clang-format -i -style=file *.[ch]

scan-build: clean
	scan-build --use-cc=$(CC) make
