/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_flashlight.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: wbarendr <wbarendr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/20 14:12:12 by wbarendr       #+#    #+#                */
/*   Updated: 2020/01/20 19:15:36 by wbarendr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "dcube.h"

int			find_distance(t_struct *w, int y, int x)
{
	y = y * w->m->rows - w->centy;
	if (y < 0)
		y = y * -1;
	x = x * w->m->columns - w->centx;
	if (x < 0)
		x = x * -1;
	return (sqrt((x * x) + (y * y)));
}

void		loop_this(float pov, t_struct *w, t_map *f)
{
	float sloop;
	int y;
	int x;
	int i;
	float dist;
	
	dist = 0;
	i = 0;
	sloop = tan(pov * radiant);
	y = (w->centy + i )/ f->rows;
	x = (sloop * i + w->centx) / f->columns;
	while (f->map[y][x] != '1' && dist < 250)
	{
		//printf("1, %f\n", tan(pov * radiant) * i);
		i++;
		y = (w->centy - i )/ f->rows;
		x = (w->centx + sloop * i) / f->columns;
		dist = find_distance(w, y, x);
		printf("%f\n", dist);
	}
	printf("y: %d x: %d\n", y, x);
	printf("i:  %d\n", i);
	i = 0;
	y = (w->centy + i )/ f->rows;
	x = (sloop * i + w->centx) / f->columns;
	dist = 0;
	while (f->map[y][x] != '1' && dist < 250)
	{
		//printf("1, %f\n", tan(pov * radiant) * i);
		i++;
		y = (w->centy - i )/ f->rows;
		x = (w->centx - sloop * i) / f->columns;
		dist = find_distance(w, y, x);
	}
	printf("y: %d x: %d\n", y, x);
	printf("i:  %d\n", i);
	printf("------\n");
}

void        make_flashlight(t_struct *w, t_map *f)
{
	w->x = f->ry;

	float pov;
	float pov2;
	
	//int first;
	
	pov = 52 / 2;
	pov2 = 90 - pov;
	//printf("pixel x: %d\n pixel y: %d\n", w->centx, w->centy);

	while (pov > 24)
	{
		loop_this(pov, w, f);
		pov--;
		pov--;
		pov--;
	}
	
	//printf("2, %f\n", tan(pov2 * radiant) * i);
}