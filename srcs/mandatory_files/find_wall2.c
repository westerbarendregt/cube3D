/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_wall2.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: wbarendr <wbarendr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/18 11:48:55 by wbarendr       #+#    #+#                */
/*   Updated: 2020/03/05 19:12:02 by wbarendr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "dcube.h"

void			find_total_distance1(t_struct *w, float mid)
{
	if (w->wl->side == 2 && w->wl->first == 0)
	{
		w->wl->spritehit[w->wl->i] = w->wl->spritehit[w->wl->i] + w->wl->xhit;
		w->wl->first = 2;
		w->wl->savex = w->wl->x;
		w->wl->savey = w->wl->y;
		w->wl->xhit += w->wl->deltax;
	}
	else if (w->wl->side == 3 && w->wl->first == 0)
	{
		w->wl->spritehit[w->wl->i] = w->wl->spritehit[w->wl->i] + w->wl->yhit;
		w->wl->first = 3;
		w->wl->savex = w->wl->x;
		w->wl->savey = w->wl->y;
		w->wl->yhit += w->wl->deltay;
	}
	if (w->wl->first != 0 && (w->wl->savex != w->wl->x ||
	w->wl->savey != w->wl->y) && w->wl->i < 10)
	{
		w->wl->first = 0;
		w->wl->side = -1;
		w->wl->i++;
	}
	find_total_distance2(w, mid);
}

void			side_zero(t_struct *w, float mid, int rx)
{
	w->on_wall = fabs(cos(mid) * w->wl->xhit) - w->wl->ydist;
	w->on_wall = w->on_wall - (int)w->on_wall;
	if (w->on_wall < 0)
		w->on_wall = w->on_wall + 1.0;
	if ((mid > PITWO && w->wl->xstep == 1) ||
	(mid > 3 * PITWO && w->wl->xstep == -1))
		w->on_wall = 1 - w->on_wall;
	w->wl->xhit = cos(fabs(w->mid - mid)) * w->wl->xhit;
	w->wl->xhit = 1.0 / w->wl->xhit;
	if (w->wl->xstep == 1)
		make_world_ea(w, w->wl->xhit, rx);
	else
		make_world_we(w, w->wl->xhit, rx);
}

void			side_one(t_struct *w, float mid, int rx)
{
	w->on_wall = fabs(sin(mid) * w->wl->yhit) - w->wl->xdist;
	w->on_wall = w->on_wall - (int)w->on_wall;
	if (w->on_wall < 0)
		w->on_wall = w->on_wall + 1.0;
	if (mid > PI)
		w->on_wall = 1 - w->on_wall;
	w->wl->yhit = cos(fabs(w->mid - mid)) * w->wl->yhit;
	w->wl->yhit = 1.0 / w->wl->yhit;
	if (w->wl->ystep == 1)
		make_world_so(w, w->wl->yhit, rx);
	else
		make_world_no(w, w->wl->yhit, rx);
}

void			find_total_distance3(t_struct *w, float mid)
{
	w->wl->y += w->wl->ystep;
	if (w->m->map[(int)w->wl->y][(int)w->wl->x] == '1')
		w->wl->side = 1;
	else if (w->m->map[(int)w->wl->y][(int)w->wl->x] == '2'
	&& w->wl->first == 0)
	{
		hit_sprite2(w, mid);
		w->wl->side = 3;
	}
	else
		w->wl->yhit += w->wl->deltay;
}

void			find_total_distance2(t_struct *w, float mid)
{
	if (w->wl->xhit < w->wl->yhit)
	{
		w->wl->x += w->wl->xstep;
		if (w->m->map[(int)w->wl->y][(int)w->wl->x] == '1')
			w->wl->side = 0;
		else if (w->m->map[(int)w->wl->y][(int)w->wl->x] == '2'
		&& w->wl->first == 0)
		{
			hit_sprite(w, mid);
			w->wl->side = 2;
		}
		else
			w->wl->xhit += w->wl->deltax;
	}
	else
		find_total_distance3(w, mid);
}
