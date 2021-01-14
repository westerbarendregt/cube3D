/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pov_walker2_bonus.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: wbarendr <wbarendr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/21 19:28:35 by wbarendr       #+#    #+#                */
/*   Updated: 2020/03/06 10:44:06 by wbarendr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "dcube_bonus.h"

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

int			release(int key, t_struct *w)
{
	if (key == 49)
	{
		light(w, w->mid);
		light_s(w, w->mid, w->color_flashlight);
	}
	if (key == 124)
		w->turn = 0;
	else if (key == 123)
		w->turn = 0;
	else if (key == 126 || key == 13 || key == 125 || key == 1)
		w->move1 = 0;
	else if (key == 0 || key == 2)
		w->move2 = 0;
	return (key);
}

int			turn(t_struct *w)
{
	w->counter++;
	w->mid = w->mid + w->turn;
	if (w->mid < 0)
		w->mid = w->mid + TWOPI;
	if (w->mid >= TWOPI)
		w->mid = w->mid - TWOPI;
	move(w);
	move_crab(w);
	light(w, w->mid);
	light_s(w, w->mid, w->color_flashlight);
	make_map_s2(w, w->m);
	if (w->counter % 2 == 0)
		mlx_put_image_to_window(w->mlx2, w->win2, w->img1, 0, 0);
	else
		mlx_put_image_to_window(w->mlx2, w->win2, w->img2, 0, 0);
	return (1);
}

int			press(int key, t_struct *w)
{
	if (key == 49)
		fire(w);
	if (key == 124)
		w->turn = -0.03;
	else if (key == 123)
		w->turn = 0.03;
	if (key == 126 || key == 13)
		w->move1 = 0.04;
	else if (key == 125 || key == 1)
		w->move1 = -0.04;
	else if (key == 0)
		w->move2 = 0.03;
	else if (key == 2)
		w->move2 = -0.03;
	else if (key == 53)
		peerexit(w);
	return (key);
}
