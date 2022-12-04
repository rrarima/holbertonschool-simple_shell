CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89

hsh:
	$(CC) $(CFLAGS) *.c -o hsh

clean:
	$(RM) *~ \#*\# \.\#* \
