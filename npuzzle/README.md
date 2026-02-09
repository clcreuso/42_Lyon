# Npuzzle Solver

Npuzzle solver algorithm using (A-star).

This solver find the "snail solution"

<img width="602" alt="Screen Shot 2019-07-03 at 17 15 57" src="https://user-images.githubusercontent.com/34065460/60603678-7c81c980-9db6-11e9-884a-583caa8a20f4.png">

Output a list of move and show each step from the given Npuzzle to solution.

Output a benchmark of algorithm performance.

## Table of Contents
- [Prerequisites](#Prerequisites)
- [Installing](#Installing)
- [Getting Started](#Getting_Started)
- [How to use](#How_to_use)
  - [Npuzzle generator usage](##Npuzzle_generator_usage)
  - [Npuzzle solver usage](##Npuzzle_solver_usage)
- [Algorithm](#Algorithm)
  - [A-star](##A-star)
  - [Heuristics](##Heuristics)
  - [Search method](##Search_method)
  - [Benchmark](##Benchmark)
- [Example](#Example)
- [Authors](#Authors)


## Prerequisites

python2

python3

Package:
  - numpy

## Installing

`git clone https://github.com/clcreuso/Npuzzle.git`

Use your package manager to install python 2 and/or 3 and python package installer `pip`.
For example `brew install python3`, `brew install python2`, and `brew install pip`

Use python package installer pip to install dependancies.
For example `pip install numpy`

If you want to use the npuzzle generator:
Install python2

If you want to use the npuzzle solver:
Install python3
Install pip
`pip install numpy`

## Getting Started

Move to generator and solver repository:
> "cd Npuzzle/Rendu"

Generate and store Npuzzle data in a "test.txt" file then display it:
> "./npuzzle-gen.py 3 -s > test.txt && cat test.txt"

- `Npuzzle-gen.py`  : Npuzzle generator script
- `3`               : generate a 3x3 Npuzzle
- `-s`              : force to generate a solvable puzzle


Solve puzzle using the Npuzzle solver:
> "./resolve.py -md -uc < test.txt"

- `resolve.py`      : Npuzzle solver script
- `-md`             : Manhattan Distance heuristic
- `-uc`             : Uniform Cost search method

You don't have to use the Npuzzle generator.
You can just enter `./resolve.py` with needed arguments for example `-md -uc`
then enter the Npuzzle size for example `3` for a 3x3 Npuzzle
and finally write your own Npuzzle line by line.
You can use comment with `#` at the beginning of your comment.

## How to use

### Npuzzle generator usage

<p align="center"><img width="543" alt="Screen Shot 2019-07-03 at 15 37 14" src="https://user-images.githubusercontent.com/34065460/60599208-56f0c200-9dae-11e9-8f05-fc2c655f4c20.png"></p>

### Npuzzle solver usage

<p align="center"><img width="522" alt="Screen Shot 2019-07-03 at 15 38 09" src="https://user-images.githubusercontent.com/34065460/60599207-56f0c200-9dae-11e9-8a7e-64522c449383.png"></p>

## Algorithm

### A-star

To solve given Npuzzle, we have implemented an A-star algorithm.

This is an informed algorithm using heuristic to chose the best path to the solution.

For our Npuzzle solver you can choose between multiple heuristics and search method detailed below.

### Heuristics

- Manhattan Distance :
Calculate distance between the piece position and its goal position

- Hamming Distance
Check if the piece is at its goal position

- Linear Conflict
Check if there is pieces between a piece position and its goal (row and column only)

### Search method

- Uniform Cost:
Number of move to get to this state + cost of the next move

- Greedy Search:
Cost of the next move

### Benchmark

- Display :

             Number of moves to get to the solution
             Number of moves    = X

             Number of states ever selected in "opened" set
             Complexity in time = Y

             Maximum number of states ever represented at the same time in memory
             Compexity in size  = Z

             Search method:
                - Search method X
             
             Heuristic scoring:
                - Heurisctic X

## Example

<p align="center"><img width="495" alt="Screen Shot 2019-07-03 at 16 47 14" src="https://user-images.githubusercontent.com/34065460/60601658-c5378380-9db2-11e9-8261-8a48cec89809.png"></p>

## Authors

* **Clement Creusot** - [clcreuso](https://github.com/clcreuso)
* **Audric  Rolland** - [aurollan](https://github.com/aurollan)

