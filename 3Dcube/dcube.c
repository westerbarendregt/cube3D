/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dcube.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: wbarendr <wbarendr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/18 12:18:51 by wbarendr       #+#    #+#                */
/*   Updated: 2020/01/20 12:43:55 by wbarendr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "dcube.h"

char	*place_string(char *str, int *i, int columns)
{
	int		j;
	char	*str1;

	j = 0;
	str1 = malloc(columns + 1);
	if (str == NULL)
		return (NULL);
	while (str[*i] != '\n' && str[*i] != '\0')
	{
		str1[j] = str[*i];
		j++;
		(*i)++;
		if (str[*i] != ' ')
			break ;
		(*i)++;
	}
	str1[j] = 0;
	(*i)++;
	return (str1);
}

int		print_array(t_map *f)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (f->map[i] != 0)
	{
		while (j != f->columns)
		{
			write(1, &f->map[i][j], 1);
			j++;
			write(1, " ", 1);
		}
		write(1, "\n", 1);
		j = 0;
		i++;
	}
	return (check_valid_arr(f));
}

char	*make_array(t_map *f, int i)
{
	int r;
	int savei;

	savei = i;
	r = 0;
	f->columns = f->columns / 2 + 1;
	f->map = malloc(sizeof(char *) * (f->rows + 1));
	if (f->map == NULL)
		return (free_willy(f, "malloc failed 4"));
	while (r < f->rows)
	{
		f->map[r] = place_string(f->str, &i, f->columns);
		if (f->map[r] == NULL)
			return (free_map(f, r, "malloc failed 5"));
		r++;
	}
	f->map[f->rows] = 0;
	r = print_array(f);
	if (r == 0)
		return ("\nDONE\n");
	r = get_other_values(f, savei);
	if (r == -1)
		return ("something went TERRIBLY wrong!!\nInput data is not correct..");
	return ("\nAll INPUT DATA IS CORRECT\n");
}

char	*check_valid(t_map *f)
{
	int i;

	f->columns = 0;
	i = ft_strlen(f->str) - 1;
	while (f->str[i] != '\n' && i != 0)
	{
		if (!(f->str[i] == '1' || f->str[i] == ' '))
			return (free_willy(f, "Last line of map is wrong"));
		i--;
		f->columns++;
	}
	while (check_char(f->str[i]) == 1 && (!(f->str[i] == '\n' &&
			f->str[i + 1] == '\n')))
		i--;
	while (f->str[i] != '\n' && f->str[i] != 0)
		i++;
	if (f->str[i] == '\n' && f->str[i + 1] == '\n')
		i++;
	i++;
	f->rows = (ft_strlen(f->str) - i) / f->columns;
	return (make_array(f, i));
}

char	*read_file(t_map *f, int fd)
{
	char	*temp;
	int		amount;

	f->str = ft_calloc(1, 1);
	if (f->str == NULL)
		return ("malloc fail 1");
	temp = malloc(10 + 1);
	if (temp == NULL)
		return (free_willy(f, "malloc fail 2"));
	amount = 1;
	while (amount != 0)
	{
		amount = read(fd, temp, 10);
		if (amount == -1)
			return (free_fred(f, &temp, "Read Failed"));
		temp[amount] = 0;
		f->str = ft_strjoin(f, &temp);
		if (f->str == NULL)
			return (free_fred(f, &temp, "malloc fail 3"));
	}
	free(temp);
	return (check_valid(f));
}
