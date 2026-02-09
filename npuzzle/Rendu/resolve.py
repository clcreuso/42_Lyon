#!/usr/bin/env PYTHON3
"""Resolve an Npuzzle with an A-star algorithm."""

import sys
import argparse
from Class.state import State
from Class.npuzzle import Npuzzle, InputError


def args_coherence(chosen_heuristics, chosen_method):
    """Check argument coherence."""
    if chosen_method["greedy"] == chosen_method["uniform"]:
        raise InputError("You have to choose between greedy search and uniform cost.")
    if chosen_heuristics["all"]\
        or chosen_heuristics["manhattan"]\
        or chosen_heuristics["hamming"]\
        or chosen_heuristics["linear"]:
        return True
    raise InputError("You have to choose an heuristic.")


def print_selected_method(chosen_method):
    """Print chosen method to inform user."""
    if chosen_method["greedy"]:
        print("GREEDY SEARCH           ✅", sep=' ', end='\n', file=sys.stdout, flush=False)
    if chosen_method["uniform"]:
        print("UNIFORM COST            ✅", sep=' ', end='\n', file=sys.stdout, flush=False)

def print_selected_heurictics(chosen_heuristics):
    """Print chosen heuristics to inform user."""
    if chosen_heuristics["all"]:
        print("ALL HEURISTIC           ✅", sep=' ', end='\n', file=sys.stdout, flush=False)
    else:
        if chosen_heuristics["linear"]:
            print("LINEAR HEURISTIC        ✅", sep=' ', end='\n', file=sys.stdout, flush=False)
        if chosen_heuristics["hamming"]:
            print("HAMMING HEURISTIC       ✅", sep=' ', end='\n', file=sys.stdout, flush=False)
        if chosen_heuristics["manhattan"]:
            print("MANHATTAN HEURISTIC     ✅", sep=' ', end='\n', file=sys.stdout, flush=False)
    print()

def parse_arguments():
    """Parse argument and return list of heuristics chosed."""
    parser = argparse.ArgumentParser()
    parser.add_argument("-a", "--all",
                        help="Resolve Npuzzle using all heuristics",
                        action="store_true")
    parser.add_argument("-md", "--manhattan",
                        help="Resolve Npuzzle using Manhattan Distance heuristic",
                        action="store_true")
    parser.add_argument("-hd", "--hamming",
                        help="Resolve Npuzzle using Hamming Distance heuristic",
                        action="store_true")
    parser.add_argument("-lc", "--linear",
                        help="Resolve Npuzzle using Linear Conflict heuristic",
                        action="store_true")
    parser.add_argument("-gs", "--greedysearch",
                        help="Resolve Npuzzle using greedy search",
                        action="store_true")
    parser.add_argument("-uc", "--uniformcost",
                        help="Resolve Npuzzle using uniform cost",
                        action="store_true")
    args = parser.parse_args()

    if len(sys.argv) <= 1:
        raise InputError("No arguments provided.")

    heuristics = {
        "all": args.all,
        "linear": args.linear,
        "hamming": args.hamming,
        "manhattan": args.manhattan
    }
    method = {
        "greedy": args.greedysearch,
        "uniform": args.uniformcost
    }
    args_coherence(heuristics, method)
    print_selected_method(method)
    print_selected_heurictics(heuristics)
    return heuristics, method

if __name__ == "__main__":
    try:
        SELECTED_HEURISTICS, SELECTED_METHOD = parse_arguments()
        PUZZLE = Npuzzle(SELECTED_HEURISTICS, SELECTED_METHOD)
        PUZZLE.parser()
        PUZZLE.is_solvable()
        PUZZLE.a_star(index=1)
    except Exception as e:
        if len(str(e)):
            print("Error: " + str(e))
        else:
            print("Error: unexpected input")
