/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibonnevi <ibonnevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:41:18 by lroussel          #+#    #+#             */
/*   Updated: 2024/08/07 20:05:02 by ibonnevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

int	find(char *path)
{
	char		*content;
	char		*ncontent;
	t_map_data	data;
	char		**map;

	content = file_get_contents(path);
	if (!content)
	{
		ft_puterror("map error\n");
		return (0);
	}
	ncontent = ft_map_is_valid(content, &data);
	if (ncontent == NULL)
	{
		ft_puterror("map error\n");
		free(content);
		return (0);
	}
	map = ft_str_to_tab(ncontent, &data);
	solve(data);
	print_solution(data);
	free_all(map);
	free(content);
	free(ncontent);
	return (1);
}

int	set_s_data(int x, int y, int size, t_square_data *s_data)
{
	(*s_data).x = x;
	(*s_data).y = y;
	(*s_data).size = size;
	return (size);
}

void	init_solve_vars(int *x, int *y, t_square_data *s_data)
{
	*x = 0;
	*y = 0;
	s_data->size = -1;
}

t_square_data	solve(t_map_data m_data)
{
	int				x;
	int				y;
	int				size;
	t_square_data	s_data;

	init_solve_vars(&x, &y, &s_data);
	while (m_data.map[y])
	{
		x = 0;
		while (m_data.map[y][x])
		{
			if (m_data.map[y][x] == m_data.obstacle_char)
			{
				x++;
				continue ;
			}
			size = find_square(x, y, 0, m_data);
			if (size > s_data.size)
				if (set_s_data(x, y, size, &s_data) >= (m_data.size_line / 2))
					return (put_square(s_data, m_data));
			x += size;
		}
		y++;
	}
	return (put_square(s_data, m_data));
}

void	print_solution(t_map_data m_data)
{
	int	y;

	y = 0;
	while (m_data.map[y])
	{
		write(1, m_data.map[y], m_data.size_line);
		write(1, "\n", 1);
		y++;
	}
}
