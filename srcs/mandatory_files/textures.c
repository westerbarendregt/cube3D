/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   textures.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: wbarendr <wbarendr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/18 14:47:33 by wbarendr       #+#    #+#                */
/*   Updated: 2020/03/05 19:32:32 by wbarendr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "dcube.h"

void			make_world_no(t_struct *w, float distance, int x)
{
	int		i;
	char	*color;
	float	y1;
	float	x1;
	int		max;

	x1 = (int)(w->t1->w_no * w->on_wall) * (w->t1->bits_per_pixel_no / 8);
	i = 0;
	max = (distance * w->m->ry) / 2;
	if (!(distance < 1))
		distance = 0.999999;
	w->wl->end = (distance * w->m->ry) / 2;
	while (i <= w->wl->end)
	{
		y1 = (((w->t1->h_no / 2.0) / max) * i) + (w->t1->h_no / 2);
		color = w->t1->addr_no + ((int)y1 * w->t1->ll_no + (int)x1);
		pixelput_three_d(w, x, w->wl->eq + i, *(unsigned int*)color);
		y1 = (w->t1->h_no / 2) - (((w->t1->h_no / 2.0) / max) * i);
		color = w->t1->addr_no + ((int)y1 * w->t1->ll_no + (int)x1);
		pixelput_three_d(w, x, w->wl->eq - i, *(unsigned int*)color);
		i++;
	}
	make_ceiling_floor(w, w->wl->eq - i, w->wl->eq + i, x);
}

void			make_sprite(t_struct *w, float distance, float on_wall, int x)
{
	int		i;
	char	*cl;
	int		x1;
	int		h1;
	float	h2;

	i = 0;
	x1 = (int)(w->t2->w_sp * on_wall) * (w->t2->bits_per_pixel_sp / 8);
	h2 = ((w->t2->h_sp) / (distance * w->m->ry));
	if (!(distance < 1))
		distance = 0.999999;
	w->wl->end = (distance * w->m->ry) / 2 - 1;
	h1 = (w->t2->h_sp / 2);
	while (i <= w->wl->end)
	{
		cl = w->t2->addr_sp + ((int)((h2 * i) + h1) * w->t2->ll_sp + x1);
		if (*(unsigned int*)cl != 0x00000000)
			pixelput_three_d(w, x, w->wl->eq + i, *(unsigned int*)cl);
		cl = w->t2->addr_sp + ((int)(h1 - (h2 * i)) * w->t2->ll_sp + x1);
		if (*(unsigned int*)cl != 0x00000000)
			pixelput_three_d(w, x, w->wl->eq - i, *(unsigned int*)cl);
		i++;
	}
}

void			make_world_we(t_struct *w, float distance, int x)
{
	int		i;
	char	*color;
	float	y1;
	float	x1;
	int		max;

	x1 = (int)(w->t1->w_we * w->on_wall) * (w->t1->bits_per_pixel_we / 8);
	i = 0;
	max = (distance * w->m->ry) / 2;
	if (!(distance < 1))
		distance = 0.999999;
	w->wl->end = (distance * w->m->ry) / 2;
	while (i <= w->wl->end)
	{
		y1 = (((w->t1->h_we / 2.0) / max) * i) + (w->t1->h_we / 2);
		color = w->t1->addr_we + ((int)y1 * w->t1->ll_we + (int)x1);
		pixelput_three_d(w, x, w->wl->eq + i, *(unsigned int*)color);
		y1 = (w->t1->h_we / 2) - (((w->t1->h_we / 2.0) / max) * i);
		color = w->t1->addr_we + ((int)y1 * w->t1->ll_we + (int)x1);
		pixelput_three_d(w, x, w->wl->eq - i, *(unsigned int*)color);
		i++;
	}
	make_ceiling_floor(w, w->wl->eq - i, w->wl->eq + i, x);
}

void			make_world_ea(t_struct *w, float distance, int x)
{
	int		i;
	char	*color;
	float	y1;
	float	x1;
	int		max;

	x1 = (int)(w->t2->w_ea * w->on_wall) * (w->t2->bits_per_pixel_ea / 8);
	i = 0;
	max = (distance * w->m->ry) / 2;
	if (!(distance < 1))
		distance = 0.999999;
	w->wl->end = (distance * w->m->ry) / 2;
	while (i <= w->wl->end)
	{
		y1 = (((w->t2->h_ea / 2.0) / max) * i) + (w->t2->h_ea / 2);
		color = w->t2->addr_ea + ((int)y1 * w->t2->ll_ea + (int)x1);
		pixelput_three_d(w, x, w->wl->eq + i, *(unsigned int*)color);
		y1 = (w->t2->h_ea / 2) - (((w->t2->h_ea / 2.0) / max) * i);
		color = w->t2->addr_ea + ((int)y1 * w->t2->ll_ea + (int)x1);
		pixelput_three_d(w, x, w->wl->eq - i, *(unsigned int*)color);
		i++;
	}
	make_ceiling_floor(w, w->wl->eq - i, w->wl->eq + i, x);
}

void			make_world_so(t_struct *w, float distance, int x)
{
	int		i;
	char	*color;
	float	y1;
	float	x1;
	int		max;

	x1 = (int)(w->t2->w_so * w->on_wall) * (w->t2->bits_per_pixel_so / 8);
	i = 0;
	max = (distance * w->m->ry) / 2;
	if (!(distance < 1))
		distance = 0.999999;
	w->wl->end = (distance * w->m->ry) / 2;
	while (i <= w->wl->end)
	{
		y1 = (((w->t2->h_so / 2.0) / max) * i) + (w->t2->h_so / 2);
		color = w->t2->addr_so + ((int)y1 * w->t2->ll_so + (int)x1);
		pixelput_three_d(w, x, w->wl->eq + i, *(unsigned int*)color);
		y1 = (w->t2->h_so / 2) - (((w->t2->h_so / 2.0) / max) * i);
		color = w->t2->addr_so + ((int)y1 * w->t2->ll_so + (int)x1);
		pixelput_three_d(w, x, w->wl->eq - i, *(unsigned int*)color);
		i++;
	}
	make_ceiling_floor(w, w->wl->eq - i, w->wl->eq + i, x);
}
