CC=gcc
CFLAGS=-Wall -Werror -Wextra -pedantic -std=gnu89 -g
RM=rm -rf
BETTY=betty
VALGRIND=valgrind
VFLAGS= --leak-check=full --show-leak-kinds=all ./hsh

TARGET=hsh
SRC0=main.c

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
