![Logo](https://uploads-ssl.webflow.com/6105315644a26f77912a1ada/610540e8b4cd6969794fe673_Holberton_School_logo-04-04.svg)
​
​
# Simple Shell
​
​
This repo contains the files required for the implementation of a basic shell.
​
## How to compile
​
All files are compiled using gcc (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0 using flags:-Wall -Werror -Wextra -pedantic
​
```bash
  gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c
```
​
​
## Installation
​
How to install and use Simple Simple Shell
​
```bash
  Clone Repo: git clone https://github.com/rrarima/holbertonschool-simple_shell.git
  Compile: gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
  Run interactive mode: ./hsh
  Run non-interactive mode: echo "/bin/ls" | ./hsh
```

# Usage/Examples
## Interactive Mode
​
​
Using the ls option on it's own displays the bare format of a file and it's type.
```javascript
#cisfun$ /bin/ls
Makefile   _getenv.c  main.h       pid          simple_shell.c
README.md  hsh        man_1_shell  print_env.c
```
Using the ls option -l will display.
```javascript
#cisfun$ /bin/ls -l
total 56
-rw-r--r-- 1 root root   127 Dec  6 05:05 Makefile
-rw-r--r-- 1 root root    48 Nov 27 22:46 README.md
-rw-r--r-- 1 root root   351 Dec  5 03:58 _getenv.c
-rwxr-xr-x 1 root root 17528 Dec  6 07:04 hsh
-rw-r--r-- 1 root root   657 Dec  6 05:49 main.h
-rw-r--r-- 1 root root     4 Nov 27 23:02 man_1_shell
drwxr-xr-x 2 root root  4096 Dec  5 03:58 pid
-rw-r--r-- 1 root root   272 Dec  4 23:58 print_env.c
-rw-r--r-- 1 root root  1197 Dec  6 07:04 simple_shell.c
```
​
## Non-Interactive Mode
```javascript
echo "/bin/ls" | ./hsh
Makefile   _getenv.c  main.h       pid          simple_shell.c
README.md  hsh        man_1_shell  print_env.c
​
​
```
```javascript
echo "/bin/ls -l" | ./hsh
total 56
-rw-r--r-- 1 root root   127 Dec  6 05:05 Makefile
-rw-r--r-- 1 root root    48 Nov 27 22:46 README.md
-rw-r--r-- 1 root root   351 Dec  5 03:58 _getenv.c
-rwxr-xr-x 1 root root 17528 Dec  6 07:04 hsh
-rw-r--r-- 1 root root   657 Dec  6 05:49 main.h
-rw-r--r-- 1 root root     4 Nov 27 23:02 man_1_shell
drwxr-xr-x 2 root root  4096 Dec  5 03:58 pid
-rw-r--r-- 1 root root   272 Dec  4 23:58 print_env.c
-rw-r--r-- 1 root root  1197 Dec  6 07:04 simple_shell.c
​
```
​
## Flowchart
Our thought process of how the shell works.
![App Screenshot](https://i.imgur.com/H0Pe4t9.png)
​
​
## Authors
This is a collaboration project done by Jenny & Eps.
- [@Jenny Nguyen](https://github.com/JennyHolberton)
- [@Rarima Rarima (Eps)](https://github.com/rrarima)
​
<blockquote><b><i>"Am I testing this program, or is it testing me? - Luis Herrera"</blockquote>
