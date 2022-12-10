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
	access_check.c\
	parse_input.c\
	print_env.c\
	fork_child.c\
	ll_path.c\
	proc_input.c\
	simple_shell.c

all: 0

0:
	$(CC) $(CFLAGS) $(SRC0) -o $(TARGET)

clean:
	$(RM) *~ \#*\# \.\#* \
	$(TARGET)

betty:
	$(BETTY) $(SRC0)

val:
	$(VALGRIND) $(VFLAGS)
