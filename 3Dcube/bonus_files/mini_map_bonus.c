/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mini_map_bonus.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: wbarendr <wbarendr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 11:13:59 by wbarendr       #+#    #+#                */
/*   Updated: 2020/02/20 14:14:36 by wbarendr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "dcube_bonus.h"

void	make_square_s(int r, int c, t_struct *w, t_map *f)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (x < f->columns_s)
	{
		while (y < f->rows_s)
		{
			pixelput_three_d(w, x + (f->columns_s * c), y +
			(f->rows_s * r), w->color_walls);
			y++;
		}
		y = 0;
		x++;
	}
}

void	center_point_s(t_struct *w)
{
	pixelput_three_d(w, w->centx * w->m->columns_s,
	w->centy * w->m->rows_s, w->color_location);
	pixelput_three_d(w, w->centx * w->m->columns_s + 1,
	w->centy * w->m->rows_s, w->color_location);
	pixelput_three_d(w, w->centx * w->m->columns_s,
	w->centy * w->m->rows_s + 1, w->color_location);
	pixelput_three_d(w, w->centx * w->m->columns_s + 1,
	w->centy * w->m->rows_s + 1, w->color_location);
}

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
			if (f->map[r][c] == '1')
				make_square_s(r, c, w, f);
			if (f->map[r][c] == '2')
				make_sprite_map_s(r, c, w, f);
			c++;
		}
		c = 0;
		r++;
	}
	center_point_s(w);
	show_gun(w);
}

void	make_map_s2(t_struct *w, t_map *f)
{
	int r;
	int c;

	r = 0;
	c = 0;
	while (f->map[r] != 0)
	{
		while (f->map[r][c] != 0)
		{
			if (f->map[r][c] == '1')
				make_square_s(r, c, w, f);
			if (f->map[r][c] == '2')
				make_sprite_map_s(r, c, w, f);
			c++;
		}
		c = 0;
		r++;
	}
	center_point_s(w);
	show_gun(w);
}
