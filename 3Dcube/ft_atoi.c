/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: wbarendr <wbarendr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 15:16:34 by wbarendr       #+#    #+#                */
/*   Updated: 2020/01/15 22:38:19 by wbarendr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "dcube.h"

int		ft_atoi(const char *str)
{
	int					i;
	unsigned long int	num;
	int					min;

	min = 1;
	num = 0;
	i = 0;
	while (str[i] == 32 || str[i] == 9 || (str[i] >= 11 && str[i] <= 13))
		i++;
	if (!(str[i] >= 48 && str[i] <= 57))
		return (-1);
	while (str[i] >= 48 && str[i] <= 57)
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (num * min);
}
