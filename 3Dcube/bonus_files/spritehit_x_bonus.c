/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   spritehit_x_bonus.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: wbarendr <wbarendr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/16 14:39:12 by wbarendr       #+#    #+#                */
/*   Updated: 2020/03/02 14:15:01 by wbarendr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "dcube_bonus.h"

void		sprite_yhit(t_struct *w, float mid, int sign, int sign2)
{
	float ray;
	float raystep;
	float y;
	float ystep;
	float count;

	w->wl->on_wall_sprite[w->wl->i] = -1;
	ray = w->on_wall;
	y = 0.5 + ((0.5 * fabs(tan(w->wl->angle_l))) * sign);
	raystep = w->m->step * tan(mid) * -1;
	ystep = w->m->step * tan(w->wl->angle_l) * -1;
	count = (ray - y) / (ystep - raystep);
	ray = ray + (raystep * count);
	w->wl->spritehit[w->wl->i] = fabs((count * w->m->step) / cos(mid));
	if (ray > 0.0 && ray < 0.5)
		w->wl->on_wall_sprite[w->wl->i] = 0.5 + ((fabs(ray - 0.5)) /
		(sin(w->wl->angle_l)) * sign2);
	else if (ray > 0.5 && ray < 1.0)
		w->wl->on_wall_sprite[w->wl->i] = (ray - 0.5) /
		fabs(sin(w->wl->angle_r)) + 0.5;
	if (!(w->wl->on_wall_sprite[w->wl->i] > 0.0 &&
	w->wl->on_wall_sprite[w->wl->i] < 1.0))
		w->wl->on_wall_sprite[w->wl->i] = -1;
}

void		sprite_west_up(t_struct *w, float mid)
{
	float ray;
	float raystep;
	float y;
	float ystep;
	float count;

	w->wl->on_wall_sprite[w->wl->i] = -1;
	ray = w->on_wall;
	y = 0.5 + 0.5 / fabs(tan(w->wl->angle_l));
	raystep = w->m->step / tan(mid);
	ystep = w->m->step / tan(w->wl->angle_l);
	count = (ray - y) / (ystep - raystep);
	ray = ray + (raystep * count);
	w->wl->spritehit[w->wl->i] = fabs((w->on_wall - ray) / cos(mid));
	if (ray > 0.0 && ray < 0.5)
		w->wl->on_wall_sprite[w->wl->i] = 0.5 - (fabs(ray - 0.5)) /
		(cos(w->wl->angle_l));
	else if (ray > 0.5 && ray < 1.0)
		w->wl->on_wall_sprite[w->wl->i] = (ray - 0.5) /
		fabs(cos(w->wl->angle_r)) + 0.5;
	if (!(w->wl->on_wall_sprite[w->wl->i] > 0.0 &&
	w->wl->on_wall_sprite[w->wl->i] < 1.0))
		w->wl->on_wall_sprite[w->wl->i] = -1;
}

void		sprite_west_down(t_struct *w, float mid)
{
	float ray;
	float raystep;
	float y;
	float ystep;
	float count;

	w->wl->on_wall_sprite[w->wl->i] = -1;
	ray = w->on_wall;
	y = 0.5 - 0.5 / tan(w->wl->angle_r);
	raystep = w->m->step / tan(mid);
	ystep = w->m->step / tan(w->wl->angle_r);
	count = (ray - y) / (ystep - raystep);
	ray = ray + (raystep * count);
	w->wl->spritehit[w->wl->i] = fabs((w->on_wall - ray) / cos(mid));
	if (ray > 0.0 && ray < 0.5)
		w->wl->on_wall_sprite[w->wl->i] = 0.5 - (fabs(ray - 0.5)) /
		(cos(w->wl->angle_l));
	else if (ray > 0.5 && ray < 1.0)
		w->wl->on_wall_sprite[w->wl->i] = (ray - 0.5) /
		fabs(cos(w->wl->angle_r)) + 0.5;
	if (!(w->wl->on_wall_sprite[w->wl->i] > 0.0 &&
	w->wl->on_wall_sprite[w->wl->i] < 1.0))
		w->wl->on_wall_sprite[w->wl->i] = -1;
}

void		sprite_east_up(t_struct *w, float mid)
{
	float ray;
	float raystep;
	float y;
	float ystep;
	float count;

	w->wl->on_wall_sprite[w->wl->i] = -1;
	ray = w->on_wall;
	y = 0.5 + 0.5 / fabs(tan(w->wl->angle_l));
	raystep = w->m->step / tan(mid);
	ystep = w->m->step / tan(w->wl->angle_l);
	count = (ray - y) / (ystep - raystep);
	ray = ray + (raystep * count);
	w->wl->spritehit[w->wl->i] = fabs((w->on_wall - ray) / cos(mid));
	if (ray > 0.0 && ray < 0.5)
		w->wl->on_wall_sprite[w->wl->i] = 0.5 - (fabs(ray - 0.5)) /
		(cos(w->wl->angle_l));
	else if (ray > 0.5 && ray < 1.0)
		w->wl->on_wall_sprite[w->wl->i] = 1.0 - ((ray - 0.5) /
		fabs(cos(w->wl->angle_r)) + 0.5);
	if (!(w->wl->on_wall_sprite[w->wl->i] > 0.0 &&
	w->wl->on_wall_sprite[w->wl->i] < 1.0))
		w->wl->on_wall_sprite[w->wl->i] = -1;
}

void		sprite_east_down(t_struct *w, float mid)
{
	float ray;
	float raystep;
	float y;
	float ystep;
	float count;

	w->wl->on_wall_sprite[w->wl->i] = -1;
	ray = w->on_wall;
	y = 0.5 - 0.5 / fabs(tan(w->wl->angle_l));
	raystep = w->m->step / tan(mid);
	ystep = w->m->step / tan(w->wl->angle_r);
	count = (ray - y) / (ystep - raystep);
	ray = ray + (raystep * count);
	w->wl->spritehit[w->wl->i] = fabs((w->on_wall - ray) / cos(mid));
	if (ray > 0.0 && ray < 0.5)
		w->wl->on_wall_sprite[w->wl->i] = 0.5 - (fabs(ray - 0.5)) /
		(cos(w->wl->angle_l));
	else if (ray > 0.5 && ray < 1.0)
		w->wl->on_wall_sprite[w->wl->i] = 1.0 - ((ray - 0.5) /
		fabs(cos(w->wl->angle_r)) + 0.5);
	if (!(w->wl->on_wall_sprite[w->wl->i] > 0.0 &&
	w->wl->on_wall_sprite[w->wl->i] < 1.0))
		w->wl->on_wall_sprite[w->wl->i] = -1;
}
