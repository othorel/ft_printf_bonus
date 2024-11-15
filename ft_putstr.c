/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:31:47 by olthorel          #+#    #+#             */
/*   Updated: 2024/11/15 16:50:12 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putstr_len(char *str, int size)
{
	int	len;

	if (size == -1)
		return (ft_putstr(str));
	len = 0;
	while (str[len] && len < size)
	{
		write(1, &str[len], 1);
		len++;
	}
	return (len);
}

int	ft_put_str(char *str, t_list format)
{
	int	size;
	int	len;

	size = 0;
	if (!str)
		len = 6;
	else
		len = ft_strlen(str);
	while (size + len < format.min)
		size = size + ft_put_char(' ');
	if (!format.dot)
		format.precision = -1;
	if (!str)
		size = size + ft_putstr_len("(null)", format.precision);
	else
		size = size + ft_putstr_len(str, format.precision);
	while (size < format.off)
		size = size + ft_put_char(' ');
	return (size);
}
