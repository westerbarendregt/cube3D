/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_test_valic.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: wbarendr <wbarendr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/21 16:57:05 by wbarendr       #+#    #+#                */
/*   Updated: 2020/01/15 22:13:33 by wbarendr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "dcube.h"
#include <mlx.h>
#include <math.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	int fd;
	t_map f;
	
	if (argc == 1)
	{
		write(1, "missing file", 13);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	printf("%s\n", read_file(&f, fd));
	printf("%d--%d \n", f.rx, f.ry);
	printf("%s\n", f.no);
	printf("%s\n", f.so);
	printf("%s\n", f.we);
	printf("%s\n", f.ea);
	printf("%s\n", f.s);
	printf("%d--%d--%d \n", f.fred, f.fgreen, f.fblue);
	printf("%d--%d--%d \n", f.cred, f.cgreen, f.cblue);
	return (0);
}
