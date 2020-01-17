/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_data_input.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: wbarendr <wbarendr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/17 11:05:14 by wbarendr       #+#    #+#                */
/*   Updated: 2020/01/17 18:05:10 by wbarendr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "dcube.h"

int		check_char(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	if (c == '0' || c == '1' || c == '2' || c == ' ')
		return (1);
	if (c == '\n')
		return (1);
	return (0);
}

int		find_values(t_map *f, int *i)
{
	int ret;

	ret = 1;
	if (f->str[*i] == 'R')
		resolution(f, i);
	else if (f->str[*i] == 'N' && f->str[*i + 1] == 'O')
		ret = north(f, i);
	else if (f->str[*i] == 'S' && f->str[*i + 1] == 'O')
		ret = south(f, i);
	else if (f->str[*i] == 'W' && f->str[*i + 1] == 'E')
		ret = west(f, i);
	else if (f->str[*i] == 'E' && f->str[*i + 1] == 'A')
		ret = east(f, i);
	else if (f->str[*i] == 'S')
		ret = sprite(f, i);
	else if (f->str[*i] == 'F')
		ft_floor(f, i);
	else if (f->str[*i] == 'C')
		ceiling(f, i);
	return (ret);
}

void	init_struct_map(t_map *f)
{
	f->fred = -1;
	f->fgreen = -1;
	f->fblue = -1;
	f->cred = -1;
	f->cgreen = -1;
	f->cblue = -1;
	f->check = 0;
	f->floor = 0;
	f->ceiling = 0;
}

void	make_colours(t_map *f)
{
	f->floor = f->floor + f->fblue % 16;
	f->floor = f->floor + f->fblue / 16 * 16;
	f->floor = f->floor + f->fgreen % 16 * pow(16, 2);
	f->floor = f->floor + f->fgreen / 16 * pow(16, 3);
	f->floor = f->floor + f->fred % 16 * pow(16, 4);
	f->floor = f->floor + f->fred / 16 * pow(16, 5);
	f->ceiling = f->ceiling + f->cblue % 16;
	f->ceiling = f->ceiling + f->cblue / 16 * 16;
	f->ceiling = f->ceiling + f->cgreen % 16 * pow(16, 2);
	f->ceiling = f->ceiling + f->cgreen / 16 * pow(16, 3);
	f->ceiling = f->ceiling + f->cred % 16 * pow(16, 4);
	f->ceiling = f->ceiling + f->cred / 16 * pow(16, 5);
}

int		get_other_values(t_map *f, int map)
{
	int i;
	int ret;

	i = 0;
	init_struct_map(f);
	while (i < map)
	{
		if (i == 0)
			ret = find_values(f, &i);
		else if (i != 0)
			if (f->str[i - 1] == '\n')
				ret = find_values(f, &i);
		if (ret == -1)
			return (-1);
		i++;
	}
	if (f->check != 4321987654321)
		return (-1);
	make_colours(f);
	return (1);
}
