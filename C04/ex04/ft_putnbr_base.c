/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibonnevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:21:45 by ibonnevi          #+#    #+#             */
/*   Updated: 2024/07/22 19:56:05 by ibonnevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	ft_strlen(char *str)
{
	unsigned int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

unsigned char	ft_check_base(char *base)
{
	unsigned int	i;
	unsigned int	j;	

	i = 0;
	if (ft_strlen(base) <= 1)
		return (0);
	while (base[i] != '\0')
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-'
			|| base[i] == '\t' || base[i] == '\n' || base[i] == '\r'
			||base[i] == '\v' || base[i] == '\f'
		)
			return (0);
		while (base[j] != '\0')
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_print_convert(unsigned int nbr, char *base)
{
	unsigned int	size;
	unsigned int	div;
	unsigned int	mod;

	size = ft_strlen(base);
	if (nbr > size - 1)
	{
		div = nbr / size;
		mod = nbr % size;
		ft_print_convert(div, base);
	}
	if (nbr > size - 1)
		write(1, &base[mod], 1);
	else
		write(1, &base[nbr], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{	
	if (ft_check_base(base) == 0)
		return ;
	if (nbr < 0)
	{
		nbr = nbr * -1;
		write(1, "-", 1);
	}
	ft_print_convert(nbr, base);
}
/*
int		main(void)
{
	write(1, "42:", 3);
	ft_putnbr_base(42, "01");
	write(1, "\n2a:", 4);
	ft_putnbr_base(42, "0123456789abcdef");
	write(1, "\n-2a:", 5);
	ft_putnbr_base(-42, "0123456789abcdef");
	write(1, "\n:", 2);
	ft_putnbr_base(42, "");
	write(1, "\n:", 2);
	ft_putnbr_base(42, "0");
	write(1, "\n:", 2);
	ft_putnbr_base(42, "+-0123456789abcdef");
	write(1, "\n:", 2);
	ft_putnbr_base(42, "\t0123456789abcdef");
}*/
