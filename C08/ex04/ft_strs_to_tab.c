/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibonnevi <ibonnevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 18:57:39 by ibonnevi          #+#    #+#             */
/*   Updated: 2024/07/31 11:47:00 by ibonnevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_get_copy(char *src)
{
	char	*cpy;
	int		i;

	i = -1;
	cpy = (char *)malloc((ft_strlen(src) + 1) * sizeof(char));
	if (cpy == NULL || src == NULL)
		return (NULL);
	while (src[++i] != '\0')
		cpy[i] = src[i];
	cpy[i] = '\0';
	return (cpy);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*stock;
	int			i;

	stock = (t_stock_str *)malloc((ac + 1) * sizeof(t_stock_str));
	if (stock == NULL)
		return (NULL);
	i = -1;
	while (++i != ac)
	{
		stock[i].size = ft_strlen(av[i]);
		stock[i].str = av[i];
		stock[i].copy = ft_get_copy(av[i]);
	}
	stock[i].str = 0;
	return (stock);
}
/*
int	main(int ac, char **av)
{
	t_stock_str *stock = ft_strs_to_tab(ac, av);
	ft_show_tab(stock);
}*/