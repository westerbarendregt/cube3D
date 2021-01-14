/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: wbarendr <wbarendr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/20 19:46:18 by wbarendr       #+#    #+#                */
/*   Updated: 2020/01/17 16:56:50 by wbarendr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "dcube.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_calloc(int size, int amount)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(size * amount);
	if (str == NULL)
		return (NULL);
	while (i < (size * amount))
	{
		str[i] = 0;
		i++;
	}
	return (str);
}

char	*ft_strjoin(t_map *f, char **str2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = malloc(ft_strlen(f->str) + ft_strlen(*str2) + 1);
	if (str == NULL)
		return (NULL);
	while (f->str[i])
	{
		str[i] = f->str[i];
		i++;
	}
	while ((*str2)[j])
	{
		str[i + j] = (*str2)[j];
		j++;
	}
	str[i + j] = 0;
	free(f->str);
	return (str);
}

int		compare(char *str, char *str2)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != str2[i])
			return (0);
		i++;
	}
	return (1);
}

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
