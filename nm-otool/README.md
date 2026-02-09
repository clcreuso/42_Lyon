# nm-otool

Binary analysis tools for Mach-O files.

## Description
Recoding the `nm` and `otool` system commands. `nm` lists symbols from object files, and `otool` displays specified parts of object files or libraries (like the `__text` section). It handles 32-bit, 64-bit, and fat binaries.

## Usage
Compile the tools:
```bash
make
```
Run them:
```bash
./ft_nm [binary]
./ft_otool [binary]
```
