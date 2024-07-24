/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibonnevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 20:45:39 by ibonnevi          #+#    #+#             */
/*   Updated: 2024/07/19 21:50:06 by ibonnevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (1);
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}
/*
int		main()
{
	char	*c = "161487878";
	char	*e = "19161 487878";
	char	*f = "1961487wfwf8";
	printf("%d", ft_str_is_numeric(c));
	printf("%d", ft_str_is_numeric(e));
	printf("%d", ft_str_is_numeric(f));
}*/
