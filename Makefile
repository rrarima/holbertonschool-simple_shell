# Compilation for the hsh simple shell requirements are 
# gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

CC=gcc
CFLAGS=-Wall -Werror -Wextra -pedantic -std=gnu89 -g
RM=rm -rf
BETTY=betty
VALGRIND=valgrind
VFLAGS= --leak-check=full --show-leak-kinds=all ./hsh

TARGET=hsh
SRC0=    _getenv.c \
    argarr.c \
    save_path.c \
    shell.c \
    string_func.c \
    find_command.c \
    can_exec.c \
    fork_exec.c \
    print_error.c \
    builtin.c \
    _env.c

# shell hsh
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

