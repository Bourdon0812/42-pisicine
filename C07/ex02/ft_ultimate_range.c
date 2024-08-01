/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibonnevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:59:32 by ibonnevi          #+#    #+#             */
/*   Updated: 2024/07/25 19:41:03 by ibonnevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	*range = malloc((max - min) * sizeof(int));
	if (*range == NULL)
		return (-1);
	i = -1;
	while (min != max)
	{
		(*range)[++i] = min++;
	}
	return (i + 1);
}
/*
int	main()
{
	int *range;
	int	i = 0;
	int nb;
	nb = ft_ultimate_range(&range, 3, 11);
	printf("%d\n", nb);
	while (i != nb)
	{
		printf("%d\n", range[i]);
		i++;
	}
}*/
