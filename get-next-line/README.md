# get-next-line

A function to read a line from a file descriptor.

## Description
The goal of this project is to create a function that returns a line read from a file descriptor, whether it's a file or standard input. It handles static variables and memory management to allow efficient sequential reading.

## Usage
Add the source files to your project and compile with:
```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c
```
