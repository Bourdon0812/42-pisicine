/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibonnevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:38:57 by ibonnevi          #+#    #+#             */
/*   Updated: 2024/07/17 13:16:58 by ibonnevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n)
{
	char	r;

	if (n < 0)
	{
		r = 'N';
		write(1, &r, 1);
		return ;
	}
	r = 'P';
	write(1, &r, 1);
}
/*
int	main(void)
{
	ft_is_negative(-4);
	return (0);
}
*/
