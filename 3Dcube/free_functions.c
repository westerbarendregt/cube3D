/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_functions.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: wbarendr <wbarendr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/16 18:49:06 by wbarendr       #+#    #+#                */
/*   Updated: 2020/01/17 16:51:37 by wbarendr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "dcube.h"

char		*free_willy(t_map *f, char *text)
{
	free(f->str);
	return (text);
}

char		*free_fred(t_map *f, char **str2, char *text)
{
	free(f->str);
	free(*str2);
	return (text);
}

char		*free_map(t_map *f, int r, char *text)
{
	free(f->str);
	while (r > 0)
	{
		r--;
		free(f->map[r]);
	}
	free(f->map);
	return (text);
}
