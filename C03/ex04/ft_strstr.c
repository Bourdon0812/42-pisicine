/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibonnevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 15:47:13 by ibonnevi          #+#    #+#             */
/*   Updated: 2024/07/22 12:22:41 by ibonnevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>
//#include <string.h>

char	*ft_strstr(char *str, char *to_find)
{
	int				i;
	int				i2;
	int				i3;

	i = 0;
	if (*to_find == '\0')
		return (str);
	while (str[i])
	{
		if (str[i] == to_find[0])
		{
			i2 = 0;
			i3 = i;
			while (to_find[i2] != '\0' && str[i3] == to_find[i2])
			{
				i2++;
				i3++;
			}
			if (to_find[i2] == '\0')
				return (&str[i]);
		}
		i++;
	}
	return (NULL);
}
