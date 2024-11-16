/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:01:48 by olthorel          #+#    #+#             */
/*   Updated: 2024/11/16 11:27:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	put_min(long *nb, int *len, t_list format)
{
	ft_putchar('-');
	(*nb) = (*nb) * -1;
	(*len)--;
	if (format.dot)
		(*len)--;
	return (1);
}

static int	put_digit(long nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		len++;
	while (nb != 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

static int	put_value(char	*start, int *size, t_list *format, long nb)
{
	int		len;

	len = put_digit(nb);
	*size = len;
	if (format->precision > len)
		*size = format->precision;
	if (nb < 0 && format->zero_off > len && format->precision > len)
		(*size)++;
	if (nb < 0 && format->dot && format->precision < format->zero_off)
		len++;
	*start = '0';
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

static int	print_digit(int len, long nb, t_list format)
{
	int	total;

	total = 0;
	if (nb == 0 && format.min && format.min < len)
		total = total + ft_putchar(' ');
	else if (nb == 0 && format.dot && !format.precision && format.min >= len)
		total = total + ft_putchar(' ');
	else if (!(nb == 0 && format.dot && !format.precision))
		total = total + ft_put_nbr(nb);
	return (total);
}

int	ft_putnbr(long nb, t_list format)
{
	int		total;
	int		len;
	char	start;
	int		len_prec;

	total = 0;
	len = put_value(&start, &len_prec, &format, nb);
	while (start == ' ' && len_prec + total < format.min)
		total = total + ft_putchar(' ');
	if (nb < 0)
		total = total + put_min(&nb, &len, format);
	else if (format.space && nb >= 0 && !format.plus && !format.dot)
		total = total + ft_putchar(' ');
	else if (format.plus && nb >= 0 && !format.dot)
		total = total + ft_putchar('+');
	while (len + total < format.min)
		total = total + ft_putchar('0');
	total = total + print_digit(len, nb, format);
	while (total < format.off)
		total = total + ft_putchar(' ');
	return (total);
}
