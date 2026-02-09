# filler

A competitive AI for a grid-filling game.

## Description
The goal is to create an AI player that competes against another on a virtual board. The goal is to place as many pieces as possible while blocking the opponent. It uses a heatmap-based strategy to optimize placement.

## Usage
Compile the player:
```bash
make
```
Run with the VM:
```bash
./filler_vm -f [map] -p1 ./clcreuso.filler -p2 [opponent]
```
