/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mini_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: wbarendr <wbarendr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 11:13:59 by wbarendr       #+#    #+#                */
/*   Updated: 2020/02/19 15:08:48 by wbarendr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "dcube.h"

void	make_map_s(t_struct *w, t_map *f)
{
	int r;
	int c;

	r = 0;
	c = 0;
	while (f->map[r] != 0)
	{
		while (f->map[r][c] != 0)
		{
			if (direction(w, f, r, c))
			{
				w->centy = r + 0.5;
				w->centx = c + 0.5;
			}
			c++;
		}
		c = 0;
		r++;
	}
}
