# lem-in

An ant farm simulator using max-flow graph algorithms.

## Description
Lem-in finds the quickest way to move `n` ants across an ant farm (graph) from start to end. It implements graph traversal and flow optimization (Edmonds-Karp or similar) to handle multiple paths and avoid collisions.

## Usage
Compile the project:
```bash
make
```
Run it with a map:
```bash
./lem-in < [map_file]
```
