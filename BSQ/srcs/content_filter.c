/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   content_filter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:35:43 by lroussel          #+#    #+#             */
/*   Updated: 2024/08/07 12:36:34 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

char	ft_fill(t_fill_param *p, t_map_data *data)
{
	while (p->str[++(p->i)] != '\0')
	{
		if (p->str[p->i] == '\n')
		{
			p->tab[p->l][p->j] = '\0';
			if (p->str[p->i + 1] != '\0')
			{
				p->tab[++(p->l)] = malloc(sizeof(char) * (data->size_line + 1));
				if (p->tab[p->l] == NULL)
				{
					while (p->l >= 0)
						free(p->tab[(p->l)--]);
					free(p->tab);
					return (0);
				}
			}
			p->j = 0;
		}
		else
			p->tab[p->l][(p->j)++] = p->str[p->i];
	}
	return (1);
}

char	**ft_str_to_tab(char *str, t_map_data *data)
{
	t_fill_param	p;
	char			**tab;

	tab = (char **)malloc(sizeof(char *) * (data->lines + 1));
	if (tab == NULL)
		return (NULL);
	tab[0] = (char *)malloc(sizeof(char) * (data->size_line + 1));
	if (tab[0] == NULL)
	{
		free(tab);
		return (NULL);
	}
	p.tab = tab;
	p.str = str;
	p.i = -1;
	p.j = 0;
	p.l = 0;
	if (!ft_fill(&p, data))
		return (NULL);
	tab[data->lines] = NULL;
	data->map = tab;
	return (tab);
}
