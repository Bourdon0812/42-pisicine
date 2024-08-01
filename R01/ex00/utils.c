/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 11:45:05 by yseguin           #+#    #+#             */
/*   Updated: 2024/07/28 11:55:15 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned int	ft_strlen(char *str);

////////////////////////////////////////////////////////////////////////////
// execute part of char_to_tab
void	char_tab_exec(char *str, int **result, int x, int y)
{
	while (*str)
	{
		if (*str != ' ')
		{
			result[y][x] = *str - 48;
			x++;
		}
		if (x == 4)
		{
			x = 0;
			y++;
		}
		str++;
	}
}

////////////////////////////////////////////////////////////////////////////
// convert a certified string to int tab for index
int	**char_to_tab(char *str)
{
	int		x;
	int		y;
	int		**result;

	x = 0;
	y = 0;
	result = malloc(4 * sizeof(int *));
	while (x < 4)
	{
		result[x] = malloc(4 * sizeof(int));
		x++;
	}
	x = 0;
	char_tab_exec(str, result, x, y);
	return (result);
}

////////////////////////////////////////////////////////////////////////////
// check if the string is conform to attend format.
int	ft_check_str(char *str)
{
	unsigned int	size;
	char			is_n;	

	size = ft_strlen(str);
	is_n = 1;
	if (size != (16 + 15))
		return (0);
	while (--size != 0)
	{
		if (is_n)
		{
			if (!(str[size] >= '1' && str[size] <= '4'))
				return (0);
			is_n = 0;
		}
		else
		{
			if (str[size] != ' ')
				return (0);
			is_n = 1;
		}
	}
	return (1);
}

////////////////////////////////////////////////////////////////////////////
// clean grid malloc if never used.
void	clean_grid(int **grid)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}
