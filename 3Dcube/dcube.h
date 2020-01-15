/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dcube.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: wbarendr <wbarendr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/20 19:53:48 by wbarendr       #+#    #+#                */
/*   Updated: 2020/01/10 16:26:55 by wbarendr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DCUBE_H
# define DCUBE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct	s_map
{
	int r1;
	int r2;
	char *no;
	char *so;
	char *we;
	char *ea;
	char *s;
	int floor1;
	int floor2;
	int floor3;
	int ceiling1;
	int ceiling2;
	int ceiling3;
}				t_map;

char	*read_file(int fd);
int     ft_strlen(char *str);
char    *ft_calloc(int size, int amount);
char    *ft_strjoin(char *str1, char *str2);
void    check_match(char c1, char c2, int *invalid, int *c);
void 	check_valid_arr(char **arr, int rows);

#endif

