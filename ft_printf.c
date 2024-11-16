/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 09:33:37 by olthorel          #+#    #+#             */
/*   Updated: 2024/11/16 11:41:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_normal(const char *specifier, va_list *args, t_list format)
{
	int	len;

	len = 0;
	if (*specifier == 'c')
		len += ft_put_char(va_arg(*args, int), format);
	else if (*specifier == 's')
		len += ft_put_str(va_arg(*args, char *), format);
	else if (*specifier == 'd' || *specifier == 'i')
		len += ft_putnbr(va_arg(*args, int), format);
	else if (*specifier == 'u')
		len += ft_putunsigned(va_arg(*args, unsigned int), format);
	else if (*specifier == 'x')
		len += ft_puthexa(va_arg(*args, int), 0, format);
	else if (*specifier == 'X')
		len += ft_puthexa(va_arg(*args, int), 1, format);
	else if (*specifier == 'p')
		len += ft_putptr(va_arg(*args, void *), format);
	else if (*specifier == '%')
		len += ft_putchar('%');
	return (len);
}

void	parse_flags(t_list *format, const char *str, int *len)
{
	if (*str == '#')
		format->hash = 1;
	else if (*str == ' ')
		format->space = 1;
	else if (*str == '+')
		format->plus = 1;
	else if (*str == '0')
	{
		format->zero_off = ft_atoi(str + 2, len);
		format->zero = 1;
	}
	else if (*str == '-')
	{
		format->off = ft_atoi(str + 2, len);
		format->min = 1;
	}
	else if (*str == '.')
	{
		format->precision = ft_atoi(str + 2, len);
		format->dot = 1;
	}
}

int	parse(const char *str, va_list *args, int *len)
{
	int		total;
	t_list	list;

	total = 0;
	init_list(&list);
	while (is_in_set(str[(*len) + 1], "0123456789# +-."))
	{
		if (is_in_set(str[(*len) + 1], "# +0-."))
			parse_flags(&list, str + (*len), len);
		else
		{
			list.min = ft_atoi(str + (*len) + 1, len);
			(*len)--;
		}
		(*len)++;
	}
	total = total + parse_normal(str + (*len), args, list);
	(*len)++;
	return (total);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;
	int		total;

	va_start(args, format);
	len = 0;
	total = 0;
	while (format[len])
	{
		if (format[len] == '%')
			total = total + parse(format + len, &args, &len);
		else
			total = total + ft_putchar(format[len]);
		len++;
	}
	va_end(args);
	return (total);
}
