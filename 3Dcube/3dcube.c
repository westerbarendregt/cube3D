/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   3dcube.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: wbarendr <wbarendr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/18 12:18:51 by wbarendr       #+#    #+#                */
/*   Updated: 2020/01/14 12:06:02 by wbarendr      ########   odam.nl         */
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

void	print_array(char **arr, int column, int rows)
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
	check_valid_arr(arr, rows);
}

char	*make_array(int rows, int columns, char *str, int i)
{
	char **arr;
	int r;

	r = 0;
	arr = malloc(sizeof(char *) * (rows + 1));
	if (arr == NULL)
		return ("malloc failed");
	while (r < rows)
	{
		arr[r] = place_string(str, &i, columns);
		if (arr[r] == NULL)
			return ("malloc failed");  // free function
		r++;
	}
	arr[rows] = 0;
	print_array(arr, columns, rows);
	return ("\n\nDONE\n");
}

char	*check_valid(char *str)
{
	int i;
	int columns;
	int rows;

	columns = 0;
	i = ft_strlen(str) - 1;
	while (str[i] != '\n' && i != 0)
	{
		if (!(str[i] == '1' || str[i] == ' '))
			return ("nope");
		i--;
		columns++;
	}
	while (check_char(str[i]) == 1 && (!(str[i] == '\n' && str[i + 1] == '\n')))
		i--;
	while (str[i] != '\n' && str[i] != 0)
		i++;
	if (str[i] == '\n'&& str[i + 1] == '\n')
		i++;
	i++;
	rows = (ft_strlen(str) - i) / columns;
	//free(str);
	return (make_array(rows, columns, str, i));
}

char	*read_file(int fd)
{
	char 	*temp;
	char 	*templ; 
	int 	amount;

	templ = ft_calloc(1, 1);
	if ( templ == NULL)
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
		templ = ft_strjoin(templ, temp);
		if (templ == NULL)
			return ("malloc");
	}
	free(temp);
	return (check_valid(templ));
}