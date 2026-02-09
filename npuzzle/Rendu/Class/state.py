"""Structure de sauvegarde de l'etat d'un tableau."""

import copy

class State:
    """Store node data object."""

    def __init__(self, index, array, score):
        """Initialise state data to save."""
        self.score = score
        self.index = index
        self.array = array
        self.movements = []

    def __lt__(self, other):
        """Compare 2 state and return True if other is greater than self."""
        if (self.score < other.score) or (self.score == other.score and self.index < other.index):
            return True
        return False

    def __str__(self):
        """Display state data as string."""
        display = f""" noeud = {self.index}\nscore = {self.score}\narray =\n{self.array}"""
        return display

    def set_movements(self, movements_list, new_movement):
        """Create movement list form previous node and last movements."""
        self.movements = copy.deepcopy(movements_list)
        self.movements.append(new_movement)
