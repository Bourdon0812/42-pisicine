/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibonnevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 12:57:07 by ibonnevi          #+#    #+#             */
/*   Updated: 2024/07/28 12:57:10 by ibonnevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *src)
{
	int	len;

	len = 0;
	while (src[len] != '\0')
		len++;
	return (len);
}

int	ft_arraystrlen(int size, char **arr, char *sep)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (i != size)
	{
		len += ft_strlen(arr[i]);
		i++;
	}
	return (len + ft_strlen(sep) * (size - 1));
}

char	*ft_strcat(char *dest, char *str)
{
	int	len;
	int	i;	

	i = 0;
	len = ft_strlen(dest);
	while (str[i] != '\0')
	{
		dest[len + i] = str[i];
		i++;
	}
	dest[len + i] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*ns;	

	if (size <= 0)
	{
		ns = malloc(sizeof(char));
		ns[0] = '\0';
		return (ns);
	}
	i = 0;
	ns = malloc(sizeof(char) * (ft_arraystrlen(size, strs, sep) + 1));
	if (ns == NULL)
		return (NULL);
	ns[0] = '\0';
	while (i != size)
	{
		ft_strcat(ns, strs[i]);
		if (i < size - 1)
			ft_strcat(ns, sep);
		i++;
	}
	return (ns);
}
/*
int	main()
{
	char *str[] = {"cou", "cou", "shallah", "je", "reussi", "la", "piscine"};
	char *ns = ft_strjoin(7, str, "\n");
	printf("%s", ns);
}*/