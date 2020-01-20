/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dcube.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: wbarendr <wbarendr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/20 19:53:48 by wbarendr       #+#    #+#                */
/*   Updated: 2020/01/20 14:24:54 by wbarendr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DCUBE_H
# define DCUBE_H

# define radiant 0.0174532925

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <mlx.h>
# include <math.h>

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
	int				fgreen;
	int				fblue;
	unsigned long	floor;
	int				cred;
	int				cgreen;
	int				cblue;
	unsigned long	ceiling;
	long			check;
}					t_map;

typedef struct		s_struct
{
	void			*mlx;
	void			*img;
	void			*win;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				x;
	int				y;
	unsigned long	color;
	int				end;
	int				centx;
	int				centy;
	t_map			*m;
}					t_struct;

/* libft functions adapted */
int					ft_strlen(char *str);
char				*ft_calloc(int size, int amount);
char				*ft_strjoin(t_map *f, char **str2);
int					ft_atoi(const char *str);
int					compare(char *str, char*str2);
/* Getting values from map */
char				*read_file(t_map *f, int fd);
void				check_match(char c1, char c2, int *invalid, int *c);
int					check_valid_arr(t_map *f);
int					get_other_values(t_map *f, int map);
int					check_char(char c);
/* get input strings */
int					north(t_map *f, int *i);
int					south(t_map *f, int *i);
int					west(t_map *f, int *i);
int					east(t_map *f, int *i);
int					sprite(t_map *f, int *i);
/* get input integers */
void				ceiling(t_map *f, int *i);
void				ft_floor(t_map *f, int *i);
void				resolution(t_map *f, int *i);
/* let's be free */
char				*free_willy(t_map *f, char *text);
char				*free_fred(t_map *f, char **str2, char *text);
char				*free_map(t_map *f, int r, char *text);

void				put_map_to_window(t_map *f);
void        		make_flashlight(t_struct *w, t_map *f);

#endif
