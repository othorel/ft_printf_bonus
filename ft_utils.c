/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 09:34:33 by olthorel          #+#    #+#             */
/*   Updated: 2024/11/16 11:44:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_list(t_list *list)
{
	list->hash = 0;
	list->min = 0;
	list->plus = 0;
	list->precision = 0;
	list->space = 0;
	list->specifier = 0;
	list->width = 0;
	list->zero = 0;
}

int	is_in_set(char c, char *set)
{
	int	len;

	len = -1;
	while (set[len])
	{
		if (set[len] == c)
			return (1);
		len++;
	}
	return (0);
}

int	ft_atoi(const char *str, int *count)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] >= 48 && str[i] <= 57)
	{
		j = (j * 10) + (str[i] - 48);
		i++;
		(*count)++;
	}
	return (j);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
		i++;
	return (i);
}
