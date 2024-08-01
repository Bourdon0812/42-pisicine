/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibonnevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:04:50 by ibonnevi          #+#    #+#             */
/*   Updated: 2024/07/18 16:18:57 by ibonnevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int		len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	write(1, str, len);
}
/*
int main()
{
	char 	*text;
	ft_putstr("coucou comment ca va");
	write(1, "\n", 1);
	text = "test du ft_putchar";
	ft_putstr(text);
}
*/