/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunicode.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 13:31:26 by elebouch          #+#    #+#             */
/*   Updated: 2017/12/23 14:24:30 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int 	ft_formatbigc(t_prtf *data, va_list ap)
{
	wint_t	c;
	int		len;

	len = 0;
	c = va_arg(ap, wchar_t);
	if (data->fg_minus)
	{
		len += ft_putwc(c);
		len += ft_width(1, data);
	}
	else
	{
		len += ft_width(1, data);
		len += ft_putwc(c);
	}
	return (len);
}

int		ft_formatbigs(t_prtf *data, va_list ap)
{
	wchar_t *s;
	int len;
	int size;

	len = -1;
	size = 0;
	s = va_arg(ap, wchar_t *);
	while (s[++size]);
	if (data->fg_minus)
	{
		while (s)
			len += ft_putwc(*s++);
		len += ft_width(size, data);
	}
	else 
	{
		len += ft_width(size, data);
		while (s)
			len += ft_putwc(*s++);
	}
	return (len);
}
