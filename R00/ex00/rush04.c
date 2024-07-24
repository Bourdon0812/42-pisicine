/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jercaro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:00:01 by jercaro           #+#    #+#             */
/*   Updated: 2024/07/21 21:17:51 by msavinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	ix;
	int	iy;

	if (x <= 0 || y <= 0)
	{
		write(1, "Try again \n", 11);
		return ;
	}
	iy = 0;
	while (++iy <= y)
	{
		ix = 0;
		while (++ix <= x)
		{
			if ((ix == 1 && iy == 1) || (ix == x && iy == y))
				ft_putchar(65);
			else if ((iy == y && ix == 1) || (ix == x && iy == 1))
				ft_putchar(67);
			else if (ix == 1 || ix == x || iy == 1 || iy == y)
				ft_putchar(66);
			else if ((ix > 1 && iy < y) || (ix < x && iy > 1))
				ft_putchar(32);
		}
		ft_putchar(10);
	}
}