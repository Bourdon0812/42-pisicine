/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:51:15 by lroussel          #+#    #+#             */
/*   Updated: 2024/08/07 13:07:43 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_puterror(char *error)
{
	int	i;

	i = 0;
	while (error[i])
		i++;
	write(2, error, i);
}

char	*ft_strncpy(char *dest, char *src, int n)
{
	int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	*ft_strndup(char *str, int start, int end)
{
	int		i;
	char	*dup;

	dup = (char *)malloc(sizeof(char) * (end - start + 2));
	if (dup == NULL)
		return (NULL);
	i = -1;
	while (start <= end)
		dup[++i] = str[start++];
	dup[i + 1] = '\0';
	return (dup);
}
