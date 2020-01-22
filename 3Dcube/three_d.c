/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   three_d.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: wbarendr <wbarendr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/22 14:19:33 by wbarendr       #+#    #+#                */
/*   Updated: 2020/01/22 19:27:41 by wbarendr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "dcube.h"

void		my_mlx_pixel_put4(t_struct *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr2 + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int			fix_fish_eye1(int x, int distance, t_struct *w)
{
	int middle;

	middle = w->m->rx / 2;
	x = x - middle;
	x = x * (w->angle / w->m->rx);
	if (x < 0)
		x = x * -1;
	//printf("angle: %d\n", x);
	return (cos(x * radiant) * distance);
}

int			fix_fish_eye(int x, int distance, t_struct *w)
{
	int middle;

	middle = w->m->rx / 2;
	x = x - middle;
	x = x * (w->angle / w->m->rx); /// don't forget about that the 
	//angle is from 0 to 60 and not from -30 t0 30
	if (x < 0)
		x = x * -1;
	printf("angle: %d\n", x);
	return (cos(x * radiant) * distance);
}

void		make_three_d(int x, int distance, t_struct *w, int angle)
{
	int y;
	int equator;

	y = 0;
	equator = w->m->ry / 2;
	printf("%d\n", w->mid);
	angle = w->mid % 90 - angle; // denk aan de w->mid omdat hij moet berekenen in welke hoek hij afneemt!
	// ga dit trouwens ook ff op papier na! 
	printf("ll-angle: %d -- ", angle);
	//angle = angle - 30;
	if (angle < 0)
		angle = angle * -1;
	printf("%d\n", angle);
	printf("distance: %d -- ", distance);
	distance = cos(angle * radiant) * distance;
	printf("new: %d\n", distance);
	printf("x: %d  times: %d  ", x, equator - distance);

	while (y < equator - distance)
	{
		my_mlx_pixel_put4(w, x, equator + y, 0x00B22B33);
		my_mlx_pixel_put4(w, x, equator - y, 0x00B22B33);
		y++;
	}
}

void		del_make_three_d(int x, int distance, t_struct *w, int angle)
{
	int y;
	int equator;

	y = 0;
	equator = w->m->ry / 2;
	angle = angle - 30;
	if (angle < 0)
		angle = angle * -1;
	distance = cos(angle * radiant) * distance;
	while (y < equator - distance / 1.5)
	{
		my_mlx_pixel_put4(w, x, equator + y, w->black);
		my_mlx_pixel_put4(w, x, equator - y, w->black);
		y++;
	}
}