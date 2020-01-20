/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   put_map_to_window.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: wbarendr <wbarendr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/16 10:18:39 by wbarendr       #+#    #+#                */
/*   Updated: 2020/01/20 15:58:09 by wbarendr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "dcube.h"

void				my_mlx_pixel_put1(t_struct *data, int x, int y, int *j)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = data->color;
	(*j)++;
}

void				my_mlx_pixel_put(t_struct *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void    make_square(int r, int c, t_struct *w, t_map *f)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while (x < f->columns)
    {
        while (y < f->rows)
        {
            my_mlx_pixel_put(w, x + (f->columns * c), y + (f->rows * r), f->floor);
            y++;
        }
        y = 0;
        x++;
    }
}

void    make_map(t_struct *w, t_map *f)
{
    int r;
    int c;

    r = 0;
    c = 0;
    f->columns = f->rx / f->columns;
    f->rows = f->ry / f->rows;
    while (f->map[r] != 0)
    {
        while (f->map[r][c] != 0)
        {
            if (f->map[r][c] == '1')
                make_square(r, c, w, f);
            c++;
        }
        c = 0;
        r++;
    }
}

void    make_center(t_struct *w, t_map *f)
{
    int x; 
    int y;

    x = 0;
    y = 0;
    while (f->map[y])
    {
        while (f->map[y][x])
        {
            if (f->map[y][x] == 'N')
                break;
            x++;
        }
        if (f->map[y][x] == 'N')
                break;
        x = 0;
        y++;
    }
	printf("rows: %d\n", f->rows);
	printf("columns: %d\n", f->columns);
	printf("x: %d\n", x);
	printf("y: %d\n", y);
	w->x = x;
	w->y = y;	
    w->centy = y * f->rows + f->rows / 2;
    w->centx = x * f->columns + f->columns / 2; 
}

void    center_point(t_struct *w)
{
    int i;
	int j;
	int co;	

	co = 0;
	i = 0;
	j = 0;
	while (co != 4)
	{
		while (i < 8)
		{
			while (j != (int)sqrt(49 - (i * i)) && co == 0)
				my_mlx_pixel_put1(w, w->centx + j, (w->centy - i), &j);
			while (j != (int)sqrt(49 - (i * i)) && co == 1)
				my_mlx_pixel_put1(w, w->centx + j, (w->centy + i), &j);
			while (j != (int)sqrt(49 - (i * i)) && co == 2)
				my_mlx_pixel_put1(w, w->centx - j, (w->centy - i), &j);
			while (j != (int)sqrt(49 - (i * i)) && co == 3)
				my_mlx_pixel_put1(w, w->centx - j, (w->centy + i), &j);
			j = 0;
			i++;
		}
		i = 0;
		co++;
	}
}

int		press(int keycode, t_struct *w)
{ 
    //printf("centx: %d\ncenty: %d\n", w->centx, w->centy);
    //printf("1: %d\n2: %d\n", (w->centx / w->m->columns * 2), w->centy / w->m->rows);
	if (keycode == 124 && w->m->map[w->centy / w->m->rows][(w->centx + 19)/ w->m->columns] != '1')
		w->centx = w->centx + 16;
	if (keycode == 123 && w->m->map[w->centy / w->m->rows][(w->centx - 19)/ w->m->columns] != '1')
		w->centx = w->centx - 16;
	if (keycode == 126 && w->m->map[(w->centy - 19) / w->m->rows][(w->centx)/ w->m->columns] != '1')
		w->centy = w->centy - 16;
	if (keycode == 125 && w->m->map[(w->centy + 19) / w->m->rows][(w->centx)/ w->m->columns] != '1')
		w->centy = w->centy + 16;
    if (w->color >= 0x00FFFFFF)
		w->end = 1;
	if (w->color <= 0x000F0F0F && w->end == 1)
		w->end = 0;
	if (w->color <= 0x00FF0F0F && w->end == 1)
		w->color = w->color - 16 * 16 * 16 * 16 * 16;
	else if (w->color <= 0x00FF0FFF && w->end == 1)
		w->color = w->color - 16;
	else if (w->color <= 0x00FFFFFF && w->end == 1)
		w->color = w->color - 16 * 16 * 16;
	if (w->color >= 0x00FFFFF && w->end == 0)
		w->color = w->color + 16 * 16 * 16 * 16 * 16;
	else if (w->color >= 0x00F0FFF && w->end == 0)
		w->color = w->color + 16 * 16 * 16;
	else if (w->color >= 0x00F0F0F && w->end == 0)
		w->color = w->color + 16;
	center_point(w);
	mlx_put_image_to_window(w->mlx, w->win, w->img, 0, 0);
	return (keycode);
}

void	put_map_to_window(t_map *f)
{
    t_struct    w;
	
	w.x = 400;
	w.y = 225;
	w.color = 0x000F0F0F;
	w.end = 0;
	w.m = f;

	w.mlx = mlx_init();
	w.img = mlx_new_image(w.mlx, f->rx, f->ry);
	w.addr = mlx_get_data_addr(w.img, &w.bits_per_pixel, &w.line_length, &w.endian);
	w.win = mlx_new_window(w.mlx, f->rx, f->ry, "Hello Wes");
	make_map(&w, f);
    mlx_put_image_to_window(w.mlx, w.win, w.img, 0, 0);
    make_center(&w, f);
	make_flashlight(&w, f);
	mlx_hook(w.win, 2, 1L<<0, press, &w);
	//mlx_loop_hook(f.mlx, render_next_frame, &w);
	mlx_loop(w.mlx);
}