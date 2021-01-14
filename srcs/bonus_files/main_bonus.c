/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_bonus.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: wbarendr <wbarendr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/21 16:57:05 by wbarendr       #+#    #+#                */
/*   Updated: 2020/03/06 14:49:23 by wbarendr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "dcube_bonus.h"

void	pixelput_three_d(t_struct *w, int x, int y, int color)
{
	char	*dst;

	if (w->counter % 2 == 0)
	{
		dst = w->addr1 + y * w->line_length + x * (w->bits_per_pixel / 8);
		*(unsigned int*)dst = color;
		return ;
	}
	dst = w->addr2 + y * w->line_length + x * (w->bits_per_pixel / 8);
	*(unsigned int*)dst = color;
}

int		ft_strcmp1(char *arg, char *cub)
{
	int i;
	int j;

	j = 0;
	while (arg[j] != 0)
		j++;
	j--;
	i = 3;
	while (i >= 0)
	{
		if (arg[j] != cub[i])
		{
			write(1, "\nDid you mean '*.cub'?\n\n", 24);
			return (1);
		}
		i--;
		j--;
	}
	return (0);
}

int		ft_strcmp(char *arg, char *save, t_map *f)
{
	int i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] != save[i])
		{
			write(1, "\nDid you mean '--save'?\n\n", 25);
			return (1);
		}
		i++;
	}
	if (arg[i] == save[i])
		f->save = 1;
	return (0);
}

int		main(int argc, char **argv)
{
	int		fd;
	t_map	f;
	char	*str;

	if (!(argc == 2 || argc == 3))
	{
		write(1, "\nmissing file or to many arguments\n\n", 37);
		return (0);
	}
	if (ft_strcmp1(argv[1], ".cub"))
		return (0);
	if (argc == 3)
		if (ft_strcmp(argv[2], "--save", &f))
			return (0);
	fd = open(argv[1], O_RDONLY);
	str = read_file(&f, fd);
	ft_putstr(str);
	if (compare(str, "\nAll INPUT DATA IS CORRECT\n") == 0)
		return (0);
	put_map_to_window(&f);
	return (0);
}
