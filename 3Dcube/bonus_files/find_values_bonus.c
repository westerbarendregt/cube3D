/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_values_bonus.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: wbarendr <wbarendr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/24 16:24:50 by wbarendr       #+#    #+#                */
/*   Updated: 2020/02/24 16:33:10 by wbarendr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "dcube_bonus.h"

int		more_values(t_map *f, int *i)
{
	if (f->str[*i] == '\n')
		return (1);
	else if (f->str[*i] == 32)
	{
		while (f->str[*i] == 32)
			(*i)++;
		if (f->str[*i] == '\n')
			return (1);
	}
	return (-1);
}
