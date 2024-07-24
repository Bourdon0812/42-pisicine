/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibonnevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:10:31 by ibonnevi          #+#    #+#             */
/*   Updated: 2024/07/17 11:31:30 by ibonnevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char	c;

	c = 'z';
	while (c != 'a' - 1)
	{
		write(1, &c, 1);
		c--;
	}	
}

/*
int main(void)
{
	ft_print_reverse_alphabet();
	return (0);
}
*/
