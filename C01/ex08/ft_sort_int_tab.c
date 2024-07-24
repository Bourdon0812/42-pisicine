/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibonnevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 20:50:35 by ibonnevi          #+#    #+#             */
/*   Updated: 2024/07/18 21:10:33 by ibonnevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	mini;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		mini = i;
		j = i + 1;
		while (j < size)
		{
			if (tab[j] < tab[mini])
			{
				mini = j;
			}
			j++;
		}
		temp = tab[mini];
		tab[mini] = tab[i];
		tab[i] = temp;
		i++;
	}
}
/*
int main()
{
    int tab[] = {5, 2, 9, 1, 5, 6};
    
    ft_sort_int_tab(tab, 6);
    
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", tab[i]);
    }
    printf("\n");
    
    return 0;
}*/
