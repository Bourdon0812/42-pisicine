/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibonnevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:14:13 by ibonnevi          #+#    #+#             */
/*   Updated: 2024/07/17 20:30:54 by ibonnevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(unsigned char c)
{
	write(1, &c, 1);
}

void	ft_print_nb(unsigned char n)
{
	ft_putchar(n / 10 + '0');
	ft_putchar(n % 10 + '0');
}

void	ft_print_comb2(void)
{
	unsigned char	n1;
	unsigned char	n2;

	n1 = 0;
	n2 = 1;
	while (n1 != 99)
	{
		while (n2 != 100)
		{
			ft_print_nb(n1);
			ft_putchar(' ');
			ft_print_nb(n2);
			if (n1 != 98)
			{
				write(1, ", ", 2);
			}
			n2++;
		}
		n1++;
		n2 = n1 + 1;
	}
}
/*
int     main(void)
{
        ft_print_comb2();
        return (0);
}
*/
