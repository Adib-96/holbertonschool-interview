#!/usr/bin/python3

"""
This module provides a function to calculate the perimeter of an island in a grid.
The grid is represented by a list of lists, where 0 represents water and 1
represents land. Each cell is square, with a side length of 1. Cells are
connected horizontally or vertically, not diagonally. The grid is completely
surrounded by water, and there is only one island (or nothing).
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
                # Start with 4 sides for each land cell
                perimeter += 4
                # Check and subtract for each adjacent land cell

                # Check the top cell
                if line > 0 and grid[line - 1][cell] == 1:
                    perimeter -= 1
                # Check the left cell
                if cell > 0 and grid[line][cell - 1] == 1:
                    perimeter -= 1
                # Check the right cell
                if cell < cols - 1 and grid[line][cell + 1] == 1:
                    perimeter -= 1
                # Check the bottom cell
                if line < rows - 1 and grid[line + 1][cell] == 1:
                    perimeter -= 1
    return perimeter
