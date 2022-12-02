CC = gcc
CFLAGS = -g -Wall -Werror -Wextra -pedantic

hsh:
	$(CC) $(CFLAGS) *.c -o hsh

clean:
	$(RM) *~ \#*\# \.\#* \
