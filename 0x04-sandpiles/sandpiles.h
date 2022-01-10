#ifndef SANDPILES
#define SANDPILES

#include <stdio.h>

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);

int is_unstable(int grid[3][3]);
void topple_grid(int grid[3][3]);
void topple_cell(int grid[3][3], int i, int j);

void _print_grid(int grid[3][3]);

#endif /* SANDPILES */
