/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: wbarendr <wbarendr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/20 19:46:18 by wbarendr       #+#    #+#                */
/*   Updated: 2019/12/21 15:23:15 by wbarendr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "dcube.h"

int     ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

char    *ft_calloc(int size, int amount)
{
    char    *str;
    int     i;

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

char    *ft_strjoin(char *str1, char *str2)
{
    int     i;
    int     j;
    char    *str;

    i = 0;
    j = 0;
    str = malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
    if (str == NULL)
        return (NULL);
    while (str1[i])
    {
        str[i] = str1[i];
        i++; 
    }
    while (str2[j])
    {
        str[i + j] = str2[j];
        j++;
    }
    str[i + j] = 0;
    return (str);
}

void     check_match(char c1, char c2, int *invalid, int *c)
{
    if (c1 != c2)
        (*invalid) = 1;
    (*c)++;
    return ;
}
