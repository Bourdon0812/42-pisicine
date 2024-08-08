/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finder.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibonnevi <ibonnevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:44:34 by lroussel          #+#    #+#             */
/*   Updated: 2024/08/07 12:49:15 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

int	check_case(int bx, int by, int offset, t_map_data m_data)
{
	int	x;
	int	y;
	int	tx;
	int	ty;

	x = bx + offset;
	y = by + offset;
	tx = bx;
	ty = by;
	while (m_data.map[ty] && ty <= (y - 1))
	{
		if (m_data.map[ty][x] == m_data.obstacle_char)
			return (0);
		ty++;
	}
	while (m_data.map[y] && m_data.map[y][tx] && tx <= x)
	{
		if (m_data.map[y][tx] == m_data.obstacle_char)
			return (0);
		tx++;
	}
	return (1);
}

int	find_square(int bx, int by, int offset, t_map_data m_data)
{
	int	x;
	int	y;

	x = bx + offset;
	y = by + offset;
	if (!m_data.map[y] || !m_data.map[y][x])
		return (0);
	if (bx == x && by == y && m_data.map[y][x] == m_data.obstacle_char)
		return (0);
	if (!check_case(bx, by, offset, m_data))
		return (0);
	return (1 + find_square(bx, by, offset + 1, m_data));
}

t_square_data	put_square(t_square_data s_data, t_map_data m_data)
{
	int	x;
	int	max_x;
	int	y;
	int	max_y;

	x = s_data.x;
	max_x = x + s_data.size;
	y = s_data.y;
	max_y = y + s_data.size;
	while (y < max_y)
	{
		x = s_data.x;
		while (x < max_x)
		{
			m_data.map[y][x] = m_data.square_char;
			x++;
		}
		y++;
	}
	return (s_data);
}
