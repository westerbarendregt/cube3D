/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_if_valid.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: wbarendr <wbarendr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/21 16:57:32 by wbarendr       #+#    #+#                */
/*   Updated: 2020/01/15 22:10:37 by wbarendr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "dcube.h"

void    check_str_for_other(char **arr, int *invalid, int *invalid2, int rows)
{
	int c;
	int r;

	r = 1;
   	c = 1;
	while (r < (rows - 1) && (*invalid) == 0 && (*invalid2) < 2)
	{
		if (arr[r][0] != '1' || arr[r][(ft_strlen(arr[r]) - 1)] != '1')
			(*invalid) = 1;
		while (c < (ft_strlen(arr[r]) - 1) && (*invalid2) < 2 && (*invalid) == 0)
		{
			if (arr[r][c] != ' ')
				(*invalid) = 1;
			c++;
			if (arr[r][c] == 'S' || arr[r][c] == 'N'|| arr[r][c] == 'W'|| arr[r][c] == 'E')
				(*invalid2)++;
			c++;
		}
		c = 1;
		r++;
	}
}

void    check_str_for_one(char *arr, int *invalid)
{
	int c;

	c = 0;
	check_match(arr[c], '1', invalid, &c);
	while (arr[c] && *invalid == 0)
	{
		check_match(arr[c], ' ', invalid, &c);
		if (arr[c] == 0 || *invalid == 1)
			break ;
		check_match(arr[c], '1', invalid, &c);
	}
}

int 	check_valid_arr(char **arr, int rows)
{
	int 	invalid;
	int		invalid2;

	invalid = 0;
	invalid2 = 0;
	check_str_for_one(arr[0], &invalid);
	check_str_for_other(arr, &invalid, &invalid2, rows);
	check_str_for_one(arr[rows - 1], &invalid);
	if (invalid == 1 || invalid2 != 1)
	{
		write(1, "\nError\nMAP = INVALID\n", 21);
		return (0);
	}
	write(1, "\nMAP = VALID\n", 13);
	return (1);
}

void	resolution(t_map *f, int *i)
{
	(*i)++;
	while (f->str[*i] == ' ')
		(*i)++;
	f->rx = ft_atoi(&f->str[*i]);
	if (f->rx > 0)
		f->check = f->check + 1;
	while (f->str[*i] >= '0' && f->str[*i] <= '9')
		(*i)++;
	while (f->str[*i] == ' ')
		(*i)++;
	f->ry = ft_atoi(&f->str[*i]);
	if (f->ry > 0)
		f->check = f->check + 20;
}

int		north(t_map *f, int *i)
{
	int k;
	int j;

	k = 0;
	j = 0;
	*i = *i + 2;
	while (f->str[*i + j] != '\n')
		j++;
	f->no = malloc(j + 1);
	if (f->no == NULL)
		return (-1);
	while (f->str[*i] != '\n')
	{
		f->no[k] = f->str[*i];
		(*i)++;
		k++;
	}
	f->check += 300;
	return (1);
}

int		south(t_map *f, int *i)
{
	int k;
	int j;

	j = 0;
	k = 0;
	*i = *i + 2;
	while (f->str[*i + j] != '\n')
		j++;
	f->so = malloc(j + 1);
	if (f->so == NULL)
		return (-1);
	while (f->str[*i] != '\n')
	{
		f->so[k] = f->str[*i];
		(*i)++;
		k++;
	}
	f->check += 4000;
	return (1);
}

int		west(t_map *f, int *i)
{
	int k;
	int j;

	j = 0;
	k = 0;
	*i = *i + 2;
	while (f->str[*i + j] != '\n')
		j++;
	f->we = malloc(j + 1);
	if (f->we == NULL)
		return (-1);
	while (f->str[*i] != '\n')
	{
		f->we[k] = f->str[*i];
		(*i)++;
		k++;
	}
	f->check += 50000;
	return (1);
}

int		east(t_map *f, int *i)
{
	int k;
	int j;

	j = 0;
	k = 0;
	*i = *i + 2;
	while (f->str[*i + j] != '\n')
		j++;
	f->ea = malloc(j + 1);
	if (f->ea == NULL)
		return (-1);
	while (f->str[*i] != '\n')
	{
		f->ea[k] = f->str[*i];
		(*i)++;
		k++;
	}
	f->check += 600000;
	return (1);
}

int		sprite(t_map *f, int *i)
{
	int k;
	int j;

	j = 0;
	k = 0;
	*i = *i + 2;
	while (f->str[*i + j] != '\n')
		j++;
	f->s = malloc(j + 1);
	if (f->s == NULL)
		return (-1);
	{
		f->s[k] = f->str[*i];
		(*i)++;
		k++;
	}
	f->check += 7000000;
	return (1);
}

void	ft_floor(t_map *f, int *i)
{
	(*i)++;
	while (f->str[*i] == ' ')
		(*i)++;
	f->fred = ft_atoi(&f->str[*i]);
	if (f->fred > -1)
		f->check = f->check + 80000000;
	while (f->str[*i] >= '0' && f->str[*i] <= '9')
		(*i)++;
	while (f->str[*i] == ' ' || f->str[*i] == ',')
		(*i)++;
	f->fgreen = ft_atoi(&f->str[*i]);
	if (f->fgreen > -1)
		f->check = f->check + 900000000;
	while (f->str[*i] >= '0' && f->str[*i] <= '9')
		(*i)++;
	while (f->str[*i] == ' ' || f->str[*i] == ',')
		(*i)++;
	f->fblue = ft_atoi(&f->str[*i]);
	if (f->fblue > -1)
		f->check = f->check + 1000000000;
}

void	ceiling(t_map *f, int *i)
{
	(*i)++;
	while (f->str[*i] == ' ')
		(*i)++;
	f->cred = ft_atoi(&f->str[*i]);
	if (f->cred > -1)
		f->check = f->check + 20000000000;
	while (f->str[*i] >= '0' && f->str[*i] <= '9')
		(*i)++;
	while (f->str[*i] == ' ' || f->str[*i] == ',')
		(*i)++;
	f->cgreen = ft_atoi(&f->str[*i]);
	if (f->cgreen > -1)
		f->check = f->check + 300000000000;
	while (f->str[*i] >= '0' && f->str[*i] <= '9')
		(*i)++;
	while (f->str[*i] == ' ' || f->str[*i] == ',')
		(*i)++;
	f->cblue = ft_atoi(&f->str[*i]);
	if (f->cblue > -1)
		f->check = f->check + 4000000000000;
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
	if (f->check !=  4321987654321)
		return (-1);
	return (1);
}