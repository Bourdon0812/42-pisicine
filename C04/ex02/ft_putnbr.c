/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibonnevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 20:13:17 by ibonnevi          #+#    #+#             */
/*   Updated: 2024/07/21 20:13:21 by ibonnevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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
}
/*
int		main(void) 
{	
	ft_putnbr(45);
	write(1, "\n", 1);
	ft_putnbr(-12);
	return (0);
}
*/
