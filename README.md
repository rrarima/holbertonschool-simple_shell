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
​
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
The thought process of how the shell works.
![App Screenshot](https://i.imgur.com/H0Pe4t9.png)
​
​
# Tasks
​
To run this project, you will need to add the following environment variables to your .env file
​

`0. README, man, AUTHORS`
```javascript
Write a README
Write a man for your shell.
You should have an AUTHORS file at the root of your repository,
listing all individuals having contributed content to the repository. Format, see Docker
```
`1. Betty would be proud`
```javascript
Write a beautiful code that passes the Betty checks
```
​
`2. Simple shell 0.1`
```javascript
Write a UNIX command line interpreter.
```
​
`3. Simple shell 0.2`
```javascript
Simple shell 0.1 +
Handle command lines with arguments
```
​
`4. Simple shell 0.3`
```javascript
Simple shell 0.2 +
Handle the PATH
fork must not be called if the command doesn’t exist
```
​
`5. Simple shell 0.4`
```javascript
Simple shell 0.3 +
Implement the exit built-in, that exits the shell
Usage: exit
You don’t have to handle any argument to the built-in exit
```
​
`6. Simple shell 1.0`
```javascript
Simple shell 0.4 +
Implement the env built-in, that prints the current environment
```
​
`7. What happens when you type ``ls -l *.c`` in the shell`
```javascript
Write a blog post describing step by step what happens
when you type ls -l *.c and hit Enter in a shell.
```
​
​
## Authors
This is a collaboration project done by Jenny & Eps.
- [@Jenny Nguyen](https://github.com/JennyHolberton)
- [@Rarima Rarima (Eps)](https://github.com/rrarima)
​
<blockquote><b><i>"Am I testing this program, or is it testing me? - Luis Herrera"</blockquote>
