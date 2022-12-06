CC = gcc
CFLAGS = -g -Wall -Werror -Wextra -pedantic -std=gnu89

hsh:
	$(CC) $(CFLAGS) simple_shell.c print_env.c -o hsh

clean:
	$(RM) *~ \#*\# \.\#* \
