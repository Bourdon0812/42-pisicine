/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibonnevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 17:28:08 by ibonnevi          #+#    #+#             */
/*   Updated: 2024/07/21 17:50:47 by ibonnevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>
//#include <string.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	ld;
	unsigned int	ls;
	unsigned int	i;
	unsigned int	i2;	

	ld = 0;
	ls = 0;
	while (dest[ld] != '\0')
		ld++;
	while (src[ls] != '\0')
		ls++;
	if (size <= ld)
		return (ls + size);
	i = 0;
	i2 = ld;
	while (i < size - ld - 1 && src[i] != '\0')
	{
		dest[i2] = src[i];
		i++;
		i2++;
	}
	dest[i2] = '\0';
	return (ld + ls);
}
/*
int	main()
{
	char	dest[10] = "cou";
	char	src[] = "cou toi";
	printf("%d", ft_strlcat(dest, src, 10));
	//printf("%d", strlcat(dest, src, 5));
	printf("%s", dest);
} */
