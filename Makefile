CC=gcc
CFLAGS=-Wall -Werror -Wextra -pedantic -std=gnu89 -g
RM=rm -rf
BETTY=betty
VALGRIND=valgrind
VFLAGS= --leak-check=full --show-leak-kinds=all ./hsh

TARGET=hsh
SRC0=main.c

TARGET1=hsh
SRC1=	simple_shell.c \
	access_check.c \
	exit_func.c \
	fork_child.c \
	ll_path.c \
	print_env.c \
	_getenv.c \
	parse_input.c \

all: 0

0:
	$(CC) $(CFLAGS) $(SRC0) -o $(TARGET)

1:
	$(CC) $(CFLAGS) $(SRC1) -o $(TARGET1)
clean:
	$(RM) *~ \#*\# \.\#* \
	$(TARGET) a.out

betty:
	$(BETTY) $(SRC0)

val:
	$(VALGRIND) $(VFLAGS)
