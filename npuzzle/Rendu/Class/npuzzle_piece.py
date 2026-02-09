"""Piece of an Npuzzle."""

from .coordinate import Coordinate


class NpuzzlePiece():
    """Working method on a puzzle piece."""

    def __init__(self, dest):
        """Intialise attributs to 0."""
        self.pos = None
        self.d_hamming = None
        self.d_manhattan = None
        self.dest = dest
        self.number = None

    def set_pos(self, pos_x, pos_y, order=None):
        """Set x and y pos and calculate distances."""
        self.pos = Coordinate(pos_x, pos_y, order)

        self.calculate_manhattan_distance()
        self.calculate_hamming_distance()

    def calculate_manhattan_distance(self):
        """Calulate manhattan_distance."""
        diff_dx = abs(self.pos.x - self.dest.x)
        diff_dy = abs(self.pos.y - self.dest.y)

        self.d_manhattan = diff_dx + diff_dy

    def calculate_hamming_distance(self):
        """Calulate hamming_distance."""
        self.d_hamming = self.pos == self.dest

    def __str__(self):
        """Print Npuzzle piece."""
        return f"""Piece               N°{self.dest.order}
                            --------------------------------------------
                             Position        = {self.pos}
                             Destination     = {self.dest}
                             Hamming value   = [{self.d_hamming}]
                             Manhattan value = [{self.d_manhattan}]\n""".replace("\t", "")
