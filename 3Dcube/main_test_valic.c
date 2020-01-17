/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_test_valic.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: wbarendr <wbarendr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/21 16:57:05 by wbarendr       #+#    #+#                */
/*   Updated: 2020/01/17 11:18:45 by wbarendr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "dcube.h"

int		main(int argc, char **argv)
{
	int fd;
	t_map f;
	char *str; 

	if (argc == 1)
	{
		write(1, "missing file", 13);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	str = read_file(&f, fd);
	printf("%s\n", str);
	if (compare(str, "\nAll INPUT DATA IS CORRECT\n") == 0)
		return (0);
	printf("%d--%d\n", f.rx, f.ry);
	printf("%s\n", f.no);
	printf("%s\n", f.so);
	printf("%s\n", f.we);
	printf("%s\n", f.ea);
	printf("%s\n", f.s);
	printf("%d--%d--%d\n", f.fred, f.fgreen, f.fblue);
	printf("%d--%d--%d\n", f.cred, f.cgreen, f.cblue);
	printf("floor: %lx\n", f.floor);
	printf("ceiling: %lx\n", f.ceiling);

	put_map_to_window(&f);
	return (0);
}
