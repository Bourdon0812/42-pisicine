/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibonnevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:53:17 by ibonnevi          #+#    #+#             */
/*   Updated: 2024/07/18 14:02:00 by ibonnevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int		r;
	int		re;

	r = *a / *b;
	re = *a % *b;
	*a = r;
	*b = re;
}
/*
int	main()
{
	int		a;
	int		b;
	
	a = 9;
	b = 2;
	
	ft_ultimate_div_mod(&a, &b);
	a += 48;
	b += 48;
	write(1, &a, 1);
	write(1, &b, 1);
}
*/
