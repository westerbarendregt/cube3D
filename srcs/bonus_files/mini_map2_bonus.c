/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mini_map2_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: wbarendr <wbarendr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/18 17:49:46 by wbarendr       #+#    #+#                */
/*   Updated: 2020/03/02 16:33:54 by wbarendr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "dcube_bonus.h"

int			my_mlx_pixel_put_s(t_struct *w, int x, int y, int color)
{
	char *dst;

	if (w->m->map[y / (int)w->m->rows_s][x / (int)w->m->columns_s] == '1')
		return (0);
	if (w->counter % 2 == 0)
	{
		dst = w->addr1 + y * w->line_length + x * (w->bits_per_pixel / 8);
		*(unsigned int*)dst = color;
		return (1);
	}
	dst = w->addr2 + y * w->line_length + x * (w->bits_per_pixel / 8);
	*(unsigned int*)dst = color;
	return (1);
}

void		make_red_square(t_struct *w, t_map *f, int r, int c)
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
			(f->rows_s * r), 0x00FF0000);
			y++;
		}
		y = 0;
		x++;
	}
}

void		make_sprite_map_s(int r, int c, t_struct *w, t_map *f)
{
	int x;

	make_red_square(w, f, r, c);
	x = 0;
	while (x < f->columns_s)
	{
		pixelput_three_d(w, x + (f->columns_s * c),
		x + (f->rows_s * r), w->black);
		x++;
	}
	x = 1;
	while (x < f->columns_s)
	{
		pixelput_three_d(w, x + (f->columns_s * c),
		(f->rows_s * (r + 1)) - x, w->black);
		x++;
	}
}

void		light_s(t_struct *w, float mid, unsigned long color)
{
	int		i;
	float	plain;

	plain = 1;
	i = 0;
	while (plain >= -1)
	{
		mid = w->mid + atan(plain / w->len_mid);
		while (my_mlx_pixel_put_s(w, w->centx * w->m->columns_s
		+ sin(mid) * i, w->centy * w->m->rows_s + cos(mid) * i, color))
			i++;
		i = 0;
		plain = plain - 0.005;
	}
}
