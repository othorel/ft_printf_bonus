/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:27:36 by olthorel          #+#    #+#             */
/*   Updated: 2024/11/15 15:28:31 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_put_char(char c, t_list format)
{
	int	len;
	
	len = 0;
	while (len + 1 < format.min)
		len = len + ft_putchar(' ');
	len = len + ft_putchar(c);
	while (len < format.off)
		len = len + ft_putchar(' ');
	return (len);
}