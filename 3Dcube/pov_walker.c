/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pov_walker.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: wbarendr <wbarendr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/21 19:28:35 by wbarendr       #+#    #+#                */
/*   Updated: 2020/01/22 16:21:11 by wbarendr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "dcube.h"

void		my_mlx_pixel_put2(t_struct *data, int x, int y, int *j)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = data->black;
	(*j)++;
}

void		name(t_struct *w, t_map *f)
{
	if (f->map[w->y][w->x] == 'N')
		w->mid = 0;
	else if (f->map[w->y][w->x] == 'E')
		w->mid = 270;
	else if (f->map[w->y][w->x] == 'S')
		w->mid = 180;
	else if (f->map[w->y][w->x] == 'W')
		w->mid = 90;
}

void		south_east(t_struct *w, int mid, unsigned long color)
{
	int				i;
	float			k;
	unsigned long	colorsave;

	colorsave = color;
	k = 0;
	i = 0;
	mid = mid % 90;
	while (k <= w->angle)
	{
		while (i <= w->radius)
		{
			if (my_mlx_pixel_put(w, w->centx + sin((mid + k) * radiant) * i, w->centy + cos((mid + k) * radiant) * i, color))
			{
				make_three_d(w->m->rx - (k / (w->angle / w->m->rx)), i, w, k);
				break ;
			}
			i++;
			if (i % 4 == 0)
				color = color + 1 * pow(16, 6);
		}
		color = colorsave;
		i = 0;
		k = k + w->angle / w->m->rx;
	}
}

void		north_east(t_struct *w, int mid, unsigned long color)
{
	int				i;
	float			k;
	unsigned long	colorsave;
		
	colorsave = color;
	k = 0;
	i = 0;
	mid = mid % 90;
	while (k <= w->angle)
	{
		while (i <= w->radius)
		{
			if (my_mlx_pixel_put(w, w->centx + cos((mid + k) * radiant) * i, w->centy - sin((mid + k) * radiant) * i, color))	
			{
				make_three_d(w->m->rx - (k / (w->angle / w->m->rx)), i, w, k);
				break ;
			}
			i++;
			if (i % 4 == 0)
				color = color + 1 * pow(16, 6);
		}
		color = colorsave;
		i = 0;
		k = k + w->angle / w->m->rx;
	}
}

void		north_west(t_struct *w, int mid, unsigned long color)
{
	int				i;
	float			k;
	unsigned long	colorsave;

	colorsave = color;
	k = 0;
	i = 0;
	mid = mid % 90;
	while (k <= w->angle)
	{
		while (i <= w->radius)
		{
			if (my_mlx_pixel_put(w, w->centx - sin((mid + k) * radiant) * i, w->centy - cos((mid + k) * radiant) * i, color))
			{
				make_three_d(w->m->rx - (k / (w->angle / w->m->rx)), i, w, k);
				break ;
			}
			i++;
			if (i % 4 == 0)
				color = color + 1 * pow(16, 6);
		}
		color = colorsave;
		i = 0;
		k = k + w->angle / w->m->rx;
	}
}

void		south_west(t_struct *w, int mid, unsigned long color)
{
	int				i;
	float			k;
	unsigned long	colorsave;

	colorsave = color;
	k = 0;
	i = 0;
	mid = mid % 90;
	while (k <= w->angle)
	{
		while (i <= w->radius)
		{
			if (my_mlx_pixel_put(w, w->centx - cos((mid + k) * radiant) * i, w->centy + sin((mid + k) * radiant) * i, color))
			{
				make_three_d(w->m->rx - (k / (w->angle / w->m->rx)), i, w, k);
				break ;
			}
			i++;
			if (i % 4 == 0)
				color = color + 1 * pow(16, 6);
		}
		color = colorsave;
		i = 0;
		k = k + w->angle / w->m->rx;
	}
}

void		se_move(t_struct *w)
{
	w->centx = w->centx + sin(w->mid % 90 * radiant) * w->step;
	w->centy = w->centy + cos(w->mid % 90 * radiant) * w->step;	
}

void		ne_move(t_struct *w)
{
	w->centx = w->centx + cos(w->mid % 90 * radiant) * w->step;
	w->centy = w->centy - sin(w->mid % 90 * radiant) * w->step;	
}

void		nw_move(t_struct *w)
{
	w->centx = w->centx - sin((w->mid % 90) * radiant) * w->step;
	w->centy = w->centy - cos((w->mid % 90) * radiant) * w->step;
}

void		sw_move(t_struct *w)
{
	w->centx = w->centx - cos(w->mid % 90 * radiant) * w->step;
	w->centy = w->centy + sin(w->mid % 90 * radiant) * w->step;
}

void		light(t_struct *w, int mid, unsigned long color)
{
	mid = mid - (w->angle / 2);
	if (mid < 0)
			mid = mid + 360;
	if (mid >= 0 && mid < 90)
		north_west(w, mid, color);
	else if (mid >= 90 && mid < 180)
		south_west(w, mid, color);
	else if (mid >= 180 && mid < 270)
		south_east(w, mid, color);
	else if (mid >= 270 && mid < 360)
		north_east(w, mid, color);
}

void    del_last(t_struct *w)
{
    int i;
	int j;
	int co;	

	co = 0;
	i = 0;
	j = 0;
	while (co != 4)
	{
		while (i < 5)
		{
			while (j != (int)sqrt(16 - (i * i)) && co == 0)
				my_mlx_pixel_put2(w, w->del_x + j, (w->del_y - i), &j);
			while (j != (int)sqrt(16 - (i * i)) && co == 1)
				my_mlx_pixel_put2(w, w->del_x + j, (w->del_y + i), &j);
			while (j != (int)sqrt(16 - (i * i)) && co == 2)
				my_mlx_pixel_put2(w, w->del_x - j, (w->del_y - i), &j);
			while (j != (int)sqrt(16 - (i * i)) && co == 3)
				my_mlx_pixel_put2(w, w->del_x - j, (w->del_y + i), &j);
			j = 0;
			i++;
		}
		i = 0;
		co++;
	}
}

void		move(t_struct *w)
{
	int x;
	int y;

	x = w->centx;
	y = w->centy;
	del_last(w);
	if (w->mid >= 0 && w->mid < 90)
		nw_move(w);
	else if (w->mid >= 90 && w->mid < 180)
		sw_move(w);
	else if (w->mid >= 180 && w->mid < 270)
		se_move(w);
	else if (w->mid >= 270 && w->mid < 360)
		ne_move(w);
	if (w->m->map[w->centy / w->m->rows][w->centx / w->m->columns] == '1')
	{
		w->centx = x;
		w->centy = y;
	}
}

int		turn(int keyboard, t_struct *w)
{
	if (keyboard == 124 || keyboard == 123 || keyboard == 126)
		del_light(w, w->mid, w->black);
	if (keyboard == 124)
	{
		w->mid = w->mid - 3;
		if (w->mid < 0)
			w->mid = w->mid + 360;
		light(w, w->mid, w->color);
	}
	else if (keyboard == 123)
	{
		w->mid = w->mid + 3;
		if (w->mid >= 360)
		w->mid = w->mid - 360;
		light(w, w->mid, w->color);
	}
	else if (keyboard == 126)
		move(w);
/* 	else if (keyboard == 125)
		move(w, -10) */
	if (keyboard == 125 || keyboard == 126)
	{
		center_point(w);
		light(w, w->mid, w->color);
	}
	w->del_x = w->centx;
	w->del_y = w->centy;
	mlx_put_image_to_window(w->mlx, w->win, w->img, 0, 0);	
	mlx_put_image_to_window(w->mlx2, w->win2, w->img2, 0, 0);
    
	return (keyboard);
}