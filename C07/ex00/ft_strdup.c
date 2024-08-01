/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibonnevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:01:47 by ibonnevi          #+#    #+#             */
/*   Updated: 2024/07/25 19:44:00 by ibonnevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <stdio.h>

unsigned int	ft_strlen_a(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i + 1);
}

char	*ft_strdup(char *src)
{
	char	*cp;
	int		i;	

	i = -1;
	if (src == NULL)
		return (NULL);
	cp = malloc(ft_strlen_a(src) * sizeof(char));
	if (cp == NULL)
		return (NULL);
	while (src[++i] != '\0')
		cp[i] = src[i];
	cp[i] = '\0';
	return (cp);
}
/*
int	main()
{
	char s[] = "coucou je suis bient cp";
	char *p = ft_strdup(s);
	printf("%s", p);
	return (0);
}*/
