/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_wall_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: wbarendr <wbarendr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/10 12:33:59 by wbarendr       #+#    #+#                */
/*   Updated: 2020/03/05 16:45:45 by wbarendr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "dcube_bonus.h"

void		find_relative_distances(t_struct *w, float mid)
{
	if (mid < PI)
	{
		w->wl->xdist = 1 - (w->centx - (int)w->centx);
		w->wl->xstep = 1;
	}
	else
	{
		w->wl->xdist = w->centx - (int)w->centx;
		w->wl->xstep = -1;
	}
	if (mid >= PITWO && mid <= 3.0 * PITWO)
	{
		w->wl->ydist = w->centy - (int)w->centy;
		w->wl->ystep = -1;
	}
	else
	{
		w->wl->ydist = 1 - (w->centy - (int)w->centy);
		w->wl->ystep = 1;
	}
	w->wl->xhit = w->wl->deltax * w->wl->xdist;
	w->wl->yhit = w->wl->deltay * w->wl->ydist;
}

void		init_angles(t_struct *w, float mid)
{
	w->wl->angle_l = mid + PITWO;
	if (w->wl->angle_l > TWOPI)
		w->wl->angle_l -= TWOPI;
	w->wl->angle_r = mid - PITWO;
	if (w->wl->angle_r < 0)
		w->wl->angle_r += TWOPI;
}

void		hit_sprite(t_struct *w, float mid)
{
	init_angles(w, mid);
	w->on_wall = fabs(cos(mid) * w->wl->xhit) - w->wl->ydist;
	w->on_wall = w->on_wall - (int)w->on_wall;
	if (w->on_wall < 0)
		w->on_wall = w->on_wall + 1.0;
	if (w->wl->xstep == -1)
	{
		if (mid > 3 * PITWO && mid <= TWOPI)
		{
			w->on_wall = 1 - w->on_wall;
			sprite_west_down(w, mid);
		}
		else
			sprite_west_up(w, mid);
	}
	else if (w->wl->xstep == 1)
	{
		if (mid < PITWO)
		{
			w->on_wall = 1 - w->on_wall;
			sprite_east_down(w, mid);
		}
		else
			sprite_east_up(w, mid);
	}
}

void		hit_sprite2(t_struct *w, float mid)
{
	init_angles(w, mid);
	w->on_wall = fabs(sin(mid) * w->wl->yhit) - w->wl->xdist;
	w->on_wall = w->on_wall - (int)w->on_wall;
	if (w->on_wall < 0)
		w->on_wall = w->on_wall + 1.0;
	if (w->wl->ystep == -1)
	{
		if (mid > PI)
		{
			w->on_wall = 1 - w->on_wall;
			sprite_yhit(w, mid, -1, 1);
		}
		else
			sprite_yhit(w, mid, 1, 1);
	}
	else if (w->wl->ystep == 1)
	{
		if (mid < PITWO)
		{
			w->on_wall = 1 - w->on_wall;
			sprite_yhit(w, mid, -1, -1);
		}
		else
			sprite_yhit(w, mid, 1, -1);
	}
}

void		find_wall(t_struct *w, float mid, int rx)
{
	w->wl->i = 0;
	w->wl->side = -1;
	w->wl->first = 0;
	w->wl->x = w->centx;
	w->wl->y = w->centy;
	w->wl->deltay = fabs(1 / cos(mid));
	w->wl->deltax = fabs(1 / sin(mid));
	find_relative_distances(w, mid);
	while (w->wl->side == -1 || w->wl->side == 2 || w->wl->side == 3)
		find_total_distance1(w, mid);
	if (w->wl->side == 0)
		side_zero(w, mid, rx);
	else if (w->wl->side == 1)
		side_one(w, mid, rx);
	while (w->wl->i > 0)
	{
		if (w->wl->on_wall_sprite[w->wl->i - 1] != -1)
		{
			w->wl->x = 1.0 / w->wl->spritehit[w->wl->i - 1];
			make_sprite(w, w->wl->x, w->wl->on_wall_sprite[w->wl->i - 1], rx);
		}
		w->wl->i--;
	}
}
