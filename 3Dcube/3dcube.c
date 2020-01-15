/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   3dcube.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: wbarendr <wbarendr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/18 12:18:51 by wbarendr       #+#    #+#                */
/*   Updated: 2020/01/15 22:01:00 by wbarendr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "dcube.h"

int		check_char(char c)
{
	if (c == 'N' || c == 'S'|| c == 'W'|| c == 'E')
		return (1);
	if (c == '0' || c == '1'|| c == '2' || c == ' ')
		return (1);
	if (c == '\n')
		return (1);
	return (0);
}

char 	*place_string(char *str, int *i, int columns)
{
	int j;
	char *str1;

	j = 0;
	str1 = malloc(columns + 1);
	if (str == NULL)
		return (NULL);
	while (str[*i] != '\n' && str[*i] != '\0')
	{
		str1[j] = str[*i];
		j++;
		(*i)++;
	}
	str1[*i] = 0;
	(*i)++;
	return (str1);
}

int 	print_array(char **arr, int column, int rows)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (arr[i] != 0)
	{
		while (j != column)
		{
			write(1, &arr[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		j = 0;
		i++;
	}
	return (check_valid_arr(arr, rows));
}

char	*make_array(t_map *f, int i)
{
	int r;
	int savei;

	savei = i;
	r = 0;
	f->map = malloc(sizeof(char *) * (f->rows + 1));
	if (f->map == NULL)
		return ("malloc failed");
	while (r < f->rows)
	{
		f->map[r] = place_string(f->str, &i, f->columns);
		if (f->map[r] == NULL)
			return ("malloc failed");  // free function
		r++;
	}
	f->map[f->rows] = 0;
	r = print_array(f->map, f->columns, f->rows);
	if (r == 0)
		return ("\n\nDONE\n");
	r = get_other_values(f, savei);
	if (r == -1)
		return ("something went TERRIBLY wrong!!");
	//map_maker(f);
	return ("did it work?\n");
}

char	*check_valid(t_map *f)
{
	int i;

	f->columns = 0;
	i = ft_strlen(f->str) - 1;
	while (f->str[i] != '\n' && i != 0)
	{
		if (!(f->str[i] == '1' || f->str[i] == ' '))
			return ("nope");
		i--;
		f->columns++;
	}
	while (check_char(f->str[i]) == 1 && (!(f->str[i] == '\n' && f->str[i + 1] == '\n')))
		i--;
	while (f->str[i] != '\n' && f->str[i] != 0)
		i++;
	if (f->str[i] == '\n' && f->str[i + 1] == '\n')
		i++;
	i++;
	f->rows = (ft_strlen(f->str) - i) / f->columns;
	//free(str);
	return (make_array(f, i));
}

char	*read_file(t_map *f, int fd)
{
	char 	*temp; 
	int 	amount;

	f->str = ft_calloc(1, 1);
	if (f->str == NULL)
		return ("malloc fail 1");
	temp = malloc(10 + 1);
	if ( temp == NULL)
		return ("malloc fail 2");
	amount = 1;
	while (amount != 0)
	{
		amount = read(fd, temp, 10);
		if (amount == -1)
			return (NULL);  // ga alle returns na!
		temp[amount] = 0; 
		f->str = ft_strjoin(f->str, temp);
		if (f->str == NULL)
			return ("malloc");
	}
	free(temp);
	return (check_valid(f));
}