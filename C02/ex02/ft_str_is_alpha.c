/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibonnevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 10:55:33 by ibonnevi          #+#    #+#             */
/*   Updated: 2024/07/19 11:53:12 by ibonnevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	int		i;

	i = 0;
	if (str[i] == '\0')
	{
		return (1);
	}
	while (str[i] != '\0')
	{	
		if (
			!(str[i] >= 'a' && str[i] <= 'z')
			&& !(str[i] >= 'A' && str[i] <= 'Z')
		)
		{
			return (0);
		}
		i++;
	}
	return (1);
}
/*
int 	main()
{
	char a[] = "queDlettresIci";
	char b[] = "QUEDMAJ";
	char c[] = "quedmin";
	char d[] = "aie9pasbon";	
	char e[] = "";	

	printf("%d", ft_str_is_alpha(a));
	printf("%d", ft_str_is_alpha(b));
	printf("%d", ft_str_is_alpha(c));
	printf("%d", ft_str_is_alpha(d));
	printf("%d", ft_str_is_alpha(e));
	return 0;
}
*/
