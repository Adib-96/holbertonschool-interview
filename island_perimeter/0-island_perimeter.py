#!/usr/bin/python3

"""
This module provides a function to calculate the perimeter of an island in a grid.
"""


def island_perimeter(grid):
    """
    Calculates the perimeter of the island represented in the grid.
    """
    perimeter = 0
    rows = len(grid)
    cols = len(grid[0]) if rows > 0 else 0

    for line in range(rows):
        for cell in range(cols):
            if grid[line][cell] == 1:
                perimeter += 4

                if line > 0 and grid[line - 1][cell] == 1:
                    perimeter -= 1
                if cell > 0 and grid[line][cell - 1] == 1:
                    perimeter -= 1
                if cell < cols - 1 and grid[line][cell + 1] == 1:
                    perimeter -= 1
                if line < rows - 1 and grid[line + 1][cell] == 1:
                    perimeter -= 1
    return perimeter
