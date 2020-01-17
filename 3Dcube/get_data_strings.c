/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_data_strings.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: wbarendr <wbarendr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/17 11:06:45 by wbarendr       #+#    #+#                */
/*   Updated: 2020/01/17 16:34:55 by wbarendr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "dcube.h"

int		north(t_map *f, int *i)
{
	int k;
	int j;

	k = 0;
	j = 0;
	*i = *i + 2;
	while (f->str[*i] == ' ')
		(*i)++;
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
	f->no[k] = 0;
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
	while (f->str[*i] == ' ')
		(*i)++;
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
	f->so[k] = 0;
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
	while (f->str[*i] == ' ')
		(*i)++;
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
	f->we[k] = 0;
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
	while (f->str[*i] == ' ')
		(*i)++;
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
	f->ea[k] = 0;
	f->check += 600000;
	return (1);
}

int		sprite(t_map *f, int *i)
{
	int k;
	int j;

	j = 0;
	k = 0;
	*i = *i + 1;
	while (f->str[*i] == ' ')
		(*i)++;
	while (f->str[*i + j] != '\n')
		j++;
	f->s = malloc(j + 1);
	if (f->s == NULL)
		return (-1);
	while (f->str[*i] != '\n')
	{
		f->s[k] = f->str[*i];
		(*i)++;
		k++;
	}
	f->s[k] = 0;
	f->check += 7000000;
	return (1);
}
