/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dcube.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: wbarendr <wbarendr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/20 19:53:48 by wbarendr       #+#    #+#                */
/*   Updated: 2020/01/15 21:59:54 by wbarendr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DCUBE_H
# define DCUBE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <mlx.h>
# include <math.h>

typedef struct		s_struct
{
	void        	*mlx;
	void 			*img;
	void 			*win;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int             x;
	int             y;
	unsigned long 	color;
	int				end;
}					t_struct;

typedef struct		s_map
{
	char			**map;
	int				rows;
	int				columns;
	char			*str;
	int				rx;
	int				ry;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*s;
	int				fred;
	int 			fgreen;
	int 			fblue;
	int 			cred;
	int 			cgreen;
	int 			cblue;
	long			check;
}					t_map;

char	*read_file(t_map *f, int fd);
int     ft_strlen(char *str);
char    *ft_calloc(int size, int amount);
char    *ft_strjoin(char *str1, char *str2);
void    check_match(char c1, char c2, int *invalid, int *c);
int 	check_valid_arr(char **arr, int rows);
int		ft_atoi(const char *str);
int 	get_other_values(t_map *f, int map);	


//void	map_maker(arr, columns, rows);

#endif

