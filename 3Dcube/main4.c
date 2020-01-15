/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main4.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: wbarendr <wbarendr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/14 17:45:44 by wbarendr       #+#    #+#                */
/*   Updated: 2020/01/14 22:23:06 by wbarendr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include <stdio.h>

typedef struct		s_struct
{
	void        	*mlx;
	void 			*img;
	void 			*win;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int             x;
	int             y;
	unsigned long 	color;
	int				end;
}					t_struct;

void				my_mlx_pixel_put(t_struct *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int     render_next_frame(t_struct *f)
{
	int i;
	int j;
	int co;	

	co = 0;
	i = 0;
	j = 0;
	while (co != 4)
	{
		while (i < 21)
		{
			if (co == 0)
				while (j != (int)sqrt(400 - (i * i)))
				{
					my_mlx_pixel_put(f, f->x + j, (f->y - i), f->color);
					j++;
				}
			if (co == 1)
				while (j != (int)sqrt(400 - (i * i)))
				{
					my_mlx_pixel_put(f, f->x + j, (f->y + i), f->color);
					j++;
				}
			if (co == 2)
				while (j != (int)sqrt(400 - (i * i)))
				{
					my_mlx_pixel_put(f, f->x - j, (f->y - i), f->color);
					j++;
				}	
			if (co == 3)
				while (j != (int)sqrt(400 - (i * i)))
				{
					my_mlx_pixel_put(f, f->x - j, (f->y + i), f->color);
					j++;
				}
			j = 0;
			i++;
		}
		i = 0;
		co++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	return (1);	
}

int		press(int keycode, t_struct *f)
{
	if (keycode == 124)
		f->x = f->x + 12;
	if (keycode == 123)
		f->x = f->x - 12;
	if (keycode == 126 && f->y > 21)
		f->y = f->y - 12;
	if (keycode == 125 && f->y < 466)
		f->y = f->y + 12;
	if (f->color >= 0x00F0F0F0)
		f->end = 1;
	if (f->color <= 0x00000000 && f->end == 1)
		f->end = 0;
	if (f->color <= 0x00F00000 && f->end == 1)
		f->color = f->color - 16 * 16 * 16 * 16 * 16;
	else if (f->color <= 0x00F000F0 && f->end == 1)
		f->color = f->color - 16;
	else if (f->color <= 0x00F0F0F0 && f->end == 1)
		f->color = f->color - 16 * 16 * 16;
	if (f->color >= 0x0000F0F0 && f->end == 0)
		f->color = f->color + 16 * 16 * 16 * 16 * 16;
	else if (f->color >= 0x000000F0 && f->end == 0)
		f->color = f->color + 16 * 16 * 16;
	else if (f->color >= 0x00000000 && f->end == 0)
		f->color = f->color + 16;
	printf("color: %lx \n", f->color);
	render_next_frame(f);
	return (keycode);
}

int     main(void)
{
	t_struct    f;
	
	f.x = 400;
	f.y = 225;
	f.color = 0x00000000;
	f.end = 0;
	
	f.mlx = mlx_init();
	f.img = mlx_new_image(f.mlx, 800, 500);
	f.addr = mlx_get_data_addr(f.img, &f.bits_per_pixel, &f.line_length, &f.endian);
	f.win = mlx_new_window(f.mlx, 800, 500, "Hello Wes");
	render_next_frame(&f);
	mlx_hook(f.win, 2, 1L<<0, press, &f);
	//mlx_loop_hook(f.mlx, render_next_frame, &f);
	mlx_loop(f.mlx);
	return (0);
}