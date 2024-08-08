/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibonnevi <ibonnevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 13:35:59 by ibonnevi          #+#    #+#             */
/*   Updated: 2024/08/01 13:52:32 by ibonnevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <stdio.h>
/*
int square(int value)
{
    return (value * value);
}*/

int	*ft_map(int *tab, int lenght, int (*f)(int))
{
	int	*res;
	int	i;

	i = -1;
	res = malloc(lenght * sizeof(int));
	if (res == NULL)
		return (NULL);
	while (++i != lenght)
		res[i] = f(tab[i]);
	return (res);
}
/*
int main()
{
    int t[6] = {2, 4, 6, 10, 100, 0};
    int *tab = ft_map(t, 6, &square);
    for(int i = 0; i != 6; i++)
        printf("%d\n", tab[i]);
}*/