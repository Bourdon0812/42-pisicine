/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibonnevi <ibonnevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:35:43 by ibonnevi          #+#    #+#             */
/*   Updated: 2024/08/07 21:10:36 by ibonnevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

int	main(int argc, char **argv)
{
	int		i;

	i = 1;
	if (argc > 1)
	{
		while (argv[i])
		{
			find(argv[i]);
			if (i < argc - 1)
				write(1, "\n", 1);
			i++;
		}
		return (0);
	}
	find(NULL);
	return (0);
}

void	free_all(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}
