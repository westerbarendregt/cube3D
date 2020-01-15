/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main3.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: wbarendr <wbarendr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/14 11:04:37 by wbarendr       #+#    #+#                */
/*   Updated: 2020/01/14 14:25:58 by wbarendr      ########   odam.nl         */
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

typedef struct  s_vars 
{
	void        *mlx;
	void        *win;
	double    	x;
	double     	y;
	float      	radiant;
	void 		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			release;
}               t_vars;

void				my_mlx_pixel_put(t_vars *data, int x, int y, int color)
{
	char    *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int             click(int button, int x, int y, t_vars *vars)
{
	vars->x = x;
	vars->y = y; 
	return (button);
}

int             release(int button, int x, int y, t_vars *vars)
{
	int i;

	i = 0;
	vars->radiant =  (x - vars->x) / (y - vars->y);
	while (vars->y + i != y)
	{
		my_mlx_pixel_put(vars,  (vars->x + (i * vars->radiant)), vars->y + i, 0x00FF0000);
		i++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);	
	return (button);
}

int				hold(int keycode, t_vars *vars)
{
	printf("%d\n", keycode);
	if (keycode == 7)
	{
		mlx_string_put(vars->mlx, vars->win, 200, 225, 0x00FF0000, "hold 5 seconds");
		sleep(5);
		if (vars->release == 1)
			mlx_string_put(vars->mlx, vars->win, 200, 100, 0x00FF0000, "great holding!");
	}
	if (keycode == 2)
		mlx_string_put(vars->mlx, vars->win, 300, 125, 0x00FF0000, "please don't press the d");
	//mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	return (keycode);	
}

int				enter(int x, int y, t_vars *vars)
{
	printf("Mouse moving in Win3, at %dx%d.\n",x,y);
	if ((x > 0 && x < 800) && (y > 0 && y < 450))
		mlx_string_put(vars->mlx, vars->win, 380, 350, 0x00FF0000, "Hello Mouse");
	if ((x < 0 || x > 800) || (y < 0 || y > 450))
		mlx_string_put(vars->mlx, vars->win, 360, 400, 0x00FF0000, "where is the mouse");
	return (x);	
}

int				leave(int x, int y, t_vars *vars)
{
	if ((x < 0 || x > 800) || (y < 0 || y > 450))
		mlx_string_put(vars->mlx, vars->win, 360, 400, 0x00FF0000, "where is the mouse");
	return (x);	
}

int				release2(int keycode, t_vars *vars)
{
	if (keycode == 7)
	{
		mlx_string_put(vars->mlx, vars->win, 50, 50, 0x00FF0000, "You let go");
		vars->release = 1;
	}
	return (keycode);
}

int             main(void)
{
	t_vars    vars;

	vars.release = 0;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 800, 450, "Draw a line");
	vars.img = mlx_new_image(vars.mlx, 800, 500);
	vars.addr = mlx_get_data_addr(vars.img, &vars.bits_per_pixel, &vars.line_length, &vars.endian);
	mlx_hook(vars.win, 4, 1L<<2, click, &vars);
    mlx_hook(vars.win, 5, 1L<<3, release, &vars);
	mlx_hook(vars.win, 2, 1L<<0, hold, &vars);

    //mlx_hook(vars.win, 5, 1L<<3, release2, &vars);
	
	mlx_hook(vars.win, 6, 1L<<6, enter, &vars);
	//mlx_hook(vars.win, 6, 1L<<6, leave, &vars);
	
	mlx_loop(vars.mlx);
} 