/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_data_integers_bonus.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: wbarendr <wbarendr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/17 11:09:45 by wbarendr       #+#    #+#                */
/*   Updated: 2020/03/02 16:52:15 by wbarendr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "dcube_bonus.h"

int		resolution(t_map *f, int *i)
{
	(*i)++;
	while (f->str[*i] == ' ')
		(*i)++;
	f->rx = ft_atoi(&f->str[*i]);
	if (f->rx > 0 && f->rx < 1000000)
		f->check = f->check + 1;
	while (f->str[*i] >= '0' && f->str[*i] <= '9')
		(*i)++;
	while (f->str[*i] == ' ')
		(*i)++;
	f->ry = ft_atoi(&f->str[*i]);
	if (f->ry > 0 && f->ry < 1000000)
		f->check = f->check + 20;
	if (f->ry >= 1000000 || f->rx >= 1000000)
		write(1, "\nlet's keep that resultion under a million eh\n\n", 47);
	while (f->str[*i] >= '0' && f->str[*i] <= '9')
		(*i)++;
	while (f->str[*i] == ' ')
		(*i)++;
	if (f->str[*i] != '\n')
		f->check = 0;
	return (1);
}

void	between(t_map *f, int *i)
{
	while (f->str[*i] == ' ')
		(*i)++;
	if (f->str[*i] != ',')
	{
		ft_putstr(free_map2(f, "don't forget the comma\n"));
		exit(0);
	}
	(*i)++;
	while (f->str[*i] == ' ')
		(*i)++;
}

int		ft_floor(t_map *f, int *i)
{
	(*i)++;
	while (f->str[*i] == ' ')
		(*i)++;
	f->fred = ft_atoi(&f->str[*i]);
	if (f->fred > -1 && f->fred < 256)
		f->check = f->check + 80000000;
	while (f->str[*i] >= '0' && f->str[*i] <= '9')
		(*i)++;
	between(f, i);
	f->fgreen = ft_atoi(&f->str[*i]);
	if (f->fgreen > -1 && f->fgreen < 256)
		f->check = f->check + 900000000;
	while (f->str[*i] >= '0' && f->str[*i] <= '9')
		(*i)++;
	between(f, i);
	f->fblue = ft_atoi(&f->str[*i]);
	if (f->fblue > -1 && f->fblue < 256)
		f->check = f->check + 1000000000;
	while (f->str[*i] >= '0' && f->str[*i] <= '9')
		(*i)++;
	while (f->str[*i] == ' ')
		(*i)++;
	if (f->str[*i] != '\n')
		f->check = 0;
	return (1);
}

int		ceiling(t_map *f, int *i)
{
	(*i)++;
	while (f->str[*i] == ' ')
		(*i)++;
	f->cred = ft_atoi(&f->str[*i]);
	if (f->cred > -1 && f->cred < 256)
		f->check = f->check + 20000000000;
	while (f->str[*i] >= '0' && f->str[*i] <= '9')
		(*i)++;
	between(f, i);
	f->cgreen = ft_atoi(&f->str[*i]);
	if (f->cgreen > -1 && f->cgreen < 256)
		f->check = f->check + 300000000000;
	while (f->str[*i] >= '0' && f->str[*i] <= '9')
		(*i)++;
	between(f, i);
	f->cblue = ft_atoi(&f->str[*i]);
	if (f->cblue > -1 && f->cblue < 256)
		f->check = f->check + 4000000000000;
	while (f->str[*i] >= '0' && f->str[*i] <= '9')
		(*i)++;
	while (f->str[*i] == ' ')
		(*i)++;
	if (f->str[*i] != '\n')
		f->check = 0;
	return (1);
}