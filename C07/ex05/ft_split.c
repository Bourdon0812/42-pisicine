/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibonnevi <ibonnevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:56:30 by ibonnevi          #+#    #+#             */
/*   Updated: 2024/07/30 10:54:03 by ibonnevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_is_separator(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strn_insert(char *src, int start, int end)
{
	char	*sub_str;
	int		i;

	sub_str = (char *)malloc((end - start + 1) * sizeof(char));
	if (sub_str == NULL)
		return (NULL);
	i = -1;
	while (start < end)
		sub_str[++i] = src[start++];
	sub_str[i + 1] = '\0';
	return (sub_str);
}

char	**ft_split(char *str, char *charset)
{
	char	**split;
	int		i;
	int		j;
	int		k;

	split = (char **)malloc((ft_strlen(str) + 1) * sizeof(char *));
	if (split == NULL)
		return (NULL);
	i = 0;
	k = -1;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && ft_is_separator(str[i], charset))
			i++;
		j = i;
		while (str[j] != '\0' && !ft_is_separator(str[j], charset))
			j++;
		if (j > i)
		{
			split[++k] = ft_strn_insert(str, i, j);
			i = j;
		}
	}
	split[k + 1] = NULL;
	return (split);
}
/*
int main()
{
	char **split = ft_split("coucou je suis genial", " ");
	int i = 0;
	while (split[i] != NULL)
	{
		printf("indice {%d} : ", i);
		printf("%s\n", split[i]);
		i++;;
	}
}*/