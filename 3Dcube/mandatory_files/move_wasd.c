/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move_wasd.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wbarendr <wbarendr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/10 12:29:47 by wbarendr       #+#    #+#                */
/*   Updated: 2020/03/02 11:56:50 by wbarendr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "dcube.h"

void		move(t_struct *w)
{
	float x;
	float y;

	x = w->centx;
	y = w->centy;
	w->centx += sin(w->mid) * w->move1;
	if (w->m->map[(int)w->centy][(int)w->centx] == '1')
		w->centx = x;
	w->centy += cos(w->mid) * w->move1;
	if (w->m->map[(int)w->centy][(int)w->centx] == '1')
		w->centy = y;
}

void		move_crab(t_struct *w)
{
	float x;
	float y;

	x = w->centx;
	y = w->centy;
	w->centx += sin(w->mid + PITWO) * w->move2;
	if (w->m->map[(int)w->centy][(int)w->centx] == '1')
		w->centx = x;
	w->centy += cos(w->mid + PITWO) * w->move2;
	if (w->m->map[(int)w->centy][(int)w->centx] == '1')
		w->centy = y;
}
