/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bonus_functions_bonus.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: wbarendr <wbarendr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/18 12:45:47 by wbarendr       #+#    #+#                */
/*   Updated: 2020/02/20 16:10:50 by wbarendr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "dcube_bonus.h"

unsigned int		make_shade(unsigned int color, float distance)
{
	int red;
	int green;
	int blue;

	blue = color % 256;
	green = (color - (color % 256)) % 65536 / 256;
	red = (color - (color % 65536)) % 16777216 / 65536;
	blue = blue * distance;
	green = green * distance;
	red = red * distance;
	color = blue + green * 256 + red * 65536;
	return (color);
}

void				circle_aim(t_struct *w, int midx, int midy)
{
	int x;

	x = 10;
	while (x >= 4)
	{
		pixelput_three_d(w, midx + (int)sqrt(196 - pow(x, 2)),
		midy + x, 0X00FF0000);
		pixelput_three_d(w, midx + (int)sqrt(196 - pow(x, 2)),
		midy - x, 0X00FF0000);
		pixelput_three_d(w, midx - (int)sqrt(196 - pow(x, 2)),
		midy + x, 0X00FF0000);
		pixelput_three_d(w, midx - (int)sqrt(196 - pow(x, 2)),
		midy - x, 0X00FF0000);
		pixelput_three_d(w, midx + x, midy + (int)sqrt(196 - pow(x, 2)),
		0X00FF0000);
		pixelput_three_d(w, midx + x, midy - (int)sqrt(196 - pow(x, 2)),
		0X00FF0000);
		pixelput_three_d(w, midx - x, midy + (int)sqrt(196 - pow(x, 2)),
		0X00FF0000);
		pixelput_three_d(w, midx - x, midy - (int)sqrt(196 - pow(x, 2)),
		0X00FF0000);
		x--;
	}
}

void				aiming_cross(t_struct *w)
{
	int x;
	int midx;
	int midy;

	midx = w->m->rx / 2;
	midy = w->m->ry / 2 + 30;
	x = -6;
	while (x <= 6)
	{
		pixelput_three_d(w, midx + x, midy, 0X00FF0000);
		pixelput_three_d(w, midx, midy + x, 0X00FF0000);
		x++;
	}
	x = 10;
	circle_aim(w, midx, midy);
}

void				show_gun(t_struct *w)
{
	int		x;
	int		x2;
	int		y;
	char	*color;

	x2 = 10;
	x = 0;
	y = 1;
	while (y < w->t1->h_gun)
	{
		while (x < w->t1->w_gun)
		{
			color = w->t1->addr_gun + (w->t1->h_gun - y) *
			w->t1->ll_gun + x * (w->t1->bits_per_pixel_gun / 8);
			if (*(unsigned int*)color <= 11585078)
				pixelput_three_d(w, x2, w->m->ry - y, *(unsigned int*)color);
			x++;
			x2++;
		}
		x = 1;
		x2 = 10;
		y++;
	}
	aiming_cross(w);
}

void				fire(t_struct *w)
{
	int		x;
	int		x2;
	int		y;
	char	*color;

	x2 = 380;
	x = 0;
	y = 85;
	while (y < w->t1->h_met)
	{
		while (x < w->t1->w_met)
		{
			color = w->t1->addr_met + (w->t1->h_met - y) *
			w->t1->ll_met + x * (w->t1->bits_per_pixel_met / 8);
			if (*(unsigned int*)color >= 185078)
				pixelput_three_d(w, x2, w->m->ry - y, *(unsigned int*)color);
			x++;
			x2++;
		}
		x = 1;
		x2 = 380;
		y++;
	}
}
