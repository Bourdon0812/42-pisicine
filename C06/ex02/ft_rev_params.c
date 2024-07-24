/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibonnevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 18:29:42 by ibonnevi          #+#    #+#             */
/*   Updated: 2024/07/23 18:39:38 by ibonnevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	unsigned int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	write(1, str, len);
}

int	main(int argc, char *argv[])
{
	int	i;

	i = argc -1;
	if (argc > 0)
	{
		while (i != 0)
		{
			ft_putstr(argv[i]);
			ft_putstr("\n");
			i--;
		}
	}
	return (0);
}
