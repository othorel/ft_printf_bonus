/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 09:20:24 by olthorel          #+#    #+#             */
/*   Updated: 2024/11/16 11:33:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct s_list
{
	int		width;
	int		precision;
	int		min;
	int		off;
	int		dot;
	int		zero;
	int		zero_off;
	int		hash;
	int		space;
	int		plus;
	char	specifier;
}			t_list;

/* ******************************************* */
/*					FT_PRINTF.C                */
/* ******************************************* */

int		parse(const char *str, va_list *args, int *len);
int		parse_normal(const char *specifier, va_list *args, t_list format);
void	parse_flags(t_list *format, const char *str, int *len);
int		ft_printf(const char *format, ...);

/* ******************************************* */
/*					FT_PUTCHAR.C               */
/* ******************************************* */

int		ft_putchar(char c);
int		ft_put_char(char c, t_list format);

/* ******************************************* */
/*					FT_PUTSTR.C                */
/* ******************************************* */

int		ft_putstr(char *str);
int		ft_put_str(char *str, t_list format);

/* ******************************************* */
/*					FT_PUTNBR.C                */
/* ******************************************* */

int		ft_putnbr(long nb, t_list format);

/* ******************************************* */	
/*					FT_PUTUNSIGNED.C           */
/* ******************************************* */

int		ft_print_unsigned(unsigned long nb);
int		ft_putunsigned(unsigned long nb, t_list format);

/* ******************************************* */
/*					FT_PUTHEXA.C               */
/* ******************************************* */

int		ft_puthexa(int nb, int upper, t_list format);

/* ******************************************* */
/*					FT_PUTPTR.C                */
/* ******************************************* */

int		ft_putptr(void *ptr, t_list format);

/* ******************************************* */
/*					FT_UTILS.C                 */
/* ******************************************* */

int		ft_atoi(const char *str, int *len);
int		is_in_set(char c, char *set);
void	init_list(t_list *list);
int		ft_strlen(const char *str);
int		ft_put_nbr(long nb);

#endif