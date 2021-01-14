/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_bmp.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: wbarendr <wbarendr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/21 13:35:51 by wbarendr       #+#    #+#                */
/*   Updated: 2020/02/24 15:14:33 by wbarendr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "dcube.h"

void	header_bmp(int fd, int width, int height)
{
	unsigned int size;
	unsigned int first_pix;

	first_pix = 54;
	size = height * width * 4 + 54;
	write(fd, "BM", 2);
	write(fd, &size, 4);
	write(fd, "\0\0\0\0", 4);
	write(fd, &first_pix, 4);
}

void	header_dip_bmp(int fd, int width, int height)
{
	unsigned int	headersize;
	unsigned short	plain;
	unsigned short	bits_per_pixel;

	headersize = 40;
	plain = 1;
	bits_per_pixel = 32;
	write(fd, &headersize, 4);
	write(fd, &width, 4);
	write(fd, &height, 4);
	write(fd, &plain, 2);
	write(fd, &bits_per_pixel, 2);
	while (plain <= 24)
	{
		write(fd, "\0", 1);
		plain++;
	}
}

void	write_pixels_real_one(int fd, char *addr, int width, int height)
{
	int x;
	int line_length;

	line_length = 0;
	if (width % 64 != 0)
		line_length = 1;
	line_length = (line_length + (width / 64)) * 256;
	x = 0;
	height -= 1;
	while (height >= 0)
	{
		while (x < width)
		{
			write(fd, &addr[height * line_length + x * 4], 4);
			x++;
		}
		x = 0;
		height--;
	}
}

void	export_bmp(char *name, char *addr, int width, int height)
{
	int fd;

	fd = open(name, O_TRUNC | O_WRONLY | O_CREAT, 0777);
	if (fd < 0)
	{
		write(1, "Open Failed\n", 12);
		return ;
	}
	header_bmp(fd, width, height);
	header_dip_bmp(fd, width, height);
	write_pixels_real_one(fd, addr, width, height);
	write(1, "image is saved\n\n", 16);
}
