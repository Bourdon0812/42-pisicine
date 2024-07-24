/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibonnevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 12:26:31 by ibonnevi          #+#    #+#             */
/*   Updated: 2024/07/18 12:43:40 by ibonnevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
/*
int main()
{
	int  a;
	int  b;
	int div;
	int mod;
	
	a = 9;
	b = 2;
	ft_div_mod(a, b, &div, &mod);
	div += 48;
	mod += 48;
	write(1, &div, 1);
	write(1, &mod, 1);
	return 0;
}
*/
