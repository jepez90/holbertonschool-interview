#include "sandpiles.h"

/**
 * sandpiles_sum - computes the sum of two sandpiles
 * and make stable the result grid
 *
 * @grid1: stable 3x3 grid of integers
 * @grid2: stable 3x3 grid of integers
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	/* sum the sandpiles */
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}

	/* if is unestable, topple all grid */
	while (is_unstable(grid1))
	{
		_print_grid(grid1);
		topple_grid(grid1);
	}
}

/**
 * is_unstable - Check if a 3x3 grid is unstable, it means, if any of its
 * values is grater than 3
 * @grid: 3x3 grid of integers
 *
 * Return: 1 if the grid is unstable, 0 if it isn't
 */
int is_unstable(int grid[3][3])
{
	int i, j;

	/* check each cell in the grid */
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
			{
				/* if exist any number grathet than 3, is unstable */
				return (1);
			}
		}
	}
	return (0);
}

/**
 * topple_grid - Tooplea 3x3 grid only one iteration
 * @grid: 3x3 grid of integers
 *
 */
void topple_grid(int grid[3][3])
{
	/* center */
	topple_cell(grid, 1, 1);

	/* corners */
	topple_cell(grid, 0, 0);
	topple_cell(grid, 0, 2);
	topple_cell(grid, 2, 0);
	topple_cell(grid, 2, 2);

	/* sides */
	topple_cell(grid, 0, 1);
	topple_cell(grid, 2, 1);
	topple_cell(grid, 1, 0);
	topple_cell(grid, 1, 2);
}

/**
 * topple_cell - Toople the cell over its neighbors
 * @grid: 3x3 grid of integers
 * @i: row  in the grid
 * @j: column in the grid
 *
 */
void topple_cell(int grid[3][3], int i, int j)
{
	/* if the cell is unstable */
	if (grid[i][j] >= 4)
	{
		/* reduce the cell */
		grid[i][j] -= 4;

		/* check if is each side exist and adds 1 */
		if (i - 1 >= 0)
			grid[i - 1][j] += 1;
		if (i + 1 <= 2)
			grid[i + 1][j] += 1;
		if (j - 1 >= 0)
			grid[i][j - 1] += 1;
		if (j + 1 <= 2)
			grid[i][j + 1] += 1;
	}
}

/**
 * _print_grid - Print 3x3 grid
 * @grid: 3x3 grid of integers
 *
 */
void _print_grid(int grid[3][3])
{
	int i;

	printf("=\n");

	for (i = 0; i < 3; i++)
	{
		printf("%d %d %d\n", grid[i][0], grid[i][1], grid[i][2]);
	}
}
