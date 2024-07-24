/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibonnevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 18:56:55 by ibonnevi          #+#    #+#             */
/*   Updated: 2024/07/18 20:40:45 by ibonnevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int		temp;
	int		start;
	int		end;

	start = 0;
	end = size - 1;
	while (start < end)
	{
		temp = tab[start];
		tab[start] = tab[end];
		tab[end] = temp;
		start++;
		end--;
	}
}

/*
int	main()
{
	int		test[4] = {'a', 'b', 'c', 'd'};
	int 	i;
	int		t;	

	i = 0;
	while (i != 4)
	{
		t = test[i];
		write(1, &t, 1);
		i++;
	}
	write(1, "\n", 1);
	ft_rev_int_tab(test, i);
	i = 0;
	while (i != 4)
	{
		t = test[i];
		write(1, &t, 1);
		i++;
	}

	return (0);
}
*/
