/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_if_valid.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: wbarendr <wbarendr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/21 16:57:32 by wbarendr       #+#    #+#                */
/*   Updated: 2020/01/17 18:05:03 by wbarendr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "dcube.h"

void	check_match(char c1, char c2, int *invalid, int *c)
{
	if (c1 != c2)
		(*invalid) = 1;
	(*c)++;
	return ;
}

void	check_direction(char *str, int *c, int *invalid, int *invalid2)
{
	if (str[*c] != ' ')
		(*invalid) = 1;
	(*c)++;
	if (str[*c] == 'S' || str[*c] == 'N' || str[*c] == 'W' || str[*c] == 'E')
		(*invalid2)++;
	(*c)++;
}

void	check_str_for_other(t_map *f, int *invalid, int *invalid2)
{
	int c;
	int r;
	int len;

	r = 1;
	c = 1;
	len = ft_strlen(f->map[r]) - 1;
	while (r < (f->rows - 1) && (*invalid) == 0 && (*invalid2) < 2)
	{
		if (f->map[r][0] != '1' || f->map[r][len] != '1')
			(*invalid) = 1;
		while (c < len && (*invalid2) < 2 && (*invalid) == 0)
			check_direction(f->map[r], &c, invalid, invalid2);
		c = 1;
		r++;
		if (len + 1 != f->columns)
			(*invalid) = 1;
		len = ft_strlen(f->map[r]) - 1;
	}
}

void	check_str_for_one(char *arr, int *invalid, int columns)
{
	int c;

	c = 0;
	if (ft_strlen(arr) != columns)
		(*invalid) = 1;
	check_match(arr[c], '1', invalid, &c);
	while (arr[c] && *invalid == 0)
	{
		check_match(arr[c], ' ', invalid, &c);
		if (arr[c] == 0 || *invalid == 1)
			break ;
		check_match(arr[c], '1', invalid, &c);
	}
}

int		check_valid_arr(t_map *f)
{
	int		invalid;
	int		invalid2;

	invalid = 0;
	invalid2 = 0;
	check_str_for_one(f->map[0], &invalid, f->columns);
	check_str_for_other(f, &invalid, &invalid2);
	check_str_for_one(f->map[f->rows - 1], &invalid, f->columns);
	if (invalid == 1 || invalid2 != 1)
	{
		write(1, "\nError\nMAP = INVALID\n", 21);
		return (0);
	}
	write(1, "\nMAP = VALID\n", 13);
	return (1);
}
