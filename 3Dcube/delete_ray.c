/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   delete_ray.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: wbarendr <wbarendr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/21 21:18:57 by wbarendr       #+#    #+#                */
/*   Updated: 2020/01/21 21:39:22 by wbarendr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "dcube.h"

void		del_south_east(t_struct *w, int mid, unsigned long color)
{
	int i;
	float k;

	k = 0;
	i = 0;
	mid = mid % 90;
	while (k <= w->angle)
	{
		while (i <= w->radius)
		{
			my_mlx_pixel_put(w, w->del_x + sin((mid + k) * radiant) * i, w->del_y + cos((mid + k) * radiant) * i, color);	
			i++;
		}
		i = 0;
		k = k + 0.25;
	}
}

void		del_north_east(t_struct *w, int mid, unsigned long color)
{
	int i;
	float k;

	k = 0;
	i = 0;
	mid = mid % 90;
	while (k <= w->angle)
	{
		while (i <= w->radius)
		{
			my_mlx_pixel_put(w, w->del_x + cos((mid + k) * radiant) * i, w->del_y - sin((mid + k) * radiant) * i, color);	
			i++;
		}
		i = 0;
		k = k + 0.25;
	}
}

void		del_north_west(t_struct *w, int mid, unsigned long color)
{
	int i;
	float k;

	k = 0;
	i = 0;
	mid = mid % 90;
	while (k <= w->angle)
	{
		while (i <= w->radius)
		{
			my_mlx_pixel_put(w, w->del_x - sin((mid + k) * radiant) * i, w->del_y - cos((mid + k) * radiant) * i, color);	
			i++;
		}
		i = 0;
		k = k + 0.25;
	}
}

void		del_south_west(t_struct *w, int mid, unsigned long color)
{
	int i;
	float k;

	k = 0;
	i = 0;
	mid = mid % 90;
	while (k <= w->angle)
	{
		while (i <= w->radius)
		{
			my_mlx_pixel_put(w, w->del_x - cos((mid + k) * radiant) * i, w->del_y + sin((mid + k) * radiant) * i, color);	
			i++;
		}
		i = 0;
		k = k + 0.25;
	}
}

void		del_light(t_struct *w, int mid, unsigned long color)
{
	mid = mid - (w->angle / 2);
	if (mid < 0)
			mid = mid + 360;
	if (mid >= 0 && mid < 90)
		del_north_west(w, mid, color);
	else if (mid >= 90 && mid < 180)
		del_south_west(w, mid, color);
	else if (mid >= 180 && mid < 270)
		del_south_east(w, mid, color);
	else if (mid >= 270 && mid < 360)
		del_north_east(w, mid, color);
}