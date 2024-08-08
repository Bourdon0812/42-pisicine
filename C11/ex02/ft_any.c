/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibonnevi <ibonnevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:00:53 by ibonnevi          #+#    #+#             */
/*   Updated: 2024/08/05 13:45:45 by ibonnevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_any(char **tab, int (*f)(char*))
{
	int	i;

	i = -1;
	while (tab[++i] != NULL)
	{
		if (f(tab[i]) != 0)
			return (1);
	}
	return (0);
}
/*
#include <stdio.h>

int	contains_a(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 'a')
			return (1);
		i++;
	}
	return (0);
}

int	main(void)
{
	char *array1[] = {"hello", "world", "example", "test", NULL};
	char *array2[] = {"hello", "world", "xyz", "test", NULL};

	if (ft_any(array1, contains_a))
		printf("Array1: At least one string contains 'a'\n");
	else
		printf("Array1: No string contains 'a'\n");

	if (ft_any(array2, contains_a))
		printf("Array2: At least one string contains 'a'\n");
	else
		printf("Array2: No string contains 'a'\n");

	return 0;
}
*/