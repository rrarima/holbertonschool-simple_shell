CC = gcc
CFLAGS = -g -Wall -Werror -Wextra -pedantic -std=gnu89

hsh:
	$(CC) $(CFLAGS) *.c -o hsh
	valgrind --leak-check=full ./hsh

clean:
	$(RM) *~ \#*\# \.\#* \
