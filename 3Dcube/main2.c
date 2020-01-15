/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main2.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: wbarendr <wbarendr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/13 12:41:58 by wbarendr       #+#    #+#                */
/*   Updated: 2020/01/14 10:54:21 by wbarendr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <math.h>
#include	<stdlib.h>
#include	<string.h>
#include        <unistd.h>
#include        <fcntl.h>
#include        <sys/mman.h>
#include	<sys/ipc.h>
#include	<sys/shm.h>
#define PIPI 3.14159265358979323846

typedef struct  s_vars {
	void        *mlx;
	void        *win;
	int			x;
	int			y;
	void 		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}               t_vars;

void				my_mlx_pixel_put(t_vars *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int             ft_close(int keycode, t_vars *vars)
{
	printf("%i\n", keycode);
	if (keycode == 53)
		mlx_destroy_window(vars->mlx, vars->win);
	//if (keycode == )
	return (keycode);
}

int				mouse(int button, int x, int y)
{
	printf("Mouse in Window, button %d at %dx%d.\n", button, x, y);
	return (button);
}

int				save_x(int x, int num)
{
	static int save;
	
	if (num == 1)
	{
		save = x;
		return (0);
	}
	return (save);
}

int				save_y(int y, int num)
{
	static int save;
	
	if (num == 1)
	{
		save = y;
		return (0);
	}
	return (save);
}		

float 			save_x1(float x, int num)
{
	static float save;
	
	if (num == 1)
	{
		save = x;
		return (0);
	}
	return (save);
}

float			save_y1(float y, int num)
{
	static float save;
	
	if (num == 1)
	{
		save = y;
		return (0);
	}
	return (save);
}	

int				mouse2(int button, int x, int y, void *p)
{
	void *k;

	printf("Mouse moving in Win3, at %dx%d.\n",x,y);
	k = p;
	save_x(x, 1);
	save_y(y, 1);
	return (button);
}

int				mouse3(int button, int x, int y, void *p)
{
	void *k;
	double x1;
	double y1;

	k = p;
	printf("2, at %dx%d.\n", x, y);
	x1 =  x - save_x(1, 0);
	y1 =  y - save_y(1, 0);

	x1 = x1/y1;
	save_x1(x1, 1);
	save_y1(y1, 1);
	
	printf("3, at %fx%f.\n", x1, y1);
	//printf("4, at %f\n", (x1/y1));
	//y1 = asin(x1/y1);
	//y1 = (y1 * 180) / PIPI;
	printf("%f\n", y1);
	return (button);
}

int             main(void)
{ 	
	t_vars      vars;
	int 		i;

	i = 0;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 800, 450, "DON'T PRESS A KEY!!!!");
	//mlx_mouse_hook(vars.win, mouse, 0);
	mlx_key_hook(vars.win, ft_close, &vars);
	//mlx_hook(vars.win, 6, 0, mouse2, 0);
	mlx_hook(vars.win, 4, 0, mouse2, 0);
	mlx_hook(vars.win, 5, 0, mouse3, 0);
	vars.img = mlx_new_image(vars.mlx, 800, 500);
	vars.addr = mlx_get_data_addr(vars.img, &vars.bits_per_pixel, &vars.line_length, &vars.endian);
	//sleep(10);
	printf("y1: -- %f\n", save_y1(1, 0));
	printf("x1: -- %f\n", save_x1(1, 0));
	while (i != save_y1(1, 0))
	{
		my_mlx_pixel_put(&vars, save_x(1, 0) + (i * save_x1(1, 0)), (save_y(1, 0) + i), 0x00FF0000);
		i++;
		printf("hi\n");
	}
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 0, 0);	
	mlx_loop(vars.mlx);
	//mlx_loop_hook(vars, vars.mlx, 0);
} 