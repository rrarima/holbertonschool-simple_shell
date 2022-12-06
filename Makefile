CC = gcc
CFLAGS = -g -Wall -Werror -Wextra -pedantic -std=gnu89

hsh:
	$(CC) $(CFLAGS) simple_shell.c print_env.c -o hsh
	valgrind --leak-check=full --show-leak-kinds=all ./hsh

clean:
	$(RM) *~ \#*\# \.\#* \
