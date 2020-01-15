/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: wbarendr <wbarendr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 12:46:41 by wbarendr       #+#    #+#                */
/*   Updated: 2020/01/10 15:12:52 by wbarendr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <math.h>

typedef struct		s_struct
{
	void 			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_struct;

void				my_mlx_pixel_put(t_struct *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void				make_circle(t_struct *img)
{
	int y;
	int x;
	int center;
	int radius;
	int i;
	unsigned long color;
	unsigned long colorsave;
	int savecenter;
	int plus;

	plus = 1;
	color = 0x00555500;
	colorsave = color;
	center = 550;
	savecenter = center;
	i = 0;
	y = 150;
	img->endian = 1;
	radius = 120;
 	while (i < radius)
	{
		x = sqrt((radius * radius) - (i * i)) + center;
		while (center < x)
		{
			my_mlx_pixel_put(img, center, (y - i), color);
			color = color + plus; 
			center++;
		}
		center = savecenter;
		my_mlx_pixel_put(img, x, (y - i), color);
		color = color + plus; 
		i++;
	}
	color = colorsave;
	i = 0;
	while (i < radius)
	{
		x = sqrt((radius * radius) - (i * i)) + center;
		while (center < x)
		{
			my_mlx_pixel_put(img, center, (y + i), color); 
			color = color + plus; 
			center++;
		}
		center = savecenter; 
		my_mlx_pixel_put(img, x, (y + i), color);
		color = color + plus; 
		i++;
	}
	i = 0;
	color = colorsave;
	while (i < radius)
	{
		x = center - sqrt((radius * radius) - (i * i));
		while (center > x)
		{
			my_mlx_pixel_put(img, center, (y - i), color); 
			color = color + plus; 
			center--;
		}
		center = savecenter; 
		my_mlx_pixel_put(img, x, (y - i), color);
		color = color + plus; 
		i++;
	}
	i = 0;
	color = colorsave;
	while (i < radius)
	{
		x = center - sqrt((radius * radius) - (i * i));
		while (center > x)
		{
			my_mlx_pixel_put(img, center, (y + i), color); 
			color = color + plus; 
			center--;
		}
		center = savecenter;
		my_mlx_pixel_put(img, x, (y + i), color);
		color = color + plus; 
		i++;
	}
}

void				make_triangle(t_struct *img)
{
	int y;
	int x;
	int i;
	int end;

	y = 200;
	x = 200;
	end = 0;
	i = 0;
	while (y < 270)
	{
		while ((x - end + i) <= (x + end)) 
		{
			my_mlx_pixel_put(img, (x - end + i), y, 0x00999900);
			i++;
		}
		end++;
		i = 0;
		y++;
	}
	while (y < 340)
	{
		while ((x - end + i) <= (x + end)) 
		{
			my_mlx_pixel_put(img, (x - end + i), y, 0x00009999);
			i++;
		}
		i = 0;
		y++;	
	}
	while (y < 410)
	{
		while ((x - end + i) <= (x + end)) 
		{
			my_mlx_pixel_put(img, (x - end + i), y, (0x00990099));
			i++;
		}
		end--;
		i = 0;
		y++;
	}
	make_circle(img);
}

void				make_square(t_struct *img)
{
	int y;
	int x;
	unsigned long color;
	int plus;

	plus = 16 * 16 * 16 * 16 * 2;
	y = 10;
	x = 10;
	color = 0x00200000;
	while (y < 100)
	{
		while (x < 100)
		{
			x++;
			my_mlx_pixel_put(img, x, y, color);
		}
		color = color + plus;
		x = 10;
		y++;
	}
	make_triangle(img);
}


int		main(void)
{
	void 		*mlx;
	void		*window;
	t_struct	img;


	mlx = mlx_init();
	window = mlx_new_window(mlx, 800, 500, "Hello Wes");
	img.img = mlx_new_image(mlx, 800, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	make_square(&img);
    mlx_put_image_to_window(mlx, window, img.img, 0, 0);
    mlx_loop(mlx);

	mlx_loop(mlx);
	return (0);
}
