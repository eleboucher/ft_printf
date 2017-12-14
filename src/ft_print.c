/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 11:20:58 by elebouch          #+#    #+#             */
/*   Updated: 2017/12/14 16:37:22 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	long long int i;

	if (data->modifier == md_h)
		i = (short)va_arg(ap, long long int);
	else if (data->modifier == md_db_h)
		i = (signed char)va_arg(ap, long long int);
	else if (data->modifier == md_l)
		i = (long)va_arg(ap, long long int);
	else if (data->modifier == md_db_l)
		i = (long long)va_arg(ap, long long int);
	else if (data->modifier == md_j)
		i = (intmax_t)va_arg(ap, long long int);
	else if (data->modifier == md_z)
		i = (size_t)va_arg(ap, long long int);
	else
		i = (int)va_arg(ap, long long int);
	return (ft_printstr(ft_lltoa_base(i, 10), data));
}

int		ft_formatuint(t_prtf *data, va_list ap)
{
	unsigned long long int i;

	if (data->modifier == md_db_h)
		i = (unsigned char)va_arg(ap, unsigned long long int);
	else if (data->modifier == md_h)
		i = (unsigned short)va_arg(ap, unsigned long long int);
	else if (data->modifier == md_l)
		i = (unsigned long)va_arg(ap, unsigned long long int);
	else if (data->modifier == md_db_l)
		i = va_arg(ap, unsigned long long int);
	else if (data->modifier == md_j)
		i = (uintmax_t)va_arg(ap, unsigned long long int);
	else if (data->modifier == md_z)
		i = (size_t)va_arg(ap, unsigned long long int);
	else
		i = (unsigned int)va_arg(ap, unsigned long long int);
	if (data->format == 'x')
		return (ft_printstr(ft_strtolower(ft_lltoa_base(i, 16)), data));
	if (data->format == 'X')
		return (ft_printstr(ft_lltoa_base(i, 16), data));
	if (data->format == 'o')
		return (ft_printstr(ft_lltoa_base(i, 8), data));
	return (ft_printstr(ft_lltoa_base(i, 10), data));
}

int		ft_formatlong(t_prtf *data, va_list ap)
{
	long long int i;

	if (data->format == 'D')
	{
		i = va_arg(ap, long int);
		return (ft_printstr(ft_lltoa_base(i, 10), data));
	}
	i = (unsigned long int)va_arg(ap, long int);
	if (data->format == 'O')
		return (ft_printstr(ft_lltoa_base(i, 8), data));
	return (ft_printstr(ft_lltoa_base(i, 10), data));
}
