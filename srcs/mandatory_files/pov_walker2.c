/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pov_walker2.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: wbarendr <wbarendr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/21 19:28:35 by wbarendr       #+#    #+#                */
/*   Updated: 2020/03/05 19:32:37 by wbarendr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "dcube.h"

void		pixelput_three_d(t_struct *w, int x, int y, int color)
{
	char	*dst;

	if (w->counter % 2 == 0)
	{
		dst = w->addr1 + y * w->line_length + x * (w->bits_per_pixel / 8);
		*(unsigned int*)dst = color;
		return ;
	}
	dst = w->addr2 + y * w->line_length + x * (w->bits_per_pixel / 8);
	*(unsigned int*)dst = color;
}

void		light(t_struct *w, float mid)
{
	float	plain;
	float	step;
	int		x;

	step = (1.0 / (w->m->rx / 2.0));
	x = 0;
	plain = 1;
	while (plain >= -1)
	{
		mid = w->mid + atan(plain / w->len_mid);
		if (mid < 0)
			mid = mid + TWOPI;
		if (mid > TWOPI)
			mid = mid - TWOPI;
		find_wall(w, mid, x);
		x++;
		plain = plain - step;
	}
}

int			turn(t_struct *w)
{
	if (w->counter == 10000)
		w->counter = 0;
	w->counter++;
	w->mid = w->mid + w->turn;
	if (w->mid < 0)
		w->mid = w->mid + TWOPI;
	if (w->mid >= TWOPI)
		w->mid = w->mid - TWOPI;
	move(w);
	move_crab(w);
	light(w, w->mid);
	if (w->counter % 2 == 0)
		mlx_put_image_to_window(w->mlx2, w->win2, w->img1, 0, 0);
	else
		mlx_put_image_to_window(w->mlx2, w->win2, w->img2, 0, 0);
	return (1);
}

int			press(int key, t_struct *w)
{
	if (key == 124)
		w->turn = -0.04;
	else if (key == 123)
		w->turn = 0.04;
	if (key == 126 || key == 13)
		w->move1 = 0.08;
	else if (key == 125 || key == 1)
		w->move1 = -0.08;
	else if (key == 0)
		w->move2 = 0.05;
	else if (key == 2)
		w->move2 = -0.05;
	else if (key == 53)
		peerexit(w);
	return (key);
}

int			lego(int key, t_struct *w)
{
	if (key == 124)
		w->turn = 0;
	else if (key == 123)
		w->turn = 0;
	if (key == 126 || key == 13 || key == 125 || key == 1)
		w->move1 = 0;
	else if (key == 0 || key == 2)
		w->move2 = 0;
	return (key);
}
