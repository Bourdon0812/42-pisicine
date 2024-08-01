/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibonnevi <ibonnevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 20:05:49 by ibonnevi          #+#    #+#             */
/*   Updated: 2024/07/31 21:32:52 by ibonnevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_is_separator(char c, char *separator)
{
	int	i;

	i = -1;
	while (separator[++i] != '\0')
		if (c == separator[i])
			return (1);
	return (0);
}

char	*ft_get_word(char *str, int start, int end)
{
	char	*word;
	int		i;

	word = (char *)malloc(sizeof(char) * (end - start + 1));
	if (word == NULL)
		return (NULL);
	i = -1;
	while (start < end)
		word[++i] = str[start++];
	word[i + 1] = '\0';
	return (word);
}

int	ft_word_count(char *str, char *sep)
{
	int		wc;		
	int		i;
	char	is_word;

	i = -1;
	wc = 0;
	is_word = 0;
	while (str[++i] != '\0')
	{
		if (ft_is_separator(str[i], sep))
			is_word = 0;
		else
		{
			if (!is_word)
			{
				wc++;
				is_word = 1;
			}
		}
	}
	return (wc);
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		k;
	int		start;
	int		end;

	tab = (char **)malloc(sizeof(char *) * (ft_word_count(str, charset) + 1));
	if (tab == NULL)
		return (NULL);
	k = -1;
	start = 0;
	while (str[start] != '\0')
	{
		while (str[start] != '\0' && ft_is_separator(str[start], charset))
			start++;
		end = start;
		while (str[end] != '\0' && !ft_is_separator(str[end], charset))
			end++;
		if (end > start)
		{
			tab[++k] = ft_get_word(str, start, end);
			start = end;
		}
	}
	tab[k + 1] = NULL;
	return (tab);
}
/*
int main()
{
	char **split = ft_split("coucou je suis_genial", " _");
	int i = 0;
	while (split[i] != NULL)
	{
		printf("indice {%d} : ", i);
		printf("%s\n", split[i]);
		i++;;
	}
}*/