# Compilation for the hsh simple shell requirements are 
# gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

CC=gcc
CFLAGS=-Wall -Werror -Wextra -pedantic -std=gnu89 -g
RM=rm -rf
BETTY=betty
VALGRIND=valgrind
VFLAGS= --leak-check=full --show-leak-kinds=all ./hsh

TARGET=hsh
SRC0=	_getenv.c \
	print_env.c\
	read_input.c\
	parse_input.c\
	fork_child.c\
	simple_shell.c

TARGET=hsh
SRC1=	func.c \
	simple_shell.c


# shell hsh
all: 0

0:
	$(CC) $(CFLAGS) $(SRC0) -o $(TARGET)

1:
	$(CC) $(CFLAGS) $(SRC1) -o $(TARGET)

clean:
	$(RM) *~ \#*\# \.\#* \
	$(TARGET)

betty:
	$(BETTY) $(SRC0)

val:
	$(VALGRIND) $(VFLAGS)
