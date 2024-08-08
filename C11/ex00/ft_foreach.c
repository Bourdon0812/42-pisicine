/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibonnevi <ibonnevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 13:17:51 by ibonnevi          #+#    #+#             */
/*   Updated: 2024/08/01 13:34:29 by ibonnevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
/*
void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = nb * -1;
		ft_putnbr(nb);
		return ;
	}
	if (nb < 10)
	{
		nb += '0';
		write(1, &nb, 1);
		return ;
	}
	ft_putnbr(nb / 10);
	nb = nb % 10 + '0';
	write(1, &nb, 1);
}*/

void	ft_foreach(int *tab, int lenght, void (*f)(int))
{
	int	i;

	i = -1;
	while (++i != lenght)
		f(tab[i]);
}

/*
int	main()
{
	int tab[6] = {1, 1823, 202, 0, 28, 2928};
	ft_foreach(tab, 3, &ft_putnbr);
}*/