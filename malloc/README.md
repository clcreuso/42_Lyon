# malloc

A custom dynamic memory management library.

## Description
Implementation of `malloc`, `free`, and `realloc` functions. It uses system calls like `mmap` to allocate large memory regions and manages them efficiently using metadata and free lists to minimize fragmentation.

## Usage
Compile the dynamic library:
```bash
make
```
Use it by preloading it:
```bash
export LD_PRELOAD=$PWD/libft_malloc.so
ls
```
