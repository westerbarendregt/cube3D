/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_data_integers.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: wbarendr <wbarendr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/17 11:09:45 by wbarendr       #+#    #+#                */
/*   Updated: 2020/01/17 11:09:57 by wbarendr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "dcube.h"

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
