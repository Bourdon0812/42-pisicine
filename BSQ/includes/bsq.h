/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibonnevi <ibonnevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:35:40 by lroussel          #+#    #+#             */
/*   Updated: 2024/08/07 21:34:55 by ibonnevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# define MAX_FILE_SIZE 100000000

typedef struct s_fill_param
{
	char	**tab;
	char	*str;
	int		i;
	int		l;
	int		j;
}		t_fill_param;

typedef struct s_map_data
{
	char	**map;
	int		lines;
	int		size_line;
	char	void_char;
	char	obstacle_char;
	char	square_char;
}		t_map_data;

typedef struct s_square_data
{
	int	x;
	int	y;
	int	size;

}		t_square_data;

//char_utils.c
int				ft_strlen(char *str);
void			ft_puterror(char *error);
char			*ft_strncpy(char *dest, char *src, int n);
char			*ft_strndup(char *str, int start, int end);

//check_utils.c
int				sl(char *str);
t_map_data		*ft_set_map_data(char **strpt, t_map_data *data);
char			*ft_map_is_valid(char *str, t_map_data *data);
int				ft_nb_lines(char *str, t_map_data *data);

//content_filter.c
char			ft_fill(t_fill_param *p, t_map_data *data);
char			**ft_str_to_tab(char *str, t_map_data *data);

//files.c
char			*create_content(int fd, char *buffer, int *i);
char			*file_get_contents(char *path);

//finder
int				check_case(int bx, int by, int offset, t_map_data m_data);
int				find_square(int bx, int by, int offset, t_map_data m_data);
t_square_data	put_square(t_square_data s_data, t_map_data m_data);

//main
void			free_all(char **tab);

//nbr_utils.c
char			ft_is_numeric(char *str);
int				ft_atoi(char *str);

//solver.c
int				find(char *path);
int				set_s_data(int x, int y, int size, t_square_data *s_data);
void			init_solve_vars(int *x, int *y, t_square_data *s_data);
t_square_data	solve(t_map_data m_data);
void			print_solution(t_map_data m_data);

#endif
