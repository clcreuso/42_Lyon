# corewar

A programming game where "champions" fight in a virtual arena.

## Description
Corewar consists of an assembler that converts assembly code into bytecode, and a Virtual Machine that executes these "champions" in a shared memory arena. The last champion to report alive wins.

## Usage
Compile everything:
```bash
make
```
Compile a champion:
```bash
./asm [champion.s]
```
Run the VM:
```bash
./corewar [-dump N] [[-n number] champion.cor] ...
```
