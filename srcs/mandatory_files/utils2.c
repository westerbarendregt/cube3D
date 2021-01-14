/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils2.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: wbarendr <wbarendr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/17 15:44:23 by wbarendr       #+#    #+#                */
/*   Updated: 2020/03/03 11:24:11 by wbarendr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "dcube.h"

int		map_length(char *str, int i)
{
	int ret;

	ret = 0;
	while (str[i] != 0 && str[i] != '\n')
	{
		if (str[i] != ' ')
			ret++;
		i++;
	}
	return (ret);
}

void	check_not_square(t_map *f, int *invalid)
{
	int r;
	int end;
	int i;

	i = 0;
	r = 0;
	while (r < f->rows - 1 && (*invalid) == 0)
	{
		end = ft_strlen(f->map[r]) - 1;
		while (end + i <= ft_strlen(f->map[r + 1]) - 1)
		{
			if (f->map[r + 1][end + i] != '1')
				(*invalid)++;
			i++;
		}
		i = 0;
		while (end >= ft_strlen(f->map[r + 1]) - 1)
		{
			if (f->map[r][end] != '1')
				(*invalid)++;
			end--;
		}
		r++;
	}
}

char	*longer_string(char *str, int longest)
{
	char	*ret;
	int		i;

	i = 0;
	ret = malloc(longest + 1);
	while (str[i] != 0)
	{
		ret[i] = str[i];
		i++;
	}
	while (i < longest)
	{
		ret[i] = '1';
		i++;
	}
	ret[i] = 0;
	free(str);
	return (ret);
}

void	fill_map_with_walls(t_map *f)
{
	int longest;
	int r;

	r = 0;
	longest = ft_strlen(f->map[r]);
	r++;
	while (f->map[r] != 0)
	{
		if (longest < ft_strlen(f->map[r]))
			longest = ft_strlen(f->map[r]);
		r++;
	}
	r = 0;
	while (f->map[r] != 0)
	{
		if (ft_strlen(f->map[r]) < longest)
			f->map[r] = longer_string(f->map[r], longest);
		r++;
	}
	f->columns = longest;
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}
