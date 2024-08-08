/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibonnevi <ibonnevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 08:31:35 by ibonnevi          #+#    #+#             */
/*   Updated: 2024/08/07 18:43:44 by ibonnevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

int	sl(char *str)
{
	int	i;
	int	n;
	int	j;

	i = -1;
	j = -1;
	n = 0;
	while (str[++i] != '\n' && str[i] != '\0')
		n++;
	if (str[i] != '\n' || str[i] == '\0')
		return (-1);
	while (str[++i] != '\0')
	{
		j++;
		if (str[i] == '\n')
		{
			if (j != n)
				return (-1);
			j = -1;
		}
	}
	return (n);
}

t_map_data	*ft_set_map_data(char **strpt, t_map_data *data)
{
	int		i;
	char	*str;
	char	*lines;

	str = *strpt;
	i = 0;
	while (str[i + 1] != '\n' && str[i + 1] != '\0')
		i++;
	if (i < 3)
		return (NULL);
	lines = ft_strndup(str, 0, i - 3);
	if (!ft_is_numeric(lines))
	{
		free(lines);
		return (NULL);
	}
	data->square_char = str[i];
	data->obstacle_char = str[i - 1];
	data->void_char = str[i - 2];
	data->lines = ft_atoi(lines);
	*strpt = ft_strndup(str, i + 2, ft_strlen(str) - 1);
	data->size_line = sl(*strpt);
	free(lines);
	return (data);
}

char	*ft_map_is_valid(char *str, t_map_data *data)
{
	if (ft_set_map_data(&str, data) == NULL)
		return (NULL);
	if (data->obstacle_char == data->square_char
		|| data->obstacle_char == data->void_char
		|| data->square_char == data->void_char
		|| !(data->void_char >= ' ' && data->void_char <= '~')
		|| !(data->obstacle_char >= ' ' && data->obstacle_char <= '~')
		|| !(data->square_char >= ' ' && data->square_char <= '~')
	)
	{
		free(str);
		return (NULL);
	}
	if (ft_nb_lines(str, data) != data->lines)
	{
		free(str);
		return (NULL);
	}
	if (data->size_line == -1)
	{
		free(str);
		return (NULL);
	}
	return (str);
}

int	ft_nb_lines(char *str, t_map_data *data)
{
	int	i;
	int	cl;

	cl = 0;
	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] != '\n' && str[i] != data->obstacle_char
			&& str[i] != data->void_char)
		{
			return (-1);
		}
		if (str[i] == '\n')
			cl++;
	}
	return (cl);
}
