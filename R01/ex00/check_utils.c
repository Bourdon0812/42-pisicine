/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 17:41:37 by ibonnevi          #+#    #+#             */
/*   Updated: 2024/07/28 11:52:00 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////
// func for check if 
char	check_high_visibility(int **grid, int top[4])
{
	int	col;
	int	max_height;
	int	visible_count;
	int	row;

	col = 0;
	while (col < 4)
	{
		max_height = 0;
		visible_count = 0;
		row = 0;
		while (row < 4)
		{
			if (grid[row][col] > max_height)
			{
				visible_count++;
				max_height = grid[row][col];
			}
			row++;
		}
		if (visible_count != top[col] && top[col] != 0)
			return (0);
		col++;
	}
	return (1);
}

////////////////////////////////////////////////////////////////////////////
// func for check if 
char	check_down_visibility(int **grid, int bottom[4])
{
	int	col;
	int	max_height;
	int	visible_count;
	int	row;

	col = 0;
	while (col < 4)
	{
		max_height = 0;
		visible_count = 0;
		row = 3;
		while (row >= 0)
		{
			if (grid[row][col] > max_height)
			{
				visible_count++;
				max_height = grid[row][col];
			}
			row--;
		}
		if (visible_count != bottom[col] && bottom[col] != 0)
			return (0);
		col++;
	}
	return (1);
}

////////////////////////////////////////////////////////////////////////////
// func for check if 
char	check_left_visibility(int **grid, int left[4])
{
	int	row;
	int	max_height;
	int	visible_count;
	int	col;

	row = 0;
	while (row < 4)
	{
		max_height = 0;
		visible_count = 0;
		col = 0;
		while (col < 4)
		{
			if (grid[row][col] > max_height)
			{
				visible_count++;
				max_height = grid[row][col];
			}
			col++;
		}
		if (visible_count != left[row] && left[row] != 0)
			return (0);
		row++;
	}
	return (1);
}

////////////////////////////////////////////////////////////////////////////
// func for check if 
char	check_right_visibility(int **grid, int right[4])
{
	int	row;
	int	max_height;
	int	visible_count;
	int	col;

	row = 0;
	while (row < 4)
	{
		max_height = 0;
		visible_count = 0;
		col = 3;
		while (col >= 0)
		{
			if (grid[row][col] > max_height)
			{
				visible_count++;
				max_height = grid[row][col];
			}
			col--;
		}
		if (visible_count != right[row] && right[row] != 0)
			return (0);
		row++;
	}
	return (1);
}

////////////////////////////////////////////////////////////////////////////
// func for check if the grid is the result or not.
char	check(int **grid, int **index)
{
	return (check_high_visibility(grid, index[0])
		&& check_down_visibility(grid, index[1])
		&& check_left_visibility(grid, index[2])
		&& check_right_visibility(grid, index[3])
	);
}
