/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   put_map_to_window2_bonus.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: wbarendr <wbarendr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/16 10:18:39 by wbarendr       #+#    #+#                */
/*   Updated: 2020/02/28 18:40:59 by wbarendr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "dcube_bonus.h"

int		direction(t_struct *w, t_map *f, int y, int x)
{
	if (f->map[y][x] == 'N')
	{
		w->mid = PI;
		return (1);
	}
	else if (f->map[y][x] == 'E')
	{
		w->mid = PITWO;
		return (1);
	}
	else if (f->map[y][x] == 'S')
	{
		w->mid = 0;
		return (1);
	}
	else if (f->map[y][x] == 'W')
	{
		w->mid = PI + PITWO;
		return (1);
	}
	return (0);
}

void	make_ceiling(t_struct *w, int y1, int x, float distance)
{
	int				y;
	unsigned int	color;

	y = 0;
	color = w->m->ceiling;
	while (y < y1 + 1)
	{
		pixelput_three_d(w, x, y, make_shade(color, distance));
		y++;
		distance = distance - 2.0 / w->m->ry;
	}
}

void	make_ceiling_floor(t_struct *w, int y1, int y2, int x)
{
	unsigned int	color;
	int				y;
	float			distance;

	distance = 1;
	make_ceiling(w, y1, x, distance);
	color = w->m->floor;
	y = w->m->ry - 1;
	while (y > y2 - 2)
	{
		pixelput_three_d(w, x, y, make_shade(color, distance));
		y--;
		distance = distance - 2.0 / w->m->ry;
	}
}

int		peerexit(t_struct *w)
{
	int i;

	i = 0;
	while (w->m->map[i])
	{
		free(w->m->map[i]);
		i++;
	}
	free(w->m->map);
	write(1, "exited the program cleanly\n\n", 28);
	exit(0);
	return (0);
}

void	put_map_to_window(t_map *f)
{
	t_struct	w;
	t_wall		wl;
	t_texture1	t1;
	t_texture2	t2;

	w.wl = &wl;
	w.t1 = &t1;
	w.t2 = &t2;
	w.m = f;
	init_data(&w, f);
	if (init_textures(&w) == -1)
		peerexit(&w);
	turn(&w);
	if (f->save == 1)
	{
		export_bmp("screenshot.bmp", w.addr2, f->rx, f->ry);
		peerexit(&w);
	}
	mlx_hook(w.win2, 2, 1L << 0, press, &w);
	mlx_hook(w.win2, 3, 1L << 1, release, &w);
	mlx_hook(w.win2, 17, 1L << 17, peerexit, &w);
	mlx_loop_hook(w.mlx2, turn, &w);
	mlx_loop(w.mlx2);
}
