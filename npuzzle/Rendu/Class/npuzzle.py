"""Npuzzle object: parse, store and resolve Npuzzle."""

import re
import sys
import copy
import numpy

from .state import State
from .coordinate import Coordinate
from .npuzzle_piece import NpuzzlePiece as new_piece


class Error(Exception):
    """Base class for exceptions in this module."""

class InputError(Error):
    """Exception raised for errors in the input."""

    def __init__(self, message):
        """Initialize error message."""
        self.message = message

class Npuzzle:
    """This class represent an Npuzzle object."""

# *********************************************************************************************** #
# ******************************************** OBJECT ******************************************* #
# *********************************************************************************************** #

    def __init__(self, heuristics, method):
        """Initialize Npuzzle variable."""
        # Board
        self.size = None
        self.pieces = {}
        self.initial_board = []
        self.current_board = []
        # A-star
        self.movements = []
        self.opened_boards = []
        self.closed_boards_hash = {}
        self.opened_boards_hash = {}
        # Benchmark
        self.time_complexity = 0
        # Flags
        self.method = method
        self.heuristics = heuristics

    def __str__(self):
        """Display object information as a string."""
        board_str = f""
        junction = ", "
        for line in range(0, self.size):
            board_str += f"[{junction.join(map(str, self.current_board[line]))}]\n"
        return board_str

# *********************************************************************************************** #
# ****************************************** SOLUTION ******************************************* #
# *********************************************************************************************** #

    def benchmark(self, index):
        """Print npuzzle resolution performance benchmark."""
        heuristics = ""
        time_complexity = len(self.opened_boards)
        size_complexity = time_complexity + len(self.closed_boards_hash)

        for heuristic in self.heuristics:
            if self.heuristics[heuristic]:
                heuristics += "    - " + heuristic.capitalize() + "\n"

        method = "    - Uniform cost\n"
        if self.method["greedy"]:
            method = "    - Greedy\n" 

        benchmark_string = f"""Benchmark
            --------------------------------------------
            
             Number of moves to get to the solution
             Number of moves = {index - 1}\n
             Number of states ever selected in \"opened\" set
             Complexity in time = {time_complexity}\n
             Maximum number of states ever represented at the same time in memory
             Compexity in size = {size_complexity}

             Search method:
            {method}
             Heuristic scoring:
            {heuristics}""".replace("            ", "")
        print(benchmark_string, sep=' ', end='\n', file=sys.stdout, flush=False)

    def print_arrow(self, movement):
        """Move piece according to chosen movement."""
        if movement == "left":
            print("Move:  ⇦", sep=' ', end='\n\n', file=sys.stdout, flush=False)
        if movement == "right":
            print("Move:  ⇨", sep=' ', end='\n\n', file=sys.stdout, flush=False)
        if movement == "down":
            print("Move:  ⇩", sep=' ', end='\n\n', file=sys.stdout, flush=False)
        if movement == "up":
            print("Move:  ⇧", sep=' ', end='\n\n', file=sys.stdout, flush=False)

    def display_solution(self):
        """Move piece according to chosen movement."""
        self.current_board = self.initial_board

        for y_pos in range(0, self.size):
            for x_pos in range(0, self.size):
                self.pieces[self.current_board[y_pos][x_pos]].set_pos(x_pos, y_pos)

        for movement in self.movements:
            print(self, sep=' ', end='', file=sys.stdout, flush=False)
            self.print_arrow(movement)
            y_pos = self.pieces[0].pos.y
            x_pos = self.pieces[0].pos.x
            if movement == "left":
                self.swap_piece(self.pieces[self.current_board[y_pos][x_pos - 1]])
            if movement == "right":
                self.swap_piece(self.pieces[self.current_board[y_pos][x_pos + 1]])
            if movement == "down":
                self.swap_piece(self.pieces[self.current_board[y_pos + 1][x_pos]])
            if movement == "up":
                self.swap_piece(self.pieces[self.current_board[y_pos - 1][x_pos]])
        print(self, sep=' ', end='', file=sys.stdout, flush=False)
        print("Solved 🎉", sep=' ', end='\n\n', file=sys.stdout, flush=False)

# *********************************************************************************************** #
# ******************************************** CHECKER ****************************************** #
# *********************************************************************************************** #

    def is_solvable(self):
        """Check if the Npuzzle is solvable."""
        solvable = True
        for piece in range(1, pow(self.size, 2)):
            for next_piece in range(piece + 1, pow(self.size, 2)):
                if self.pieces[piece].pos.order > self.pieces[next_piece].pos.order:
                    solvable = not solvable
        if not solvable:
            raise InputError("This puzzle is unsolvable.")
        return solvable

# *********************************************************************************************** #
# ******************************************** PARSER ******************************************* #
# *********************************************************************************************** #

    def filtered_input(self):
        """Return an input() without comment."""
        string_get = re.sub(r'#.*', '', input())
        return list(map(int, string_get.strip().split()))

    def piece_order(self, searched_piece):
        """Parse the solved Npuzzle."""
        for piece in self.pieces.values():
            if piece.dest == searched_piece.pos:
                return piece.dest.order
        raise InputError("Argument not found")

    def parser_helper(self, index, pos_x, pos_y):
        """Parser helper."""
        if self.pieces[index].pos:
            raise InputError("Duplicate piece in arguments")
        self.pieces[index].number = index
        self.pieces[index].set_pos(pos_x, pos_y)
        self.pieces[index].pos.order = self.piece_order(self.pieces[index])

    def helper_set_solution(self, array, coord, movement):
        """Check if you reach an edge."""
        if movement == "down":
            if coord.y < self.size - 1 and array[coord.y + 1][coord.x] == 0:
                coord.y = coord.y + 1
                return 1
        if movement == "right":
            if coord.x < self.size - 1 and array[coord.y][coord.x + 1] == 0:
                coord.x = coord.x + 1
                return 1
        if movement == "up":
            if coord.y > 0 and array[coord.y - 1][coord.x] == 0:
                coord.y = coord.y - 1
                return 1
        if movement == "left":
            if coord.x > 0 and array[coord.y][coord.x - 1] == 0:
                coord.x = coord.x - 1
                return 1
        return 0

    def set_solution(self):
        """Parse the solved Npuzzle."""
        array = numpy.zeros((self.size, self.size), dtype=numpy.int)
        coord = Coordinate(-1, 0)
        index = 1
        while numpy.amin(array) == 0:
            for movement in ("right", "down", "left", "up"):
                while self.helper_set_solution(array, coord, movement):
                    dest = Coordinate(coord.x, coord.y, index)
                    self.pieces[index] = new_piece(dest)
                    array[coord.y][coord.x], index = index, index + 1
        self.pieces[0] = self.pieces.pop(pow(self.size, 2))

    def initialize(self, size):
        """Parse stream input to construct pieces pos."""
        self.size = size
        self.initial_board = numpy.zeros((size, size), dtype=numpy.int)
        self.set_solution()

    def parser(self):
        """Parse stream input to construct pieces pos."""
        pos_y = 0
        while pos_y is not self.size:
            array = self.filtered_input()

            if array and self.size:
                if self.size < 3:
                    raise InputError("Invalid input size")
                if len(array) is not self.size:
                    raise InputError("Invalid number of arguments")
                if len(array) is not len(set(array)):
                    raise InputError("Duplicate piece in arguments")
                if max(array) >= pow(self.size, 2):
                    raise InputError("Argument too big")
                for pos_x, piece_index in enumerate(array):
                    self.parser_helper(piece_index, pos_x, pos_y)
                    self.initial_board[pos_y][pos_x] = piece_index
                pos_y += 1
            if array and not self.size:
                self.initialize(array[0])

# *********************************************************************************************** #
# ******************************************** ALGORITHM **************************************** #
# *********************************************************************************************** #

    def a_star(self, index=1):
        """Solve the Npuzzle regarding the chosen heuristic."""
        self.current_board = copy.deepcopy(self.initial_board)
        initial_board_score = self.calcul_heuristics()
        self.opened_boards = [State(0, self.current_board, initial_board_score)]
        self.register_in_opened_board()
        while self.opened_boards:
            self.reinit_pieces()
            if self.is_solved():
                self.display_solution()
                self.benchmark(index)
                return True
            self.register_in_closed_board()
            self.delete_in_opened_board()
            self.explore_node(index)
            index = self.opened_boards[0].index + 1
        raise InputError("No solution found")

    def explore_node(self, index):
        """Choose the best move to do."""
        y_pos = self.pieces[0].pos.y
        x_pos = self.pieces[0].pos.x
        if x_pos > 0:
            self.open_sub_node(self.pieces[self.current_board[y_pos][x_pos - 1]], index, "left")
        if x_pos < self.size - 1:
            self.open_sub_node(self.pieces[self.current_board[y_pos][x_pos + 1]], index, "right")
        if y_pos > 0:
            self.open_sub_node(self.pieces[self.current_board[y_pos - 1][x_pos]], index, "up")
        if y_pos < self.size - 1:
            self.open_sub_node(self.pieces[self.current_board[y_pos + 1][x_pos]], index, "down")

    def open_sub_node(self, tested_piece, index, movement):
        """Test movement score."""
        self.swap_piece(tested_piece)
        if self.is_registered_in_closed_board() or self.is_registered_in_opened_board():
            self.swap_piece(tested_piece)
            return None
        scoring_result = self.calcul_heuristics()
        if self.method["uniform"]:
            self.opened_boards.insert(0, State(index,
                                               copy.deepcopy(self.current_board),
                                               scoring_result + index))
        if self.method["greedy"]:
            self.opened_boards.insert(0, State(index,
                                               copy.deepcopy(self.current_board),
                                               scoring_result))
        self.opened_boards[0].set_movements(self.movements, movement)
        self.opened_boards.sort()
        self.register_in_opened_board()
        self.swap_piece(tested_piece)
        return scoring_result

    def reinit_pieces(self):
        """Initialize the boards like the chosen node."""
        self.current_board = self.opened_boards[0].array
        self.movements = self.opened_boards[0].movements
        for y_pos in range(0, self.size):
            for x_pos in range(0, self.size):
                self.pieces[self.current_board[y_pos][x_pos]].set_pos(x_pos, y_pos)

# *********************************************************************************************** #
# ****************************************** HEURISTICS ***************************************** #
# *********************************************************************************************** #

    def total_linear_conflict(self):
        """Calculate linear conflict score of the puzzle."""
        result = 0
        for piece in self.pieces.values():
            if piece.number == 0:
                continue
            if piece.pos.order != piece.dest.order:
                if piece.pos.y == piece.dest.y or piece.pos.x == piece.dest.x:
                    result += piece.d_manhattan
        return result

    def total_hamming_position(self):
        """Check is npuzzle is solved using manhattan distance."""
        result = 0
        for piece in self.pieces.values():
            if piece.number == 0: 
                continue
            if piece.pos.x != piece.dest.x or piece.pos.y != piece.dest.y:
                result += 1
        return result

    def total_manhattan_distance(self):
        """Calulate total manhattan distance of the npuzzle."""
        result = 0
        for piece in self.pieces.values():
            if piece.number == 0: 
                continue
            result += piece.d_manhattan
        return result

    def calcul_heuristics(self):
        """Calculate score with chosen_heuristics."""
        scoring = 0
        if self.heuristics["linear"] or self.heuristics["all"]:
            scoring += self.total_linear_conflict()
        if self.heuristics["hamming"] or self.heuristics["all"]:
            scoring += self.total_hamming_position()
        if self.heuristics["manhattan"] or self.heuristics["all"]:
            scoring += self.total_manhattan_distance()
        return scoring

# *********************************************************************************************** #
# **************************************** MANAGE LIST ****************************************** #
# *********************************************************************************************** #

    def register_in_closed_board(self):
        """Register npuzzle state in closed board."""
        key = "".join(map(str, self.current_board))
        self.closed_boards_hash[key] = True

    def is_registered_in_closed_board(self):
        """Test if a board pattern is in the closed board."""
        key = "".join(map(str, self.current_board))
        return key in self.closed_boards_hash

    def register_in_opened_board(self):
        """Register npuzzle state in open board."""
        key = "".join(map(str, self.current_board))
        self.opened_boards_hash[key] = True

    def is_registered_in_opened_board(self):
        """Test if a board pattern is in the opened board."""
        key = "".join(map(str, self.current_board))
        return key in self.opened_boards_hash

    def delete_in_opened_board(self):
        """Delete board in opened board and register in closed board."""
        key = "".join(map(str, self.current_board))
        self.closed_boards_hash[key] = True
        del self.opened_boards_hash[key]
        del self.opened_boards[0]

# *********************************************************************************************** #
# ******************************************** TOOLS ******************************************** #
# *********************************************************************************************** #

    def is_solved(self):
        """Check if the puzzle is solved."""
        return self.total_hamming_position() == 0

    def swap_piece(self, moved_piece):
        """Swap 2 pieces of the Npuzzle."""
        piece_zero = self.pieces[0]
        piece_zero.pos, moved_piece.pos = moved_piece.pos, piece_zero.pos
        piece_zero.calculate_manhattan_distance()
        moved_piece.calculate_manhattan_distance()
        self.current_board[piece_zero.pos.y][piece_zero.pos.x] = 0
        self.current_board[moved_piece.pos.y][moved_piece.pos.x] = moved_piece.dest.order
        return self.calcul_heuristics()
