#include "sandpiles.h"

/**
 * printGrid - Prints a 3x3 grid.
 * @grid: The grid to print.
 *
 * Return: void
 */
void printGrid(int grid[3][3])
{
/*
* return: void
*/
printf("=\n");
for (int i = 0; i < 3; i++)
{
for (int j = 0; j < 3; j++)
{
printf("%d ", grid[i][j]);
}
printf("\n");
}
}

/**
 * isStable - Checks if the sandpile is stable.
 * @grid: The grid to check.
 *
 * Return: 1 if stable, 0 otherwise.
 */
int isStable(int grid[3][3])
{
for (int i = 0; i < 3; i++)
{
for (int j = 0; j < 3; j++)
{
if (grid[i][j] > 3)
{
return (0);
}
}
}
return (1);
}
/**
 * topple - Performs one toppling round.
 * @grid: The grid to topple.
 *
 * Return: void
 */
void topple(int grid[3][3])
{
int tempGrid[3][3];
for (int i = 0; i < 3; i++)
{
for (int j = 0; j < 3; j++)
{
tempGrid[i][j] = grid[i][j];
}
}

for (int i = 0; i < 3; i++)
{
for (int j = 0; j < 3; j++)
{
if (tempGrid[i][j] > 3)
{
grid[i][j] -= 4;
if (i > 0)
{
grid[i - 1][j]++;
}
if (i < 2)
{
grid[i + 1][j]++;
}
if (j > 0)
{
grid[i][j - 1]++;
}
if (j < 2)
{
grid[i][j + 1]++;
}
}
}
}
}
/**
 * sandpiles_sum - Computes the sum of two sandpiles.
 * @grid1: The first grid and result grid.
 * @grid2: The second grid.
 *
 * Return: void
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
for (int i = 0; i < 3; i++)
{
for (int j = 0; j < 3; j++)
{
grid1[i][j] += grid2[i][j];
}
}

while (!isStable(grid1))
{
printGrid(grid1);
topple(grid1);
}
printGrid(grid1);
}
