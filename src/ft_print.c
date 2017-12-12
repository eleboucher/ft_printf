/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 11:20:58 by elebouch          #+#    #+#             */
/*   Updated: 2017/12/12 12:22:30 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		ft_formatstr(t_prtf *data, va_list ap)
{
	char *s;

	s = va_arg(ap, char *);
	if (!s)
		return (ft_printstr("(null)", data));
	if (data->format == 'S' || (data->format == 's' && data->modifier == md_l))
		return (ft_printstr(s, data));
	if (data->format == 's')
		return (ft_printstr(s, data));
	return (0);
}

int		ft_formatchr(t_prtf *data, va_list ap)
{
	char c;

	(void)data;
	c = va_arg(ap, int);
	write(1, &c, 1);
	return (1);
}

int		ft_formatint(t_prtf *data, va_list ap)
{
	long long i;

	i = va_arg(ap, long long);
	if (data->modifier == md_h)
		return (ft_printstr(ft_lltoa_base((short)i, 10), data));
	if (data->modifier == md_db_h)
		return (ft_printstr(ft_lltoa_base((unsigned char)i, 10), data));
	if (data->modifier == md_l)
		return (ft_printstr(ft_lltoa_base((long)i, 10), data));
	if (data->modifier == md_db_l)
		return (ft_printstr(ft_lltoa_base((long long)i, 10), data));
	if (data->modifier == md_j)
		return (ft_printstr(ft_lltoa_base((intmax_t)i, 10), data));
	if (data->modifier == md_z)
		return (ft_printstr(ft_lltoa_base((size_t)i, 10), data));
	return (ft_printstr(ft_lltoa_base((int)i, 10), data));
}

int		ft_formatuint(t_prtf *data, va_list ap)
{
	unsigned long long i;

	if (data->modifier == md_db_h)
		i = (unsigned char)va_arg(ap, unsigned long long);
	else if (data->modifier == md_h)
		i = (unsigned short)va_arg(ap, unsigned long long);
	else if (data->modifier == md_l)
		i = (unsigned long)va_arg(ap, unsigned long long);
	else if (data->modifier == md_db_l)
		i = va_arg(ap, unsigned long long);
	else if (data->modifier == md_j)
		i = (uintmax_t)va_arg(ap, unsigned long long);
	else if (data->modifier == md_z)
		i = (size_t)va_arg(ap, unsigned long long);
	else
		i = (unsigned int)va_arg(ap, unsigned long long);
	if (data->format == 'x')
		return (ft_printstr(ft_strtolower(ft_lltoa_base(i, 16)), data));
	if (data->format == 'X')
		return (ft_printstr(ft_lltoa_base(i, 16), data));
	if (data->format == 'o')
		return (ft_printstr(ft_lltoa_base(i, 8), data));
	return (ft_printstr(ft_lltoa_base(i, 10), data));
}
