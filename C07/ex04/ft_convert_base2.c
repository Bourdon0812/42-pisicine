/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibonnevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 10:22:12 by ibonnevi          #+#    #+#             */
/*   Updated: 2024/07/29 10:22:24 by ibonnevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned int	ft_strlen(char *str)
{
	unsigned int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

unsigned int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\n'
		|| c == '\r' || c == '\v' || c == '\f')
		return (1);
	return (0);
}

unsigned int	ft_putsign(char c, char *sign)
{
	if (c != '+' && c != '-')
		return (0);
	if (c == '-')
		*sign = *sign * -1;
	return (1);
}

int	ft_basenbr(char c, char *base, unsigned int len, int *result)
{
	unsigned int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
		{
			*result = *result * len + i;
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_convert(int nbr, char *base)
{
	int		size;
	int		len;
	int		tmp;
	char	*res;

	size = ft_strlen(base);
	len = 1;
	tmp = nbr;
	while (tmp >= size)
	{
		tmp /= size;
		len++;
	}
	res = malloc((len + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	res[len] = '\0';
	while (len > 0)
	{
		res[len - 1] = base[nbr % size];
		nbr /= size;
		len--;
	}
	return (res);
}
