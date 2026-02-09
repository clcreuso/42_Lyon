"""Coordinate Class soring x, y and order value."""


class Coordinate():
    """Working method on coordinate."""

    def __init__(self, x, y, order=None):
        """Attributes x and y coordinate."""
        self.x = x
        self.y = y
        self.order = order

    def get_x(self):
        """Return x coordinate."""
        return self.x

    def get_y(self):
        """Return y coordinate."""
        return self.y

    def __str__(self):
        """Convert object information as a string."""
        return f"[x: {self.x}] [y: {self.y}] [order: {self.order}]"

    def __eq__(self, other):
        """Check if object coordinate are equal."""
        return self.y == other.y and self.x == other.x

    def __ne__(self, other):
        """Check if object coordinate are not equal."""
        return self.y != other.y or self.x != other.x

    def distance(self, other):
        """Calculate distance between 2 points."""
        return abs(self.y - other.y) + abs(self.x - other.x)

    def __repr__(self):
        """Display object information."""
        return "Coordinate[%d, %d, %d]" % (self.x, self.y, self.order)

    def __lt__(self, other):
        """Check witch point is nearer the origin."""
        if (self.y < other.y) or (self.y == other.y and self.x < other.x):
            return True
        return False

    def __gt__(self, other):
        """Check witch point is further the origin."""
        if (self.y > other.y) or (self.y == other.y and self.x > other.x):
            return True
        return False
