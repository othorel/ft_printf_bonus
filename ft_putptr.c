/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:54:28 by olthorel          #+#    #+#             */
/*   Updated: 2024/11/15 19:23:09 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int ft_long_hexa(long unsigned addr)
{
	char	c;
	int		total;

	total = 0;
	if (addr >= 16)
	{
		total = total + ft_long_hexa(addr / 16);
		total = total + ft_long_hexa(addr % 16);
	}
	else
	{
		c = (addr % 16) + '0';
		if (addr % 16 > 9)
			c = (addr % 16) + 'a' - 10;
		write(1, &c, 1);
		total++;
	}
	return (total);
}

static int ft_hexalen(long unsigned addr)
{
	int		total;

	total = 0;
	if (addr >= 16)
	{
		total = total + ft_hexalen(addr / 16);
		total = total + ft_hexalen(addr % 16);
	}
	else
		total++;
	return (total);
}

int	ft_putptr(void *ptr, t_list format)
{
	long	addr;
	int		len;
	int		total;
	
	addr = (long unsigned)ptr;
	total = 0;
	len = ft_hexalen(addr) + 2;
	while (total + len < format.min)
		total = total + ft_putchar(' ');
	total = total + ft_putstr("0x");
	total = total + ft_long_hexa(addr);
	while (total < format.off)
		total = total + ft_putchar(' ');
	return (total);
}	
