/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_if_valid.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: wbarendr <wbarendr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/21 16:57:32 by wbarendr       #+#    #+#                */
/*   Updated: 2019/12/21 18:19:46 by wbarendr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "dcube.h"

void    check_str_for_other(char **arr, int *invalid, int *invalid2, int rows)
{
	int c;
	int r;

	r = 1;
   	c = 1;
	while (r < (rows - 1) && (*invalid) == 0 && (*invalid2) < 2)
	{
		if (arr[r][0] != '1' || arr[r][(ft_strlen(arr[r]) - 1)] != '1')
			(*invalid) = 1;
		while (c < (ft_strlen(arr[r]) - 1) && (*invalid2) < 2 && (*invalid) == 0)
		{
			if (arr[r][c] != ' ')
				(*invalid) = 1;
			c++;
			if (arr[r][c] == 'S' || arr[r][c] == 'N'|| arr[r][c] == 'W'|| arr[r][c] == 'E')
				(*invalid2)++;
			c++;
		}
		c = 1;
		r++;
	}
}

void    check_str_for_one(char *arr, int *invalid)
{
	int c;

	c = 0;
	check_match(arr[c], '1', invalid, &c);
	while (arr[c] && *invalid == 0)
	{
		check_match(arr[c], ' ', invalid, &c);
		if (arr[c] == 0 || *invalid == 1)
			break ;
		check_match(arr[c], '1', invalid, &c);
	}
}

void 	check_valid_arr(char **arr, int rows)
{
	int 	invalid;
	int		invalid2;

	invalid = 0;
	invalid2 = 0;
	check_str_for_one(arr[0], &invalid);
	check_str_for_other(arr, &invalid, &invalid2, rows);
	check_str_for_one(arr[rows - 1], &invalid);
	if (invalid == 1 || invalid2 != 1)
		write(1, "\nMAP = INVALID", 14);
	else 
		write(1, "\nMAP = VALID", 12);
}
