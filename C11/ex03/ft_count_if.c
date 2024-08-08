/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibonnevi <ibonnevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:14:37 by ibonnevi          #+#    #+#             */
/*   Updated: 2024/08/05 13:50:46 by ibonnevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int lenght, int (*f)(char*))
{
	int	c;
	int	i;

	i = -1;
	c = 0;
	while (++i != lenght)
	{
		if (f(tab[i]) != 0)
			c++;
	}
	return (c);
}
/*
#include <stdio.h>

int contains_a(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == 'a')
            return (1);
        i++;
    }
    return (0);
}

int main(void)
{
    char *array1[] = {"hello", "world", "example", "test", NULL};
    char *array2[] = {"hello", "world", "xyz", "test", NULL};

    int count1 = ft_count_if(array1, 4, contains_a);
    int count2 = ft_count_if(array2, 4, contains_a);

    printf("Array1: %d strings contain 'a'\n", count1);
    printf("Array2: %d strings contain 'a'\n", count2);

    return 0;
}*/
