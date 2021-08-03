CC = clang
CFLAGS = -Wall -Wextra -Werror -Wpedantic -g
LDFLAGS=
OBJS = collatz.o

all: collatz

collatz: $(OBJS)
	$(CC) $(LDFLAGS) -o collatz $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f collatz $(OBJS)

scan-build: clean
	scan-build --use-cc=clang make

format:
	clang-format -i -style=file *.[ch]
