/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:26:30 by olthorel          #+#    #+#             */
/*   Updated: 2024/11/16 11:36:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_base(int nb, char *base)
{
	unsigned int	nbr;
	unsigned int	base_len;
	int				total;

	total = 0;
	nbr = nb;
	base_len = ft_strlen(base);
	if (nbr >= base_len)
	{
		total = total + ft_putnbr_base(nbr / base_len, base);
		total = total + ft_putnbr_base(nbr % base_len, base);
	}
	else
		total = total + ft_putchar(base[nbr]);
	return (total);
}

static int	ft_hexa_len(int nb)
{
	int				total;
	unsigned int	nbr;

	total = 0;
	nbr = nb;
	if (nbr >= 16)
	{
		total = total + ft_hexa_len(nbr / 16);
		total = total + ft_hexa_len(nbr % 16);
	}
	else
		total++;
	return (total);
}

static int	ft_value(char *start, int *size, t_list *format, int nb)
{
	int		len;

	len = ft_hexa_len(nb);
	*size = len;
	if (format->precision > len)
		*size = format->precision;
	if (format->zero && format->dot && format->zero_off > format->precision)
		*start = ' ';
	if (!format->zero)
		*start = ' ';
	if (format->zero)
		format->min = format->zero_off;
	if (format->precision > format->min)
		format->min = format->precision;
	return (len);
}

static int	ft_print_x(int upper, int len, int nb, t_list format)
{
	int		total;

	total = 0;
	if (nb == 0 && format.min && format.min < len)
		total = total + ft_putchar(' ');
	else if (nb == 0 && format.dot && !format.precision && format.min >= len)
		total = total + ft_putchar(' ');
	else if (!(nb == 0 && format.dot && !format.precision))
	{
		if (upper)
			total = total + ft_putnbr_base(nb, "0123456789ABCDEF");
		else
			total = total + ft_putnbr_base(nb, "0123456789abcdef");
	}
	return (total);
}

int	ft_puthexa(int nb, int upper, t_list format)
{
	int		len;
	int		total;
	char	start;
	int		size;

	total = 0;
	len = ft_value(&start, &size, &format, nb);
	while (size + total < format.min)
		total = total + ft_putchar(start);
	while (len + total < format.min)
		total = total + ft_putchar('0');
	if (format.hash && nb != 0)
	{
		if (upper)
			total = total + ft_putstr("0X");
		else
			total = total + ft_putstr("0x");
	}
	total = total + ft_print_x(upper, len, nb, format);
	while (total < format.min)
		total = total + ft_putchar(' ');
	return (total);
}
