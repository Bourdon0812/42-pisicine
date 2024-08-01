/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_gen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 16:59:57 by yseguin           #+#    #+#             */
/*   Updated: 2024/07/28 11:55:04 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	clean_grid(int **grid);

////////////////////////////////////////////////////////////////////////////
// check if a number is unique in colum for respect format (line alredy given)
int	is_unique_in_columns(int **grid)
{
	int		col;
	int		seen[5];
	int		row;

	col = 0;
	row = 0;
	while (col < 4)
	{
		row = 0;
		seen[0] = 0;
		seen[1] = 0;
		seen[2] = 0;
		seen[3] = 0;
		seen[4] = 0;
		while (row < 4)
		{
			if (seen[grid[row][col]])
				return (0);
			seen[grid[row][col]] = 1;
			row++;
		}
		col++;
	}
	return (1);
}

////////////////////////////////////////////////////////////////////////////
//  This func add choosen  line to square. used into to_execute.
void	fill_grid(int **grid, int row, int line)
{
	int		col;

	col = 3;
	while (col >= 0)
	{
		grid[row][col] = line % 10;
		line /= 10;
		col--;
	}
}

////////////////////////////////////////////////////////////////////////////
// func wich be executed on all to_loop loop. 
void	to_execute(int ***all, int *count, int *i_j_k_l)
{
	const int	all_line[24] = {
		1234, 1243, 1324, 1342, 1432, 1423,
		2134, 2143, 2314, 2341, 2413, 2431,
		3124, 3142, 3214, 3241, 3412, 3421,
		4123, 4132, 4213, 4231, 4312, 4321
	};
	int			**grid;
	int			m;

	grid = malloc(4 * sizeof(int *));
	m = 0;
	while (m < 4)
	{
		grid[m] = malloc(4 * sizeof(int));
		m++;
	}
	fill_grid(grid, 0, all_line[i_j_k_l[0]]);
	fill_grid(grid, 1, all_line[i_j_k_l[1]]);
	fill_grid(grid, 2, all_line[i_j_k_l[2]]);
	fill_grid(grid, 3, all_line[i_j_k_l[3]]);
	if (is_unique_in_columns(grid))
		all[(*count)++] = grid;
	else
		clean_grid(grid);
}

////////////////////////////////////////////////////////////////////////////
// func do 4 loop for generate all possible square and save them into all tab
void	to_loop(int ***all, int *count, int *i_j_k_l)
{
	while (i_j_k_l[0] < 24)
	{
		while (i_j_k_l[1] < 24)
		{
			while (i_j_k_l[2] < 24)
			{
				while (i_j_k_l[3] < 24)
				{
					to_execute(all, count, i_j_k_l);
					i_j_k_l[3]++;
				}
				i_j_k_l[3] = 0;
				i_j_k_l[2]++;
			}
			i_j_k_l[2] = 0;
			i_j_k_l[1]++;
		}
		i_j_k_l[1] = 0;
		i_j_k_l[0]++;
	}
}

////////////////////////////////////////////////////////////////////////////
// func for create all possible square and save them -> [[[], [], [], []]]
int	***create_all(void)
{
	int		***all;
	int		count;
	int		i_j_k_l[4];

	all = malloc(288 * sizeof(int [4]));
	count = 0;
	i_j_k_l[0] = 0;
	i_j_k_l[1] = 0;
	i_j_k_l[2] = 0;
	i_j_k_l[3] = 0;
	to_loop(all, &count, i_j_k_l);
	all[count] = NULL;
	return (all);
}
