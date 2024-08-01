/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibonnevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 10:22:02 by ibonnevi          #+#    #+#             */
/*   Updated: 2024/07/29 10:22:04 by ibonnevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
//#include <stdio.h>

unsigned int	ft_strlen(char *str);
unsigned int	ft_isspace(char c);
unsigned int	ft_putsign(char c, char *sign);
int				ft_basenbr(char c, char *base, unsigned int len, int *result);
char			*ft_convert(int nbr, char *base);

char	*ft_neg(char *str)
{
	int		len;
	char	*neg_str;
	int		i;

	len = 0;
	while (str[len])
		len++;
	neg_str = malloc((len + 2) * sizeof(char));
	if (!neg_str)
		return (NULL);
	neg_str[0] = '-';
	i = 0;
	while (i < len)
	{
		neg_str[i + 1] = str[i];
		i++;
	}
	neg_str[i + 1] = '\0';
	free(str);
	return (neg_str);
}

unsigned char	ft_check_base(char *base)
{
	unsigned int	i;
	unsigned int	j;	

	i = 0;
	if (ft_strlen(base) <= 1)
		return (0);
	while (base[i] != '\0')
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-'
			|| base[i] == '\t' || base[i] == '\n' || base[i] == '\r'
			||base[i] == '\v' || base[i] == '\f'
		)
			return (0);
		while (base[j] != '\0')
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	char			sign;
	unsigned int	i;
	unsigned int	len;
	int				result;

	if (!ft_check_base(base))
		return (0);
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	sign = 1;
	while (ft_putsign(str[i], &sign))
		i++;
	len = ft_strlen(base);
	result = 0;
	while (ft_basenbr(str[i], base, len, &result))
		i++;
	if (sign < 0)
		return (-result);
	return (result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		resa;
	int		sign;
	char	*resdef;

	sign = 1;
	if (!ft_check_base(base_from) || !ft_check_base(base_to))
		return (NULL);
	resa = ft_atoi_base(nbr, base_from);
	if (resa < 0)
	{
		sign *= -1;
		resa *= -1;
	}
	resdef = ft_convert(resa, base_to);
	if (sign < 0)
		resdef = ft_neg(resdef);
	return (resdef);
}
/*
int	main(void)
{
	printf("42:%s\n", ft_convert_base("--2a", "0123456789abcdef", "0123456789"));
	printf("-2a:%s\n", ft_convert_base("-42", "0123456789", "0123456789abcdef"));
}*/