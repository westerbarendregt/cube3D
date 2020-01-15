/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: wbarendr <wbarendr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/21 16:57:05 by wbarendr       #+#    #+#                */
/*   Updated: 2019/12/21 17:57:22 by wbarendr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "dcube.h"

int		main(int argc, char **argv)
{
	int fd;

	if (argc == 1)
	{
		write(1, "missing file", 13);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	printf("%s\n", read_file(fd));
	return (0);
}
