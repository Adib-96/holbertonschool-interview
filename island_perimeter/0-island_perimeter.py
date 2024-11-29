#!/usr/bin/python3
"""
Function to calculate the perimeter of the island described in grid
"""


def island_perimeter(grid):
    """
    Function that returns the perimeter of the island described in grid.
    The grid is a list of lists of integers where 1 represents land,
    and 0 represents water.

    Args:
    grid (list of list of int): A grid representing the island.

    Returns:
    int: The perimeter of the island.
    """
    perimeter = 0
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            # Check if the current cell is land
            if grid[i][j] == 1:
                # Check up
                if i == 0 or grid[i - 1][j] == 0:
                    perimeter += 1
                # Check down
                if i == len(grid) - 1 or grid[i + 1][j] == 0:
                    perimeter += 1
                # Check left
                if j == 0 or grid[i][j - 1] == 0:
                    perimeter += 1
                # Check right
                if j == len(grid[i]) - 1 or grid[i][j + 1] == 0:
                    perimeter += 1
    return perimeter
