/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibonnevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 18:40:31 by ibonnevi          #+#    #+#             */
/*   Updated: 2024/07/23 19:45:54 by ibonnevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	write(1, str, i);
}

int	ft_strcomp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

void	ft_sort(int size, char *tab[])
{
	int		min;
	int		i;
	int		j;	
	char	*temp;

	i = 1;
	while (i != size - 1)
	{
		j = i + 1;
		min = i;
		while (j != size)
		{
			if (ft_strcomp(tab[i], tab[j]) > 0)
				min = j;
			j++;
		}
		temp = tab[min];
		tab[min] = tab[i];
		tab[i] = temp;
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	i;

	i = 1;
	if (argc > 1)
	{
		ft_sort(argc, argv);
		while (i < argc)
		{
			ft_putstr(argv[i]);
			ft_putstr("\n");
			i++;
		}
	}
	return (0);
}
