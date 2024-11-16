/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:53:27 by olthorel          #+#    #+#             */
/*   Updated: 2024/11/16 11:40:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned(unsigned long nb)
{
	int				total;
	unsigned long	nbr;

	total = 0;
	nbr = nb;
	if (nbr > 100)
		total = total + ft_print_unsigned(nbr / 100);
	else if (nbr == 100)
		total = total + ft_putstr("10");
	else if ((nbr / 10) > 0)
		total = total + ft_putchar((nbr / 10) + '0');
	total = total + ft_putchar((nbr % 10) + '0');
	return (total);
}

static int	ft_nbdigit(unsigned long nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

static int	ft_putvalue(char *start, int *size,
			t_list *format, unsigned long nb)
{
	int		len;

	len = ft_nbdigit(nb);
	*size = len;
	if (format->precision > len)
		*size = format->precision;
	*start = '0';
	if (format->zero_off && format->zero_off > format->precision)
		*start = ' ';
	if (!format->zero)
		*start = ' ';
	if (format->zero)
		format->min = format->zero_off;
	if (format->precision > format->min)
		format->min = format->precision;
	return (len);
}

static int	ft_print_u(int len, unsigned long nb, t_list format)
{
	int	total;

	total = 0;
	if (nb == 0 && format.min && format.min < len)
		total = total + ft_putchar(' ');
	else if (nb == 0 && format.dot && !format.precision && format.min >= len)
		total = total + ft_putchar(' ');
	else if (!(nb == 0 && format.dot && !format.precision))
		total = total + ft_print_unsigned(nb);
	return (total);
}

int	ft_putunsigned(unsigned long nb, t_list format)
{
	int		len;
	int		size;
	int		total;
	char	start;

	total = 0;
	len = ft_putvalue(&start, &size, &format, nb);
	while (size + total < format.min)
		total = total + ft_putchar(start);
	while (len + total < format.min)
		total = total + ft_putchar('0');
	total = total + ft_print_u(len, nb, format);
	while (total < format.off)
		total = total + ft_putchar(' ');
	return (total);
}
